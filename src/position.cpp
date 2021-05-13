#include "position.h"
#include "hero.h"

/*

Position::Position():cell_(0),line_(0),side_(0),empty_(true),hero_(Hero()){};
Position::Position(int cell, int line, int side):cell_(cell),line_(line),side_(side),empty_(true),hero_(Hero()){};

Position& Position::operator=(const Position& position){
    cell_ = position.cell_;
    line_ = position.line_;
    side_ = position.side_;
    empty_ = position.empty_;
    hero_ = position.hero_;
}

void Position::SetHero(Card* card){
    Hero hero(card);
    hero_ = hero;
    empty_ = false;
}

int Position::GetCell(){return cell_;}
int Position::GetLine(){return line_;}
int Position::GetSide(){return side_;}
bool Position::isEmpty(){return empty_;}


*/