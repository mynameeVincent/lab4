#pragma once
#include"string.h"
#include"bint.hpp"
namespace kostl
{
	class data
	{
		string	First_Name;
		string	Last_Name;
		string	city;
		string	strit;
		bint	house;
		bint	flat;
	public:
		data()
		{
			std::cout << "First_Name\t";
			std::cin >> First_Name;
			std::cout << "Last_Name\t";
			std::cin >> Last_Name;
			std::cout << "city\t\t";
			std::cin >> city;
			std::cout << "strit\t\t";
			std::cin >> strit;
			std::cout << "house\t\t";
			std::cin.get();
			std::cin >> house;
			std::cout << "flat\t\t";
			std::cin >> flat;
		}
		friend std::istream& operator>>(std::istream& in, data& tt);
		friend std::ostream& operator<<(std::ostream& in, const data& tt);
	};
}