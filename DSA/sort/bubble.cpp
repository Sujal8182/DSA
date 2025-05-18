#include<iostream>
using namespace std;

int main()
{
    int array[5] = {50,40,30,20,10};
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(array[j] > array[j + 1]){
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
        
    }
    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << " ";
    }
    
}