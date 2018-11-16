#include <cstring>
#ifndef DATA_H
#define DATA_H

class Data{
private:
    char *name;
    char *real_name;
    char *bd;
    int male;
    char *ability;
    char *weaknesses;
    int win_amount;
    double strength_rating;
public:

    char *getName() const {
        return name;
    }

    void setName(char *name) {
        strcpy(this->name, name);
    }

    char *getReal_name() const {
        return real_name;
    }

    void setReal_name(char *real_name) {
        strcpy(this->real_name, real_name);
    }

    char *getBd() const {
        return bd;
    }

    void setBd(char *bd) {
        strcpy(this->bd, bd);
    }

    int getMale() const {
        return male;
    }

    void setMale(int male) {
        this->male = male;
    }

    char *getAbility() const {
        return ability;
    }

    void setAbility(char *ability) {
        strcpy(this->ability, ability);
    }

    char *getWeaknesses() const {
        return weaknesses;
    }

    void setWeaknesses(char *weaknesses) {
        strcpy(this->weaknesses, weaknesses);
    }

    int getWin_amount() const {
        return win_amount;
    }

    void setWin_amount(int target) {
        this->win_amount = target;
    }

    double getStrength_rating() const {
        return strength_rating;
    }

    void setStrength_rating(double strength_rating) {
        this->strength_rating = strength_rating;
    }
    Data(char name[32], char real_name[32],char bd[32],int male, char ability[32],char weaknesses[128],int win_amount, double strength_rating){
        this->name=new char[32];
        this->real_name=new char[32];
        this->bd=new char[32];
        this->ability=new char[32];
        this->weaknesses=new char[128];
        setName(name);
        setReal_name(real_name);
        setBd(bd);
        setMale(male);
        setAbility(ability);
        setWeaknesses(weaknesses);
        setWin_amount(win_amount);
        setStrength_rating(strength_rating);
    }
    ~Data(){
        delete[] this->name;
        delete[] this->real_name;
        delete[] this->bd;
        delete[] this->ability;
        delete[] this->weaknesses;

    }
};
#endif
