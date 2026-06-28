#include "electricity_bill.h"
#include <iostream>
#include <stdexcept>
using namespace std;
class electricity_bill
{
	double mnthUsage[12];
	int year;
	double saleRate;
public:
	void setMnthUsage(int mnth, double usage)
	{
		if (mnth >= 0)
			if (mnth<12)
				if (usage >= 0)
				{
					mnthUsage[mnth] = usage;
					return;
				}
		throw exception("invalid value: month and/or usage");
	};
	double getMnthUsage(int mnth)
	{
		if (mnthUsage[mnth]>=0)
		return mnthUsage[mnth];
		throw exception("usage not set");
	};
	void setSaleRate(double sr)
	{
		if (sr > 0)
		{
			saleRate = sr;
			return;
		}
		throw exception("invalid value: sale rate");
	};
	double getSaleRate()
	{
		if (saleRate>0)
		return saleRate;
		throw exception("sale rate not set");
	};
	void setYear(int yr)
	{
		if (yr >= 1890)
		{
			year = yr;
			return;
		}
		throw exception("invalid value: year");
	};
	int getYear()
	{
		if (year >= 1890)
		return year;
		throw exception("year not set");
	};
	double sumPay()
	{
		double sum=0;
		double mu;
		double sr;
		for (int i = 0;i < 12;i++)
			try
			{
				mu = getMnthUsage(i);
				sr = getSaleRate();
				sum += mu * sr;
			}
			catch (exception& err)
			{
				cout << err.what() << ", remaining elements are ignored" << endl;
				return sum;
			}
		return sum;
	};
	double avrgMnthUsage()
	{
		double sum = 0;
		double mu;
		for (int i = 0;i < 12;i++)
			try
			{
				mu = getMnthUsage(i);
				sum += mu;
			}
			catch (exception& err)
			{
				cout << err.what() << ", remaining elements are ignored" << endl;
				return sum/i;
			}
			return sum / 12;
	};
	electricity_bill()
	{
		for (int i = 0; i < 12; i++) mnthUsage[i] = -1;
		year = -1;
		saleRate = -1;
	};
	electricity_bill(int yr, double sr)
	{ 
		setYear(yr);
		setSaleRate(sr);
		int mnth = 0;
		double usage = -1;
		bool cond = true;
			while(cond&&mnth<12)
			{
				cout<<"input usage for "<<mnth+1<<"th month (input negative number to keep left monthly usage unset): ";
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
	electricity_bill(double firstUsg, int yr, double sr)
	{
		setYear(yr);
		setSaleRate(sr);
		setMnthUsage(0,firstUsg);
		for (int i = 1;i < 12;i++)
			mnthUsage[i] = -1;
	};
};