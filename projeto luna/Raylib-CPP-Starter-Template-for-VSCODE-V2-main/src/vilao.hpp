#pragma once
#include <raylib.h>

class Vilao {
    public:
        Vilao(int type, Vector2 position);
        void Update(int direction);
        void Draw();
        int GetType();
        static void UnloadImages();
        Rectangle getRect();
        static Texture2D vilaoImages[2];
        int type;
        Vector2 position;
        int health = 100;
    private:

};