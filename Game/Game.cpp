#include "Game.h"
int Plan::total = 0;
int Game::gamecount=0;
Game::Game(std::string n, int p ) : name(n), price(p) {}
Game::~Game() {}
std::string Game::getName()const
{
    return name;
}
int Game::getPrice()const
{
    return price;
}


RPG::RPG(std::string n, int p, int s,int numofpaths_,int hour) : Game(n,p),standarttime(s),numofpaths(numofpaths_),path(hour)
{
    gamecount++;
}
int RPG::getTime()const
{
    int totaltime;
    totaltime = standarttime + numofpaths * path;

    return totaltime;
}

RPG::~RPG()
{
    gamecount--;
}

Platformer::Platformer(std::string n, int p, int s, int a,int l):Game(n,p),standart(s),additional(a),levels(l)
{
    gamecount++;
}
int Platformer::getTime()const
{
    int total = (standart+ additional)*levels;

    return total;
}

Platformer::~Platformer()
{
    gamecount--;
}

SandBox::SandBox(std::string n, int p,int h):Game(n,p),playinghours(h)
{
    gamecount++;
}
int SandBox::getTime()const
{

    int per = playinghours + (playinghours % 20);

    return per;
}
SandBox::~SandBox()
{
    gamecount--;
}
Plan::Plan(std::string n , std::string e ,int b):nick(n),email(e),budget(b){}

void Plan::add(Game* game){
if (game->getPrice()+total > budget){
    throw BudgetError();
}
    else {
        games.push_back(game);
        total = total+game->getPrice();
    }

}
std::string Plan::getEmail()const{return email;}
std::string Plan::getNick()const{return nick;}
int Plan::getBudget(){return budget;}

void Plan::remove(std::string gamename){
bool found = false;

for(size_t i = 0 ; i<games.size();i++){
if(gamename == games[i]->getName() )
games.erase(games.begin()+i);
found =true;
break;
}

if (!found){
        throw NameError();

}
}

void Plan::removeall(){
for (size_t i = 0 ; i < games.size();i++){
     delete games[i];

}
games.clear();
}

int Plan::averagetime() const {
    int time = 0;

    for (size_t i = 0; i < games.size(); ++i) {
        time += games[i]->getTime();
    }

    if (games.size() > 0) {
        int avg = time / games.size();
        return avg;
    } else {
        return 0;
}
}

int Plan::TotalCost() const {
    int total = 0;

    for (size_t i = 0; i < games.size(); ++i) {
        total += games[i]->getPrice();
    }

    return total;
}





Game* Plan::operator[](const std::string& gamename) const {
    for (size_t i = 0 ; i < games.size();i++) {
        if (games[i]->getName() == gamename) {
            return games[i];
        }
    }


    throw NameError();
}
std::ostream& operator<<(std::ostream& os, const Game& game) {
    os << "Game: " << game.getName() << ", Price: " << game.getPrice();
    return os;
}

std::ostream& operator<<(std::ostream& os, const Plan& plan) {
    os << "Nick: " << plan.getNick() << " (" << plan.getEmail() << "), Avg time: " << plan.averagetime() << ", Total Cost: " << plan.TotalCost() << std::endl;

    for (size_t i = 0; i < plan.games.size(); ++i) {
        os << "    " << *plan.games[i] << std::endl;
    }

    return os;
}







