#include"bint.hpp"
namespace kostl 
{
	std::istream& operator>>(std::istream& in, bint& tt)
	{
		tt.data = 0;
		char* hoi = new char[21]{};
		in.getline(hoi,20,10);
		int N=1;
		for (int f = 19; f >= 0; f--)
		{
			if (hoi[f] >= '0' && hoi[f] <= '9')
			{
				tt.data += (hoi[f] - 48) * N;
				N*=10;
			}
		}
		return in;
	}
	std::ostream& operator<<(std::ostream& in, const bint& tt)
	{
		in << tt.data;
		return in;
	}
	bint::bint()
	{
		data = 0;
	}
}