#include <iostream>
#include <vector>
#include "position.h"
#include "player.h"
#include "card.h"
#include "deck.h"
#include "pole.h"

Position& GetPosition(int cell, int line, int side, std::vector<Position>& pole){
    for(int i = 0; i < pole.size(); i++){
        if((pole[i].GetCell() == cell) && (pole[i].GetLine() == line) && (pole[i].GetSide() == side))
            return pole[i];
    }
}

void Show(std::vector<Position>& pole){
    Position PolePosition;
    for(int itline = 0; itline < 3; itline++){
        for(int itcell = 0; itcell < 3; itcell++){
            PolePosition = GetPosition(itcell, itline, 0, pole);
            if(PolePosition.isEmpty())
                std::cout << 0;
            else
                std::cout << 1;
        }
        std::cout << " ";
        for(int itcell = 0; itcell < 3; itcell++){
            PolePosition = GetPosition(itcell, itline, 1, pole);
            if(PolePosition.isEmpty())
                std::cout << 0;
            else
                std::cout << 1;
        }
        std::cout << std::endl;
    }
}

void SetPosition(std::vector<Position>& pole, Position& position){
    for(int i = 0; i < pole.size(); i++){
        if((pole[i].GetCell() == position.GetCell()) && (pole[i].GetLine() == position.GetLine()) && (pole[i].GetSide() == position.GetSide()))
            pole[i] = position;
    }
}

void infoPosition(std::vector<Position>& pole, Position& position){
    if(!position.isEmpty()){
        std::cout << "Здоровье Героя:" << position.GetHero().GetHealth() << " " << "Атака Героя:" << position.GetHero().GetStrength() << std::endl; 
    }
}

void Attack(Player& ChosenPlayer, Position& FriendlyHero, Position& EnemyHero, std::vector<Position>& pole){
    EnemyHero.GetHero().ReduceHealth(FriendlyHero.GetHero().GetStrength());
    if(EnemyHero.GetHero().GetHealth() <= 0) EnemyHero.RemoveHero();
}

bool CheckLeader(Position& FirstPlayerLeader, Position& SecondPlayerLeader,std::vector<Position>& pole){
    if(FirstPlayerLeader.isEmpty()){
        std::cout << "Победил второй игрок!!!!!!";
        return false;
    }
    if(SecondPlayerLeader.isEmpty()){
        std::cout << "Победил первый игрок!!!!!!";
        return false;
    }
    return true;
}



