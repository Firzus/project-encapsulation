#pragma once

#include <string>
#include <iostream>

class Entity
{
protected:
	int posX = 0, posY = 0;
	std::string label;

public:
    virtual ~Entity() = default;

	virtual void draw() const = 0;

	virtual void setPosition(int x, int y);
	virtual void move(int x, int y);

	// Physics
	virtual bool isColliding(Entity* other) = 0;

	// Getters
	std::string getLabel() const { return label; }
	int getPosX() const { return posX; }
	int getPosY() const { return posY; }
};