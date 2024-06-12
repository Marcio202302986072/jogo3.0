#pragma once
#include <raylib.h>

class Laser{
    public:
        Laser(Vector2 position,int speed);
        void Update();
        void Draw();
        Rectangle getRect();
        bool active;
    private:
        Texture2D image;
        Vector2 position;
        int speed;

};