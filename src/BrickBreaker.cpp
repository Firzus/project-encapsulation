#include "BrickBreaker.h"

void BrickBreaker::init()
{
	component->createQuadrilateral("player", 400, 580, ColorRGBA(2, 6, 23, 255), 150, 20, 0);
	component->createCircle("ball", 400, 300, ColorRGBA(203, 213, 225, 255), 15);
	player = component->getEntity<Quadrilateral>("player");
	ball = component->getEntity<Circle>("ball");
	ball->setDirX(3);
	ball->setDirY(-3);

	// Bricks
    for (int i = 0; i < numBricks; ++i) {
        int x = (i % 8) * 100;
        int y = (i / 8) * 40;

        component->createSprite("brick" + std::to_string(i + 1), x, y, "resources/textures/bricks/brick-" + std::to_string(i + 1) + ".png", 0, 1.0f);
		
		// Add the brick to the list
		bricks.push_back("brick" + std::to_string(i + 1));
	}
}

void BrickBreaker::update()
{
    // V�rification des collisions avec les murs
    if (ball->getPosX() - ball->getRadius() <= 0 || ball->getPosX() + ball->getRadius() >= window->getWindowWidth()) {
        ball->setDirX(-ball->getDirX()); // Rebond horizontal
    }
    if (ball->getPosY() - ball->getRadius() <= 0) {
        ball->setDirY(-ball->getDirY()); // Rebond en haut
    }

    // Collision avec la barre du joueur
    if (ball->isColliding(player)) {
        ball->setDirY(-ball->getDirY());
    }

    // Collision avec les briques
    for (auto it = bricks.begin(); it != bricks.end();) {
        auto brick = component->getEntity<Sprite>(*it);
        if (brick && ball->isColliding(brick)) {
            ball->setDirY(-ball->getDirY()); // Rebond vertical
            component->deleteEntity(*it);   // Supprimer la brique
            it = bricks.erase(it);          // Retirer la brique du tableau
        }
        else {
            ++it;
        }
    }

    // Perdre si la balle tombe en bas
    if (ball->getPosY() - ball->getRadius() > window->getWindowHeight()) {
        std::cout << "Game Over! Press R to restart.\n";
        //gameOver = true;
    }

    // D�placement de la balle
    ball->move();

    // D�placement de la barre du joueur (contr�le clavier)
    //if (IsKeyDown(KEY_RIGHT)) {
    //    player->move(5, 0); // D�placer � droite
    //}
    //if (IsKeyDown(KEY_LEFT)) {
    //    player->move(-5, 0); // D�placer � gauche
    //}
}
