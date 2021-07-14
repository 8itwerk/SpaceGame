#include "SystemClass.h"

// Singular global instance of the System class
SystemClass System;


//Constructor
SystemClass::SystemClass() :
	desktop(sf::VideoMode::getDesktopMode()),
	window(desktop, "FarOut")
{
	window.setVerticalSyncEnabled(true);
	//window.setMouseCursorVisible(false); //debug
	view = window.getDefaultView(); //again, might move into scenes
	runWindow();
}



// Push to the sceneStack to be call during update and draw
void SystemClass::pushScene(Scene * toPush)
{
	sceneStack.push_front(toPush);

}



// Pop scenes from the sceneStack
// Return true for success, false for empty stack
bool SystemClass::popScene()
{
	sceneStack.pop_front();

  // TODO Check for empty list
	return true;
}



// Add a scene to the collection
bool SystemClass::addScene(int id, Scene * toadd)
{

	return false;
}



// Return a scene from the scene collection
Scene * SystemClass::getScene(int id)
{

	return NULL;
}



// Remove a scene from the scene collection 
bool SystemClass::removeScene(int id)
{

	return false;
}



// This function starts the window and runs the game loop
void SystemClass::runWindow() {
	sf::Time dt; //SFML time object for tracking time between updates
	sf::Time timer; //Currently not used

    // Remove this when done testing ship implementation
	Ship ship;
	PrototypeScene scene;
	
	while (window.isOpen()) { //This is the game loop

		//Event check
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Restart returns the amount of time on the clock (aka stopwatch) and
		//starts it from zero again. This is the amount of time since the last
		//time we came through this loop
		dt = clock.restart();

		window.clear();

		update(dt);
		// Remove the next 8 lines when done testing ship implementation
		// Draw the ship
		// This is just here for testing
		scene.update(dt);
		scene.draw(window);
		ship.move(dt);
		ship.update(dt);
		window.draw(ship);
		view.setCenter(ship.getPosition());
		window.setView(view);

		window.display();
	}
}



// Basic actions to be taken each loop, including calling update
// and draw functions for the active scene, and checking some key events
void SystemClass::update(sf::Time dt) {

	//Keyboard events     ---Most keyboard events will need to be passed into the active scene
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		window.close();
	}

	//Update active scenes (dt)
	for (currentScene = sceneStack.begin(); currentScene != sceneStack.end(); ++currentScene)
		(*currentScene)->update(dt);


	//Draw active scene
	for (currentScene = sceneStack.begin(); currentScene != sceneStack.end(); ++currentScene)
		(*currentScene)->draw(window);

}


