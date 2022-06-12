#pragma once
#include<iostream>
#include <random>
#include <chrono>
#include "colour.h"


class Game {
public:
     enum GameToys: char {EMPTY = ' ', X = 'X', O = '0'};
private:

     const uint32_t min{0};
     const uint32_t max{1};

     const GameToys human_gametoy = X;
     const GameToys ii_gametoy = O;
     const GameToys empty_gametoy = EMPTY;

     const bool human_choise = true;
     const bool ii_choise = false;

     bool random_choise{0}; // true for human step, false for ii step



    struct gamenode {

        int32_t x;
        int32_t y;
        uint32_t width = 100;
        uint32_t heigth = 100;
        Colour color;
        bool is_fill = false;
        bool is_image = false;
        GameToys game_node_toy = EMPTY;

    };


    gamenode** game_field = nullptr;
    uint32_t size_of_game_filed = 3;// размкер игрового поля  3x3
    static uint32_t game_steps;


public:

    Game();

    uint32_t GetSizeOfGameField() const {return size_of_game_filed;}
    inline gamenode** GetGamefield() const {return game_field;}



    inline bool GetChoise() const { return random_choise; }
    inline GameToys GetHumanGameToy() const {return human_gametoy;}
    inline GameToys GetIiGameToy() const {return ii_gametoy;}
    inline GameToys GetEmptyGameToy() const {return empty_gametoy;}
    inline bool GetHumanChoise() const {return human_choise;}
    inline bool GetIiChoise() const {return ii_choise;}
     uint32_t GetGameSteps() const {return game_steps;}

    void PrintAlarm();

    void HumanSelect(int32_t mouse_x, int32_t mouse_y);
    void HumanTakeAmove(int32_t mouse_x, int32_t mouse_y);
    void IiTakeAmove();


    friend  uint32_t GetRandomChoise( const uint32_t min, const  uint32_t max);

    void SetChoise(bool choise);

    bool CalculateWinner();

//=================================================================================================
    ~Game() {

            if (game_field) {

                for (uint32_t count = 0; count < size_of_game_filed; ++count){
                        delete [] game_field[count];
                }
             delete [] game_field;
             game_field = nullptr;
            }
    }


};


 uint32_t GetRandomChoise(const uint32_t min, const uint32_t max);

