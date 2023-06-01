#ifndef EFFECT_H
#define EFFECT_H

class Cell;

class Effect {
public:
    virtual void apply(Cell& cell) = 0;
};

#endif  
