#include <iostream>
#include <limits>
#include <string>
#include <chrono>
#include <random>
#include <fstream>
#include <filesystem>

const uint32_t char_rand_min { 30 };
const uint32_t char_rand_max { 127 };
const uint32_t rand_min { 0 };
const uint32_t rand_max { 100 };


int32_t CreateFullFile(const std::string& filename,  bool create_random  = true  , std::string write_str = "" );
std::string ReadToStrFromFile(const std::string filename);
uint32_t SizeOfArray();
int32_t FullArray(uint32_t* array, const uint32_t size, bool israndom = false );
int32_t ExerciseOne();
int32_t ExerciseTwo();
int32_t ExerciseThree();
int32_t ExerciseFour();
int32_t ExerciseFive();
int32_t PrintArray(const uint32_t* array, const uint32_t size);
uint32_t  GetRandom( const uint32_t min, const uint32_t max);
int32_t CreateNewFileFromTwoAnother(const std::string& filename_one, const std::string& filename_second, const std::string filename_result);


int32_t main() {

  /*Выделить в памяти динамический одномерный массив типа int. Размер массива запросить у пользователя.
   * Инициализировать его числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 ...
   * Вывести массив на экран. Не забыть освободить память. =) Разбить программу на функции.*/

    //ExerciseOne();


  /*Динамически выделить матрицу 4х4 типа int. Инициализировать ее псевдослучайными числами через функцию rand.
   * Вывести на экран. Разбейте вашу программу на функции которые вызываются из main.*/

    //ExerciseTwo();

  /*Написать программу, которая создаст два текстовых файла (*.txt), примерно по 50-100 символов в каждом
   * (особого значения не имеет с каким именно содержимым). Имена файлов запросить у польлзователя.*/

    //ExerciseThree();

 /* Написать функцию, «склеивающую» эти файлы в третий текстовый файл (имя файлов спросить у пользователя).*/

   // ExerciseFour();


 /*  Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы
  *   слово в указанном пользователем файле (для простоты работаем только с латиницей). Используем функцию find которая есть в строках std::string. */

    ExerciseFive();
    return 0;

}


/*===========================================================================================================================================*/

 uint32_t  GetRandom( const uint32_t min, const uint32_t max) {

    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937_64 rand_gen(seed);
    std::uniform_int_distribution<uint32_t> dis(min,max);
    return  dis(rand_gen);

}

/*===========================================================================================================================================*/

uint32_t SizeOfArray() {

    int64_t  size{0};


     while (true) {

         std::cout << "Enter size of array please : ";
         std::cin >> size;

            if ( (size <= 0) || (size > std::numeric_limits<uint32_t>::max()) || (std::cin.fail())  ) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

            } else {     

                   return static_cast<uint32_t>(size);
            }
     }

}


/*===========================================================================================================================================*/

int32_t FullArray(uint32_t* array, const uint32_t size, bool israndom) {

    if ( (!array) || size == 0 ) {

        std::cerr << "Exeprion, array or size not exists" << std::endl;
        return -1;
    }

    if (!israndom) {

        array[0] = 1;

            for (int count{1}; count < size; ++count) {

                array[count] = array[count -1 ]<<1;
            }

    } else {

        for (int count{0}; count < size; ++count) {

            array[count] = GetRandom( rand_min, rand_max);
        }

    }
       return 0;
}


/*===========================================================================================================================================*/

int32_t PrintArray(const uint32_t* array, const uint32_t size) {

    if((!array) || size == 0) {

        std::cerr << "Exeprion, array or size not exists" << std::endl;
        return -1;
    }

    for (int count{0}; count < size; ++count) {

        std::cout << "Array count : " << count << " number : " << *(array+count) << std::endl;
    }

return 0;
}



std::string GetNameOfFile(){

    std::string name;
    std::cout << "Please Enter the  opened filename : "  << name << std::endl;

    do {

    std::cin>>name;

   } while (name.empty());


   return name;
}


int32_t CreateFullFile(const std::string& filename, bool create_random, std::string write_str) {

    std::ofstream File;


    File.open(filename);

    if (!File.is_open()) {

        std::cerr << "Sorry, cant open the file : " << filename << std::endl;

    }

    if (create_random) {


        for (uint32_t count {0}; count < rand_max; ++count) {

            File << static_cast<char>(GetRandom(char_rand_min, char_rand_max));
        }

    } else {

                if (write_str.empty()) {
                    std::cerr << "Sorry, Buffer string is empty, nothing write to the file" << std::endl;
                }

           File << write_str;

    }

    //File << '\n' ;
    File.close();

    return 0;
}

