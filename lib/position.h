#include "hero.h"
#include "card.h"
#ifndef POSITION_H
#define POSITION_H

class Position{
public:
    Position():cell_(0),line_(0),side_(0),empty_(true),hero_(Hero()){};
    Position(int cell, int line, int side):cell_(cell),line_(line),side_(side),empty_(true),hero_(Hero()){};
   // Position(const Position& other);
    //Position& operator = (const Position& other);
   // ~Position();

    //Пустая ли клетка?
    bool isEmpty(){return empty_;};
    //Получить героя с клетки
    //Hero& GetHero();
    //Информация о позиции
    //Поставить героя
    void SetHero(Card* card){
        Hero hero(card);
        hero_ = hero;
        empty_ = false;
    };
    void RemoveHero(){
        empty_ = true;
    }
    
    int GetCell(){return cell_;}
    int GetLine(){return line_;}
    int GetSide(){return side_;}
    Hero& GetHero(){return hero_;}

private:
    //Дальняя клетка - 1 Средняя - 2 Ближняя - 3
    unsigned int cell_;
    //Передняя линия - 1 Средняя -2 Задняя - 3
    unsigned int line_;
    //Сторона сражения
    unsigned int side_;
    //Состояние клетки
    bool empty_;
    //Герой на данной клетке
    Hero hero_;
};
#endif 