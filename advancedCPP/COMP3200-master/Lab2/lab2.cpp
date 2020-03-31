#include <iomanip>
#include <limits>
#include "lab2.h"

using namespace std;

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		out << setw(12) << right << "oct"
			<< setw(11) << right << "dec"
			<< setw(9) << right << "hex" << "\n"
			<< setfill('-') << setw(12) << "" << " "
			<< setw(10) << "" << " "
			<< setw(8) << "" << "\n";
		unsigned int temp;

		in >> temp;
		if (in.fail())
		{
			in.clear();
			in.ignore(LLONG_MAX, ' ');
		}
		else
		{
			out << setfill(' ')
				<< setw(12) << right << oct << temp
				<< setw(11) << right << dec << temp
				<< setw(9) << right << uppercase << hex << temp << "\n";
		}

		while (!in.eof())
		{
			in >> temp;
			if (in.fail())
			{
				in.clear();
				in.ignore(LLONG_MAX, ' ');
			}
			else
			{
				out << setfill(' ')
					<< setw(12) << right << oct << temp
					<< setw(11) << right << dec << temp
					<< setw(9) << right << uppercase << hex << temp << "\n";
			}
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		float temp;
		float max = std::numeric_limits<float>::lowest();;
		while (!in.eof())
		{
			in >> temp;
			if (in.fail())
			{
				in.clear();
				in.ignore(LLONG_MAX, ' ');
			}
			else
			{
				if (temp > max)
				{
					max = temp;
				}

				out << setfill(' ') << setprecision(3) << fixed;
				out << setw(5) << right << "";
				out << setw(15) << internal << showpos << temp << endl;
			}
		}

		out << "max: " << setw(15) << internal << showpos << max << endl;
	}
}

