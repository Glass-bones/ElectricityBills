#include "electricBill.h"
#include <iostream>
#include <stdexcept>
#include <ctime>
using namespace std;

electricBill::electricBill()
{
	for (int i = 0; i < monthsInYear; i++) monthUsage[i] = invalid;
	year = invalid;
	cost = invalid;
};
electricBill::electricBill(int year, double cost, double usage)
{
	setYear(year);
	setCost(cost);
	setMonthUsage(0, usage);
	for (int i = 1; i < monthsInYear; i++)
		monthUsage[i] = invalid;
};

electricBill::electricBill(int year, double cost, std::span<const double> monthsUsage)
{
	setYear(year);
	setCost(cost);
	setMonthsUsage(0, monthsUsage);
	if (monthsUsage.size() < monthsInYear)
		for (int i = monthsUsage.size(); i < monthsInYear; i++)
		{
			this->monthUsage[i] = invalid;
		}
};
electricBill::~electricBill()
{
	if (monthUsage != nullptr)
	{
		delete[] monthUsage;
		monthUsage = nullptr;
	}
	//cout << "month usage data erased" << endl;
}
void electricBill::setMonthUsage(int month, double usage)
{
	if (month < 0 || month>monthsInYear-1) 
	{
		throw exception("invalid value: month");
	}
	if (usage < 0)
	{
		throw exception("invalid value: usage");
	}
	if (monthUsage == nullptr)
		monthUsage = new double[monthsInYear];
	monthUsage[month] = usage;
};
void electricBill::setMonthsUsage(int month, std::span<const double> monthsUsage)
{
	if (month < 0 || month>monthsInYear - 1)
	{
		throw exception("invalid value: month");
	}
	if (monthsUsage.data() == nullptr)
	{
		throw exception("invalid value: usage");
	}
	if (monthsUsage.size() + month < monthsInYear)
	{
		for (int i = 0;i < monthsUsage.size();i++)
		{
			setMonthUsage(month + i, monthsUsage[i]);
		}
	}
	else
	{
		for (int i = month;i < monthsInYear;i++)
		{
			setMonthUsage(i, monthsUsage[i-month]);
		}
	}
};
double electricBill::getMonthUsage(int month) const
{
	if (month < 0 || month>monthsInYear - 1)
	{
		throw exception("invalid value: month");
	}
	if (monthUsage == nullptr || monthUsage[month] < 0)
	{
		throw exception("usage not set");
	}
	return monthUsage[month];
};
void electricBill::setCost(double cost)
{
	if (cost <= 0)
	{
		throw exception("invalid value: sale rate");
	}
	this->cost = cost;
};
double electricBill::getCost() const
{
	if (cost<=0)
	{
		throw exception("cost not set");
	}
	return cost;
};
void electricBill::setYear(int year)
{
	if (year < minYear)
	{
		throw exception("invalid value: year");
	}
	this->year = year;
};
int electricBill::getYear() const
{
	if (year < minYear)
	{
		throw exception("year not set");
	}
	return year;
};
double electricBill::sumPay() const
{
	double sum=0;
	double cost=this->cost;
	if(cost >0)
	{
		for (int i = 0; i < monthsInYear; i++)
		{
			if (monthUsage[i] >= 0)
				sum += monthUsage[i] * cost;
			else if (i > 0)
				return sum;
			else return invalid;
		}
		return sum;
	}
				
	return invalid;
};
double electricBill::averageUsage() const
{
	double sum = 0;
	for (int i = 0; i < monthsInYear; i++)
	{
		if (monthUsage[i] >= 0)
			sum += monthUsage[i];
		else if (i > 0)
			return sum/i;
		else return invalid;
	}
	return sum / monthsInYear;
};