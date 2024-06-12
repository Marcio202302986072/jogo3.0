#include "game.hpp"

game::game() {
    collectSound = LoadSound("collect-points-190037.mp3");
    gameOverSound = LoadSound("game-over-160612.mp3");
    InitGame();
}

game::~game() {
    Vilao::UnloadImages();
    UnloadMusicStream(music);
    UnloadSound(gameOverSound);
}

void game::Update() {
    if (run) {
        double currentTime = GetTime();
        if (currentTime - timeLastSpam > powerSpamIntervalo) {
            power.Spam();
            timeLastSpam = GetTime();
            powerSpamIntervalo = GetRandomValue(10, 20);
        }

        for (auto& laser : carro.lasers) {
            laser.Update();
        }
        if (carro.isShooting && GetTime() < carro.shootTime) {
            carro.FireLaser();
        } else {
            carro.isShooting = false;
        }

        MoveVilao();
        VilaoTiroLaser();

        for (auto& laser : vilaoLasers) {
            laser.Update();
        }

        DeleteInactiveLaser();
        power.Update();
        CheckForCollisions();
        score.Update();

        if (vilaos.empty()) {
            GameOver();
        }
    } else {
        if (IsKeyDown(KEY_ENTER)) {
            Reset();
            InitGame();
        }
    }
}

void game::Draw() {
    carro.Draw();

    for (auto& laser : carro.lasers) {
        laser.Draw();
    }
    for (auto& vilao : vilaos) {
        vilao.Draw();
    }
    for (auto& laser : vilaoLasers) {
        laser.Draw();
    }
    score.Draw(GetFontDefault());
}

void game::HandleInput() {
    if (run) {
        if (IsKeyDown(KEY_LEFT)) {
            carro.MovLeft();
        }
        if (IsKeyDown(KEY_RIGHT)) {
            carro.MovRight();
        }
        if (IsKeyDown(KEY_UP)) {
            carro.MovUp();
        }
        if (IsKeyDown(KEY_DOWN)) {
            carro.MovDown();
        }
        power.Draw();
    }
}

void game::DeleteInactiveLaser() {
    for (auto it = carro.lasers.begin(); it != carro.lasers.end();) {
        if (!it->active) {
            it = carro.lasers.erase(it);
        } else {
            ++it;
        }
    }
    for (auto it = vilaoLasers.begin(); it != vilaoLasers.end();) {
        if (!it->active) {
            it = vilaoLasers.erase(it);
        } else {
            ++it;
        }
    }
}

std::vector<Mang> game::CreateVilao() {
    std::vector<Mang> vilao;
    for (int row = 0; row < 6; row++) {
        for (int column = 0; column < 1; column++) {
            int vilaoType;
            if (row == 0 || row == 2 || row == 4) {
                vilaoType = 1;
            }
            else if (row == 1 || row == 3 || row == 5) {
                vilaoType = 2;
            }
            float x = 650 + column * 110;
            float y = row * 110;
            vilaos.push_back(Mang(vilaoType, {x, y})); // Cria instâncias de Mang
        }
    }
    return vilaos;
}

void game::MoveVilao() {
    for (auto& vilao : vilaos) {
        if (vilao.position.y + vilao.vilaoImages[vilao.type - 1].height > GetScreenHeight()) {
            vilaoDirection = -1;
        }
        if (vilao.position.y < 0) {
            vilaoDirection = 1;
        }
        vilao.Update(vilaoDirection);
    }
}

void game::VilaoTiroLaser() {
    double currentTime = GetTime();
    if (currentTime - timeLastVilaoTiro >= vilaoLaserTiroIntevalo && !vilaos.empty()) {
        int randomIndex = GetRandomValue(0, vilaos.size() - 1);
        Mang& vilao = vilaos[randomIndex]; // Acessa um vilão Mang específico
        vilaoLasers.push_back(Laser({vilao.position.x + vilao.vilaoImages[vilao.type - 1].width / 2, 
                                     vilao.position.y + vilao.vilaoImages[vilao.type - 1].height}, 6));
        timeLastVilaoTiro = GetTime();
    }
}

void game::CheckForCollisions() {
    for (auto& laser : carro.lasers) {
        auto it = vilaos.begin();
        while (it != vilaos.end()) {
            if (CheckCollisionRecs(it->getRect(), laser.getRect())) {
                it->health--; // Diminui a vida do vilão em 1
                laser.active = false;
                if (it->health <= 0) {
                    it = vilaos.erase(it); // Remove o vilão se a vida acabou
                } else {
                    ++it;
                }
            } else {
                ++it;
            }
        }
        if (CheckCollisionRecs(power.getRect(), laser.getRect())) {
            power.alive = false;
            laser.active = false;
        }
    }

    for (auto& laser : vilaoLasers) {
        if (CheckCollisionRecs(laser.getRect(), carro.getRect())) {
            laser.active = false;
            lives--;
            if (lives == 0) {
                GameOver();
            }
        }
    }

    if (CheckCollisionRecs(power.getRect(), carro.getRect())) {
        power.alive = false;
    }
}

void game::GameOver() {
    PlaySound(gameOverSound);
    run = false;
} 

void game::InitGame() {
    vilaos = CreateVilao();
    vilaoDirection = 1;
    timeLastVilaoTiro = 0.0;
    timeLastSpam = 0.0;
    powerSpamIntervalo = GetRandomValue(10, 20);
    power.Spam();
    lives = 3;
    score = Score();
    run = true;
}

void game::Reset() {
    carro.Reset();
    vilaos.clear();
    vilaoLasers.clear();
}
