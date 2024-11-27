#ifndef CAR
#define CAR
#include <iostream>
#include <vector>

class CarData{

std::string registrationnum;
std::string brand;
std::vector <std::string> customernames;
std::vector<int> rentperiod;

public:

    CarData(std::string regnum, std::string carbrand);
    CarData(const CarData& other);
    CarData& operator=(const CarData& other);
    ~CarData();
    void SetRegNum(std::string regnum);
    std::string GetRegNum()const;
    std::string GetBrand()const;
    void AddRental(std::string cname,int rent);
    void RemoveRentals(std::string cname);
    double AvarageTime ();
    int GetRentCount()const;
    bool operator<(const CarData& other)const;
    int& operator[](int index);
    friend std::ostream& operator<<(std::ostream& os,const CarData& c);
};




#endif // CAR
