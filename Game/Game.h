#ifndef GAME
#define GAME
#include <iostream>
#include <vector>
#include<cmath>
#include <exception>


class Game {
 protected:
     std::string name;
     int price;
 public:
    static int gamecount;
    static int count();
    Game(std::string n,int p);
    virtual int getTime()const=0;
    virtual ~Game();
    std::string getName()const;
    int getPrice()const;
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

class RPG : public Game{
protected:
    int standarttime;
    int numofpaths;
    int path;
public:
        RPG(std::string n , int p , int s,int numofpaths_ , int hour);
        int getTime()const override;
        ~RPG();

};


class Platformer : public Game {
protected:
    int standart;
    int additional;
    int levels;

public:
    Platformer(std::string n , int p , int s , int a ,int l );
        int getTime()const override;
        ~Platformer();

};

class SandBox : public Game{
protected:
    int playinghours;
public:
    SandBox(std::string n , int p ,int h );
    int getTime()const override;
    ~SandBox();

};


class Plan {
protected:
    std::string nick;
    std::string email;
    int budget;
    std::vector<Game*> games;
public:
    std::string getNick()const ;
    std::string getEmail()const;
    int getBudget();

    Plan(std::string n , std::string e ,int b);
    static int total;
    class BudgetError : public std::exception{
    const char* what() const noexcept{
    return "BudgetError : Limit";
    }


    };

    class NameError : public std::exception{
    const char* what() const noexcept{
    return "NameError : Name not found";
    }


    };

    void add(Game* game);

    void remove (std::string gamename);
    void removeall();
    int TotalCost()const;
    int averagetime()const;

Game* operator[](const std::string& gamename) const;
friend std::ostream&  operator<<(std::ostream& os , const Plan& plan );

};


#endif // GAME
