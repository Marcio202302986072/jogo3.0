#pragma once
#include "carro.hpp"
#include "mang.hpp" // Incluímos mang.hpp em vez de vilao.hpp
#include "score.hpp"
#include "power.hpp"
#include <vector>

class game {
public:
    game();
    ~game();
    void Draw();
    void Update();
    void HandleInput();

    bool run;
    int lives;
    Music music;

private:
    void DeleteInactiveLaser();
    std::vector<Mang> CreateVilao(); // Mudamos para vector<Mang>
    void MoveVilao();
    void VilaoTiroLaser();
    void CheckForCollisions();
    void GameOver();
    void Reset();
    void InitGame();

    carro carro;
    std::vector<Mang> vilaos; // Mudamos para vector<Mang>
    int vilaoDirection;
    std::vector<Laser> vilaoLasers;
    constexpr static float vilaoLaserTiroIntevalo = 0.35;
    float timeLastVilaoTiro;
    float powerSpamIntervalo;
    float timeLastSpam;
    Power power;
    Score score;
    Sound gameOverSound;
    Sound collectSound;
};
