#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <random>

class Cell {
private:
    std::tuple<int, int> position;
    char type;

public:
    Cell(int x, int y, char t) : position(x, y), type(t) {}

    std::tuple<int, int> getPos() {
        return position;
    }

    char getType() {
        return type;
    }

    void setPos(int x, int y) {
        position = std::make_tuple(x, y);
    }

    void setType(char t) {
        type = t;
    }
};

class Effect {
public:
    virtual void apply(Cell& cell) = 0;
};

class Utils {
public:
    static std::tuple<int, int> generateRandomPos(int gridWidth, int gridHeight) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribX(0, gridWidth - 1);
        std::uniform_int_distribution<int> distribY(0, gridHeight - 1);

        int x = distribX(gen);
        int y = distribY(gen);

        return std::make_tuple(x, y);
    }

    static double calculateDistance(std::tuple<int, int> pos1, std::tuple<int, int> pos2) {
        int x1 = std::get<0>(pos1);
        int y1 = std::get<1>(pos1);
        int x2 = std::get<0>(pos2);
        int y2 = std::get<1>(pos2);

        double distance = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
        return distance;
    }
};

class Trap : public Cell, public Effect {
private:
    bool active;

public:
    Trap(int x, int y) : Cell(x, y, 'T'), active(true) {}

    bool isActive() {
        return active;
    }

    void apply(Cell& cell) override {
        cell.setType('T');
        active = false;
    }
};

class Character : public Cell {
public:
    Character(int x, int y) : Cell(x, y, 'C') {}

    void move(int dx, int dy) {
        std::tuple<int, int> pos = getPos();
        int x = std::get<0>(pos);
        int y = std::get<1>(pos);

        setPos(x + dx, y + dy);
    }
};

class Game {
private:
    std::vector<Cell*> grid;

public:
    Game() {}

    std::vector<Cell*>& getGrid() {
        return grid;
    }

    void initGame(int numCharacters, int numTraps, int gridWidth, int gridHeight) {
        for (int i = 0; i < numCharacters; i++) {
            std::tuple<int, int> randomPos = Utils::generateRandomPos(gridWidth, gridHeight);
            Character* character = new Character(std::get<0>(randomPos), std::get<1>(randomPos));
            grid.push_back(character);
        }

        for (int i = 0; i < numTraps; i++) {
            std::tuple<int, int> randomPos = Utils::generateRandomPos(gridWidth, gridHeight);
            Trap* trap = new Trap(std::get<0>(randomPos), std::
