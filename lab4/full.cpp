#include"full.hpp"
namespace kostl
{
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