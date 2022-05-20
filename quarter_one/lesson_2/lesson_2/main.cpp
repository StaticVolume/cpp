#include <iostream>

 const int CHAR_AARAY_MAX_SIZE { 120 };
 const int TIC_TAC_ENUM_MAX_SIZE { 3 };
 const int GAME_SIMBOLS { 4 };
 const int MIN_HOR_VERT_SIZE_OF_TIC_TAC_FIELD { 3 };

int main(int argc, char* argv[]) {

    /* Задание № 1 . Вносим переменные без перефиксов, определяющих область видимости и жизни  */


    short int a { sizeof(short int) };    // (можно просто short, или signed short int, или signed short ), или  стандартный размер на Linux 2 байта; диапазон знакового от  -32768..32767 , беззнакового от 0..65535
    a = -15;
    unsigned short int a1 { 65U };    // беззнаковый тип,  можно записывать как с префиксом u или U так и без.(Другие варианты записи : a1 = 65u, a1 = 65), может хранить от 0..65535


    int b {sizeof(int)};    // стандартный размер  на Linux 4 байта; диапазон знакового от −2 147 483 648..2 147 483 647, беззнакового от 0..4 294 967 295
    b = -10;
    unsigned int b1 { 10u} ;  //можно записывать как с префиксом u или U так и без.(Другие варианты записи : b1 = 65U, b1 = 65)


    long int c { sizeof(long int) };  // (signed long int или signed long) стандартный размер на Linux 8 байт; диапазон знакового от −9 223 372 036 854 775 808..9 223 372 036 854 775 807, беззнакового - 0..18 446 744 073 709 551 615
    c = -5L;    // можно записывать с префиксом L, так и без него. (Другие варианты записи : c = -5l, c = -5)
    unsigned long int c1 { 5ul };     // можно записывать как с префиксом u или U так и без.(Другие варианты записи : c1 = 5UL, c1 = 5uL, c1 = 5Ul, c1 = 5; )


    long long int d { sizeof(long long) };    // (signed long long int или signed long long)  стандартный размер на Linux 8 байт; диапазон ззнакового от −9 223 372 036 854 775 808..9 223 372 036 854 775 807, беззнакового - 0..18 446 744 073 709 551 615
    d = -20;    // можно записывать с префиксом LL, так и без него. (Другие варианты записи : c = -20LL, c = -20ll)
    unsigned long long int d1 { 20ull };  // можно записывать как с префиксом u или U так и без.(Другие варианты записи : d1 = 20ULL, d1 = 5Ull, d1 = 5uLL, c1 = 5; )


    char e { sizeof(char) };  //  стандартный размер на Linux 1 байт; диапазон знакового от -128..127 , беззнакового от  0..255
    e = 'e';    // возможно хранение как символьного значения переменной
    char e1 = 101;  // так и числового
    unsigned char e2 { '@' }; // беззнаковый тип, другое наименование uchar e2 = 64; хранит значения от 0..255
    signed char e3 { -23 };   // знаковый тип, хранит значение от -128..127


    bool f { sizeof(bool) }; // стандартный размер на Linux 1 байт; имеет 2 варианта значения : true и false. Любое число != 0 воспринимается как true; 0 воспринимается как false;
    f = (e == e1)? true : false;    // или    f = ( e==e1 )? -3 : 0; что равноценно


    float g { sizeof(float) };    // стандартный размер  на Linux 4 байта; диапазон 3,4E +/- 38 (7 знаков)
    g = 71'325.567567f;    // точность float : от 6 до 9 цифр после разделителя, но обычно точность равна 7 знакам. Float не может быть беззнаковым
    g = 134.45E-2f; // другой тип записи; данное число  = 1.3445.


    double i { sizeof(double) };  // стандартный размер  на Linux 8 байта; диапазон 1,7E +/- 308 (15 знаков)
    i = 5'675.867'574'563'452'234; // точность double : от 15 до 18 цифр после разделителя, обычно точность равна 16 цифрам.





    /* Задание 2.  Создание Enum для крестиков-ноликов */

    enum class tic_tac_toe_enum { X, O, EMPTY };





     /* Задание 3.  Создание массива  перечислений крестиков - ноликов без указания точного размера */

    tic_tac_toe_enum tic_tac_toe_array[] { tic_tac_toe_enum::X, tic_tac_toe_enum::O, tic_tac_toe_enum::EMPTY };

    static const char game_symbols[GAME_SIMBOLS]{ 'X', '0', ' ' }; // заодно создали масив символов для запонения поля symbol в структуре My_Tic_Tac_Toe_Field




     /* Задание 4.  Создание структуры  для крестиков-ноликов */


    struct My_Tic_Tac_Toe_Field {



        struct gamer {

            bool is_first_move { false };
            unsigned char player_score { 0 };
            char name [CHAR_AARAY_MAX_SIZE] { "Unknown" };
            tic_tac_toe_enum my_figure_type { tic_tac_toe_enum::EMPTY };
            char symbol = game_symbols[static_cast<int>(my_figure_type)];
        };

        struct field_separate_symbols {         // определение типа символов разделителей пространства игрового поля.

            char horizontal_separate { '-' };
            char vertical_separate { '|' } ;

        };

        enum class tic_tac_figure_colour { WHITE, RED, GREEN, BLUE, YELLOW, BLACK };    //цвет компонентов(разделителей, игровых символов)

        field_separate_symbols separate_simbols;
        tic_tac_figure_colour figure_colour = tic_tac_figure_colour::WHITE;
        char tic_tac_field[MIN_HOR_VERT_SIZE_OF_TIC_TAC_FIELD][MIN_HOR_VERT_SIZE_OF_TIC_TAC_FIELD]; // формирование массива игрового поля размера 3x3
        tic_tac_toe_enum tic_tac_tarray[TIC_TAC_ENUM_MAX_SIZE] { tic_tac_toe_enum::X, tic_tac_toe_enum::O, tic_tac_toe_enum::EMPTY };
        gamer player_one;   // игроки
        gamer player_two;
    };

    My_Tic_Tac_Toe_Field* my = new My_Tic_Tac_Toe_Field();
    int sz = sizeof(My_Tic_Tac_Toe_Field);




     /* Задание 5.  Создание структуры MyVariant */

    struct MyVariant {

        char is_char : 1;
        char is_int : 1;
        char is_float : 1;

            union MyData {
                char a;
                int b;
                float c;
            } my_data;

    };


    MyVariant variant;  // используем
    variant.is_int = 1;

    if (variant.is_char) {
        std::cin >> variant.my_data.a;
    }else if (variant.is_int) {
        std::cin >> variant.my_data.b;
    }else
        std::cin >> variant.my_data.c;


    return 0;
}
