#include <iostream>
#include "SuperHero.h"
#include <cstring>

//search name
//filter strength_rating
int main() {
    char *name = new char[32];
    char *real_name = new char[32];
    char *bd = new char[32];
    int male = 0;
    char *ability = new char[32];
    char *weaknesses = new char[32];
    int win_amount = 0;
    double strength_rating = 0.0;
    std::cin >> name;
    std::cin >> real_name;
    std::cin >> bd;
    std::cin >> male;
    std::cin >> ability;
    std::cin >> weaknesses;
    std::cin >> win_amount;
    std::cin >> strength_rating;
    const char *path = "D:\\programming\\C_LAB\\LAB_1\\data.txt";
    DeQuSH dq;

    for (int i = 0; i < 10; i++) {
        char *name1 = new char[32];
        char *real_name1 = new char[32];
        char *bd1 = new char[32];
        int male1 = 0;
        char *ability1 = new char[32];
        char *weaknesses1 = new char[32];
        int win_amount1 = 0;
        double strength_rating1 = 0.0;

        strcpy(name1, strcat(name, std::to_string(i).c_str()));
        strcpy(real_name1, strcat(real_name, std::to_string(i).c_str()));
        strcpy(bd1, strcat(bd, std::to_string(i).c_str()));
        male1 = male;
        strcpy(ability1, strcat(ability, std::to_string(i).c_str()));
        strcpy(weaknesses1, strcat(weaknesses, std::to_string(i).c_str()));
        win_amount1 = win_amount;
        strength_rating1 = strength_rating;
        SuperHero superHero(name1, real_name1, bd1, male1, ability1, weaknesses1, win_amount1, strength_rating1);
        SuperHero *sh = &superHero;
        dq.print(sh);
    }


    return 0;
}
