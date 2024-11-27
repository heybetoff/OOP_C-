#include "Course.h"
#include <iostream>

int Course::coursecount = 0;


Course::Course(std::string n,std::string a): name(n), area(a){}

std::string Course::getName(){return name;}
 int Course::count(){return coursecount;}
 std::string Course::getArea(){return area;}

 Course::~Course(){}

 double ScoredCourse::getMark()const {
     double mark = 0.0;
    if(points >= 0 && points <=49 ) {mark = 2;}
    if(points>=50 && points<=59) {mark = 3;}
    if(points>=60 && points<=69) {mark = 3.5;}
    if(points>=70 && points<=79) {mark = 4;}
    if(points>=80 && points<=89) {mark = 4.5;}
    else {mark = 5;}
    return mark;
 }
ScoredCourse::ScoredCourse(std::string n, std::string a, int p) : Course(n, a), points(p) {}
ScoredCourse::~ScoredCourse(){}

int ScoredCourse::getPoints(){return points;}


double AveragedCourse::getMark()const {
double avgm;
if (mark1 == 2 || mark2 ==2){
    avgm = 2.0;
}
else{
    avgm = (mark1+mark2) / 2.0;
}
    return avgm;
}


AveragedCourse::AveragedCourse(std::string n , std::string a , double m1 , double m2 ): Course (n,a), mark1(m1),mark2(m2){}


AveragedCourse::~AveragedCourse(){}


double CheckCourse::getMark()const {
double mark = 0.0;

int passed = as1+as2+as3+as4;

if (passed==0 || passed == 1){mark = 2.0;}
else if (passed == 2 ) {mark = 3.0;}
else if (passed == 3 ) {mark = 4.0;}
else { mark =  5.0;}
return mark;
}



CheckCourse::CheckCourse(std::string n , std::string a , bool a1 , bool a2 , bool a3, bool a4): Course(n,a), as1(a1),as2(a2),as3(a3),as4(a4){}
CheckCourse::~CheckCourse(){}


void Study::add(Course* course){
int ssize = courses.size();
if(ssize>= maxcourse){
    throw LimitError();
}
else {
    courses.push_back(course);
    Course::coursecount++;
}
}

void Study::Remove(std::string coursename) {
    bool found = false;

    for (size_t i = 0; i < courses.size(); i++) {
        if (coursename == courses[i]->getName()) {
            courses.erase(courses.begin() + i);
            found = true;
            Course::coursecount--;
            break;
        }
    }

    if (!found) {
        throw NameError();
    }
}

void Study::RemoveAll(){

for (size_t i = 0; i<courses.size();i++){
    delete courses[i];

}
courses.clear();

}

Study::Study(std::string n , int y , int m) : student_name(n),year(y),maxcourse(m){}


double Study::AverageGrade()const{
double avg =0.0 ;

for ( size_t i = 0 ; i< courses.size();i++){
    avg +=courses[i]->getMark();

}

return avg/courses.size();

}

Course& Study::operator [](size_t index){
int i = index - 1;
int ssize = courses.size();
if (i >= ssize){
    throw std::out_of_range("Exceeds the size of vector");

}

return *courses[i];

}

std::ostream& operator<<(std::ostream& os, const Study& study){
os <<"Student Name : "<<study.student_name<< " ,Year : " <<study.year << " Max Course Count : "<<study.maxcourse<<std::endl;

for(size_t i = 0; i <study.courses.size();i++){
    os <<study.courses[i]->getName()<<" , "<<study.courses[i]->getArea()<< " , Mark : "<<study.courses[i]->getMark()<<std::endl;


}
os<< " Average Grade " << study.AverageGrade()<<std::endl;

return os;
}







