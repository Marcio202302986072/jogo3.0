#include "gameobject.hpp"

GameObject::GameObject(Vector2 initialPosition) {
    position = initialPosition;
}

GameObject::~GameObject() {
    // Destructor
}

Vector2 GameObject::getPosition() const {
    return position;
}

void GameObject::setPosition(Vector2 newPosition) {
    position = newPosition;
}
