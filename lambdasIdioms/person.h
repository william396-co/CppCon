#pragma once

#include <vector>
#include <string>

#include "../util/print.h"
#include "../util/date.h"

struct Person
{

    Person(std::string name, std::string date)
        : name{std::move(name)},
          dateOfBirth{std::move(date)}{
        }
    std::string name;
    Date dateOfBirth;
};

inline void test_sort(){
    println(__PRETTY_FUNCTION__);


    std::vector<Person> people = {
        {"John Doe", "1953-02-25"},
        {"Vasiliy Pupkin", "1986-04-26"},
        {"Erika Musterman","1964-08-12"}
    };

    std::sort(people.begin(), people.end(), [](Person const& lhs, Person const& rhs){
            return lhs.name < rhs.name;
            });
}
