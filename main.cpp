#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//Heros and Opponents uses the same class
class Hero{
private:
    string name;

public:
    Hero(){
    }

    void setName(string name){ // set the name of the character you're playing
        this->name = name;
    }

    string getName(){ // get the name of the character you're playing
        return name;
    }
};


// Define the Pokemon class
class Pokemon {
private:
    string name;
    int hp;
    int str;
    int att;
    string type;
    int skilldamage;
    int ultdamage;
    string display;
    int energy;
    int skillpoints;

public:
    // Construction used to set variables
    Pokemon(string name = "", string type = "", int hp = 100, int str = 50, int att = 20, int skilldamage = 30, int ultdamage = 60, string display = "", int energy = 0, int skillpoints = 3) {
        this->name = name;
        this->type = type;
        this->hp = hp;
        this->str = str;
        this->att = att;
        this->skilldamage = skilldamage;
        this->ultdamage = ultdamage;
        this->display = display;
        this->energy = energy;
        this->skillpoints = skillpoints;
    }

    // Attack that is used
    int attack(int choice) {
        if (choice == 1) {
            cout << name << " attacks for " << att << " hp\n"; //attacks based off your att
            energy += 10;
            if (skillpoints < 3) {
                skillpoints += 1;
            }
            return att;
        }
        else if (choice == 3){
            if(energy >= 60){ //check if you have enough energy
                cout << name << " attacks for " << ultdamage << " hp\n";
                energy = 0;
                return ultdamage;
            }
                else {
                cout << "Not enough energy for ultimate attack!\n";
                return 0;
            }
        }
        else{
            cout << "Invalid choice" <<endl;
        }
    }

    //Takes away hp based on damage
    void defend(int damage) {
        cout << name << " defends " << damage << " points of damage.\n";
        hp -= damage;
    }

    // Getters of the Pokemon class
    int getHP() {
        return hp;
    }

    string getName() {
        return name;
    }

    string getDisplay() {
        return display;
    }

    int getSkillDamage() {
        return skilldamage;
    }

    int getSkillPoints() {
        return skillpoints;
    }

    int getEnergy() {
        return energy;
    }

    string getType() {
        return type;
    }

    // Setters of the Pokemon class
    void setName(string name) {
        this->name = name;
    }

    void setDisplay(string display) {
        this->display = display;
    }

    void showDisplay() {
        cout << display << " (Name: " <<name << ")";
    }

    void setSkillPoints(int skillpoints) {
        this->skillpoints = skillpoints;
    }

    void setEnergy(int energy) {
        this->energy = energy;
    }

    void printStat() {
        cout << name << endl;
        cout << "HP: " << hp << endl;
        cout << "Str: " << str << endl;
        cout << "Att: " << att << endl;
        cout << "Energy: " << energy << " out of " << "60" << endl;
        cout << "SkillPoints: " << skillpoints << endl;
        cout << endl;
    }

    // Stats that will be printed during battle
    void printBattleStats() {
        cout << "HP: " << hp << endl;
        cout << "Energy: " << energy << "out of " << "60" << endl;
        cout << "SkillPoints: " << skillpoints << endl;
        cout << endl;
    }
};

// Happy Type inherited from Pokemon class
class HappyType : public Pokemon {
private:
    string type = "happy";
    string displayOptions[3] = {":D", ";)", "C:"};
    string nameList[5] = {"Bella", "Luna", "Leo", "Lily", "Molly"};
public:
    //Constructor used for the stats of a Happy Type Emoticon
    HappyType(string name = "Happy", string type = "happy", int hp = 100, int str = 50, int att = 20, int skilldamage = 30, int ultdamage = 60, int energy = 0, int skillpoints = 3)
        : Pokemon(name, type, hp, str, att, skilldamage, ultdamage, "", energy, skillpoints){
        randomize();
    }

    //used to randomize between 3 different happy type displays
    //randomizes between 5 different names
     void randomize() {
        int nameIndex = rand() % 5;
        int displayIndex = rand() % 3;
        setDisplay(displayOptions[displayIndex]);
        setName(nameList[nameIndex]);
    }
};

// Angry Type inherited from Pokemon class
class AngryType : public Pokemon {
private:
    string type = "angry";
    string displayOptions[3] = {">:c", ">:o", ">:T"};
    string nameList[5] = {"Maxxamus", "Gizmo", "Simba", "Toby", "Jackson"};
public:
    AngryType(string name = "Angry", string type = "angry", int hp = 90, int str = 80, int att = 25, int skilldamage = 30, int ultdamage = 60, int energy = 0, int skillpoints = 3)
        : Pokemon(name, type, hp, str, att, skilldamage, ultdamage, "", energy, skillpoints) {
        randomize();
    }

    //used to randomize between 3 different angry type displays
     void randomize(){
        int nameIndex = rand() % 5;
        int displayIndex = rand() % 3;
        setDisplay(displayOptions[displayIndex]);
        setName(nameList[nameIndex]);
    }
};

