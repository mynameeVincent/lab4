#include"lab.hpp"
#include<iostream>
#include<conio.h>

//#define	StL		kostl
//#define	PseStl	HMStl

enum choice
{
	Exit = 0,

	n_vec = 1,

	n_dat = 2,

	help = 3,

	clean = 4
};

int main()
{
	kostl::bint comand;
	std::cout << "0\t-\tExit\n1\t-\tsort vector\n2\t-\tperson's data\n3\t-\thelp\n4\t-\tclean\n";
	std::cout << "in your cmand ";
	std::cin >> comand;
	while (comand.get_int() != choice::Exit)
	{
		switch (comand.get_int())
		{
			case n_vec:
			{
				unsigned int t;
				std::cout << "input how mach elements do you need ";
				std::cin >> t;
				PseStl::vector<int> ty(t);
				std::cout << "please input your vector\t";
				for (int f = 0; f < ty.size(); f++)
				{
					int rr;
					std::cin >> rr;
					ty[f] = rr;
				}
				for (int f = 0; f < ty.size(); f++)
					std::cout << ty[f] << "\t";
				std::cout << "\n\n";
				ty.Marge_Sort();						//chec it
				for (int f = 0; f < ty.size(); f++)
					std::cout << ty[f] << "\t";
				std::cin.get();
				break;
			}
			case n_dat:
			{
				StL::data test;
				std::cout << test;
				break;
			}
			case clean:
			{
				system("cls");
			}
			case help:
			{
				std::cout <<"0\t-\tExit\n1\t-\tsort vector\n2\t-\tperson's data\n3\t-\thelp\n4\t-\tclean\n" ;
				break;
			}
			default:
			{
				break;
			}
		}
		std::cout << "\nin your cmand ";
		
		std::cin >> comand;
	}
}