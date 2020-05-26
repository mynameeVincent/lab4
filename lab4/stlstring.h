#pragma once
#include<string>
namespace StL
{
	class string
	{
	protected:
		std::string *st;
		void god();
	public:
		int Get_N()
		{
			return (*st).size();
		}
		string(const int& N = 10)
		{
			st = new std::string;
		}
		~string()
		{
			delete st;
			st = nullptr;
		}
		char& operator[](int n)
		{
			return (*st)[n];
		}
		friend std::istream& operator>>(std::istream& in, string& tt);
		friend std::ostream& operator<<(std::ostream& in, const string& tt);
	};

	std::istream& operator>>(std::istream& in, string& tt)
	{
		in >> *tt.st;
		int ni = 0;
		for (int f = 0; f < tt.st->size(); f++)
		{
			if (tt.st->at(f) >= 'a' && tt.st->at(f) <= 'z' || tt.st->at(f) >= 'A' && tt.st->at(f) <= 'Z' || tt.st->at(f) == '-')
				tt.st->at(f - ni) = tt.st->at(f);
			else
				ni++;
		}
		tt.st->resize(tt.st->size() - ni + 1);
		tt.st->at(tt.st->size() - 1) = 0;

		char now = 0, pre = 0;
		for (int f = 0; f < tt.st->size(); f++)
		{
			pre = now;
			now = tt.st->at(f);
			if ((pre != 0 && pre != '-') && now >= 'A' && now <= 'Z' && now != '-')
			{
				tt.st->at(f) = char(now + 32);
			}

			if (((pre == '\0') || pre == '-') && (now >= 'a' && now <= 'z'))
			{
				tt.st->at(f) = char(now - 32);
			}
		}
		tt.st->at(tt.st->size() - 1) = 0;
		return in;
	}

	std::ostream& operator<<(std::ostream& in, const string& tt)
	{
		for (int f = 0; f < tt.st->size(); f++)
			in << tt.st->at(f);
		return in;
	}
}