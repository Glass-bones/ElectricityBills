#pragma once
#include "eb_menu.h"
#include <iostream>
#include <ctime>
class electricity_bill: public eb_menu
{
	double* mnthUsage=nullptr;
	int year;
	double saleRate;
public:
	void setMnths(double*) override;
	void prntMnths() override;
	void setMnthUsage(int,double);
	double getMnthUsage(int);
	double getMnthUsage();
	void setSaleRate(double);
	double getSaleRate();
	void setYear(int);
	int getYear();
	virtual double sumPay();
	double avrgMnthUsage();
	electricity_bill();
	electricity_bill(int, double);
	electricity_bill(double, int, double);
	electricity_bill(time_t);
	//const double& operator[](int);
	friend std::ostream& operator <<(std::ostream&, const electricity_bill);
	virtual ~electricity_bill();
};