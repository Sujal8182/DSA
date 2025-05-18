#include<iostream>
using namespace std;

int main()
{
    int array[5] = {50,40,30,20,10};
    int minIndex;
    int temp;

    for (int i = 0; i < 5; i++)
    {
        minIndex = i;
        
        for (int j = i; j < 5; j++)
        {
            if (array[j] < array[minIndex]){
                minIndex = j ;
            }    
        }
        temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
        
    }
    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << " ";
    }
}