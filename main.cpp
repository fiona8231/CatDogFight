#include <iostream>
#include <cmath>

using namespace std;

// ---------- PROBLEM WARRIORS BATTLE TILL DEATH ----------
// Make this
/*
Cat attacks Dog and deals 6 damage
Dog is down to health: 82
Dog attacks Cat and deals 15 damage
Cat is down to health: 85
Cat attacks Dog and deals 0 damage
Dog is down to health: 82
Dog attacks Cat and deals 11 damage
Cat is down to health: 74
Cat attacks Dog and deals 0 damage
Dog is down to health: 82
Dog attacks Cat and deals 5 damage
Cat is down to health: 69
Cat attacks Dog and deals 27 damage
Dog is down to health: 55
Dog attacks Cat and deals 0 damage
Cat is down to health: 69
Cat attacks Dog and deals 11 damage
Dog is down to health: 44
Dog attacks Cat and deals 7 damage
Cat is down to health: 62
Cat attacks Dog and deals 7 damage
Dog is down to health: 37
Dog attacks Cat and deals 11 damage
Cat is down to health: 51
Cat attacks Dog and deals 25 damage
Dog is down to health: 12
Dog attacks Cat and deals 16 damage
Cat is down to health: 35
Cat attacks Dog and deals 16 damage
Dog is down to health: -4
Dog is dead
Game Over!

*/

class Warrior{
private:
    int attackMax;
    int blockMax;
public:
    string name;
    int health;
    Warrior(string n, int h, int attack, int block){
        this->name = n;
        this->health = h;
        this->attackMax =  attack ;
        this->blockMax = block;
    }

    // The attack and block method amount will be random
    //Method Attack()
    int Attack(){
        return rand() % this->attackMax;
    }
    //Method block()
    int Block(){
        return rand() % this->blockMax;

    }

};


class Battle{

    // Battle::StartFight(cat, dog);
    //how to end this fight
public:
    static void StartFight(Warrior& cat, Warrior& dog){
        while (true){
            if(AttackResult(cat, dog).compare("Game Over!") == 0){
                cout << "Game Over!" << endl;
                break;
            } if(AttackResult(dog, cat).compare("Game Over!") == 0){
                cout << "Game Over!" << endl;
                break;
                }
        }

    }

    //Method
    static string AttackResult(Warrior& warriorA, Warrior& warriorB){
        // Get random attack & block amounts and calculate damage
        int AattackB = warriorA.Attack();
        int BblockA = warriorB.Block();
        int Damage2WarriorB = ceil(AattackB - BblockA);

        // Change health
        Damage2WarriorB = (Damage2WarriorB <=0) ? 0 : Damage2WarriorB;
        warriorB.health = warriorB.health - Damage2WarriorB;
        cout << warriorA.name.c_str() << " attacks " << warriorB.name.c_str() <<
             " and deals " << Damage2WarriorB << " damage " << endl;
        cout << warriorB.name.c_str() << " is down to health: " << warriorB.health << endl;

        // Once health < 0 end game by passing back Game Over
        if(warriorB.health <= 0){
            cout << warriorB.name.c_str() << " is dead " << endl;
            return "Game Over!";
        } else{
            return "Fight Again";
        }

    }

};


int main() {

srand(time(NULL));

//Create warrior
    //name, health, heal, block
    Warrior cat("Cat", 100, 35, 10);
    Warrior dog("Dog", 88, 25, 8);

    //Create battle
    //pass in object
    Battle::StartFight(cat, dog);

    return 0;
}