#pragma once
#include "Framework/TileMap.h"

class WorldMap
{
public:
	WorldMap();
	~WorldMap();

	void drawMap(sf::RenderWindow* window);

protected:
	TileMap tileMap;
};

