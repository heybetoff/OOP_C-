#include "car.hpp"
#include<iostream>


int main(){
CarData c1("10UH648","Opel Astra");

std::cout<<c1.GetRegNum()<<std::endl;
c1.AddRental("Asaf ",5);
c1.AddRental("Azar ",7);
c1.AddRental("Adam ",20);
c1.AddRental("Aydin ",2);
std::cout<<"Average Time : "<<c1.AvarageTime()<<std::endl;
c1[1]=12;
std::cout<<c1;

}
