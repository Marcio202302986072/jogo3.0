#include "score.hpp"

Score::Score() : score(0), startTime(GetTime()) {}

void Score::Update() {
    score = static_cast<int>(GetTime() - startTime);
}

void Score::Draw(Font font) {
    DrawTextEx(font, TextFormat("Score: %i", score), {400 , 0}, 34, 2, RED);
}

int Score::GetScore() const {
    return score;
}
