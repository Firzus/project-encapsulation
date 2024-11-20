#pragma once

#include <string>

class Entity
{
protected:
	int posX, posY;
	int dirX, dirY;
	std::string label;
	int speed = 1;

public:
    virtual ~Entity() = default;

	virtual void draw() const = 0;

	virtual void setPosition(int x, int y);
	virtual void setDirection(int x, int y);
	virtual void move();

	// Physics
	virtual void bounceOfEntity(Entity* other) = 0;
	virtual bool isColliding(Entity* other) = 0;

	// Getters
	std::string getLabel() const { return label; }
	int getPosX() const { return posX; }
	int getPosY() const { return posY; }
	int getDirX() const { return dirX; }
	int getDirY() const { return dirY; }
};
