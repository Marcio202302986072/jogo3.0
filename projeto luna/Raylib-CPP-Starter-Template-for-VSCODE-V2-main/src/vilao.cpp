#include "vilao.hpp"
Texture2D Vilao::vilaoImages[2] = {}; 
Vilao::Vilao(int type, Vector2 position){
    this -> type = type;
    this -> position = position;
    if(vilaoImages[type -1].id == 0){

    switch (type) {
        case 1:
            vilaoImages[0] = LoadTexture("mang.png");
            break;
        case 2:
            vilaoImages[1] = LoadTexture("react.png");
            break;
        default:
            vilaoImages[0] = LoadTexture("mang.png");
            break;

    }
    }

 }

 void Vilao::Draw(){
    DrawTextureV(vilaoImages[type -1], position, WHITE);
 }

 int Vilao::GetType(){
    return type;
 }

 void Vilao::UnloadImages(){
    for(int i =0; i < 4; i++){
        UnloadTexture(vilaoImages[i]);
    }
 }

 void Vilao::Update(int direction){
    position.y += direction;
 }
 Rectangle Vilao::getRect(){
    return {position.x, position.y,
    float(vilaoImages[type - 1].width),
    float(vilaoImages[type - 1].height)
    };
 }