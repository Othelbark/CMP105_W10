#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	view = window->getView();

	// initialise game objects
	player.setInput(input);
	player.setView(&view);
	player.setPosition(200, 300);
	player.setSize(sf::Vector2f(30, 42));
	player.setCollisionBox(0, 0, 30, 42);
	playerTexture.loadFromFile("gfx/MarioSheetT.png");
	player.setTexture(&playerTexture);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

	player.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	player.update(dt);
	worldMap.checkMapCollision(&player);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(player);
	worldMap.drawMap(window);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}