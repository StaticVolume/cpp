#include <iostream>
#include <chrono>
#include <random>
#include <typeinfo>
#include <functional>



int GetRandomI(const int min, const int max);
ushort GetRandomUSH(const ushort min, const ushort max);
double GetRandomD(const double min, const double max);

void ChangArrayIFunc(ushort* array, const int size);// функция замены 1 на 0 и 0 на 1 массиве из 0 и 1, задание № 2

void FullArrayStep3(int* array, const int size);// функция запонения с шагом 3 для задания № 3

//Для функции печати  по хорошему надо создавать шаблонную функцию, так как типов массивов много, чтобы зря не перегружать и не нагромождать код
template <typename T>
void PrintArray(const T* array, const int size) ; //Написать функцию которая выводит массив чисел на экран. Параметры функции это сам массив и его размер. Вызвать эту функцию из main.

template<typename T>
void CircleArrayShift(T* array, const int size, const int shift_num); // функция циклического сдвига для массива.

template <typename T>
void FullArray(T* array, const int size, T (*GetRand)(T,T) );

bool CheckBalance(const int* array, const int size);






int main(int argc, char* argv[]) {

   /*Написать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его размер. Вызвать эту функцию из main.*/

    int size {0};
    double* d_array { nullptr };

    do {

        std::cout << "\nEnter size of massive" << std::endl;
        std::cin >> size;

    } while (size == 0 || size < 0);

    d_array = new double[size]{};
    FullArray<double>(d_array, size, GetRandomD);
    PrintArray<double>(d_array, size);


   /***********************************************************************************************************************************************/

   /*Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.*/

    size = 0;
    ushort* i_array { nullptr };

    do {

        std::cout << "\nEnter size of massive" << std::endl;
        std::cin >> size;

    } while (size == 0 || size < 0);

    i_array = new ushort[size]{0};

    FullArray<ushort>(i_array, size, GetRandomUSH);
    PrintArray<ushort>(i_array, size);
    ChangArrayIFunc(i_array, size);
    PrintArray<ushort>(i_array, size);

   /***********************************************************************************************************************************************/

    /* Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.*/

     size = 0;
     int* i3_array {nullptr};

     do {

         std::cout << "\nEnter size of massive" << std::endl;
         std::cin >> size;

     } while (size == 0 || size < 0);

     i3_array = new int[size]{0};

     PrintArray(i3_array, size);
     FullArrayStep3(i3_array, size);
     PrintArray(i3_array, size);

   /***********************************************************************************************************************************************/

   /* Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным), при этом метод должен циклически сместить все элементы массива на n позиций.*/
    size = 10;
    int shift_num {0};
    int* i4_array = nullptr;

    do {
    std::cout << "\nEnter size of massive" << std::endl;
    std::cin >> size;
    std::cout << "\nEnter num of shift : positive to array << n; negative to array >> n.  : " << std::endl;
    std::cin >> shift_num;
    } while ( !std::cin || size == 0 || size < 0 );

    i4_array = new int[size]{0};
    FullArray<int>(i4_array, size, GetRandomI);
    PrintArray(i4_array, size);
    CircleArrayShift<int>(i4_array, size, shift_num);
    PrintArray(i4_array, size);


   /***********************************************************************************************************************************************/
   /*** Написать функцию, которой передается не пустой одномерный целочисленный массив, она должна вернуть истину если в массиве есть место,
    * в котором сумма левой и правой части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1]) → true,
    * checkBalance ([2, 1, 1, 2, 1]) → false, checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||, эти символы в массив не входят.*/

    size = 0;
    int* i5_array = nullptr;

    do {

        std::cout << "\nEnter size of massive" << std::endl;
        std::cin >> size;

    } while (size == 0 || size < 0);

    i5_array = new int[size]{0};

    /*i5_array[0] = 1; // тестовый прогон успешен
    i5_array[1] = 1;
    i5_array[2] = 1;
    i5_array[3] = 2;
    i5_array[4] = 1;*/

    /*i5_array[0] = 10; тестовый прогон успешен
    i5_array[1] = 1;
    i5_array[2] = 2;
    i5_array[3] = 3;
    i5_array[4] = 4;*/

    FullArray<int>(i5_array, size, GetRandomI);
    PrintArray(i5_array, size);
    bool is_balance =  CheckBalance(i5_array, 5);

    if(is_balance) {

         std::cout << "\n..............................................\n" << std::endl;
         std::cout << "array is balanced: " << std::endl;

    }else {

        std::cout << "\n..............................................\n" << std::endl;
        std::cout << "array is not balanced: " << std::endl;

    }

    /*.............................................................................................................................................*/
    delete [] i5_array;
    delete [] i4_array;
    delete [] i3_array;
    delete [] i_array;
    delete [] d_array;
    return 0;
}






