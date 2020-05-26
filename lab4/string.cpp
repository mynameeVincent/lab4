#include "string.h"
namespace kostl
{
	string::string(const int& N)
	{
		this->n = 0;
		if (N > 0)
		{
			this->N = N;
		}
		else
		{
			this->N = 10;
		}
		this->str = new char[this->N]{};
	}

	string::~string()
	{
		delete[] str;
	}

	std::ostream& operator<<(std::ostream& son, const string& tt)
	{
		for (int f = 0; tt.str[f] != 0; f++)
			son << tt.str[f];
		return son;
	}
	
	int string::Get_N()
	{
		return N;
	}
	
	void string::god()
	{
		int ni=0;
		for (int f = 0; str[f]!=0; f++)
		{
			if (str[f] >= 'a' && str[f] <= 'z' || str[f] >= 'A' && str[f] <= 'Z' || str[f] == '-')
				str[f - ni] = str[f];
			else
				ni++;
		}
		this->n -= ni;
		str[this->n] = 0;


		char now=0, pre=0;
		for (int f = 0; f < n; f++)
		{
			pre = now;
			now = str[f];
			if ((pre != 0 && pre != '-') && now >= 'A' && now <= 'Z' && now != '-')
			{
				str[f] = char(now + 32);
			}
			
			if (((pre == '\0') || pre == '-') && (now >= 'a' && now <= 'z'))
			{
				str[f] = char(now - 32);
			}
		}
		str[n] = 0;
	}
	
	std::istream& operator>>(std::istream& sin, string& tt)
	{
		char* hi = new char[tt.N]{};
		tt.n = 0;
		delete tt.str;
		tt.str = hi;
		char symb = 0;
		while (true)
		{
			sin.get(symb);
			if (symb == ' ' || symb == 10 || symb == 13)
				break;
			if (!(tt.N > tt.n))
			{
				tt.big();
			}
			tt.str[tt.n] = symb;
			tt.n++;
		}
		tt.god();
		return sin;
	}
	
	void string::big()
	{
		this->N *= 2;
		char* yo = new char[this->N]{};
		for (int f = 0; f < n; f++)
		{
			yo[f] = this->str[f];
		}
		delete this->str;
		str = yo;
		yo = nullptr;
	}
	
	char& string::operator[](int n)
	{
		return this->str[n];
	}
}