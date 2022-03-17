﻿// Kucha.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>
#include <clocale>
#include<Windows.h>

using namespace std;

void printarr(int* A, int len)
{
    int i;
    for (i = 0; i < len; i++)
        cout << A[i] << " ";
    cout << endl;
}

void kuchasort(int* A, int len)
{
    if (len > 1)
    {
        int i;
        for (i = len / 2 - 1; i >= 0; i--)
        {
            if (2 * i + 2 < len)
            {
                if (A[i] < A[2 * i + 1] && A[i] < A[2 * i + 2])
                    if (A[2 * i + 1] > A[2 * i + 2])
                        swap(A[i], A[2 * i + 1]);
                    else swap(A[i], A[2 * i + 2]);
                else if (A[i] < A[2 * i + 1])
                    swap(A[i], A[2 * i + 1]);
                else if (A[i] < A[2 * i + 2])
                    swap(A[i], A[2 * i + 2]);
            }
            else if (A[i] < A[2 * i + 1])
                swap(A[i], A[2 * i + 1]);
        }
        swap(A[0], A[len - 1]);
        printarr(A, len);
        kuchasort(A, len - 1);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Пирамидальная сортировка." << endl;
    int n, i;
    cout << "Введите количество сортируемых чисел: ";
    cin >> n;
    int* A = new int[n];
    cout << "Введите через пробел все числа: ";
    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    kuchasort(A, n);
    printarr(A, n);
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
