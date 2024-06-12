#include "mang.hpp"

Mang::Mang(int type, Vector2 position) : Vilao(type, position) {
    // Definir a imagem específica para Mang
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
