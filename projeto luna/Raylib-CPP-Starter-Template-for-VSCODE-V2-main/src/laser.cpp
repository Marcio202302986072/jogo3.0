#include "laser.hpp"

Laser::Laser(Vector2 position, int speed){
    image = LoadTexture("C++.png");
    this -> position = position;
    this -> speed = speed;
    active = true;
}

void Laser::Draw(){
    if(active)
        DrawTextureV(image,position,WHITE);
}

Rectangle Laser::getRect(){
    Rectangle rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.width = 4;
    rect.height = 15;
    return rect;

}

void Laser::Update(){
    position.x -= speed;
    if(active) {
        if(position.x > GetScreenWidth() || position.x < 0){
            active = false;
        }
    }

}