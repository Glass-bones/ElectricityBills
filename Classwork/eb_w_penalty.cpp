#include "eb_w_penalty.h"
using namespace std;
void eb_w_penalty::setPenalty(int mnth, double pen)
{
	if (mnth < 0 || mnth>11)
		throw exception("invalid value: month");
	if (pen >= 0)
	{
		penalty[mnth] = pen;
		return;
	}
	throw exception("invalid value: penalty");
};
double eb_w_penalty::getPenalty(int mnth)
{
	if (mnth > 11 || mnth < 0)
		throw exception("invalid value: month");
	if (penalty[mnth] >= 0)
		return penalty[mnth];
	throw exception("penalty not set");
};
const double& eb_w_penalty::getPenalty()
const{
	return *penalty;
};
double eb_w_penalty::sumPay() 
{
	double sum = electricity_bill::sumPay();
	if (sum < 0) sum = 0;
	for (int i = 0;i < 12;i++)
		if (penalty[i] >= 0)
			sum += penalty[i];
		else return sum;
	return sum;
};
eb_w_penalty::eb_w_penalty()
{
};
eb_w_penalty::eb_w_penalty(int, double pen)
{
};

eb_w_penalty(int, double, double, double)
{

}
eb_w_penalty::eb_w_penalty(time_t)
{
};
eb_w_penalty::~eb_w_penalty()
{
	if (penalty != nullptr)
	{
		delete [] penalty;
		penalty = nullptr;
	}
	cout << "penalty data erased" << endl;
};
