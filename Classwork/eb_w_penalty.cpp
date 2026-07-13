#include "eb_w_penalty.h"
#include <random>
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
eb_w_penalty::eb_w_penalty():electricity_bill()
{
	if (penalty == nullptr) penalty = new double[12];
	for (int i = 0; i < 12; i++) penalty[i] = -1;
};
eb_w_penalty::eb_w_penalty(int year, double saleRate):electricity_bill(year, saleRate)
{
	int mnth = 0;
	double pen = -1;
	bool cond = true;
	cout << "input negative number to ignore remaining elements;" << endl;
	if (penalty == nullptr) penalty = new double[12];
	while (cond && mnth < 12)
	{
		cout << "input penalty for " << mnth + 1 << " month: ";
		cin >> pen;
		if (pen >= 0)
		{
			setPenalty(mnth, pen);
			mnth++;
		}
		else cond = false;
	}
	while (mnth < 12)
	{
		penalty[mnth] = -1;
		mnth++;
	}
};

eb_w_penalty::eb_w_penalty(int year, double firstUsg, double saleRate, double firstPen):electricity_bill(firstUsg,year,saleRate)
{
	if (penalty == nullptr) penalty = new double[12];
	setPenalty(0, firstPen);
	for (int i = 1;i < 12;i++)
		penalty[i] = -1;
}
eb_w_penalty::eb_w_penalty(time_t t):electricity_bill(t)
{
	random_device frnd;
	mt19937 gen(frnd());
	uniform_real_distribution<double> d(0.00, 20.00);
	bernoulli_distribution yn(0.3);
	if (penalty == nullptr) penalty = new double[12];
	for (int i = 0;i < 12;i++)
		if (yn(gen))
			setPenalty(i, d(gen));
		else
			setPenalty(i, 0);
	/*srand(t);
	if (penalty == nullptr) penalty = new double[12];
	for (int i = 0;i < 12;i++)
		if (rand() % 10 < 4)
			setPenalty(i, (rand() % 1890) / 1000.0);
		else
			setPenalty(i, 0);*/
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
