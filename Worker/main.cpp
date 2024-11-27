#include "worker.hpp"
#include <iostream>

int main() {

    std::cout<<Worker::counter<<std::endl;

    Worker worker1("John Doe", 22.5);


    worker1.addTime(20);
    worker1.addTime(20);
    worker1.addTime(20);
    worker1.addTime(20);
    worker1.addTime(20);
    worker1.addTime(20);
    worker1.addTime(20);
    worker1.addTime(20);
    worker1.addTime(2);

    Worker w2("Adam",25);
    w2.addTime(20);
    w2.addTime(20);

    std::cout << worker1;


    std::cout << "Total work time: " << worker1.TotalWorkTime() << " hours" << std::endl;


    std::cout << "Earnings: $" << worker1.getEarnings() << std::endl;
    worker1.ModifyTimes();



   worker1[1] = 12;

std::cout << "Updated worker details:" << std::endl;
    std::cout << worker1;

    if(worker1>w2){

        std::cout<<"W1 worked more than w2"<<std::endl;
    }
    else{
        std::cout<<"W2 worked more than w1"<<std::endl;
    }

std::cout<<Worker::counter<<std::endl;
    return 0;
}