int main(){
    Pole poleshko;
    std::vector<Position> pole_;
    for(int side = 0; side < 2; side++){
        for(int cell = 0; cell < 3; cell++){
            for(int line = 0; line < 3; line++){
                    Position position(cell,line,side);
                    pole_.push_back(position);
            }
        }
    }
    poleshko.Show();

    /*for(int i = 0; i < pole_.size(); i++){
       std::cout << pole_[i].GetCell() << pole_[i].GetLine() << pole_[i].GetSide() << std::boolalpha << pole_[i].isEmpty() << std::endl;
    }

    std::cout << "//////////////////////////" << std::endl;*/

    
    Position FirstPlayerLeader(1,1,0);
    Position SecondPlayerLeader(1,1,1);

    std::cout << "//////////////////////////" << std::endl;
    
    /*std::cout << test.GetCell() << test.GetLine() << test.GetSide() << std::boolalpha << test.isEmpty() << std::endl;

    std::cout << "//////////////////////////" << std::endl;*/
    std::vector<Card*> LeaderCards; 
    int choice = 0;

    Breed LeaderMageBreed(NULL,15,7);
    Card* LeaderMageCard = LeaderMageBreed.NewCard();
    LeaderCards.push_back(LeaderMageCard);

    Breed LeaderWarriorBreed(NULL,22,6);
    Card* LeaderWarriorCard = LeaderWarriorBreed.NewCard();
    LeaderCards.push_back(LeaderWarriorCard);

    Breed LeaderPriestBreed(NULL,30,3);
    Card* LeaderPriestCard = LeaderPriestBreed.NewCard();
    LeaderCards.push_back(LeaderPriestCard);

    std::cout << "Выбери лидера Первый игрок" << std::endl;
    for(int i = 0; i < LeaderCards.size(); i++){
        std::cout << "Здоровье Героя:"<< LeaderCards[i]->GetBreed().GetHealth() << " " << "Атака Героя:" << LeaderCards[i]->GetBreed().GetStrength() << std::endl;
    }
    std::cin >> choice;
    FirstPlayerLeader.SetHero(LeaderCards[choice]);
    SetPosition(pole_,FirstPlayerLeader);

    std::cout << "Выбери лидера Второй игрок" << std::endl;
    for(int i = 0; i < LeaderCards.size(); i++){
        std::cout << "Здоровье Героя:"<< LeaderCards[i]->GetBreed().GetHealth() << " " << "Атака Героя:" << LeaderCards[i]->GetBreed().GetStrength() << std::endl;
    }
    std::cin >> choice;
    SecondPlayerLeader.SetHero(LeaderCards[choice]);
    SetPosition(pole_,SecondPlayerLeader);
    

    std::vector<Card*> useCard;

    Breed MageBreed(NULL,10,5);
    Card* MageCard = MageBreed.NewCard();
    useCard.push_back(MageCard);

    Breed WarriorBreed(NULL,16,4);
    Card* WarriorCard = WarriorBreed.NewCard();
    useCard.push_back(WarriorCard);


    Breed PriestBreed(NULL,20,2);
    Card* PriestCard = PriestBreed.NewCard();
    useCard.push_back(PriestCard);


    Deck FirstDeck(useCard);
    Deck SecondDeck(useCard);

    Player FirstPlayer(FirstDeck,0);
    /*FirstPlayer.GetDeck().ShowDeck();

    std::cout << "//////////////////////////" << std::endl;*/

    Player SecondPlayer(SecondDeck,1);
    /*SecondPlayer.GetDeck().ShowDeck();

    std::cout << "//////////////////////////" << std::endl;*/
    FirstPlayer.StartingHand();
    SecondPlayer.StartingHand();

    int currentside = 0;
    Player CurrentPlayer = FirstPlayer;
    int MovesAmount = 2;

    while(CheckLeader(GetPosition(1,1,0,pole_),GetPosition(1,1,1,pole_),pole_)){
        if(MovesAmount == 0){
            if(currentside == 0){
                std::cout << "Ход переходит ко второму игроку" << std::endl;
                currentside = 1;
                CurrentPlayer = SecondPlayer;
            }else{
                std::cout << "Ход переходит ко первому игроку" << std::endl;
                currentside = 0;
                CurrentPlayer = FirstPlayer;
            }
            MovesAmount = 2;
        }
        if(currentside == 0) 
            std::cout << "Ход Первого игрока" <<std::endl;
        else
            std::cout << "Ход Второго игрока" <<std::endl;

        std::cout <<"Взять карту(1)" << std::endl;
        std::cout <<"Посмотреть руку(2)" << std::endl;
        std::cout <<"Получить информацию о герое на поле(3)" << std::endl;
        std::cout <<"Атаковать своим героем врага(4)" << std::endl;
        std::cout <<"Посмотреть поле(5)" << std::endl;
        std::cout <<"Поставить героя(6)" << std::endl;
        std::cout << "//////////////////////////" << std::endl;

        choice = 0;
        std::cin >> choice;
        switch(choice){
            case(1):{
                CurrentPlayer.DrawCard();
                MovesAmount --;
                break;
            }
            case(2):{
                CurrentPlayer.GetHand().ShowDeck();
                std::cout << "//////////////////////////" << std::endl;
                break;
            }
            case(3):{
                std::cout << "Введите клетку и линию и сторону"  << std::endl;
                int line = 0;
                int cell = 0;
                int side = 0;

                std::cin >> cell >> line >> side;
                Position kletka = GetPosition(cell,line,side,pole_);
                infoPosition(pole_,kletka);
                std::cout << "//////////////////////////" << std::endl;
                break;
            }
            case(4):{
                std::cout << "Введите клетку и линию вашего героя"  << std::endl;
                int line = 0;
                int cell = 0;

                std::cin >> cell >> line;
                Position YourHero = GetPosition(cell,line,CurrentPlayer.GetSide(),pole_);

                std::cout << "Введите клетку и линию вражеского героя"  << std::endl;
                std::cin >> cell >> line;
                int EnemySide;
                if(CurrentPlayer.GetSide() == 0){
                    EnemySide = 1;
                }else{
                    EnemySide = 0;
                }
                Position EnemyHero = GetPosition(cell,line,EnemySide,pole_);

                Attack(CurrentPlayer,YourHero,EnemyHero,pole_);
                SetPosition(pole_,EnemyHero);
                MovesAmount--;
                break;
            }
            case(5):{
                Show(pole_);
                break;
            }
            case(6):{
                std::cout << "Выберете карту" <<std::endl;
                std::cin >> choice;
                Card* ChosenCard = CurrentPlayer.ChooseCard(choice); 

                std::cout << "Введите клетку и линию"  << std::endl;
                int line = 0;
                int cell = 0;
                std::cin >> cell >> line;

                Position kletka = GetPosition(cell,line,CurrentPlayer.GetSide(),pole_);
                kletka.SetHero(ChosenCard);
                SetPosition(pole_,kletka);
                MovesAmount --;
                break;
            }
            default:{
                break;
            }
        }
    }

    /*Card* FirstLeaderCard;
    FirstLeaderCard = FirstPlayer.ChooseCard(0);
    Position FirstPlayerLeader(1,1,0);
    FirstPlayerLeader.SetHero(FirstLeaderCard);

    Card* SecondLeaderCard;
    SecondLeaderCard = SecondPlayer.ChooseCard(0);
    Position SecondPlayerLeader(1,1,1);
    SecondPlayerLeader.SetHero(SecondLeaderCard);
    //std::cout << test.GetCell() << test.GetLine() << test.GetSide() << std::boolalpha << test.isEmpty() << std::endl;

    std::cout << "//////////////////////////" << std::endl;
    SetPosition(pole_,FirstPlayerLeader);
    SetPosition(pole_,SecondPlayerLeader);
    Show(pole_);
    std::cout << "//////////////////////////" << std::endl;

    SecondPlayer.GetHand().ShowDeck();

    std::cout << "//////////////////////////" << std::endl;

    infoPosition(pole_,FirstPlayerLeader);
    infoPosition(pole_,SecondPlayerLeader);
*/
    /*std::cout << "//////////////////////////" << std::endl;
    while(CheckLeader(FirstPlayerLeader,SecondPlayerLeader,pole_)){
        Attack(SecondPlayer,SecondPlayerLeader,FirstPlayerLeader,pole_);
        infoPosition(pole_,FirstPlayerLeader);
    }*/
    


    return 0;
}