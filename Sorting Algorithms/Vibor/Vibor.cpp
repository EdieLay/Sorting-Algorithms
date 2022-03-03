// Vibor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
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

void swapmin(int* A, int len, int start, int option)
{
    int min = A[start], max = A[start], i, num = start, temp;
    if (option == 1)
    {
        for (i = start + 1; i < len; i++)
            if (A[i] < min)
            {
                min = A[i];
                num = i;
            }
    }
    else if (option == 2)
    {
        for (i = start + 1; i < len; i++)
            if (A[i] > max)
            {
                max = A[i];
                num = i;
            }
    }
    temp = A[num];
    A[num] = A[start];
    A[start] = temp;
}

void chooseasc(int* A, int len)
{
    int i;
    for (i = 0; i < len - 1; i++)
        swapmin(A, len, i, 1);
    cout << "Массив в возрастающем порядке: ";
    printarr(A, len);
}

void choosedesc(int* A, int len)
{
    int i;
    for (i = 0; i < len - 1; i++)
        swapmin(A, len, i, 2);
    cout << "Массив в убывающем порядке: ";
    printarr(A, len);
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Сортировка выбором." << endl;
    int n, i;
    cout << "Введите количество сортируемых чисел: ";
    cin >> n;
    int* A = new int[n];
    int* B = new int[n];
    cout << "Введите через пробел все числа: ";
    for (i = 0; i < n; i++)
    {
        cin >> A[i];
        B[i] = A[i];
    }
    chooseasc(A, n);
    choosedesc(B, n);
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
