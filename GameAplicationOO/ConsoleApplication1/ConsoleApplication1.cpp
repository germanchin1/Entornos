#include "Character.h"
#include <iostream>

using namespace std;

int main() {
    Character hero("FRODO", 200, 30);    
    Character enemy("ORCO", 100, 10);    
    Boss boss("SAURON", 180, 25);     

    cout << "¡FRODO se enfrenta a su primer enemigo: " << enemy.getName() << "!" << endl;

    // Primera pelea contra el Character normal
    while (hero.getHp() > 0 && enemy.getHp() > 0) {
        hero.attack(enemy);
        if (enemy.getHp() <= 0) {
            cout << enemy.getName() << " ha sido derrotado." << endl;
            break;
        }

        enemy.attack(hero);
        if (hero.getHp() <= 0) {
            cout << hero.getName() << " ha sido derrotado. GAME OVER." << endl;
            return 0;
        }

        cout << hero.getName() << " HP: " << hero.getHp() << endl;
        cout << enemy.getName() << " HP: " << enemy.getHp() << endl;
    }

    cout << "¡Frodo ha vencido! Se recupera antes del siguiente combate." << endl;
    hero.setHp(150);  

    cout << "\n¡Ahora FRODO se enfrenta al BOSS: " << boss.getName() << "!" << endl;

    // Segunda pelea contra el Boss
    while (hero.getHp() > 0 && boss.getHp() > 0) {
        hero.attack(boss);
        if (boss.getHp() <= 0) {
            cout << boss.getName() << " ha sido derrotado. ¡FRODO GANA LA BATALLA!" << endl;
            break;
        }

        if (boss.getHp() < 100) {  // Si el Boss tiene menos de 100 HP, usa su ataque especial
            boss.specialAttack(hero);
        }
        else {
            boss.attack(hero);
        }

        if (hero.getHp() <= 0) {
            cout << hero.getName() << " ha sido derrotado. GAME OVER." << endl;
            return 0;
        }

        cout << hero.getName() << " HP: " << hero.getHp() << endl;
        cout << boss.getName() << " HP: " << boss.getHp() << endl;
    }

    cout << "¡Fin de la batalla! FRODO ha vencido a todos sus enemigos." << endl;
    return 0;
}
