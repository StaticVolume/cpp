#pragma once
#include <iostream>


class Colour {
private:

     uint8_t red;
     uint8_t green;
     uint8_t blue;
     uint8_t alpha;

public:

    Colour(uint8_t R  , uint8_t G , uint8_t B , uint8_t alpha =0);
    Colour();
    Colour(Colour& color);

    inline int8_t GetColourR() const {return red;}
    inline int8_t GetColourG() const {return green;}
    inline int8_t GetColourB() const {return blue;}
    inline int8_t GetColourA() const {return alpha;}

    void SetColourFromNums(uint8_t in_red, uint8_t in_green, uint8_t in_blue, uint8_t in_alpha = 0);
    void SetColour(Colour& color);
    void SetColourR(uint8_t in_red);
    void SetColourB(uint8_t in_green);
    void SetColourG(uint8_t in_blue);
    void SetColourA(uint8_t in_alpha);
};
