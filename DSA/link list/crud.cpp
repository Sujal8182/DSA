#include <iostream>
using namespace std;

struct node{
    public:

    int data;
    node *next;

    node(int value){
        data = value;
    }
};
void insert(int &op,int &count, node *&ptr,node *&head){
    cout << "press 1 to insert at beginning" << endl;
            cout << "press 2 to insert at ending" << endl;
            cout << "press 3 to insert at any position" << endl;
            cout << "Enter the option : ";
            cin >> op;
            if(op >= 1 && op <= 3){
                if(op == 1){
                int dd = 0;
                cout << "Enter the value : ";
                cin >> dd;
            
                node *nn = new node(dd);
                nn->next = head;
                head = nn;
                count++;
                }
                else if(op == 2){
                    int dd = 0;
                    cout << "Enter the value : ";
                    cin >> dd;
                
                    node *temp = new node(dd);
                    
                    ptr = head;
                    while(ptr->next != NULL){
                        ptr = ptr->next;
                    }
                    ptr->next = temp;
                    count++;
                }
                else if(op == 3){
                    if(count >=2){
                        int pos,val;
                        
                        while(true){
                            cout << "enter the position between 1 and "<< count << ": ";
                            cin >> pos;
                            if(pos >=1 && pos <= count){
                                break;
                            }
                            else{
                                cout << "Invalid position. Please try again." << endl;
                            }
                        }
                        cout << "Enter the value : ";
                        cin >> val;
                        
                        node *posi = new node(val);
                        
                        ptr = head;
                        count = 0;
                        
                        while(ptr !=NULL){
                            count++;
                            if(count == pos){
                                posi->next = ptr->next;
                                ptr->next = posi;
                            }
                            ptr = ptr->next;
                        }
                    }else{
                        cout << "Need at least 2 nodes to insert at a specific position."<< endl;
                    }
                }
            }
            else{
                cout << "Invalid input" << endl;
            }

}
void update(int &count, node *&ptr,node *&head){
    int pos,val;
    count = 0;
    ptr = head;
    while(ptr != NULL){
        cout << ptr->data << endl;
        ptr = ptr->next;
        count++;
    }
    int i = 1;
    while(i <= count){
        cout << "(" << i << ")" << " ";
        i++;
    }

    while(true){
        cout << "enter the position between 1 and "<< count << ": ";
        cin >> pos;
        if(pos >=1 && pos <= count){
            break;
        }
        else{
            cout << "Invalid position. Please try again." << endl;
        }
    }

    cout << "Enter the value : ";
    cin >> val;
    count = 0;
    while(ptr !=NULL){
        count++;
        ptr = ptr->next;
    }    



}


int main() {

        node *head = new node(10);
        node *current = new node(20);
        head->next = current;
        node *ptr = NULL;
        ptr = head;
        current = new node(30);
        head->next->next = current;
        current = new node(40);
        head->next->next->next = current;
        current = new node(50);
        head->next->next->next->next = current;
        int count = 0;
        while(ptr != NULL){
            cout << ptr->data << endl;
            ptr = ptr->next;
            count++;
        }
    int user = 0;

    do{
        cout << "---------Node---------"<< endl;
        cout << "Enter 1 to Insert value" << endl;
        cout << "Enter 2 to Read value" << endl;
        cout << "Enter 3 to Update value" << endl;
        cout << "Enter 4 to Delete value" << endl;
        cout << "Enter 5 to exit" << endl;
        cout << "-----------------------------------"<< endl;
        cout << "Enter the number : ";
        cin >> user;
    
        int op = 0;
        switch(user){
            case 1:
                insert(op,count,ptr,head);
                break;
            case 2:
                ptr = head;
                while(ptr != NULL){
                    cout << ptr->data << " ";
                    ptr = ptr->next;
                    }
                    cout << endl;
                break;
            
            case 3:
                    update(count,ptr,head);
                break;
            case 4:
                break;
            case 0:
                break;
        };
    
    }while(user != 0);

}
