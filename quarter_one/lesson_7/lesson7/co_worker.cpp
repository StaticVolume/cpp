#include "co_worker.h"

Co_Worker::Co_Worker (std:: string name, std::string last_name, std:: string department, uint32_t passport_serial,
           uint32_t passport_number, uint32_t experience, Gender gender, uint32_t age): first_name{name},last_name{last_name}, department{department},
            passport_serial{passport_serial}, passport_number{passport_number}, experience{experience}, gender{gender}, age{age}  {

    size = SizeOfCo_Worker(*this);

}



size_t  Co_Worker::SizeOfCo_Worker(const Co_Worker& worker){

    return  sizeof(worker);
}

int32_t Co_Worker::Print(std::ostream& stream) {

    stream << "===========================================\n" << std::endl;

    stream << " Size :" << size << std::endl;
    stream << " First name : " << first_name << std::endl;
    stream << " Last name: " << last_name << std::endl;
    stream << " Department : " << department << std::endl;
    stream << " Passport serial : " << passport_serial << std::endl;
    stream << " Passport number : " << passport_number << std::endl;
    stream << " Work Experience" << experience << std::endl;
    stream << " Age: " << age << std::endl;
    stream << " Gender: " << gender << std::endl;

    return 0;
}

