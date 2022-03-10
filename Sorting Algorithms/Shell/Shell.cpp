﻿// Shell.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <clocale>
#include<Windows.h>
#include <cmath>

using namespace std;

void printarr(int* A, int len)
{
    int i;
    for (i = 0; i < len; i++)
        cout << A[i] << " ";
    cout << endl;
}

void shellsort(int* A, int len, int option)
{
    int i, step, temp, cur, k = 1, c;
    while (len / pow(2, k) >= 2)
        k++;
    for (i = 1; i <= k; i++)
    {
        c = 0;
        step = len / pow(2, i);
        while (step + c < len)
        {
            cur = step + c;
            c++;
            while (cur - step >= 0)
            {
                if ((A[cur - step] > A[cur] && option == 1) || (A[cur - step] < A[cur] && option == 2))
                {
                    temp = A[cur];
                    A[cur] = A[cur - step];
                    A[cur - step] = temp;
                    cur = cur - step;
                }
                else break;
            }
        }
        printarr(A, len);
    }
    if (option == 1)
    {
        cout << "Массив в возрастающему порядке: ";
        printarr(A, len);
    }
    else if (option == 2)
    {
        cout << "Массив в убывающем порядке: ";
        printarr(A, len);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Сортировка методом Шелла." << endl;
    int n, i;
    cout << "Введите количество сортируемых чисел: ";
    cin >> n;
    int* A = new int[n];
    cout << "Введите через пробел все числа: ";
    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    shellsort(A, n, 1);
    shellsort(A, n, 2);
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
