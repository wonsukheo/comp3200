#include "Lab2.h"

#include <iomanip>

using namespace std;

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		out << setw(12) << "oct" << setw(11) << "dec" << setw(9) << "hex" << endl;

		out << setw(13) << setfill('-') << ' ' << setw(11) << setfill('-')
			<< ' ' << setw(9) << setfill('-') << '\n';

		out << setfill(' ');

		int num;
		string discard;
		
 		while (true)
		{
			in >> num;

			if (!in.fail())
			{
				out << setw(12) << oct << num << setw(11) << dec << num << setw(9) << hex << uppercase << num << endl;
				continue;
			}

			if (in.eof())
			{
				break;
			}

			in.clear();
			in >> discard;			
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		float num;
		float max = LLONG_MIN;
		string discard;

		while (true)
		{
			in >> num;

			if (!in.fail())
			{
				out << setw(5) << ' '
					<< setw(15) << showpos << showpoint << fixed << setprecision(3) << internal << num << endl;

				if (num > max)
				{
					max = num;
				}

				continue;
			}

			if (in.eof())
			{
				out << setw(5) << left << "max:"
					<< setw(15) << showpos << showpoint << fixed << setprecision(3) << internal << max << endl;

				break;
			}

			in.clear();
			in >> std::ws;

			in >> discard;
		}
	}
}