std::string ReadToStrFromFile(const std::string filename) {

    std::string res;
    std::ifstream File(filename);


    if (std::filesystem::exists(filename)) {

        if (!File.is_open() ) {

            std::cerr << "Sorry, cant open the file : " << filename <<  std::endl;
            exit(-1);

         }

        while(!File.eof()) {

          getline(File, res);
          File.ignore('\n');
        }

        File.close();

    } else {

        std::cerr << "Sory file is not exists, we reate new  file : " << filename << " whis random phrases " << std::endl;

        CreateFullFile(filename);
        res += ReadToStrFromFile(filename);

    }

    return res;
}



int32_t CreateNewFileFromTwoAnother(const std::string& filename_one, const std::string& filename_second, const std::string filename_result) {

    std::string buffer;

    CreateFullFile(filename_one);
    CreateFullFile(filename_second);

    buffer +=  ReadToStrFromFile(filename_one);
    buffer +=  ReadToStrFromFile(filename_second);

    CreateFullFile(filename_result, false, buffer);

    return 0;
}

/*===========================================================================================================================================*/

int32_t ExerciseOne() {

    std::cout << "\nExercise One stated " << std::endl;

    uint32_t size {SizeOfArray()};
    uint32_t* arr = new (std::nothrow) uint32_t[size]{1};

    if(!arr){

        std::cout << "Sorry cant create array, BAD_ALLOC EXEPTION" << std::endl;
        return -1;
    }

    FullArray(arr, size);
    PrintArray(arr, size);

    delete [] arr;

   std::cout << "Exercise One finish \n" << std::endl;

    return 0;
}

/*===========================================================================================================================================*/

int32_t ExerciseTwo() {

    std::cout << "\nExercise Two stated " << std::endl;

    uint32_t wsize{SizeOfArray()};
    uint32_t hsize{SizeOfArray()};

    uint32_t** arr = new (std::nothrow) uint32_t* [hsize]{nullptr};


    if(!arr){

        std::cout << "Sorry cant create array, BAD_ALLOC EXEPTION" << std::endl;
        return -1;
    }


    for(uint32_t arr_size {0}; arr_size < hsize; ++arr_size) {

        arr[arr_size] = new (std::nothrow) u_int32_t[wsize];

        if(!arr[arr_size]){

            std::cout << "Sorry cant create array, BAD_ALLOC EXEPTION" << std::endl;
            return -2;
        }

        FullArray(arr[arr_size], wsize, true);
        PrintArray(arr[arr_size], wsize);

        delete [] arr[arr_size];
    }

  delete [] arr;

  std::cout << "Exercise Two finish \n" << std::endl;
    return 0;
}

/*===========================================================================================================================================*/

int32_t ExerciseThree() {

    std::cout << "\nExercise Three stated " << std::endl;


    std::string first_filename { GetNameOfFile() };
    std::string second_filename { GetNameOfFile() };

    CreateFullFile(first_filename);
    CreateFullFile(second_filename);


    std::cout << "Exercise Three finish\n " << std::endl;

    return 0;
}


/*===========================================================================================================================================*/

int32_t ExerciseFour() {

     std::cout << "\nExercise Four stated " << std::endl;


    std::string first_filename { GetNameOfFile() };
    std::string second_filename { GetNameOfFile() };

    std::string third_res_strig { GetNameOfFile() };


    CreateNewFileFromTwoAnother(first_filename,  second_filename , third_res_strig);


     std::cout << "Exercise Four finish\n" << std::endl;


    return 0;
}

/*===========================================================================================================================================*/

int32_t ExerciseFive() {

    std::cout << "\nExercise Four stated " << std::endl;

    std::string find_phrase;
    std::string file_buffer;

    do {

      std::cout << "Please enter the find_phrase : ";
      std::cin >> find_phrase;
      std::cout << std::endl;

    } while(find_phrase.empty() || find_phrase == " ");

    std::string filename { GetNameOfFile() };


    file_buffer += ReadToStrFromFile(filename) ;

    if (file_buffer.find(find_phrase) != std::string::npos) {

        std::cout << "We find  " << find_phrase << " in " << filename << std::endl;

    } else {

        std::cout << "Sorry, we cant find the phrase" << std::endl;
    }


     std::cout << "Exercise Four finish\n" << std::endl;

    return 0;
}
