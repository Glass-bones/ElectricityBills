#pragma once
#include "electricity_bill.h"
template <typename srType>
//шаблон в отдельном файле заголовка, чтобы не форматировать базовый класс целиком
class eb_shablon
{
	electricity_bill* eb=nullptr;
public:
	void setMnthsSha(std::span<const double> arr)
	{
		eb->setMnths(arr);
	};
	void prntMnthsSha()
	{
		eb->prntMnths();
	};
	void setMnthUsageSha(int mnth, double usage)
	{
		eb->setMnthUsage(mnth, usage)
	};
	double getMnthUsageSha(int mnth)
	{
		return eb->getMnthUsage(mnth);
	};
	double getMnthUsageSha()
	{
		return eb->getMnthUsage();
	};
	void setSaleRateSha(srType sr)
	{
		eb->setSaleRate((double)sr);
	};
	srType getSaleRateSha()
	{
		return (srType)eb->getSaleRate();
	};
	void setYearSha(int yr)
	{
		eb->setYear(yr);
	};
	int getYearSha()
	{
		return eb->getYear();
	};
	double sumPaySha()
	{
		return eb->sumPay();
	};
	double avrgMnthUsage()
	{
		return eb->avrgMnthUsage();
	};
	eb_shablon()
	{
		eb = new electricity_bill();
	};
	eb_shablon(int year, srType sr)
	{
		eb = new electricity_bill(year, (double)sr);
	};
	eb_shablon(double firstUsage, int year, srType sr)
	{
		eb= new electricity_bill(firstUsage,year,(double)sr)
	};
	~eb_shablon()
	{
		if(eb!=nullptr)
		{
			delete eb;
			eb = nullptr;
		}
	};
};