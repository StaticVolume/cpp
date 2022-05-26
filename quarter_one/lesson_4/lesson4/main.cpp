#include <iostream>
#include <string>

#define INT_MIN 10
#define INT_MAX 20

int main (int argc, char* argv[] ) {

/* Задание № 1 : Написать программу, проверяющую что сумма двух (введенных с клавиатуры) чисел лежит в пределах от 10 до 20 (включительно),
 * если да – вывести строку "true", в противном случае – "false" */

    uint32_t a, b;
    std::cout << "Enter 2 numbers : " << std::endl;
    std::cin >> a >> b;

    if ( ( (a+b) >= INT_MIN ) && ( (a+b) <= INT_MAX) ) {
        std::cout << "true" << std::endl;\

    }else {

        std::cout << "false" << std::endl;
    }


  //можно сделать так

  /* bool result = ( ( (a+b) >= INT_MIN ) && ( (a+b) <= INT_MAX) ) ? true : false;

   switch (static_cast<char>(result)) {

    case 0 : std::cout << "false" << std::endl;
       break;
    case 1 : std::cout << "true" << std::endl;

   } */



/* Задание № 2 : Написать программу, выводящую на экран строку “true”, если две целочисленные константы,
 * объявленные в её начале либо обе равны десяти сами по себе, либо их сумма равна десяти. Иначе "false" */

    //новые две переменные

    int32_t c,d;
    std::cout << "Enter new 2 numbers : " << std::endl;
    std::cin >> c >> d;

    bool ecxercise2  = ( ( c ==d ) || ((c+d) == INT_MIN ) ) ? true : false;

    switch (static_cast<char>(ecxercise2)) {

     case 0 : std::cout << "false" << std::endl;
        break;
     case 1 : std::cout << "true" << std::endl;

    }


    // можно через if

   /* if ( ( c ==d ) || ((c+d) == INT_MIN ) )  {

        std::cout << "true" << std::endl;\

    }else {

        std::cout << "false" << std::endl;
    } */


/* Задание № 3 : Написать программу которая выводит на экран список всех нечетных чисел он 1 до 50.
 * Например: "Your numbers: 1 3 5 7 9 11 13 ...". Для решения используйте любой С++ цикл.*/

    uint32_t e,j;
    std::cout << "Enter new 2 numbers : " << std::endl;
    std::cin >> e >> j;
    std::cout << "................" << std::endl;
    std::cout << "Your numbers : " << std::endl;
    for(uint32_t count = e ; count  <= j ; ++count ) {

            if ( (count % 2) != 0 ) {

                std::cout<< count <<"  ";
            }
    }
    std::cout << " " << std::endl;

 /* Задание № 4 : Со звёздочкой. Написать программу, проверяющую, является ли некоторое число - простым.
  * Простое число — это целое положительное число, которое делится без остатка только на единицу и себя само.*/

    int32_t o;

    bool is_simple = true;

    std::cout << "Enter one new number :" << std::endl;
    std::cin >> o;

    for ( int32_t p = 1; p <= o ; ++p ) {

            if ( (o % p == 0) && ( ( p != 1  ) && (p != o) ) ) {
                is_simple = false;
                break;

            }

    }

    switch (static_cast<char>(is_simple)) {

        case 0 : std::cout << "Number is not simple"  << std::endl;
        break;
        case 1 : std::cout << "Number is simple"  << std::endl;
        break;
    }


/* Задание № 5 Со звёздочкой. Пользователь вводит с клавиатуры число (год): от 1 до 3000.
 * Написать программу, которая определяет является ли этот год високосным. Каждый 4-й год является високосным,
 * кроме каждого 100-го, при этом каждый 400-й – високосный. Вывести результаты работы программы в консоль.*/

    uint32_t  year;

    do {
    std::cout << "Enter the year :" << std::endl;
    std::cin >> year;

    } while (year > 3000);


    if (  (year == 400) || ( ( (year % 4) == 0 ) && (year != 100 )) ) {

        std::cout << "leap year"<< std::endl;

    } else {

        std::cout << "Is not a leap year"  << std::endl;
    }


}
