#pragma once
class electricity_bill
{
	double mnthUsage[12];
	int year;
	double saleRate;
public:
	void setMnthUsage(int,double);
	double getMnthUsage(int);
	void setSaleRate(double);
	double getSaleRate();
	void setYear(int);
	int getYear();
	double sumPay();
	double avrgMnthUsage();
	electricity_bill();
	electricity_bill(int, double);
	electricity_bill(double, int, double);
};

