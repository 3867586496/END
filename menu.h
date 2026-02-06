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

    void handleMenuInput();

    void handleStartMenuInput(std::string operation);

    
    


    
        
    
};

#endif