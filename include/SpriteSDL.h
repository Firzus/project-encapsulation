#pragma once
#define SDL_MAIN_HANDLED

#include "Sprite.h"
#include <SDL2/SDL.h>

class SpriteSDL : public Sprite
{
private:
	SDL_Renderer* renderer = NULL;
	SDL_Surface* image = NULL;
	SDL_Texture* texture = NULL;
	SDL_Rect dstrect = { 0,0,0,0 };
	SDL_Point pivot;

	float rotation = 0;

public:
	SpriteSDL(std::string label, int x, int y, std::string texturePath, float rotation, float scale, SDL_Renderer* renderer);
	~SpriteSDL() override;

	void draw() const override;

	bool isColliding(Entity* other) override;

	// Getters - Setters
	//Texture2D getTexture() const { return texture; }
};

