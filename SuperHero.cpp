#include "SuperHero.h"
#include <cstring>
#include <iostream>

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

DeQuSH::DeQuSH() {
    DeQuSH::first = nullptr;
    DeQuSH::last = nullptr;
}

DeQuSH DeQuSH::create_empty() {
    DeQuSH tmp;
    return tmp;
}

void DeQuSH::PushBack(SuperHero *target) {
    if (DeQuSH::first == nullptr) {
        DeQuSH::first = target;
        DeQuSH::last = target;
    } else {
        DeQuSH::last->next = target;
        DeQuSH::last = target;
    }
}

void DeQuSH::PushFront(SuperHero *target) {
    if (DeQuSH::first == nullptr) {
        DeQuSH::first = target;
        DeQuSH::last = target;
    } else {
        DeQuSH::first->previous = target;
        DeQuSH::first = target;
    }
}

SuperHero *DeQuSH::PopBack() {
    if (DeQuSH::last != nullptr) {
        SuperHero *tmp = DeQuSH::last;
        DeQuSH::last = tmp->previous;
        return tmp;
    }
    return nullptr;
}

SuperHero *DeQuSH::PopFront() {
    if (DeQuSH::first != nullptr) {
        SuperHero *tmp = DeQuSH::first;
        DeQuSH::first = tmp->next;
        return tmp;
    }
    return nullptr;
}

int DeQuSH::IsEmpty() {
    return 0;
}

void DeQuSH::clear() {

}

void DeQuSH::print() {
    SuperHero *current = DeQuSH::first;
    while (current != nullptr) {
        print(current);
        current = current->next;
    }
}

void DeQuSH::print(SuperHero *hero) {
    std::cout << "**********************************" << std::endl;
    std::cout << "Printing hero stats" << std::endl;
    std::cout << "Hero name : " << hero->getName() << std::endl;
    std::cout << "Hero real name : " << hero->getReal_name() << std::endl;
    std::cout << "Hero birthday : " << hero->getBd() << std::endl;
    std::cout << "Hero male : " << ((hero->getMale() == 0) ? "Man" : "Woman") << std::endl;
    std::cout << "Hero ability : " << hero->getAbility() << std::endl;
    std::cout << "Hero weaknesses : " << hero->getWeaknesses() << std::endl;
    std::cout << "Hero wins : " << hero->getWin_amount() << std::endl;
    std::cout << "Hero strength rating : " << hero->getStrength_rating() << std::endl;
    std::cout << "**********************************" << std::endl;
}

int DeQuSH::save(const char *path) {
    return 0;
}

int DeQuSH::load(const char *path) {
    return 0;
}

void DeQuSH::insert(SuperHero *hero, int n) {

}

