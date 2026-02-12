
#include"save.h"
#include"menu.h"
#include"gamemainloop.h"

double gameLevelFactor=0;
double gameDevelopmentFactor=0;

bool isEndlessMode=false;
bool isStoryMode=false;

bool isMainGameRunning=false;

bool isContinueGame=true;

bool isInitialize=false;

std::vector<consumables> consumablesList;
std::vector<weapon> weaponList;
std::vector<armor> armorList;
std::vector<material> materialList;

int main(){

    setShowMode();

    menu mainMenu;
    character mainCharacter;
    while(isContinueGame){
        mainMenu.showCurrentMenu();
        
        mainMenu.handleMenuInput(isContinueGame);
        if(isMainGameRunning){
            if(!isInitialize){
                initialize();
            }
            
        }


    }

    return 0;
}