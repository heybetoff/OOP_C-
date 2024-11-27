#include "car.hpp"
#include <stdexcept>




CarData::CarData(std::string regnum,std::string carbrand ){
registrationnum = regnum;
brand = carbrand;

}
CarData::CarData(const CarData& other ){
brand = other.brand;
registrationnum = other.registrationnum;
customernames = other.customernames;
rentperiod = other.rentperiod;
}
CarData& CarData::operator=(const CarData& other){
if (this != &other){
    brand = other.brand;
registrationnum = other.registrationnum;
customernames = other.customernames;
rentperiod = other.rentperiod;

}
return *this;

}

CarData::~CarData(){
std::cout<<registrationnum<<" "<<"has been deleted"<<std::endl;
}

void CarData::SetRegNum(std::string regnum){
registrationnum=regnum;
}

std::string CarData::GetRegNum()const{
return registrationnum;

}

std::string CarData::GetBrand()const{
return brand;
}

void CarData::AddRental(std::string cname,int rent){
customernames.push_back(cname);
rentperiod.push_back(rent);
}

void CarData::RemoveRentals(std::string cname){
bool found = false;
    for(size_t i = 0; i < customernames.size();i++){
        if (cname == customernames[i]){
            customernames.erase(customernames.begin()+i);
            rentperiod.erase(rentperiod.begin()+i);
            found = true;
            --i;
        }
        if (!found){
            throw std::runtime_error("customer not found in the list");
        }
    }

}

double CarData::AvarageTime(){
double total= 0.0;
int count = 0;
    if(rentperiod.empty()){
        return 0.0;
    }

    for(int i = 0; i< rentperiod.size();i++){
        total+=rentperiod[i];
        count++;
    }
return total/count;
}

int CarData::GetRentCount()const{
return rentperiod.size();
}

bool CarData::operator<(const CarData& other)const{
return GetRentCount() < other.GetRentCount();
}

int& CarData::operator[](int index){
int i = index -1;
 if(index > rentperiod.size()){
    throw std::out_of_range("Out of range");
 }
    return rentperiod[i];

}
std::ostream& operator<<(std::ostream& os, const CarData& c ){
os<<"Car : "<<c.GetBrand()<<" "<<c.GetRegNum()<<std::endl;
for (size_t i = 0; i <c.GetRentCount();i++){
    os<<c.customernames[i]<<" "<<c.rentperiod[i]<<std::endl;

}
return os;

}


