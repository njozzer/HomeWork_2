#include <ostream>

#ifndef SH_H
#define SH_H

namespace Heroes {
    class DeQuSH;

    class SuperHero {
    public:

        char *getName() const;

        void setName(char *name);

        char *getReal_name() const;

        void setReal_name(char *real_name);

        char *getBd() const;

        void setBd(char *bd);

        int getMale() const;

        void setMale(int male);

        char *getAbility() const;

        void setAbility(char *ability);

        char *getWeaknesses() const;

        void setWeaknesses(char *weaknesses);

        int getWin_amount() const;

        void setWin_amount(int win_amount);

        double getStrength_rating() const;

        void setStrength_rating(double strength_rating);


        SuperHero *next;
        SuperHero *previous;
        SuperHero();
        SuperHero(char name[32], char real_name[32], char bd[32], int male, char ability[32], char weaknesses[128],
                  int win_amount, double strength_rating);

        ~SuperHero();

        SuperHero(SuperHero *h);

        SuperHero &operator=(SuperHero &v);

        //SuperHero &operator+(DeQuSH &dq);

        //SuperHero &operator-(DeQuSH &dq);
        bool operator<(double str);

        bool operator==(double str);

        bool operator>(double str);

        friend SuperHero &operator+(SuperHero &sh, DeQuSH &dq);

        friend SuperHero &operator-(SuperHero &sh, DeQuSH &dq);

        friend std::ostream &operator<<(std::ostream &os, SuperHero *sh);
        friend std::istream &operator>>(std::istream &is, SuperHero *sh);

    private:
        char *name;
        char *real_name;
        char *bd;
        int male;
        char *ability;
        char *weaknesses;
        int win_amount;
        double strength_rating;


    };

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

        //DeQuSH &operator+(SuperHero &sh);

        //DeQuSH &operator-(SuperHero &sh);
        SuperHero *operator[](int i);

        friend DeQuSH &operator+(DeQuSH &dq, SuperHero &sh);

        friend DeQuSH &operator-(DeQuSH &dq, SuperHero &sh);
    };
}
#endif