#include <iostream>
using namespace std;

void push(int &top, int stack[],int size){
    int val;
    if(top < size){
       
        top++;
        cout << "Enter the value : ";
        cin >> val;
       
        stack[top] = val;
       
        for(int i = 0; i <= top ; i++){
            cout << stack[i] << " ";
        }
        cout << endl;
    }else{
        cout << "Stack is full" << endl;
    }
}

void pop(int &top){
    if(top != -1){
       
    top--;
    }else{
        cout << "top is empty" << endl;
    }
}
void Peek(int top, int stack[]){
    cout << stack[top] << endl;
}

void IsEmpty(int top){
    if(top == -1){
        cout << "Stack is Empty.."<< endl;
    }else{
        cout << "Stack is not empty.."<< endl;
    }
}
void IsFull(int top, int size){
    if(top == size){
        cout << "Stack is Full" << endl;
    }else if(top == -1){
        cout << "Stack is Empty.." << endl;
    }else{
        cout << "Stack is not Full but not also Empty.." << endl;
    }
}
void Size(int top){
    cout << top << endl;
}
int main() {
    int size,top;
    top = -1;
    cout <<  "Enter the size : ";
    cin >> size;
    int *stack = new int[size];
   
    int option;
    do{
        cout << "----------Stack------------" << endl;
        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "3.Peek" << endl;
        cout << "4.Is Empty ?" << endl;
        cout << "5.Is Full" << endl;
        cout << "6.Size" << endl;
        cout << "0.Exit" << endl;
        cout << "----------------------------" << endl;
        cout << "Choose : ";
        cin >> option;
       
        switch(option){
            case 1:
                push(top,stack,size);
                break;
            case 2:
                pop(top);
                break;
            case 3:
                Peek(top,stack);
                break;
            case 4:
                IsEmpty(top);
                break;
            case 5:
                IsFull(top,size);
                break;
            case 6:
                Size(top);
                break;
            case 0:
                cout << "Great..."<< endl;
                break;
            default:
                cout << "Invalid input.. " << endl;
                break;
               
        }
    }while(option != 0);
}