#include "Racer.hpp"
#include <iostream>


Racer::Racer(std::string name){
drivername = name;
nextnumber++;
startnum = nextNumber ;

}

Racer::Racer(const Racer& other){
drivername = other.drivername;
startnum = other.startnum;
laptime = other.laptime;

}

Racer& Racer::operator=(const Racer& other){
if(this != &other){
    drivername = other.drivername;
startnum = other.startnum;
laptime = other.laptime;


}
return *this;
}

Racer::~Racer(){}


int Racer::GetNextNumber(){
return nextNumber;
}
  void Racer::SetName(std::string name){
  drivername = name;

  }

std::string Racer::GetName()const{
return drivername;
}

int Racer::GetNum()const{
return startnum;

}


void Racer::AddLapTime(double time){

if (time<=0){

    throw std::logic_error("Time is negative or equal to 0 not possible");
}
    laptime.push_back(time);

}

void Racer::RemoveLapTime(int index){

    if (index > laptime.size() ){
        throw std::out_of_range("Out of range");
    }
    else {
        laptime.erase(laptime.begin()+index);

    }

}

int Racer::GetLapCount()const{

return laptime.size();
}


double Racer::avg()const{
double total = 0.0;
int counter = 0;

for (size_t i = 0; i < laptime.size();i++){
    total+=laptime[i];
    counter++;
}
double avg = total/counter;

return avg;
}

double Racer::GetBestLaptime() const {
    if (laptime.empty()) {

        return -1.0;
    }

    double best = laptime[0];

    for (size_t i = 1; i < laptime.size(); i++) {
        if (best > laptime[i]) {
            best = laptime[i];
        }
    }

    return best;
}

bool Racer::operator>(const Racer& other){
return avg()>other.avg();

}

double& Racer::operator[](double index){
 double i = index -1 ;
  if (i>laptime.size()){
    throw std::out_of_range("out of range");
  }


return laptime[i];
}


std::ostream& operator<<(std::ostream& oo, const Racer& r) {
    oo << "Racer Name : " << r.GetName() << std::endl;
    oo << "Racer Number : " << r.GetNum() << std::endl;
    oo << "Lap times : ";
    for (size_t i = 0; i < r.laptime.size(); i++) {
        oo << r.laptime[i] << " , ";
    }
    oo << std::endl;
    oo << "Best Lap Time :  " << r.GetBestLaptime() << std::endl;

    return oo;
}


