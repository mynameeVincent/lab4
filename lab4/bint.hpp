#pragma once
#include<iostream>
namespace kostl
{
	class bint
	{
		int data;
	public:
		bint();
		int get_int()
		{
			return this->data;
		}
		friend std::istream& operator>>(std::istream& in, bint& tt);
		friend std::ostream& operator<<(std::ostream& in, const bint& tt);
	};
}