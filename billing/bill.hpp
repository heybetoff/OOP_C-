#ifndef BILLING
#define BILLING
#include <bits/stdc++.h>
using namespace std;




class billing{

string userName;
int userNumber;
vector<int>numbers;
vector<int>minutes;
public:
    static int connectiontotal;
    int getconnectiontotal();
    billing( int UN, std::string name);
    billing(const billing& other);
    billing& operator=(const billing& other);
    ~billing();
    void setName(string UN);
    string getName()const;
    int getNumber()const;
    void AddCall(int phnum,int minut);
    void RemoveCall(int phnum);
    int totalConnectionTIme()const;
    int getBillingCount();
    static int totalCount;
    bool operator>(const billing& other);
    friend ostream& operator<<(ostream& os,const billing& b);
};


#endif 

