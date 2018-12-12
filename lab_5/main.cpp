#include <iostream>
#include <list>
#include <cstring>
#include <algorithm>
#include <fstream>
class Node {
private:
    std::string name;
    std::string real_name;
    std::string bd;
    int male;
    std::string ability;
    std::string weaknesses;
    int win_amount;
    double strength_rating;
public:
    std::string getName() const {
        return name;
    }

    void setName(std::string name) {
        this->name = name;
    }

    std::string getReal_name() const {
        return real_name;
    }

    void setReal_name(std::string real_name) {
        this->real_name = real_name;
    }

    std::string getBd() const {
        return bd;
    }

    void setBd(std::string bd) {
        this->bd = bd;
    }

    int getMale() const {
        return male;
    }

    void setMale(int male) {
        this->male = male;
    }

    std::string getAbility() const {
        return ability;
    }

    void setAbility(std::string ability) {
        this->ability = ability;
    }

    std::string getWeaknesses() const {
        return weaknesses;
    }

    void setWeaknesses(std::string weaknesses) {
        this->weaknesses = weaknesses;
    }

    int getWin_amount() const {
        return win_amount;
    }

    void setWin_amount(int win_amount) {
        this->win_amount = win_amount;
    }

    double getStrength_rating() const {
        return strength_rating;
    }

    void setStrength_rating(double strength_rating) {
        this->strength_rating = strength_rating;
    }
    Node(){

    }
};
class Compare {
public:
    bool operator()( const Node * a,const Node * b ) {
        if( a->getName().compare(b->getName() ) < 0 ) {
            return true;
        }else{
            return false;
        }
    }

};
class Filter {
    int arg;
    double value;
    //-1 === '<', 0 === '==', 1 === '>';
public:
    Filter(int a,double value){
        this->arg = a;
        this->value = value;
    }
    bool operator()( const Node * a ) {
        switch ( arg ) {
            case -1: {
                return a->getStrength_rating() < value ? true : false;
                break;
            }
            case 0: {
                return a->getStrength_rating() == value ? true : false;
                break;
            }
            case 1: {
                return a->getStrength_rating() > value ? true : false;
                break;
            }
        }
        return false;
    }
};
class Main_List : public std::list < Node* > {
public:
    void print() {

        for( auto i = this->begin(); i != this->end(); i++ ) {
            print( ( *i ) );
        }
    }

    void print(Node *hero) {
        std::cout << "**********************************" << std::endl;
        std::cout << "Printing hero stats" << std::endl;
        std::cout << "Hero name : " << hero->getName() << std::endl;
        std::cout << "Hero real name : " << hero->getReal_name() << std::endl;
        std::cout << "Hero birthday : " << hero->getBd() << std::endl;
        std::cout << "Hero male : " << ( ( hero->getMale() == 0 ) ? "Man" : "Woman" ) << std::endl;
        std::cout << "Hero ability : " << hero->getAbility() << std::endl;
        std::cout << "Hero weaknesses : " << hero->getWeaknesses() << std::endl;
        std::cout << "Hero wins : " << hero->getWin_amount() << std::endl;
        std::cout << "Hero strength rating : " << hero->getStrength_rating() << std::endl;
        std::cout << "**********************************" << std::endl;
    }
    int save(const char *path) {
        std::ofstream fstr;
        fstr.open(path);
        for( auto i = this->begin(); i != this->end(); i++ ) {
            fstr << ( *i )->getName() << " " << ( *i )->getReal_name() << " " << ( *i )->getBd() << " "
                 << ( *i )->getMale() << " " << ( *i )->getAbility() << " " << ( *i )->getWeaknesses() << " "
                 << ( *i )->getWin_amount() << " " << ( *i )->getStrength_rating() << std::endl;
        }

        fstr.close();
        return 0;
    }

    int load(const char *path) {
        std::ifstream fstr;
        fstr.open(path);
        while ( !fstr.eof() ) {
            std::string name;
            std::string real_name;
            std::string bd;
            int male = 0;
            std::string ability;
            std::string weaknesses;
            int win_amount = 0;
            double strength_rating = 0.0;
            fstr >> name;
            fstr >> real_name;
            fstr >> bd;
            fstr >> male;
            fstr >> ability;
            fstr >> weaknesses;
            fstr >> win_amount;
            fstr >> strength_rating;
            Node *n = new Node();
            n->setName(name);
            n->setReal_name(real_name);
            n->setBd(bd);
            n->setMale(male);
            n->setAbility(ability);
            n->setWeaknesses(weaknesses);
            n->setWin_amount(win_amount);
            n->setStrength_rating(strength_rating);
            push_back(n);
        }
        fstr.close();
        return 0;
    }
};
int main(){
    Main_List lst;
    /*Node *a = new Node();
       Node *b = new Node();
       Node *c = new Node();
       Node *d = new Node();
       a->setName("Aa");
       a->setStrength_rating(100);
       b->setName("Ab");
       b->setStrength_rating(300);
       c->setName("Ac");
       c->setStrength_rating(10);
       d->setName("Ad");
       d->setStrength_rating(250);
       lst.push_back(d);
       lst.push_back(a);
       lst.push_back(c);
       lst.push_back(b);*/
    /*for_each(lst.begin(),lst.end(),[] (Node *a){
       std::cout << a->getName() << '\n';
       });
       std::cout << "*****" << '\n';
       for_each(lst.rbegin(),lst.rend(),[] (Node *a){
       std::cout << a->getName() << '\n';
       });
       std::cout << "*****" << '\n';
       lst.sort(Compare() );
       for_each(lst.begin(),lst.end(),[] (Node *a){
       std::cout << a->getName() << '\n';
       });
       auto it = lst.begin();
       while( it != lst.end() ) {
       it = std::find_if (it, lst.end(), Filter(-1,145) );
       if( it == lst.end() ) break;
       std::cout << ( *it )->getStrength_rating() << '\n';
       it++;

       }*/
    lst.load("D:\\programming\\lab_5\\data.txt");
    lst.save("D:\\programming\\lab_5\\data2.txt");
    lst.print();
}