// Sad Type inherited from Pokemon class
class SadType : public Pokemon {
private:
    string type = "sad";
    string displayOptions[3] = {"D:", ":c", ";n;"};
    string nameList[5] = {"Luna", "Oreo", "Milly", "Ruby", "Sadie"};
public:
    SadType(string name = "Sad", string type = "sad", int hp = 130, int str = 45, int att = 5, int skilldamage = 30, int ultdamage = 60, int energy = 0, int skillpoints = 3)
        : Pokemon(name, type, hp, str, att, skilldamage, ultdamage, "", energy, skillpoints) {
        randomize();
    }

    //used to randomize between 3 different sad type displays
     void randomize() {
        int nameIndex = rand() % 5;
        int displayIndex = rand() % 3;
        setDisplay(displayOptions[displayIndex]);
        setName(nameList[nameIndex]);
    }
};

// Meh Type inherited from Pokemon class
class MehType : public Pokemon {
private:
    string type = "meh";
    string displayOptions[3] = {":u", ":p", ":l"};
    string nameList[5] = {"Duke", "Ivy", "Shadow", "Soap", "Bubbles"};
public:
    MehType(string name = "Meh", string type = "meh", int hp = 100, int str = 50, int att = 15, int skilldamage = 30, int ultdamage = 60, int energy = 0, int skillpoints = 3)
        : Pokemon(name, type, hp, str, att, skilldamage, ultdamage, "", energy, skillpoints) {
        randomize();
    }

    //used to randpmize between 3 different mehtype displays
    void randomize() {
        int nameIndex = rand() % 5;
        int displayIndex = rand() % 3;
        setDisplay(displayOptions[displayIndex]);
        setName(nameList[nameIndex]);
    }
};

//basing skill damage on elemental type
//ex. happy type is effective against angry, while being weak against a sad type
int skilldamage(Pokemon main, Pokemon foe) {
    if (main.getType() == "happy") {
        if (foe.getType() == "angry") {
            cout << "IT'S SUPER EFFECTIVE" << endl;
            return main.getSkillDamage() + 10; //increase skill damage by 10
        }
        else if (foe.getType() == "sad") {
            cout << "It's not very effective..." << endl;
            return main.getSkillDamage() - 10; //decrease skill damage by 10
        }
    }
    else if (main.getType() == "angry") {
        if (foe.getType() == "sad") {
            cout << "IT'S SUPER EFFECTIVE" << endl;
            return main.getSkillDamage() + 10;
        }
        else if (foe.getType() == "happy") {
            cout << "It's not very effective..." << endl;
            return main.getSkillDamage() - 10;
        }
    }
    else if (main.getType() == "sad") {
        if (foe.getType() == "happy") {
            cout << "IT'S SUPER EFFECTIVE" << endl;
            return main.getSkillDamage() + 10;
        }
        else if (foe.getType() == "angry") {
            cout << "It's not very effective..." << endl;
            return main.getSkillDamage() - 10;
        }
    }
    return main.getSkillDamage(); //return normal skill damage for Meh Skill Types
}



// Function that is ultized for battle
void battle(Pokemon main, Pokemon foe){
    int damage;
    int foedamage;
    do {
        cout << main.getName() << "'s Turn:" << endl;
        if (main.getHP() <= 0){ //check if Emoticon is able to battle
            cout << main.getName() << " cannot battle!" << endl;
        return; //returns back to main
        }
        int choice;
        //print out choices
        cout << "Choose attack:" <<endl;
        cout << "1. Normal" <<endl;
        cout << "2. Skill" <<endl;
        cout << "3. Ultimate" <<endl;
        cout << "4. Switch Pokemon: " <<endl;
        cout << "5. Show Stats: " <<endl;
        cin >> choice;
        if(choice == 5){
            main.printStat(); //print full stats
            foe.printStat();
        }
        if(choice == 4){
            cout << "Switching Pokemon..." << endl;
            return; // Exits the function and goes into main
        }
        if(choice == 2){
            damage = skilldamage(main, foe);
            cout << main.getName() << " attacks for " << damage << " hp" << endl;
            foe.defend(damage);
            main.setSkillPoints(main.getSkillPoints() + 1); //increases skill points by 1
            main.setEnergy(main.getEnergy() + 20); //increases energy by 20
        }
        else{
            damage = main.attack(choice);
            foe.defend(damage);
        }
        if(foe.getHP() <= 0){
            cout << foe.getName() << " has fainted!" <<endl; //Indicates that Emoticon has no more HP
            break;
        }

        cout << "Press enter to continue" <<endl;
        cin.ignore();
        cin.get();
        cout << foe.getName() << "'s Turn:" << endl;
        foedamage = foe.attack(rand() % 3 + 1); //chose a random attack

        if(foedamage == 2){
            damage = skilldamage(foe, main);
            cout << foe.getName() << " attacks for " << damage << " hp" << endl;
            main.defend(damage);
            foe.setSkillPoints(foe.getSkillPoints() + 1);
            foe.setEnergy(foe.getEnergy() + 20);
        }
        else{
            damage = main.attack(foedamage);
            main.defend(damage);
        }
        if(main.getHP() <= 0){
            cout << main.getName() << " has fainted!\n";
            break;
        }
        main.printBattleStats(); //print stats
        foe.printBattleStats();
    }while(main.getHP() > 0 && foe.getHP() > 0);
}

