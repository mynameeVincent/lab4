#pragma once
#include<iostream>

namespace kostl
{
	class string
	{
		char* str;
		int N;
		int n;
		void big();
		void god();
	public:
		int Get_N();
		string(const int &N = 10);
		~string();
		char& operator[](int n);
		friend std::istream& operator>>(std::istream& in, string& tt);
		friend std::ostream& operator<<(std::ostream& in, const string& tt);
	};

}
