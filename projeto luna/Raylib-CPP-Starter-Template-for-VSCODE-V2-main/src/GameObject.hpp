#pragma once
#include <raylib.h>

class GameObject {
    public:
        GameObject(Vector2 initialPosition);
        virtual ~GameObject();
        virtual void Draw() = 0;
        Vector2 getPosition() const;
        void setPosition(Vector2 newPosition);
    protected:
        Vector2 position;
};
