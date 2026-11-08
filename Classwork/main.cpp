#include "electricBill.h"
#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    /*обертка для проверки исключений
    
    try 
    {

    }
    catch (const exception& e) 
    {
        cerr << e.what() << endl;
    }

    */

    //инициализация экземпляра класса для любого конструктора

    //electricBill testElBil=electricBill();
    //electricBill testElBil = electricBill(1987,66.7,1.3);
    //*
    double monthsUsage[12] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2 };
    electricBill test = electricBill(1987,66.7,monthsUsage);
    //*/

    //проверка методов класса

    test.setMonthUsage(0, 1.1);
    cout << "второй месяц: " << test.getMonthUsage(1)<<endl;
    test.setCost(78.9);
    cout << "цена: " << test.getCost() << endl;
    test.setYear(1983);
    cout << "год: " << test.getYear() << endl;
    cout << "счет за год: " << test.sumPay() << endl;
    cout << "среднее использование: " << test.averageUsage() << endl;
    return 0;
}
