#pragma once
#include <raylib.h>

class Power{
    public:
        Power();
        ~Power();
        void Update();
        void Draw();
        void Spam();
        Rectangle getRect();
        bool alive;
    private:
        Vector2 position;
        Texture2D image;
        int speed;
};