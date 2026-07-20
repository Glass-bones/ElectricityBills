#pragma once
#include "electricity_bill.h"
template <typename usageType>
//шаблон в отдельном файле заголовка, чтобы не форматировать базовый класс целиком
class eb_shablon
{
	electricity_bill* eb=nullptr;
	int startingMnth;
public:
	void setStartMnth(int mnth)
	{
		if (mnth >= 0 && mnth < 12)
		{
			startingMnth=mnth;
			return;
		}
		throw std::exception("invalid value: starting month");
	};
	int getStartMnth()
	{
		if (startingMnth >= 0 && startingMnth < 12)
			return startingMnth;
		throw std::exception("starting month not set");
	};
	void setMnthsSha(std::span<const usageType> arr)
	{
		eb->setMnths(arr);
	};
	void prntMnthsSha()
	{
		eb->prntMnths();
	};
	void setMnthUsageSha(int mnth, usageType usage)
	{
		if(mnth<=getStartMnth())
			eb->setMnthUsage(mnth, (double)usage);
		throw std::exception("invalid value: month");
	};
	usageType getMnthUsageSha(int mnth)
	{
		if (mnth <= getStartMnth())
			return (usageType)eb->getMnthUsage(mnth);
		throw std::exception("invalid value: month");
	};
	void setSaleRateSha(double sr)
	{
		eb->setSaleRate(sr);
	};
	double getSaleRateSha()
	{
		return eb->getSaleRate();
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
		double sum = 0;
		double sr = eb->getSaleRate();
		if (sr > 0)
		{
			for (int i = startingMnth;i < 12;i++)
			{
				try
				{
					sum += eb->getMnthUsage(i) * sr;
				}
				catch (std::exception& err)
				{
					if (i > startingMnth)
						return sum;
					else return -1;
				}
			}
			return sum;
		}
		return -1;
	};
	double avrgMnthUsage()
	{
		double sum = 0;
		for (int i = startingMnth;i < 12;i++)
		{
			try
			{
				sum += eb->getMnthUsage(i);
			}
			catch (std::exception& err)
			{
				if (i > startingMnth)
					return sum / i - startingMnth;
				else return -1;
			}
		}
		return sum / 12-startingMnth;
	};
	eb_shablon(usageType typeExamle)
	{
		eb = new electricity_bill();
		startingMnth = -1;
	};
	eb_shablon(usageType firstUsage, int year,int mnth, double sr)
	{
		setStartMnth(mnth);
		eb = new electricity_bill();
		eb->setMnthUsage(mnth, (double)firstUsage);
		eb->setYear(year);
		eb->setSaleRate(sr);
	};
	virtual ~eb_shablon()
	{
		if(eb!=nullptr)
		{
			delete eb;
			eb = nullptr;
		}
	};
};