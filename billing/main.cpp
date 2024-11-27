#include "bill.hpp"
#include <iostream>

int main(){
std::cout<<billing::connectiontotal<<std::endl;

billing b1(452395899,"Seymur");
b1.AddCall(589632147,30);
b1.AddCall(856978123,15);
b1.AddCall(126978123,30);
b1.AddCall(696978123,10);
std::cout<<b1;
std::cout<<"Total min"<<b1.totalConnectionTIme();
std::cout << billing::getBillingCount << std::endl;
billing b2(452385667,"am");
b1.AddCall(126978123,32);
std::cout<<billing::connectiontotal<<std::endl;
}
