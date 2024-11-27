#ifndef RESTAURANT_KNOWN
#define RESTAURANT_KNOWN
#include <iostream>
#include <string>
#include <vector>


class Worker
{
    std::string Name;
    double Wage;
    std::vector<int> WorkHour;

public:
static int counter;
    Worker(std::string name,double wage);
    Worker(const Worker& other);
    Worker& operator=(const Worker& other);
    ~Worker();
    void setName(std::string newname);
    std::string getName();
    void setWage(double newwage);
    double getWage ();
    void addTime(int time);
    int listSize();
    int TotalWorkTime()const;
    void ModifyTimes();
    int GetCounter();
    int overTimeWorkers();
    double getEarnings();
     int& operator[](int index);
   friend std::ostream& operator<<(std::ostream& os, const Worker& worker);
    bool operator>(const Worker& other);





};

#endif
