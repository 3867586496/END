#ifndef GAMEMAINLOOP_H
#define GAMEMAINLOOP_H
#include<string>
#include<vector>
void setShowMode();
void clearConsole();

std::string getInputChoose();

void initialize();
void hourUpdate();
void daylyUpdate();

struct consumables{
    std::string name;
    int itemId;
    int quantity;
    int level;
    int satiety;
    int thirst;
    int health;
    int spaceTaken;
};

struct weapon{
    std::string name;
    int itemId;
    int quantity;
    int damage;
    int useStamina;
    bool isRanged;
};

struct armor{
    std::string name;
    int itemId;
    int quantity;
    int armorValue;
};

class enemy{
    public:
    std::string enemyName;
    int totalHealth;
    int currentHealth;
    int totalStamina;
    int currentStamina;
    int distance;
    int basicDamage;
    int basicArmorValue;
    weapon ownWeapon;
    armor ownArmor;
};
class character{

};
class bag{
    
};

class area{
    int areaId;
};
/*
关于时间处理逻辑
改变的时间统一使用分钟来计算
*/
struct time{
    int day;
    int hour;
    int minute;
};

#endif