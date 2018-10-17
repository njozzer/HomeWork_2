#include "SuperHero.h"

#ifndef DQ_H
#define DQ_H
using namespace Heroes;

namespace DeQueue {

    class DeQuSH {
    public:
        DeQuSH();

        SuperHero *first;
        SuperHero *last;

        static DeQuSH create_empty();

        void PushBack(SuperHero *target);

        void PushFront(SuperHero *target);

        SuperHero *PopBack();

        SuperHero *PopFront();

        int IsEmpty();

        void clear();

        void print();

        void print(SuperHero *hero);

        int save(const char *path);

        int load(const char *path);

        void insert(SuperHero *hero, int n);

        DeQuSH search(char name[32]);

        DeQuSH filter(double strength_rating, char c);

        SuperHero *copy(SuperHero *sh);

        DeQuSH &operator+(SuperHero &sh);

        DeQuSH &operator-(char name[32]);
    };
}


#endif