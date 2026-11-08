#pragma once
#include <span>
class electricBill
{
	const int monthsInYear = 12;
	const int minYear = 1890;
	const int invalid = -1;
	double* monthUsage;
	int year;
	double cost;
public:
	electricBill();
	electricBill(int year, double cost, double usage);
	electricBill(int year, double cost, std::span<const double> monthsUsage);
	~electricBill();
	void setMonthUsage(int month,double usage);
	void setMonthsUsage(int month, std::span<const double> monthsUsage);
	double getMonthUsage(int month) const;
	void setCost(double cost);
	double getCost() const;
	void setYear(int year);
	int getYear() const;
	double sumPay() const;
	double averageUsage() const;
};

