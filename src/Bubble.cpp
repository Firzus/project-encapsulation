#include "Bubble.h"

void Bubble::init()
{
	shapeColor1 = { 255, 0, 0, 255 };
	shapeColor2 = { 0, 255, 0, 255 };
	shapeColor3 = { 0, 0, 255, 255 };
	shapeColor4 = { 234, 239, 44, 255 };
	shapeColor5 = { 165, 55, 253, 255 };
	shapeColor6 = { 227, 61, 148, 255 };

	createBubble("circle1", 100, 100, shapeColor1, 45, -2, 1);
	createBubble("circle2", 300, 100, shapeColor2, 35, -1, 2);
	createBubble("circle3", 500, 500, shapeColor3, 70, 1, 2);
	createBubble("circle5", 300, 600, shapeColor4, 25, 3, 2);
	createBubble("circle4", 600, 300, shapeColor5, 50, 1, 2);
	createBubble("circle6", 600, 600, shapeColor6, 20, 1, 2);
}

void Bubble::update()
{
	// Physics and collisions
	for (auto it = circles.begin(); it != circles.end();)
	{
		Circle* circle = *it;

		for (auto other = circles.begin(); other != circles.end();)
		{
			Circle* otherCircle = *other;

			if (circle->isColliding(otherCircle))
			{
				circle->bounceOfEntity(otherCircle);
			}
			other++;
		}

		// Left and right screen collisions
		if (circle->getPosX() - circle->getRadius() <= 0)
		{
			circle->setPosition(circle->getRadius(), circle->getPosY());
			circle->setDirX(-circle->getDirX());
		}
		if(circle->getPosX() + circle->getRadius() >= window->getWindowWidth())
		{
			circle->setPosition(window->getWindowWidth() - circle->getRadius(), circle->getPosY());
			circle->setDirX(-circle->getDirX());
		}

		// Up and down screen collisions
		if (circle->getPosY() - circle->getRadius() <= 0)
		{
			circle->setPosition(circle->getPosX(), circle->getRadius());
			circle->setDirY(-circle->getDirY());
		}
		if (circle->getPosY() + circle->getRadius() >= window->getWindowHeight())
		{
			circle->setPosition(circle->getPosX(), window->getWindowHeight() - circle->getRadius());
			circle->setDirY(-circle->getDirY());
		}

		// Call the move function for every circle in the list
		for (Circle* circle : circles)
		{
			if (circle != nullptr)
			{
				circle->move();
			}
		}
		it++;
	}
}

void Bubble::createBubble(std::string label, int x, int y, const ColorRGBA& color, float radius, int speedX, int speedY)
{
	component->createCircle(label, x, y, color, radius);

	auto it = component->getEntities().find(label);
	if (it != component->getEntities().end()) {
		Circle* circle = dynamic_cast<Circle*>(it->second);
		if (circle) {
			circles.push_back(circle);
		}
	}

	component->getEntity<Circle>(label)->setDirX(speedX);
	component->getEntity<Circle>(label)->setDirY(speedY);
}
