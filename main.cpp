#include <iostream>

/*
Написать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его размер.
 Вызвать эту функцию из main.

Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ].
Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.

Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его
значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.

* Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным,
или отрицательным), при этом метод должен циклически сместить все элементы массива на n позиций.

** Написать функцию, которой передается не пустой одномерный целочисленный массив, она должна вернуть
 истину если в массиве есть место, в котором сумма левой и правой части массива равны.
 Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false,
  checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||, эти символы в массив
   не входят.

*/

void __fastcall printArray(double* pArray, const size_t arrSIZE)
{
    for (size_t i = 0; i < arrSIZE; i++)
    {
        if (i == 0)
            std::cout << " Array = " << pArray[i] << ", ";
        else if (i == (arrSIZE - 1))
            std::cout << pArray[i] << "." << std::endl;
        else
            std::cout << pArray[i] << ", ";
    }
    return;
}

void __fastcall printArray(int* pArray, const size_t arrSIZE)
{
    for (size_t i = 0; i < arrSIZE; i++)
    {
        if (i == 0)
            std::cout << " Array = " << pArray[i] << ", ";
        else if (i == (arrSIZE - 1))
            std::cout << pArray[i] << "." << std::endl;
        else
            std::cout << pArray[i] << ", ";
    }
    return;
}

void __fastcall reverseArr(int * pArray, const size_t arrSIZE)
{
    for (size_t i = 0; i < arrSIZE; i++)
    {
         pArray[i] = (pArray[i] == 1) ? 0 : 1;
        /*
        if (pArray[i] == 0)
        {
            pArray[i] = 1;
        }
        else
        {
            pArray[i] = 0;
        }
        */
    }
    
    return;
}

void _fastcall fillArray(int* pArray, const size_t arrSIZE)
{
    int startNum = 1;
    int addSum = 3;
    for (size_t i = 0; i < arrSIZE; i++)
    {
        pArray[i] = startNum;
        startNum += addSum;
    }
}

void rotLeft(int* pArray, const size_t arrSIZE)
{
    int temp = pArray[0];
    for (size_t i = 0; i < arrSIZE; i++)
    {
        pArray[i] = pArray[i + 1];
    }
    pArray[arrSIZE - 1] = temp;
}

void rotRight(int* pArray, const size_t arrSIZE)
{
    int temp = pArray[arrSIZE - 1];

    for (size_t i = arrSIZE - 1; i > 0 ; i--)
    {
        pArray[i] = pArray[i - 1];
    }
    pArray[arrSIZE - 1] = temp;

}




void task1()
{
    /*
        Написать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его размер.
            Вызвать эту функцию из main.
    */

    const size_t SIZE = 5;
    double arr[SIZE] = { 3.4, 43.3, 12.3, 321.3, 32.32 };
    printArray(arr, SIZE);
}

void task2()
{
    /*
        Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ].
             Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить на экран массив
            до изменений и после.
    */

    const size_t SIZE = 10;
    int arrInt[SIZE]{ 0, 1, 0, 0, 1, 1, 0, 1, 0, 1 };
    printArray(arrInt, SIZE);
    reverseArr(arrInt, SIZE);
    printArray(arrInt, SIZE);
}

void task3()
{
    /*
        Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его
            значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.
    */
    const int SIZE = 8;
    int arr[SIZE]{};
    printArray(arr, SIZE);
    fillArray(arr, SIZE);
    printArray(arr, SIZE);

}

void task4(int *pArr, const size_t arrSIZE, int n)
{
    /*
     * Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным,
        или отрицательным), при этом метод должен циклически сместить все элементы массива на n позиций. 
    */

    int temp{ 0 };
    if (n == 0)
        return;
    
    for (int i = 0; i < abs(n); i++)
    {
        if (n > 0)
            rotRight(pArr, arrSIZE);
        else
            rotLeft(pArr, arrSIZE);

    }
}

bool checkBalance(int* pArr, const int arrSIZE)
{
    int doTemp = pArr[0];
    int afterTemp = 0;
    
    for (size_t i = 0; i < arrSIZE; i++)
    {
        for (size_t a = i + 1; a < arrSIZE; a++)
        {
            afterTemp += pArr[a];
        }
        if (doTemp == afterTemp)
        {
            return true;
        }
        else
        {
            afterTemp = 0;
            doTemp += pArr[i + 1];
        }
       
    }
    return false;
}

void task5()
{
    /*
             ** Написать функцию, которой передается не пустой одномерный целочисленный массив, она должна вернуть
          истину если в массиве есть место, в котором сумма левой и правой части массива равны.
          Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false,
          checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||, эти символы в массив
          не входят.
    */
    const int fSIZE = 5;
    const int dSIZE = 6;
    int arr1[dSIZE]{ 1, 32, 3, 43, 32, 2 };
    int arr2[dSIZE]{ 4, 6, 2, 3, 3, 6 };
    int arr3[fSIZE]{ 5, 1, 1, 9, 4 };

    std::cout << "Balance array = " << checkBalance(arr1, dSIZE) << std::endl;
    std::cout << "Balance array = " << checkBalance(arr2, dSIZE) << std::endl;
    std::cout << "Balance array = " << checkBalance(arr3, fSIZE) << std::endl;

}

int main()
{
    //task1();
    //task2();
    //task3();
    //task4();
    task5();

    system("pause");
}
