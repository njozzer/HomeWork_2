#include <ostream>

#ifndef SH_H
#define SH_H

namespace Heroes {
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

        SuperHero(char name[32], char real_name[32], char bd[32], int male, char ability[32], char weaknesses[128],
                  int win_amount, double strength_rating);

        ~SuperHero();

        SuperHero(SuperHero *h);

        SuperHero &operator=(SuperHero &v);

        SuperHero &operator+(DeQuSH &dq);

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
}
#endif