#include <SFML/Graphics.hpp>
#include <iostream>
#include <forward_list>

#include "Scene.h"

// #pragma once

#ifndef SYSCLS
#define SYSCLS

// Would like to remove #include of Ship.h, just here to test the ship drawing
#include "Ship.h"

class SystemClass {
public:
	SystemClass();

	// Function to request a scene change (takes name/ID of new scene)

	// Active Scene Stack functions
	void pushScene(Scene * toPush);
	bool popScene();

	// Potential functions to access stored data

private:
	// Starts the window and runs the game loop
	void runWindow();

	// Basic actions to be taken each loop, including calling update
	// and draw functions for the active scene, and checking some key events
	void update(sf::Time dt);

	//Data module
	//Scenes (probably stored in hash table)
	std::forward_list<Scene *> sceneStack;
	std::forward_list<Scene *>::iterator currentScene;

	//Window stuff
	sf::VideoMode desktop;
	sf::RenderWindow window;
	sf::View view; //not sure if this should be here or in each scene
	sf::Clock clock;
	// Ship ship;
};
#endif