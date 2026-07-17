// Classwork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include "electricity_bill.h"
#include "eb_w_penalty.h"
#include "eb_shablon.h"
#include <iostream>
#include <format>
#include <windows.h>
using namespace std;
void operator += (double& sum, electricity_bill& eb)
{
    sum += eb.avrgMnthUsage();
}
int main()
{
    int choise = -1;
    eb_w_penalty* testElBil = nullptr;
    while (choise < 0 || choise>4)
    {
        cout << "testing class eb_w_penalty\n0 - create empty instance\n1 - create instance with first month set\n2 - create instance with month setup loop\n3 - create random instance\n4 - end test" << endl;
        cin >> choise;
        int year;
        double saleRate;
        double firstUsg;
        double firstPen;
        switch (choise)
        {
        case 0:
            testElBil = new eb_w_penalty();
            break;
        case 1:
            cout << "year = ";
            cin >> year;
            cout << "sale rate = ";
            cin >> saleRate;
            cout << "usage in first month = ";
            cin >> firstUsg;
            cout << "penalty in first month = ";
            cin >> firstPen;
            try
            {
                testElBil = new eb_w_penalty(year,firstUsg,saleRate,firstPen);
            }
            catch (exception& err)
            {
                cout << err.what() << ", test terminated.";
                return 0;
            }
            break;
        case 2:
            cout << "year = ";
            cin >> year;
            cout << "sale rate = ";
            cin >> saleRate;
            try
            {
                testElBil = new eb_w_penalty(year, saleRate);
            }
            catch (exception& err)
            {
                cout << err.what() << ", test terminated.";
                return 0;
            }
            break;
        case 3:
            testElBil = new eb_w_penalty(time(nullptr));
            break;
        case 4:
            return 0;
        default:
            system("cls");
            cout << "invalid value" << endl;
        }
    }
    system("cls");
    choise = -1;
    while (choise!=10)
    {
        cout << "testing class eb_w_penalty\n0 - set month usage\n1 - get month usage\n2 - set sale rate\n3 - get sale rate\n4 - set year\n5 - get year\n6 - get payment summary\n7 - get average monthly usage\n8 - set penalty\n9 - get penalty\n10 - end test"<<endl;
        cin >> choise;
        int month;
        int year;
        double d;
        switch (choise)
        {
        case 0:
            cout << "month = ";
            cin >> month;
            cout << "monthly usage = ";
            cin >> d;
            try
            {
                testElBil->setMnthUsage(month-1,d);
                system("cls");
            }
            catch (exception& err)
            {
                system("cls");
                cout << err.what()<<endl;
            }
            break;
        case 1:
            cout << "month = ";
            cin >> month;
            try
            {
                d = testElBil->getMnthUsage(month-1);
                system("cls");
                cout << month << " month usage = " << d << endl;
            }
            catch (exception& err)
            {
                system("cls");
                cout << err.what() << endl;
            }
            break;
        case 2:
            cout << "sale rate = ";
            cin >> d;
            try
            {
                testElBil->setSaleRate(d);
                system("cls");
            }
            catch (exception& err)
            {
                system("cls");
                cout << err.what() << endl;
            }
            break;
        case 3:
            try
            {
                d = testElBil->getSaleRate();
                system("cls");
                cout << "sale rate = " << d << endl;
            }
            catch (exception& err)
            {
                system("cls");
                cout << err.what() << endl;
            }
            break;
        case 4:
            cout << "year = ";
            cin >> year;
            try
            {
                testElBil->setYear(year);
                system("cls");
            }
            catch (exception& err)
            {
                system("cls");
                cout << err.what() << endl;
            }
            break;
        case 5:
            try
            {
                year = testElBil->getYear();
                system("cls");
                cout << "year = " << year << endl;
            }
            catch (exception& err)
            {
                system("cls");
                cout << err.what() << endl;
            }
            break;
        case 6:
            try
            {
                d = testElBil->sumPay();
                system("cls");
                if (d >= 0)
                    cout << "payment summary = " << d << endl;
                else cout << "sale rate and/or usage not set" << endl;
            }
            catch (exception& err)
            {
                system("cls");
                cout << err.what() << endl;
            }
            break;
        case 7:
            try
            {
                d = testElBil->avrgMnthUsage();
                system("cls");
                if (d >= 0)
                    cout << "average monthly usage = " << d << endl;
                else cout << "usage not set" << endl;
            }
            catch (exception& err)
            {
                system("cls");
                cout << err.what() << endl;
            }
            break;
        case 8:
            cout << "month = ";
            cin >> month;
            cout << "penalty = ";
            cin >> d;
            try
            {
                testElBil->setPenalty(month - 1, d);
                system("cls");
            }
            catch (exception& err)
            {
                system("cls");
                cout << err.what() << endl;
            }
            break;
        case 9:
            cout << "month = ";
            cin >> month;
            try
            {
                d = testElBil->getPenalty(month - 1);
                system("cls");
                cout << month << " month penalty = " << d << endl;
            }
            catch (exception& err)
            {
                system("cls");
                cout << err.what() << endl;
            }
            break;
        case 10:
            break;
        default:
            system("cls");
            cout << "invalid value" << endl;
        }
    }
    double a = 0;
    electricity_bill* inmas[10];
    double tstone[10]{ {1.1},{2.2},{3.3},{4.4},{5.5},{6.6},{7.7},{8.8},{9.9},{0.0} };
    double tsttwo[15]{ {0.1},{0.2},{0.3},{0.4},{0.5},{0.6},{0.7},{0.8},{0.9},{1.0},{1.1},{1.2},{1.3},{1.4},{1.5} };
    for (int i = 0;i < 10;i++)
    {
        if (i % 2 == 0)
            inmas[i] = new eb_w_penalty(time(nullptr));
        else inmas[i] = new electricity_bill(time(nullptr));
        inmas[i]->prntMnths();
        a += *inmas[i];
        inmas[i]->setMnths(tstone);
        inmas[i]->prntMnths();
        inmas[i]->setMnths(tsttwo);
        inmas[i]->prntMnths();
        /*srand(time(nullptr));
        Sleep(rand() % 100+1000);*/
    }
    for (int i = 0;i < 10;i++) delete inmas[i];
    cout << "sum of averages = " << a << endl;
    cout << *testElBil << "'ere we go" << endl;
    return 0;
}
