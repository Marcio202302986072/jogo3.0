#include "carro.hpp"

carro::carro() : GameObject({50, 250}) {
    image = LoadTexture("carro.png");
    lastFireTime = 0.0;
}

carro::~carro() {
    UnloadTexture(image);
}

void carro::Draw() {
    DrawTextureV(image, position, WHITE);
}

void carro::MovLeft() {
    if (position.x > 0) {
        position.x -= 3.5;
    }
}

void carro::MovRight() {
    if (position.x < GetScreenWidth() - 250) {
        position.x += 3.5;
    }
}

void carro::MovUp() {
    if (position.y > 0) {
        position.y -= 3.5;
    }
}

void carro::MovDown() {
    if (position.y < GetScreenHeight() - image.height) {
        position.y += 3.5;
    }
}

void carro::FireLaser() {
    if (GetTime() - lastFireTime >= 0.35) {
        lasers.push_back(Laser({position.x + image.width / 2 - 2, position.y + image.height / 2 + 10}, -6));
        lastFireTime = GetTime();
    }
}

Rectangle carro::getRect() {
    return {position.x, position.y, float(image.width), float(image.height)};
}

void carro::Reset() {
    position.x = 50;
    position.y = 250;
    lasers.clear();
}
