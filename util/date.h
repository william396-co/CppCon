#pragma once

#include <string>

class Date{
public:
    Date(std::string&& date):m_date{std::move(date)}{}
    Date(std::string const& date): m_date{date}{}
private:
    std::string m_date;
};
