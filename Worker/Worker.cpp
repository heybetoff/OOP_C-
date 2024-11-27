#include "worker.hpp"
#include<stdexcept>

Worker::Worker(std::string name,double wage){

 Name = name;
 Wage = wage;

}

Worker::Worker(const Worker& other){
Name = other.Name;
Wage = other.Wage;
WorkHour= other.WorkHour;

}

Worker& Worker::operator=(const Worker& other){
if (this!= &other){
    Name = other.Name;
    Wage = other.Wage;
    WorkHour = other.WorkHour;
}
return *this;
}

Worker::~Worker(){

std::cout<<"Worker " <<Name<<" destroyed"<<std::endl;

}

void Worker::setName(std::string newname){

Name = newname;

}

int Worker::counter=0;

std::string Worker::getName(){
return Name;
}

void Worker::setWage(double newwage){

Wage = newwage;

}

double Worker::getWage(){

return Wage;

}

void Worker::addTime(int time){

if (time > 24){
    throw std::logic_error("Can not be more than 24 hours");
}
    else{

        WorkHour.push_back(time);
    }
}

int Worker::listSize(){

return WorkHour.size();

}

int Worker::TotalWorkTime()const{
int total = 0;
    for (int hours : WorkHour) {
        total += hours;
    }
    return total;
}
int Worker::overTimeWorkers() {
    int totalHourLimit = 160;
    int totalWorkTime = TotalWorkTime();
    int count=0;
    if (totalWorkTime > totalHourLimit) {
        count++;
        counter++;
    }

    return count;
}

void Worker::ModifyTimes() {
    for (size_t i = 0; i < WorkHour.size(); ++i) {
        if (WorkHour[i] > 12) {
            int remaining = WorkHour[i] - 12;
            WorkHour[i] = 12;
            WorkHour.insert(WorkHour.begin() + i + 1, remaining);
    ++i;
        }
    }
}


double Worker::getEarnings() {
    double totalHours = TotalWorkTime();
    double regularPay = 0;
    double overtimePay = 0;

    if (totalHours <= 160) {
        regularPay = totalHours * Wage;
    } else {
        regularPay = 160 * Wage;
        double overtimeHours = totalHours - 160;
        overtimePay = overtimeHours * Wage * 1.1;
    }
double total = regularPay + overtimePay;

    return total;
}


int& Worker::operator[](int index ){

if (index >= WorkHour.size()) {
        throw std::out_of_range("Index out of range");
    }
    return WorkHour[index];
}

std::ostream& operator<<(std::ostream& os, const Worker& worker) {
    os << "Worker Name: " << worker.Name << std::endl;
    os << "Wage: " << worker.Wage << std::endl;
    os << "Work Hours: ";
    for (int i : worker.WorkHour) {
        os << i << " ";
    }
    os<<" "<<"Total : "<<worker.TotalWorkTime()<<std::endl;

    return os;
}

bool Worker::operator>(const Worker& other) {
    return TotalWorkTime() > other.TotalWorkTime();
}
