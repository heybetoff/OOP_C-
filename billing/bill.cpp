#include "bill.hpp"
#include <bits/stdc++.h>
using namespace std;


billing::billing(int UN, std::string name){
    ++totalCount;
    userName= name;
    userNumber=UN;
}
billing::billing(const billing& other ){
    userName=other.userName;
    userNumber=other.userNumber;
    numbers=other.numbers;
    minutes=other.minutes;
}
billing&billing::operator=(const billing& other){
    if( this!= &other)
    {
         userName=other.userName;
    userNumber=other.userNumber;
    numbers=other.numbers;
    minutes=other.minutes;
    }
    return *this;
}
billing::~billing(){
    cout<<"user "<< userNumber<< "has been destroyed "<<endl;
}
void billing::setName(string UN){
    userName=UN;
}
string billing::getName()const{
    return userName;
}

int billing::getNumber()const{
    return userNumber;
}


void billing::AddCall(int phnum,int minut){
    if(phnum == userNumber){
        throw std::logic_error("You cannot call yourself");
    }
     else{
        numbers.push_back(phnum);
        minutes.push_back(minut);
        connectiontotal+=minut;
    }


}
int billing::connectiontotal = 0;

int billing::getconnectiontotal(){
return connectiontotal;
}
void billing::RemoveCall(int phnum){

for(size_t i = 0; i<numbers.size();i++){
    if(phnum==numbers[i]){
        numbers.erase(numbers.begin()+i);
        minutes.erase(minutes.begin()+i);
        connectiontotal-=minutes[i];
    }
    else{

    throw std::logic_error("Number is not present in the list");
    }

}

}

int billing::totalConnectionTIme()const{
int total= 0;
for(size_t i = 0; i<numbers.size();i++){
   total+=minutes[i];
}

return total;
}

int billing::getBillingCount()
{
    return totalCount;
}

int billing::totalCount = 0;


bool billing::operator>(const billing& other){

return totalConnectionTIme()>other.totalConnectionTIme();
}


ostream& operator<<(ostream& os, const billing& b){
os <<"Billing for : "<<b.getNumber()<<";"<<b.getName()<<std::endl;
for(size_t i = 0; i < b.numbers.size();i++){
    os<<i+1<<"."<<b.numbers[i]<<",  "<<b.minutes[i]<<" minutes"<<endl;
}

int remaining =0;
int hours = 0;
if(b.totalConnectionTIme()>=60){
    remaining = b.totalConnectionTIme()-60;
    hours = hours+1;
}

os<<"Summary time : "<<hours<<" hours "<<remaining<<" minutes"<<std::endl;

return os;
}


