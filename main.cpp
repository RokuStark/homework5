#include <iostream>




void printArray(double *pArray ,const size_t arrSIZE)
{
    for (size_t i = 0; i < arrSIZE; i++)
    {
        if(i == 0)
        std::cout << " Array = " << pArray[i] << ", ";
        else if(i == (arrSIZE -1))
        std::cout << pArray[i] << "." <<std::endl;
        else
        std::cout << pArray[i] << ", ";
    }
    return;
}

void printArray(int *pArray ,const size_t arrSIZE)
{
    for (size_t i = 0; i < arrSIZE; i++)
    {
        if(i == 0)
        std::cout << " Array = " << pArray[i] << ", ";
        else if(i == (arrSIZE -1))
        std::cout << pArray[i] << "." <<std::endl;
        else
        std::cout << pArray[i] << ", ";
    }
    return;
}

void reverseArr(int *pArray, const size_t arrSIZE)
{
    
    return;
}
int main()
{
    // Task 1
    const size_t SIZE = 5;
    double arr[SIZE] = {3.4 , 43.3 , 12.3 , 321.3 , 32.32};
    printArray(arr, SIZE);

    // Task 2

    int arrInt[SIZE]{0,1,0,0,1};
    


}