int main(){
    srand(time(0));
    string name;
    Pokemon team[5]; // Player's team of 5 Emoticons
    Pokemon gym[5];  // Opponent's team of 5 Emoticons

    cout << "Write your name: " <<endl;
    cin >> name;
    cout <<endl;

    Hero myHero;
    myHero.setName(name); //set Hero's name

    Hero myOpponent;
    myOpponent.setName("Dr.Mammor");

   cout << "Welcome trainer " << name << " to the world of Emoticons!!!" << endl;
    cout << "In this world, there are 4 types of Emoticons: Happy, Sad, Angry, and Meh" << endl;
    cout << "To learn more about the battle system -> Press 1: " << endl;
    cout << "To continue -> Press 2: " << endl;
    int learn;
    cin >> learn;
    if(learn == 1){
        cout << "Happy Types are strong against Angry Types & weak against Sad Types" << endl;
        cout << "Sad Types are strong against Happy Types & weak against Angry Types" << endl;
        cout << "Angry Types are strong against Sad Types & weak against Happy Types" << endl;
        cout << "Meh Types are neutral against all types" << endl;
        cout << "Press enter to continue" << endl;
        cin.ignore();
        cin.get();
    }

    cout <<endl;

    cout << "Randomizing your team..." << endl;
    cout << "Press enter to continue" <<endl;
    cin.ignore(); //ignores input
    cin.get(); //goes to next part in main

    for (int i = 0; i < 5; i++) {
        int typeChoice = rand() % 4; //Randomizing between 4 different types
        switch (typeChoice) { //different cases for type chosen
            case 0:
                team[i] = HappyType(); //creates random happy type
                break;
            case 1:
                team[i] = AngryType();
                break;
            case 2:
                team[i] = SadType();
                break;
            case 3:
                team[i] = MehType();
                break;
        }
        //print out your team
        cout << "Your Emoticon " << i + 1 << ": ";
        team[i].showDisplay();
        cout << endl;
    }

    cout << "Press enter to continue" <<endl;
    cin.ignore();
    cin.get();

    cout << "Randomizing opponent's team..." << endl;
    cout << "Press enter to continue" <<endl;
    cin.get();

    //Randomizes Opponent Team
    for (int i = 0; i < 5; i++) {
        int typeChoice = rand() % 4;
        switch (typeChoice) {
            case 0:
                gym[i] = HappyType();
                break;
            case 1:
                gym[i] = AngryType();
                break;
            case 2:
                gym[i] = SadType();
                break;
            case 3:
                gym[i] = MehType();
                break;
        }
        cout << "Opponent's Emoticon " << i + 1 << ": ";
        gym[i].showDisplay();
        cout << endl;
    }


    cout << "Dr.Mammor challenged you to a battle!" <<endl;
    cout << "Press enter to continue" <<endl;
    cin.get();
    //set Index to 0 to default
    int playerPokemonIndex = 0;
    int opponentPokemonIndex = 0;
    //game ends when all Emoticons die
    while (playerPokemonIndex < 5 && opponentPokemonIndex < 5) {
        cout << "Gym Battle between " << name << " and " << "Dr.Mammor" << " begins!" << endl;
        cout << "Battle between " << team[playerPokemonIndex].getName() << " VS " << gym[opponentPokemonIndex].getName() << " begins!" << endl;
        battle(team[playerPokemonIndex], gym[opponentPokemonIndex]);
        battle(team[playerPokemonIndex], gym[opponentPokemonIndex]);
        playerPokemonIndex++; //increase index for next battle
        opponentPokemonIndex++;
        // Check if any team has run out of Pokemon
        if(playerPokemonIndex >= 5){
            cout << "You have run out of Emoticons! Dr.Mammor wins!" << endl; //Prints Winner
            break;
        }
        else if(opponentPokemonIndex >= 5){
            cout << "Opponent has run out of Emoticons! " << name << "wins!" << endl;
            break;
        }
        int switchchoice;
        cout << "Are you sure you want to switch Emoticons? (0 = Yes, 1 = No): "; //Confirm Decision
        cin >> switchchoice;
        if(switchchoice == 0){
            cout << "Available Emoticons to switch to:" << endl;
            for(int i = playerPokemonIndex; i < 5; i++){
                cout << i - playerPokemonIndex + 1 << ". " << team[i].getName() << endl; //print out Pokemon that are able to be switched to
            }
            //Shows Emoticons that can be switched to
            cout << "Choose a Emoticon to switch to (1-5): ";
            int switchPokemonIndex;
            cin >> switchPokemonIndex;
            if(switchPokemonIndex >= 1 && switchPokemonIndex <= 5){
                // Switches Indexes
                playerPokemonIndex += switchPokemonIndex;
                cout << name << " switched to " << team[playerPokemonIndex].getName() << "!" << endl;
            }
            else{
                cout << "Choice not Available" << endl;
            }
        }
    }

    return 0;
}


