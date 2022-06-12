#include "colour.h"

Colour::Colour(uint8_t R  , uint8_t G , uint8_t B , uint8_t alpha) : red{R}, green{G}, blue{B}, alpha{alpha} {}

Colour::Colour() {

    red = 0;
    green = 0;
    blue = 0;
    alpha = 0;
}

Colour::Colour(Colour& color): red{color.red}, green{color.green}, blue{color.blue}, alpha{color.alpha} {}

void Colour::SetColour(Colour& color) {

    red = color.red;
    green = color.green;
    blue = color.blue;
    alpha = color.alpha;
}
void Colour::SetColourFromNums(uint8_t in_red, uint8_t in_green, uint8_t in_blue, uint8_t in_alpha)
{
    red = in_red;
    green = in_green;
    blue = in_blue;
    alpha = in_alpha;
}

void Colour::SetColourR(uint8_t in_red) {
    red = in_red;
}

void Colour::SetColourB(uint8_t in_green) {
    green = in_green;
}

void Colour::SetColourG(uint8_t in_blue) {
    blue = in_blue;
}
void Colour::SetColourA(uint8_t in_alpha) {

    alpha = in_alpha;
}
