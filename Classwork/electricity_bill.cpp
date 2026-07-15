#include "electricity_bill.h"
#include <iostream>
#include <stdexcept>
#include <random>
#include <format>
using namespace std;
	void electricity_bill::setMnths(std::span<const double> d)
	{
		if (d.size() < 12)
		{
			int i = 0;
			for (double val : d)
			{
				setMnthUsage(i, val);
				i++;
			}
		}
		else
			for (int i = 0;i < 12;i++)
				setMnthUsage(i, d[i]);
	}
	void electricity_bill::prntMnths()
	{
		cout << "year " << getYear() << "\nusage:" << endl;
		for (int j = 0;j < 12;j++)
			cout << "month " << j + 1 << " = " << format("{:>5.2f}", getMnthUsage(j)) << "; ";
		cout << endl;
	}
	void electricity_bill::setMnthUsage(int mnth, double usage)
	{
		if (mnth < 0 || mnth>11) 
			throw exception("invalid value: month");
		if (usage >= 0)
		{
			mnthUsage[mnth] = usage;
			return;
		}
		throw exception("invalid value: usage");
	};
	double electricity_bill::getMnthUsage(int mnth)
	{
		if (mnth > 11 || mnth < 0)
			throw exception("invalid value: month");
		if (mnthUsage[mnth]>=0)
		return mnthUsage[mnth];
		throw exception("usage not set");
	};
	double electricity_bill::getMnthUsage()
	{
		if (mnthUsage[0] >= 0)
			return mnthUsage[0];
		throw exception("usage not set");
	};
	void electricity_bill::setSaleRate(double sr)
	{
		if (sr > 0)
		{
			saleRate = sr;
			return;
		}
		throw exception("invalid value: sale rate");
	};
	double electricity_bill::getSaleRate()
	{
		if (saleRate>0)
		return saleRate;
		throw exception("sale rate not set");
	};
	void electricity_bill::setYear(int yr)
	{
		if (yr >= 1890)
		{
			year = yr;
			return;
		}
		throw exception("invalid value: year");
	};
	int electricity_bill::getYear()
	{
		if (year >= 1890)
		return year;
		throw exception("year not set");
	};
	double electricity_bill::sumPay()
	{
		double sum=0;
		double sr=saleRate;
		if(sr>0)
		{
			for (int i = 0;i < 12;i++)
			{
				if (mnthUsage[i] >= 0)
					sum += mnthUsage[i] * sr;
				else if (i > 0)
					return sum;
				else return -1;
			}
			return sum;
		}
				
		return -1;
	};
	double electricity_bill::avrgMnthUsage()
	{
		double sum = 0;
		for (int i = 0;i < 12;i++)
		{
			if (mnthUsage[i] >= 0)
				sum += mnthUsage[i];
			else if (i > 0)
				return sum/i;
			else return -1;
		}
		return sum / 12;
	};
	electricity_bill::electricity_bill()
	{
		if (mnthUsage == nullptr) mnthUsage = new double[12];
		for (int i = 0; i < 12; i++) mnthUsage[i] = -1;
		year = -1;
		saleRate = -1;
	};
	electricity_bill::electricity_bill(int yr, double sr)
	{ 
		setYear(yr);
		setSaleRate(sr);
		int mnth = 0;
		double usage = -1;
		bool cond = true;
		cout << "input negative number to ignore remaining elements;" << endl;
		if (mnthUsage == nullptr) mnthUsage = new double[12];
			while(cond&&mnth<12)
			{
				cout<<"input usage for "<<mnth+1<<" month: ";
				cin >> usage;
				if (usage >= 0)
				{
					setMnthUsage(mnth, usage);
					mnth++;
				}
				else cond = false;
			}
			while (mnth < 12)
			{
				mnthUsage[mnth] = -1;
				mnth++;
			}
	};
	electricity_bill::electricity_bill(double firstUsg, int yr, double sr)
	{
		setYear(yr);
		setSaleRate(sr);
		if (mnthUsage == nullptr) mnthUsage = new double[12];
		setMnthUsage(0,firstUsg);
		for (int i = 1;i < 12;i++)
			mnthUsage[i] = -1;
	};
	electricity_bill::electricity_bill(time_t t)
	{
		random_device frnd;
		mt19937 gen(frnd());
		uniform_int_distribution d(0, 1889);
		setYear(d(gen) + 1890);
		setSaleRate(d(gen) / 100.0);
		if (mnthUsage == nullptr) mnthUsage = new double[12];
		for (int i = 0;i < 12;i++)
			setMnthUsage(i, d(gen) / 100.0);
		/*srand(t)
		setYear(rand() % 1890 + 1890);
		setSaleRate((rand() % 1890) / 100.0);
		if (mnthUsage == nullptr) mnthUsage = new double[12];
		for (int i = 0;i < 12;i++)
			setMnthUsage(i, (rand() % 1890) / 100.0);*/
	};
	/*const double& electricity_bill::operator[](int index)
	{
		if (index > 11 || index < 0)
			throw exception("index out of bounds");
		if (mnthUsage[index] < 0)
			throw exception("invalid value: usage");
		if (saleRate >= 0)
			return mnthUsage[index] * saleRate;
		throw exception("invalid value: sale rate");
	};*/
	ostream& operator<<(ostream& os, electricity_bill eb)
	{
		os << "year = " << eb.getYear() << "\nsale rate = " << eb.getSaleRate()<<endl;
		return os;
	};
	electricity_bill::~electricity_bill()
	{
		if (mnthUsage != nullptr)
		{
			delete [] mnthUsage;
			mnthUsage = nullptr;
		}
		cout << "month usage data erased" << endl;
	}