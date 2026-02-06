#ifndef MENU_H
#define MENU_H
#include<string>
#include<vector>
struct menuReferenceList{
    std::string thisMenuName;
    std::string thisMenuContent;
};

class menu{
    public:

    static std::string menuPosition;
    static std::vector<menuReferenceList> menuList;

    void showCurrentMenu();
    int searchThisMenuNameIndex();
    void readMenuList();

    menu();

    void handleMenuInput(bool &isContinueGame);

    void handleStartMenuInput(std::string operation,bool  &isContinueGame);
    void handleChooseGameModeMenuInput(std::string operation);
    void handleChooseGameLevelMenuInput(std::string operation);


    
        
    
};

#endif