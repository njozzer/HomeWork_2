#include "SuperHero.h"
#include <cstring>
#include <iostream>
#include <fstream>

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
        SuperHero *tmp = DeQuSH::last;
        if (tmp == nullptr) {
            DeQuSH::last = target;
            DeQuSH::first = target;
        } else {
            tmp->next = target;
            target->previous = tmp;
            DeQuSH::last = target;
        }
    }

    void DeQuSH::PushFront(SuperHero *target) {
        SuperHero *tmp = DeQuSH::first;
        if (tmp == nullptr) {
            DeQuSH::last = target;
            DeQuSH::first = target;
        } else {
            tmp->previous = target;
            target->next = tmp;
            DeQuSH::first = target;
        }
    }

    SuperHero *DeQuSH::PopBack() {
        if (DeQuSH::last != nullptr) {
            SuperHero *tmp = DeQuSH::last;
            DeQuSH::last = tmp->previous;
            DeQuSH::last->next = nullptr;
            tmp->previous = nullptr;
            tmp->next = nullptr;
            return tmp;
        }
        return nullptr;
    }

    SuperHero *DeQuSH::PopFront() {
        if (DeQuSH::first != nullptr) {
            SuperHero *tmp = DeQuSH::first;
            DeQuSH::first = tmp->next;
            DeQuSH::first->previous = nullptr;
            tmp->previous = nullptr;
            tmp->next = nullptr;
            return tmp;
        }
        return nullptr;
    }

    int DeQuSH::IsEmpty() {
        if (DeQuSH::first == nullptr) {
            return 0;
        } else {
            return -1;
        }
    }

    void DeQuSH::clear() {
        SuperHero *current = DeQuSH::first;
        DeQuSH::first = nullptr;
        DeQuSH::last = nullptr;
        if (current == nullptr) {
            return;
        }
        while (current != nullptr) {
            SuperHero *tmp = current->next;
            delete current;
            current = tmp;
        }

    }

    void DeQuSH::print() {

        SuperHero *current = DeQuSH::first;
        if (current == nullptr) {
            std::cout << "EMPTY Q" << std::endl;
            return;
        }
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
        std::ofstream fstr;
        fstr.open(path);
        SuperHero *current = DeQuSH::first;
        if (current == nullptr) {
            return 0;
        }
        while (current != nullptr) {
            fstr << current->getName() << " " << current->getReal_name() << " " << current->getBd() << " "
                 << current->getMale() << " " << current->getAbility() << " " << current->getWeaknesses() << " "
                 << current->getWin_amount() << " " << current->getStrength_rating();
            if (current->next != nullptr) {
                fstr << std::endl;
            }
            current = current->next;
        }
        fstr.close();
        return 0;
    }

    int DeQuSH::load(const char *path) {
        std::ifstream fstr;
        fstr.open(path);
        while (!fstr.eof()) {
            char *name = new char[32];
            char *real_name = new char[32];
            char *bd = new char[32];
            int male = 0;
            char *ability = new char[32];
            char *weaknesses = new char[128];
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
            SuperHero *sh = new SuperHero(name, real_name, bd, male, ability, weaknesses, win_amount, strength_rating);
            DeQuSH::PushBack(sh);
        }
        fstr.close();
        return 0;
    }

    void DeQuSH::insert(SuperHero *hero, int n) {
        SuperHero *tmp = DeQuSH::first;
        if (tmp == nullptr) {
            DeQuSH::first = hero;
            DeQuSH::last = hero;
        } else {
            while (n > 0 && tmp->next != nullptr) {
                tmp = tmp->next;
                n--;
            }
            if (n > 0) {
                tmp->next = hero;
                hero->previous = tmp;
            }
            if (n == 0) {
                tmp->previous->next = hero;
                hero->previous = tmp->previous;
                hero->next = tmp;
                tmp->previous = hero;
            }


        }
    }

    DeQuSH DeQuSH::search(char *name) {
        DeQuSH deQuSH;
        SuperHero *current = DeQuSH::first;
        if (current == nullptr) {
            return deQuSH;
        }
        while (current != nullptr) {
            int cmp = strcmp(name, current->getName());
            if (cmp == 0) {
                deQuSH.PushBack(copy(current));
            }
            current = current->next;
        }
        return deQuSH;
    }

    DeQuSH DeQuSH::filter(double strength_rating, char c) {
        DeQuSH deQuSH;
        SuperHero *current = DeQuSH::first;
        if (current == nullptr) {
            return deQuSH;
        } else {
            switch (c) {
                case '<': {
                    while (current != nullptr) {
                        if (current->getStrength_rating() < strength_rating) {
                            deQuSH.PushBack(copy(current));
                        }
                        current = current->next;
                    }
                    break;
                }
                case '=': {
                    while (current != nullptr) {
                        if (current->getStrength_rating() == strength_rating) {
                            deQuSH.PushBack(copy(current));
                        }
                        current = current->next;
                    }
                    break;
                }
                case '>': {
                    while (current != nullptr) {
                        if (current->getStrength_rating() > strength_rating) {
                            deQuSH.PushBack(copy(current));
                        }
                        current = current->next;
                    }
                    break;
                }
            }
        }
        return deQuSH;
    }

    SuperHero *DeQuSH::copy(SuperHero *sh) {
        return new SuperHero(sh->getName(), sh->getReal_name(), sh->getBd(), sh->getMale(), sh->getAbility(),
                             sh->getWeaknesses(), sh->getWin_amount(), sh->getStrength_rating());
    }

}