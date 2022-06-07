#pragma once


#include<iostream>
#include <chrono>
#include <random>
#include <limits>


namespace superarray {

const float min {-100.999999};
const float max {100.999999};

    int32_t ArraiInit(float* array, const uint32_t size);
    int32_t PrintArray(const float *array, const uint32_t size);
    int32_t PositiveAndNegative(const float *array, const uint32_t size);


    float Random (const float min, const float max);

}

