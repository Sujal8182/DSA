#include <iostream>
using namespace std;

void Enqueue(int queue[],int &top){
    top++;
    int val;
    cout << "Enter the value : ";
    cin >> val;
   
    queue[top] = val;
   
    for(int i = top; i >= 0; i--){
        cout << queue[i] << " ";
    }
    cout << endl;
}

void Dequeue(int queue[],int &top, int size){
    for(int i = 0; i < size; i++){
        queue[i] = queue[i + 1];
    }
    top--;
   
    for(int i = top; i >= 0; i--){
        cout << queue[i] << " ";
    }
    cout << endl;
}

void Front(int queue[],int &top){
    cout << "The front value : " << queue[top] << endl;
}
void Rear(int queue[], int &top){
    cout << "The rear value : " << queue[0] << endl;
}
void IsEmpty(int top){
    if(top == -1){
        cout << "The Queue is Empty" << endl;
    }else{
        cout << "The Queue is not empty" << endl;
    }
}
void IsFull(int top,int size){
    if(top == size){
        cout << "The Queue is full" << endl;
    }else if(top < size){
        cout << "Queue have some values but not full" << endl;
    }else{
        cout << "Queue is Empty" << endl;
    }
}
void Size(int top){
    cout << "The size of queue : "<< top + 1 << endl;
}

int main() {
    int size,option;
    cout << "Enter the size of Queue : ";
    cin >> size;
    int top = -1;
    int end = -1;
   
    int *queue = new int[size];
   
    do{
        cout << "----------Queue------------" << endl;
        cout << "1.Enqueue"<< endl;
        cout << "2.Dequeue"<< endl;
        cout << "3.Front"<< endl;
        cout << "4.End"<< endl;
        cout << "5.IsEmpty"<< endl;
        cout << "6.IsFull"<< endl;
        cout << "7.Size"<< endl;
        cout << "0.Exit"<< endl;
        cout << "----------------------------" << endl;
        cout << "Choose : ";
        cin >> option;
       
        switch(option){
            case 1:
                if(top != size){
                   
                    Enqueue(queue,top);
                }else{
                    cout << "THe Queue is full" << endl;
                }
                break;
            case 2:
                Dequeue(queue,top,size);
                break;
            case 3:
                Front(queue,top);
                break;
            case 4:
                Rear(queue,top);
                break;
            case 5:
                IsEmpty(top);
                break;
            case 6:
                IsFull(top,size);
                break;
            case 7:
                Size(top);
                break;
            case 0:
                cout << "bye.." << endl;
                break;
            default:
                cout << "Invalid option "<< endl;
                break;
               
        }
    }while(option != 0);
}