#include <iostream>
#include <fstream>
#include <math.h>
#include "mylib.h"
#include "co_worker.h"

 /*#define SwapINT(A,B)  A  =  ( (A) ^ (B) ); \ через xor не получается, часть переменных присваиваются в 0. Такая же история при swap через сумму.
                        B = ( (A) ^ (B) ); \
                         A = ( (A) ^ (B) );*/


#define SwapINT(A,B, TEMP)  ( (TEMP) = (A) ); ( (A) = (B) );( (B) = (TEMP) );
#define ARRAYSIZE S

//Функции написаны, хотя можно было использовать шаблоны в mylib и не зависеть от типа, но я все же решил их написать. Но по хорошему надо писать шаблоны.
// Так же я не стал удалять закоментированный код, так как ещё могут возникать ошибки.

uint32_t GetNumber(bool is_unsigned = true, bool arr_size = false);// получаем число
int32_t ArrayInit(int32_t* arr, const uint32_t size);// запонение массива с клавиатуры
int32_t QuickSort(int32_t* arr, const uint32_t size); // быстрая сортировка (рекурсивная версия)
int32_t PrintArr(int32_t* arr, const uint32_t size);

int32_t main(int32_t argc, char** argv)
{
    /*Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h)
     *  во втором модуле mylib объявить 3 функции: для инициализации массива (типа float),
     *  печати его на экран и подсчета количества отрицательных и положительных элементов.
     *  Вызывайте эти 3-и функции из main для работы с массивом.*/

    /*Сделайте задание 1 добавив свой неймспейс во втором модуле (первое задание тогда можно не делать).*/

    float* arr {nullptr};

    uint32_t size = GetNumber(true, true);

    arr = new float [size];

    superarray::ArraiInit(arr, size);
    superarray::PrintArray(arr, size);
    superarray::PositiveAndNegative(arr, size);



    /*=============================================================================================================================================================================*/

    std::cout << "\n=========================================================================================\n" << std::endl;

    /*Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число (введенное с клавиатуры)
     *  в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно) и возвращает true или false,
     *  вывести на экран «true» или «false». 3. Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define.
     *  Инициализируйте его через ввод с клавиатуры. Напишите для него свою функцию сортировки (например Пузырьком).
     *  Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.*/


    #define CALCULATE(A,B) (((A >= 0) && (A < B)) ? true : false)

    uint32_t a {GetNumber()};
    uint32_t b {GetNumber()};

    std::cout << std::boolalpha << CALCULATE( a , b ) << std::endl;

    #undef CALCULATE

   uint32_t S {GetNumber(true,true) };
    //uint32_t S = 10;
   int32_t* iarray = new int32_t [ARRAYSIZE];

   ArrayInit(iarray, ARRAYSIZE);
   /*iarray[0] = -235;
   iarray[1] = 12;
   iarray[2] = -25;
   iarray[3] = -5;
   iarray[4] = 23;
   iarray[5] = 35;
   iarray[6] = -1;
   iarray[7] = 125;
   iarray[8] = 250;
   iarray[9] = 1;*/

    QuickSort(iarray, ARRAYSIZE);
    PrintArr(iarray, ARRAYSIZE);

    /*=============================================================================================================================================================================*/

    std::cout << "\n=========================================================================================\n" << std::endl;

    /*Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое выравнивание с
     * помощью директивы pragma pack. Выделите динамически переменную этого типа. Инициализируйте ее.
     * Выведите ее на экран и ее размер с помощью sizeof. Сохраните эту структуру в текстовый файл.*/

      Co_Worker worker1("Andrey", "Ji", "IT", 0510442356, 1223245632, 5, Mail, 32);
      worker1.Print();
      std::ofstream out_file;
      out_file.open("out.txt");

      if (!out_file.is_open()) {

          std::cerr << "Sorry cant open the file" << std::endl;
      }

      worker1.Print(out_file);


    out_file.close();
    delete [] arr;
    delete [] iarray;
    return 0;
}



uint32_t GetNumber(bool is_unsigned, bool arr_size) {
    int64_t res; // так как uint32_t априори не может быть отрицательным, то проверить его на отрицательность невозможно,
                 //так как любое отрицательное число будет вызывать переполнение и циклический переход на очень большое положительное число,
                 // поэтому было принято решение создавать переменную знакового типа с большим в 2 раза размером, чтобы можно было уместить все значение в данном случае uint32_t
                // и с возможностью проверки на знаковость.

    while(true) {
        if (arr_size == true) {
        std::cout << "Please enter  the number(or size of array) : ";
        } else {
            std::cout << "Please enter  the number: ";
        }

        std::cin >> res;

        if (std::cin.fail() || res == 0) {

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        } else { break;}

    };


    return (is_unsigned) ? static_cast<uint32_t>(std::abs((res))) : static_cast<int32_t>(res);
}


int32_t ArrayInit(int32_t* arr, const uint32_t size) {

   if (arr == nullptr || size == 0) {

       std::cerr << "Sorry array is not exist of size = 0" << std::endl;
       return -1;
   }

   for (int32_t count {0}; count < size; ++count) {

        *(arr + count) = GetNumber(false, false);
   }

 return 0;
}

int32_t QuickSort(int32_t* arr, const uint32_t size) {

    if (arr == nullptr || size == 0) {

        std::cerr << "Sorry array is not exist of size = 0" << std::endl;
        return -1;
    }

    uint32_t first{0};
    uint32_t last = size -1;
    int32_t mid = arr[size/2];
    int32_t temp{0};

    do {

        for(; arr[first] < mid; ++first);
        for(; arr[last] > mid; --last);

        if (first <= last ) {

            SwapINT(arr[first], arr[last],temp);
            //std::swap(arr[first], arr[last]);

            ++first;
            --last;
        }

    }while (first <= last);

    if (last > 0) {

        QuickSort(arr, last+1);
    }
    if (first < size-1) {

            QuickSort(&arr[first], size-first);
    }

    return 0;
}


int32_t PrintArr(int32_t* arr, const uint32_t size) {

    if (arr == nullptr || size == 0) {

        std::cerr << "Sorry array is not exist of size = 0" << std::endl;
        return -1;
    }

    for (uint32_t count {0} ; count < size; ++count) {

        std::cout <<"\nCount : " << count << " array[count] = " << arr[count] << std::endl;
    }

    return 0;
}
