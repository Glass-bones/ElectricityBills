// Classwork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include "electricity_bill.h"
#include <iostream>
using namespace std;
int main()
{
    int choise = -1;
    electricity_bill* testElBil = nullptr;
    while (choise < 0 || choise>4)
    {
        cout << "testing class electricity_bill\n0 - create empty instance\n1 - create instance with first monthly usage set\n2 - create instance with monthly usage setup loop\n3 - end test" << endl;
        cin >> choise;
        int year;
        double saleRate;
        double firstUsg;
        switch (choise)
        {
        case 0:
            testElBil = new electricity_bill();
            break;
        case 1:
            cout << "year = ";
            cin >> year;
            cout << "sale rate = ";
            cin >> saleRate;
            cout << "usage in first month = ";
            cin >> firstUsg;
            try
            {
                testElBil = new electricity_bill(firstUsg,year,saleRate);
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
                testElBil = new electricity_bill(year, saleRate);
            }
            catch (exception& err)
            {
                cout << err.what() << ", test terminated.";
                return 0;
            }
            break;
        case 3:
            return 0;
        default:
            system("cls");
            cout << "invalid value" << endl;
        }
    }
    system("cls");
    choise = -1;
    while (choise!=8)
    {
        cout << "testing class electricity_bill\n0 - set month usage\n1 - get month usage\n2 - set sale rate\n3 - get sale rate\n4 - set year\n5 - get year\n6 - get payment summary\n7 - get average monthly usage\n8 - end test"<<endl;
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
            break;
        default:
            system("cls");
            cout << "invalid value" << endl;
        }
    }
    return 0;
}

// забыл выделить ветв для 1й лабы
