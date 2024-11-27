#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#ifndef COURSE
#define COURSE

class Course {
protected:
    std::string name;
    std::string area;
public:
    Course(std::string n,std::string a);

    static  int coursecount;
    static int count();
    virtual double getMark()const = 0;
    std::string getName();
    std::string getArea();
 virtual ~Course();

};


class ScoredCourse : public Course {
protected:
    int points;
public:
    ScoredCourse(std::string n , std::string a,int p);
    double getMark() const override;
    int getPoints();
    ~ScoredCourse();
};


class AveragedCourse : public Course {
protected:
    double mark1,mark2;

public:
    AveragedCourse(std::string n, std::string a , double m1,double m2);
        double getMark() const override;
    ~AveragedCourse();

};


class CheckCourse : public Course {
protected:
    bool as1,as2,as3,as4;
public:
    CheckCourse(std::string n , std::string a , bool a1,bool a2 , bool a3 , bool a4);
    double getMark()const override;
    ~CheckCourse();

};

class Study {
protected:
    std::string student_name;
    int year;
    int maxcourse;
    std::vector<Course*>courses;

public:

   Study(std::string n , int y , int m);

    class LimitError : public std::exception{
    public:

        const char* what() const noexcept override{
        return "LimitError : Limit exceeded";
    }

    };
     class NameError : public std::exception{
     public:

    const char* what() const noexcept override{
    return "NameError : Name not found";
    }

    };

    void add(Course* course);
    void Remove(std::string coursename);

    void RemoveAll();
    double AverageGrade()const;

    Course& operator[](size_t index);

   friend std::ostream& operator<<(std::ostream& os, const Study& study);
};



#endif // COURSE
