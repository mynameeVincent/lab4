#pragma once
#include <iostream>
#include"bint.hpp"
#include"stlstring.h"
namespace StL
{
	class data
	{
		string	First_Name;
		string	Last_Name;
		string	city;
		string	strit;
		kostl::bint	house;
		kostl::bint	flat;
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
			std::cin.get();
			std::cout << "house\t\t";
			std::cin >> house;
			std::cout << "flat\t\t";
			std::cin >> flat;
		}
		friend std::istream& operator>>(std::istream& in, data& tt);
		friend std::ostream& operator<<(std::ostream& in, const data& tt);
	};

	std::istream& operator>>(std::istream& in, data& tt)
	{
		std::cout << "First Name\t";
		in >> tt.First_Name;
		std::cout << "Last Name\t";
		in >> tt.Last_Name;
		std::cout << "city\t\t";
		in >> tt.city;
		std::cout << "strit\t\t";
		in >> tt.strit;
		std::cin.get();
		std::cout << "houce\t\t";
		in >> tt.house;
		std::cout << "flat\t\t";
		in >> tt.flat;
		return in;
	}

	std::ostream& operator<<(std::ostream& in, const data& tt)
	{
		in << "\nFirst Name\t" << tt.First_Name << "\nLast Name\t" << tt.Last_Name << "\ncity\t\t" << tt.city << "\nstrit\t\t" << tt.strit << "\nhouce\t\t" << tt.house << "\nflat\t\t" << tt.flat<<"\n\n";
		return in;
	}
}