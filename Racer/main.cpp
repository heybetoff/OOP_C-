#include "Racer.hpp"
#include <iostream>
int Racer::nextNumber = 1;

int main(){
std::cout<<Racer::GetNextNumber()<<std::endl;
Racer r1("Hamilton");
std::cout<<r1.GetNum()<<std::endl;
Racer r2("Heybatov");
std::cout<<r2.GetNum()<<std::endl;

r1.AddLapTime(56.35);
r1.AddLapTime(69.35);
r1.AddLapTime(87.35);
r1.AddLapTime(30.35);
std::cout<<r1.GetBestLaptime()<<std::endl;
r2.AddLapTime(60.35);
r2.AddLapTime(89.35);
r2.AddLapTime(45.35);
r2.AddLapTime(38.35);
std::cout<<r2.GetBestLaptime()<<std::endl;
r1[1]=59.35;

std::cout<<r1;
std::cout<<std::endl;

if(r1>r2){

    std::cout<<"r1 has better avarage than r2"<<std::endl;
}
else {
    std::cout<<"r2 has better avarage than r1"<<std::endl;
}


}



