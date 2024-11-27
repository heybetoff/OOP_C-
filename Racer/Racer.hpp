#ifndef RACER
#define RACER
#include <iostream>
#include<vector>
#include <stdexcept>



class Racer{

std::string drivername;
int startnum;
std::vector<double> laptime;
 static int nextNumber;

public:
    int GetNextNumber();
    Racer(std::string name);
    Racer(const Racer& other);
    Racer& operator=(const Racer& other);
    ~Racer();
    void SetName(std::string name);
    std::string GetName()const;
    int GetNum()const;
    void AddLapTime(double time);
    void RemoveLapTime(int index);
    int GetLapCount()const;
    double GetBestLaptime()const;
    double avg()const;
    bool operator>(const Racer& other);
    double& operator[](double index);
    friend std::ostream& operator<<(std::ostream& oo, const Racer& r);
};






#endif // RACER
