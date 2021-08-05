// Prototype Menu
// This is a simple demonstration of the menu system in its most basic form
// using two variations: a start menu and a pause menu.

#include "SystemClass.h"
#include "Scene.h"
#include "GameObject.h"
#include <string>
#include <vector>



/*
class MenuBox : public GameObject {
    public:
        MenuBox(); 

        void update(sf::Time dt);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::Texture texture;

};
*/



class Option {
    public:
        // Constructor building the option
        Option();
    
        // Actions taken when the option is selected (to be overloaded by dev)
        virtual bool onSelection() = 0;

    private:
        // Position of the Lable reletive to the window
        sf::Vector2f lablePos;  
        // Position of the Curser when the option is selected reletive to
        // to the window box                     
        sf::Vector2f curPos;
        // Text representation of the option
        sf::Text lable;
        // Add any other representations of the object
};



class Menu : public Scene {
    public:
        Menu();

        void update(sf::Time dt);
        void draw(sf::RenderWindow& window);

    private:
        // Menu box drawn behind the options 
        // I'm thinking of just integrating this into the menu
        // MenuBox mb;

        // Menu box drawn behind the options
	    sf::RectangleShape menuBox;
        // List of options availible in the menu
        std::vector<std::string> options;
        // Position of the curser in the menu relitive to the window
        sf::Vector2f curPos;

};



// Add class Start Menu
// Add class Pause Menu



// Start option for the start menu
class OptStart : public Option {
    public:
        OptStart();

        // Pops the menu and pushes the main scene
        bool onSelection();
};



// Quit option for the start and pause menus
class OptQuit : public Option {
    public:
        OptQuit();

        // Pops all scenes from the stack and quits the menu
        bool onSelection();
};



// Continue option for the pause menu
class OptCont : public Option {
    public:
        OptCont();

        // Pops the menu, pushes the main scene and unpauses the game
        bool onSelection();
};