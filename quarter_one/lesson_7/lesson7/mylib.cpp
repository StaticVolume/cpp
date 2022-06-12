#include "mylib.h"

namespace superarray {



int32_t ArraiInit(float* array, const uint32_t size) {


    if(array == nullptr || size == 0) {

        std::cerr << "Sory, Array is not exist or empty! " << std::endl;
        return -1;
    }



    for (uint32_t count {0}; count < size;  ++count) {

       *(array+count) = Random(min,max);
    }

    return 0;
}




int32_t PrintArray(const float *array, const uint32_t size) {

    if(array == nullptr || size == 0) {

        std::cerr << "Sory, Array is not exist or empty! " << std::endl;
        return -1;
    }

    std::cout << "\nMassive type : " << typeid (*array).name() << std::endl;

    std::cout << "\nMassive size : " << size << std::endl;


    for (uint32_t count {0}; count < size;  ++count) {

        std::cout << " Count : " << count+1 << " number : " << *(array+count) << std::endl;
    }

return 0;
}




int32_t PositiveAndNegative(const float *array, const uint32_t size) {

    uint32_t positive_count {0};
    uint32_t negative_count {0};

    if(array == nullptr || size == 0) {

        std::cerr << "Sory, Array is not exist or empty! " << std::endl;
        return -1;
    }


    for (uint32_t count {0}; count < size;  ++count) {

        if( *(array+count) > 0 ) { ++positive_count; }  else  { ++negative_count; }

    }

    std::cout << "\nMassive positive counts : " << positive_count << std::endl;

    std::cout << "\nMassive negative counts : " << negative_count << std::endl;


return 0;
}




float Random (float min, float max) {

        if ( min > max) { std::swap( min, max ); }

        auto seed = std::chrono::system_clock::now().time_since_epoch().count(); // создание зерна случайной последовательности
        std::mt19937_64 rand_generator(seed); // создание случайной последовательности на основании зерна
        std::uniform_real_distribution<float> dis(min, max); //создаем распредение в диапазоне от min до max

        return dis(rand_generator); // вызываем как функцию передавая последовательность для получения рандомного числа от min до max


}


}

