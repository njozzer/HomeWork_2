#include "SuperHero.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include "DeQueue.h"

using namespace DeQueue;
namespace Heroes {
    SuperHero::SuperHero(char name[32], char real_name[32],
                         char bd[32], int male,
                         char ability[32], char weaknesses[128],
                         int win_amount, double strength_rating) {
        SuperHero::name = new char[32];
        strcpy(SuperHero::name, name);
        SuperHero::real_name = new char[32];
        strcpy(SuperHero::real_name, real_name);
        SuperHero::bd = new char[32];
        strcpy(SuperHero::bd, bd);
        SuperHero::male = male;
        SuperHero::ability = new char[32];
        strcpy(SuperHero::ability, ability);
        SuperHero::weaknesses = new char[128];
        strcpy(SuperHero::weaknesses, weaknesses);
        SuperHero::win_amount = win_amount;
        SuperHero::strength_rating = strength_rating;
        SuperHero::next = nullptr;
        SuperHero::previous = nullptr;
    }

    SuperHero::~SuperHero() {
        delete[] SuperHero::name;
        delete[] SuperHero::real_name;
        delete[] SuperHero::bd;
        delete[] SuperHero::ability;
        delete[] SuperHero::weaknesses;

    }

    SuperHero::SuperHero(SuperHero *h) {
        SuperHero::name = new char[32];
        strcpy(SuperHero::name, h->name);
        SuperHero::real_name = new char[32];
        strcpy(SuperHero::real_name, h->real_name);
        SuperHero::bd = new char[32];
        strcpy(SuperHero::bd, h->bd);
        SuperHero::male = male;
        SuperHero::ability = new char[32];
        strcpy(SuperHero::ability, h->ability);
        SuperHero::weaknesses = new char[128];
        strcpy(SuperHero::weaknesses, h->weaknesses);
        SuperHero::win_amount = win_amount;
        SuperHero::strength_rating = strength_rating;
        SuperHero::next = nullptr;
        SuperHero::previous = nullptr;
    }

    char *SuperHero::getName() const {
        return name;
    }

    void SuperHero::setName(char *name) {
        strcpy(SuperHero::name, name);
    }

    char *SuperHero::getReal_name() const {
        return real_name;
    }

    void SuperHero::setReal_name(char *real_name) {
        strcpy(SuperHero::real_name, real_name);
    }

    char *SuperHero::getBd() const {
        return bd;
    }

    void SuperHero::setBd(char *bd) {
        strcpy(SuperHero::bd, bd);
    }

    int SuperHero::getMale() const {
        return male;
    }

    void SuperHero::setMale(int male) {
        SuperHero::male = male;
    }

    char *SuperHero::getAbility() const {
        return ability;
    }

    void SuperHero::setAbility(char *ability) {
        strcpy(SuperHero::ability, ability);
    }

    char *SuperHero::getWeaknesses() const {
        return weaknesses;
    }

    void SuperHero::setWeaknesses(char *weaknesses) {
        strcpy(SuperHero::weaknesses, weaknesses);
    }

    int SuperHero::getWin_amount() const {
        return win_amount;
    }

    void SuperHero::setWin_amount(int win_amount) {
        SuperHero::win_amount = win_amount;
    }

    double SuperHero::getStrength_rating() const {
        return strength_rating;
    }

    void SuperHero::setStrength_rating(double strength_rating) {
        SuperHero::strength_rating = strength_rating;
    }

    SuperHero &SuperHero::operator=(SuperHero &v) {
        SuperHero::name = v.name;
        SuperHero::real_name = v.real_name;
        SuperHero::bd = v.bd;
        SuperHero::male = v.male;
        SuperHero::ability = v.ability;
        SuperHero::weaknesses = v.weaknesses;
        SuperHero::win_amount = v.win_amount;
        SuperHero::strength_rating = v.strength_rating;
        return *this;
    }

    SuperHero &SuperHero::operator+(DeQuSH &dq) {
        dq.Push_Back(*this);
        return *this;
    }
}
