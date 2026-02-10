#ifndef GAMEMAINLOOP_H
#define GAMEMAINLOOP_H
#include<string>
#include<vector>
/*
关于时间处理逻辑
改变的时间统一使用分钟来计算
*/
struct gameTime{
    int day;
    int hour;
    int minute;
};

struct consumables{
    std::string name;
    
    

    int level=1;
    int satiety=0;
    int thirst=0;
    int health=0;

    int spaceTaken=0;
};
//增加波动
struct weapon{
    std::string name;
    
    int level;
    
    int damage;
    int useStamina;
    bool isRanged;
    int spaceTaken;
};

struct armor{
    std::string name;

    int level;
    
    
    int armorValue;

    int spaceTaken;
};

struct material{
    std::string name;

    int spaceTaken;

    int level;
};
//type指的是前面定义的几类
struct item{
    std::string type;
    consumables comsumables;
    weapon weapon;
    armor armor;
    material material; 
};

struct itemDetail{
    item item;

    int quantity;
};
/*
对于生命值，
设定是200为标准

*/
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
    public:

};
/*
背包是要以200一级space计数

*/
class bag{
    
};

struct chest{
    int level;
    std::string chestName;
    std::vector<itemDetail> itemDetail;
};

struct room{
    std::vector<chest> chestList;
    std::vector<enemy> enemyList;
    std::string roomName;
    int floor;
};

struct building{
    std::vector<room> roomList;
    std::string buildingName;
    int floor;
};

struct area{
    int areaId;
    std::vector<building> buildingList;
    std::string areaName;
};

void calculateGameDevelopmentFactor(gameTime currentTime);

void setShowMode();
void clearConsole();

std::string getInputChoose();

void initialize();
void hourUpdate();
void dailyUpdate();

gameTime timeUpdate(gameTime currentTime,int changedMinute);

void readConsumables(std::vector<consumables> &consumablesList);
void readWeapon(std::vector<weapon> &weaponList);
void readArmor(std::vector<armor> &armorList);
void readMaterial(std::vector<material> &materialList);

#endif