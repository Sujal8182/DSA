#include<iostream>
using namespace std;

int main()
{
    int array[5] = {50,40,30,20,10};

    for (int i = 1; i < 5; i++)
    {
        int key = array[i] ;
        int j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
        
    }
    
    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << " ";
    }
    
}