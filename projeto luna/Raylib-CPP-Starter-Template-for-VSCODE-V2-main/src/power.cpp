#include "power.hpp"

Power::Power(){
    image = LoadTexture("html.png");
    alive = false;
}

Power::~Power(){
    UnloadTexture(image);
}

void Power::Spam(){
    position.x = 230;
    int side = GetRandomValue(0,1);

    if(side ==0){
        position.x = 0;
        speed = 3;
    } else{
        position.y = GetScreenHeight() - image.height;
        speed = -3;
    }
    alive = true;
}

Rectangle Power::getRect(){
    if(alive){
     return{position.x,position.y,float(image.width), float(image.height)};   
    }else{
        return{position.x, position.y, 0, 0};
    }
    
}

void Power::Update(){
    if(alive) {
        position.y += speed;
        if(position.y > GetScreenHeight() - image.height || position.y < 0){
            alive = false;
        }
    }
}

void Power::Draw(){
    if(alive){
        DrawTextureV(image, position, WHITE);
    }
}