bool CheckBalance(const int* array, const int size) {
    bool is_balance { false };
    int summ_from_start { 0 };
    int summ_from_end { 0 };

    for (int count {0}; count < size-1; ++count ) {

         summ_from_start +=array[count];
         summ_from_end = 0;

         for (int c = count + 1; c < size; ++c) {

             summ_from_end+=array[c];
         }

        if(summ_from_start == summ_from_end){
            is_balance = true;
            break;
        }
    }

    return is_balance;
}



void FullArrayStep3(int* array, const int size) {
    array[0] = 1;
    for (int c { 1 }; c < size; ++c ) {
        array[c] = array[c-1] + 3;
    }
}



void ChangArrayIFunc(ushort* array, const int size) {

    for (int c { 0 }; c < size; ++c ) {
        array[c]  = !(array[c]);
    }

}



template <typename T>
void FullArray(T* array, const int size , T (*GetRand) (T,T)) {

    if( typeid(T) == typeid(double) || typeid(T) == typeid(float)  ) {

        const double a = -100.000126834;
        const double b = 100.654548924;

        for (int c { 0 } ; c < size ; ++c) {
            *(array + c) = GetRand(a,b);
        }

    } else if (typeid(T) == typeid(ushort)) {
        const int a = 0;
        const int b = 1;
            for (int c { 0 } ; c < size ; ++c) {
                *(array + c) = GetRand(a,b);
            }
    }else {
        const int a = -100;
        const int b = 100;
            for (int c { 0 } ; c < size ; ++c) {
                 *(array + c) = GetRand(a,b);
            }
    }

}



template <typename  T>
void PrintArray(const T* array, const int size) {

    std::cout << "\n..............................................\n" << std::endl;
     std::cout << "array type : " << typeid(*array).name() << std::endl;
    std::cout << "array size : " << sizeof (array) * size << " byte " <<  std::endl;
    std::cout << "count of array  : " << size << std::endl;
    std::cout << "\n..............................................\n" << std::endl;

    for (int c { 0 } ; c < size ; ++c) {
             std::cout << "count of element : " << c+1 << "   number : " << *(array + c) << std::endl;
        }
}



template<typename T>
void CircleArrayShift(T* array,  const int size, const int shift_num) {

    T buffer { 0 };
    if (shift_num > 0) {
        std::cout << "\nYou choise : array  << "  << shift_num << "\n" << std::endl;

        for (int shift_size{ 0 }; shift_size < shift_num ; ++shift_size){

             buffer = array[0];

                for (int c { 0 } ; c < size-1 ; ++c ){

                        array[c] = array [c+1];

               }
            array[size-1] = buffer;
        }

     } else if (shift_num < 0){

       std::cout << "\nYou choise : array  >> "  << abs(shift_num) << "\n" << std::endl;

       for (int shift_size{ 0 }; shift_size < abs(shift_num) ; ++shift_size) {

            buffer = array[size - 1];

                for (int c { size-1 } ; c > 0 ; --c ){

                    array[c] = array [c-1];

                }

            array[0] = buffer;
        }

    } else {
        std::cout << "Sorry, no shift" << std::endl;
     }
  }




int GetRandomI( const int min, const int max) {

    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937_64 rand_gen(seed);
    std::uniform_int_distribution<int> dis(min,max);
    return  dis(rand_gen);

}

double GetRandomD(const double min, const double max) {

    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937_64 rand_gen(seed);
    std::uniform_real_distribution<double> dis(min,max);
    return  dis(rand_gen);

}

ushort GetRandomUSH(const ushort min,const ushort max) {

    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937_64 rand_gen(seed);
    std::uniform_int_distribution<ushort> dis(min,max);
    return  dis(rand_gen);

}
