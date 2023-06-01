#include "Utils.h"
#include <random>
#include <cmath>

std::tuple<int, int> Utils::generateRandomPos(int gridWidth, int gridHeight) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribX(0, gridWidth - 1);
    std::uniform_int_distribution<> distribY(0, gridHeight - 1);
    int x = distribX(gen);
    int y = distribY(gen);
    return std::make_tuple(x, y);
}

double Utils::calculateDistance(std::tuple<int, int> pos1, std::tuple<int, int> pos2) {
    int x1 = std::get<0>(pos1);
    int y1 = std::get<1>(pos1);
    int x2 = std::get<0>(pos2);
    int y2 = std::get<1>(pos2);
    double dx = x2 - x1;
    double dy = y2 - y1;
    return std::sqrt(dx * dx + dy * dy);
}
