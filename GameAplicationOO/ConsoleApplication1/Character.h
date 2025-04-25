#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
using namespace std;

class Character {
protected:
    string name;
    int hp;
    int damage;

public:
    // Constructores
    Character();
    Character(string name, int hp, int damage);

    // Getters y setters
    string getName();
    void setName(string name);

    int getHp();
    void setHp(int hp);

    int getDamage();
    void setDamage(int damage);

    // Método de ataque
    virtual void attack(Character& c);
};

class Boss : public Character {
private:
    bool specialUsed;  // Indica si ya usó el ataque especial

public:
    Boss(string name, int hp, int damage);

    // Ataque especial que golpea 2 veces
    void specialAttack(Character& c);
};

#endif // CHARACTER_H
