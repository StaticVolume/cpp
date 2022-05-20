#include <iostream>

using namespace std;

/* Задание № 4 Написать программу, вычисляющую выражение из первого задания, а переменные для неё объявлены и инициализировать в другом cpp файле. Используйте extern.*/



int main()
{
    extern const int a;
    extern const int b;
    extern const int c;
    extern const int d;

    float res = a * ( b + static_cast<float>(c)/d);

    std::cout << res << std::endl;
    return 0;
}
