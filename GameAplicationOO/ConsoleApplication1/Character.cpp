#include "Character.h"

// Constructor por defecto
Character::Character() {
    name = "Hero";
    hp = 100;
    damage = 10;
}

// Constructor con parámetros
Character::Character(string name, int hp, int damage) {
    this->name = name;
    this->hp = hp;
    this->damage = damage;
}

// Métodos Getters y Setters
string Character::getName() {
    return name;
}

void Character::setName(string name) {
    this->name = name;
}

int Character::getHp() {
    return hp;
}

void Character::setHp(int hp) {
    this->hp = hp;
}

int Character::getDamage() {
    return damage;
}

void Character::setDamage(int damage) {
    this->damage = damage;
}

// Método de ataque normal
void Character::attack(Character& c) {
    cout << name << " ataca a " << c.getName() << " causando " << damage << " de daño." << endl;
    c.setHp(c.getHp() - damage);
}

// Constructor de Boss
Boss::Boss(string name, int hp, int damage) : Character(name, hp, damage) {
    specialUsed = false;  // Inicialmente no ha usado el ataque especial
}

// Ataque especial que golpea dos veces
void Boss::specialAttack(Character& c) {
    if (!specialUsed) {
        cout << name << " usa su ATAQUE ESPECIAL contra " << c.getName() << " golpeando 2 veces!" << endl;
        c.setHp(c.getHp() - damage);
        c.setHp(c.getHp() - damage);
        specialUsed = true;  // Se marca como usado para que no pueda volver a usarse
    }
    else {
        cout << name << " ya usó su ataque especial y no puede volver a usarlo." << endl;
    }
}
