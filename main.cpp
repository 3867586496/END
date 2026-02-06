#include<iostream>
#include<string>
#include"save.h"
#include"menu.h"
#include"gamemainloop.h"

double gameLevelFactor=0;
double gameDevelopmentFactor=0;

bool isEndlessMode=false;
bool isStoryMode=false;

bool isMainGameRunning=false;

bool isContinueGame=true;


int main(){

    setShowMode();

    menu mainMenu;

    while(isContinueGame){
        mainMenu.showCurrentMenu();
        
        mainMenu.handleMenuInput(isContinueGame);
        if(isMainGameRunning){

        }


    }

    return 0;
}