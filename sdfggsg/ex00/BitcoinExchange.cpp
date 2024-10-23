#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}


BitcoinExchange::~BitcoinExchange(){}


void BitcoinExchange::double_it_and_give_it_the_next_person(std::string date,double value)
{
    bool flag;
    std::map<std::string, float>::iterator it = this->csvRead.begin();

    while (it != this->csvRead.end())
    {
        if (it->first == date)
        {
            std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
            flag = false;
            break;
        }
        it++;
        if (it == this->csvRead.end())
            flag = true;
    }
    if (flag)
    {
        it = this->csvRead.lower_bound(date);
        it--;
        std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
    }
}

void BitcoinExchange::parser(std::string first, double second, int min_year)
{
    int year;
    int month;
    int day;
    int control;
    double value;

    year = atoi(first.substr(0,4).c_str());
    month = atoi(first.substr(5,2).c_str());
    day = atoi(first.substr(8,10).c_str());
    value = second;
    control = 0;

    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        control = 1;
    if(((year > 2022) || (year < min_year)) || ((month > 12) || (month < 1)) || ((day > 31) || (day < 1)))
    {
        std::cout << "bad input => " << first.substr(0,10) << std::endl;
    }
    else if(day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
    {
            std::cout << "bad input => " << first.substr(0,10) << std::endl;
    }
    else if(month == 2 && control == 1 && day > 29)
    {
        std::cout << "bad input => " << first.substr(0,10) << std::endl;
    }
    else if(month == 2 && control == 0 && day > 28)
    {
        std::cout << "bad input => " << first.substr(0,10) << std::endl;
    }
    else if(value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
    }
    else if(value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
    }
    else
        double_it_and_give_it_the_next_person(first.substr(0,10),value);
}

int BitcoinExchange::min_year()
{
	int min_date = 2024;
	std::map<std::string, float>::iterator it;

	for (it = this->csvRead.begin(); it != this->csvRead.end(); it++)
		if (min_date > std::atoi(it->first.substr(0,4).c_str()))
			min_date = std::atoi(it->first.substr(0,4).c_str());
	return (min_date);
}

void BitcoinExchange::exchange(const char * arg, int min_year)
{
	std::ifstream file(arg);
    std::string databaseFileLine;
    std::getline(file, databaseFileLine);

    std::map<std::string, double> dataMap;

    if(databaseFileLine != "date | value")
    {
        std::cout << "Error: bad input " << std::endl;
        return ;
    }
    while (std::getline(file, databaseFileLine))
    {
        if(databaseFileLine[4] != '-'||  databaseFileLine[7] != '-' || databaseFileLine[11] != '|')
        {
            std::cout << "Error: bad input " << std::endl;
            break ;
        }
        if(databaseFileLine.size() > 11)
        {
			double value = atof((databaseFileLine.substr(13)).c_str());
            parser(databaseFileLine.substr(0, 10), value, min_year);
        }
        else
            std::cout << "Error: bad input => " << databaseFileLine.substr(0, 10) << std::endl;


    }
    file.close();
}

void BitcoinExchange::data_read()
{
    std::string databaseFileLine;
    std::map<std::string, double> dataMap;


    std::ifstream file("data.csv");
    std::getline(file, databaseFileLine);


    while (std::getline(file, databaseFileLine))
    {
        float value = atof((databaseFileLine.substr(11)).c_str());
		this->csvRead[databaseFileLine.substr(0, 10)] = value;
    }
    file.close();

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &arg)
{
	(void)arg;
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
	(void)cpy;
}