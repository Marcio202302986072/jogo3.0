#pragma once
#include <raylib.h>

class Score {
public:
    Score();
    void Update();
    void Draw(Font font);
    int GetScore() const;

private:
    int score;
    float startTime;
};
