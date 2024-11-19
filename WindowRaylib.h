#pragma once

#include <iostream>
#include "raylib.h"
#include "Window.h"
#include "CircleRaylib.h"

class WindowRaylib : public Window {
public:
    void init() override;
    void createWindow(int width, int height, const std::string& title) override;
    void clear(const ColorRGBA& color) override;
    void beginDrawing() override;
    void endDrawing() override;
    bool isOpen() const override;
	void close() override;

	// Entities
    void createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius) override;
    void removeCircle(const std::string& label) override;
	void createSprite(int x, int y, const std::string& filePath) override;
	
	// Utils
    void setFrameRate(int frameRate) override;
};