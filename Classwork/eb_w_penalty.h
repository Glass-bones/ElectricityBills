#pragma once
#include "electricity_bill.h"
class eb_w_penalty :
    public electricity_bill
{
    double *penalty=nullptr;
public:
    void setMnths(double*) override;
    void prntMnths() override;
    void setPenalty(int, double);
    double getPenalty(int);
    const double& getPenalty() const;
    double sumPay() override;
    eb_w_penalty();
    eb_w_penalty(int, double);
    eb_w_penalty(int, double, double, double);
    eb_w_penalty(time_t);
    ~eb_w_penalty() override;
};

