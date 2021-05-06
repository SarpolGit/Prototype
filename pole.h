/*
#include "position.h"
#include <vector>
#include <iostream>

#ifndef POLE_H
#define POLE_H
class Pole{
public:
    Pole(){
        int i = 0;
        for(int cell = 0; cell < 3; cell++){
            for(int line = 0; line < 3; line++){
                for(int side = 0; side < 2; side++){
                    Position position(cell,line,side);
                    pole_[i] = position;
                    i++;
                }
            }
        }
    }
    void Show(){
        for(int i = 0; i < 18; i++){
        std::cout << pole_[i].GetCell() << pole_[i].GetLine() << pole_[i].GetSide() << std::boolalpha << pole_[i].isEmpty() << std::endl;
    }
    }
    std::vector <Position>& GetVector(){return pole_;};
    Position& GetPosition(int cell, int line, int side){
        for(int i = 0; i < 18; i++){
            if((pole_[i].GetCell() == cell) && (pole_[i].GetLine() == line) && (pole_[i].GetSide() == side))
                return pole_[i];
        }
    }
private:
    std::vector<Position> pole_;
};
#endif
*/