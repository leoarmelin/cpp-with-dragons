//
//  main.cpp
//  LearnCpp
//
//  Created by Leonardo Armelin on 08/12/22.
//

#include <iostream>
using namespace std;

class Entity {
    void takeDamage(int damage) {
        if (damage > defense) {
            life = life - (damage - defense);
        }
    };
    
    public:
        int life;
        int defense;
        int attack;
    
        void giveDamage(Entity &entity) {
            entity.takeDamage(attack);
        }
};

class Hero : public Entity {
    public:
    string name;
    Hero(string mName) {
        name = mName;
        attack = 10;
        defense = 7;
        life = 80;
    }
};

class Skeleton : public Entity {
    public:
    Skeleton() {
        attack = 6;
        defense = 3;
        life = 20;
    }
};

class Dragon : public Entity {
    public:
    Dragon() {
        attack = 12;
        defense = 7;
        life = 50;
    }
};

int main(int argc, const char * argv[]) {
    // Declaring entities
    Hero player = Hero("Leo");
    Skeleton enemySkeleton = Skeleton();
    Dragon enemyDragon = Dragon();
    
    // Running methods
    cout << "The hero finds a skeleton and attacks it." << endl;
    cout << "Skeleton life was " << enemySkeleton.life << ". ";
    player.giveDamage(enemySkeleton);
    cout << "Skeleton life is now " << enemySkeleton.life << endl;
    
    cout << "The hero finds a dragon and the dragon spits fire." << endl;
    cout << "The hero life was " << player.life << ". ";
    enemyDragon.giveDamage(player);
    cout << "The hero life is now " << player.life << endl;
    return 0;
}
