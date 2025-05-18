#include <iostream>
using namespace std;

struct node{
  public :
  int data;
  node *next;
 
  node(int val){
      data = val;
      next = nullptr;
  }
  ~node(){
     
  }
};

void InsertSt(int value, node *&head){
    if(head == NULL){
        cout << "making a head node "<< endl;
        head = new node(value);
       
    }else{
        cout << "making another" << endl;
        node *current = new node(value);
        current->next = head;
        head = current;
    }
   
}

void InsertAfterValue(int &value , int &poss,node *&head){
    node *ptr = head;
   
    node *newNode = new node(value);
    while(ptr != NULL){
        if(ptr->data == poss){
            newNode->next = ptr->next;
            ptr->next = newNode;
            break;
        }
        ptr = ptr->next;
       
    }
}

void InsertEnd(int value,node *&head){
   
    node *end = new node(value);
    if(head == NULL){
        head = end ;
        return;
    }
   
    node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = end;
}

void read(node *&head){
    if(head != NULL){
        node *ptr = head;
       
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;;
        }
    }else{
        cout << "Need to fil nodes.."<< endl;
    }
}

void update(node *&head){
    int upval;
    node *ptr = head;
   
    cout << "Which value you wanna change : ";
    cin >> upval;
    while(ptr != NULL){
        if(ptr->data == upval){
            int vall;
            cout << "Enter the value to change : ";
            cin >> vall;
           
            ptr->data = vall;
           
            break;
        }
        ptr = ptr->next;
    }
}

void deleteNode(node *&head){
    node *ptr = head;
    int delposs;
    int count = 0;
    while(ptr != NULL){
        count++;
        cout << count << " ";
        ptr = ptr->next;
    }
   cout << endl;
   
    while(true){
        cout << "which position you wanna delete : ";
        cin >> delposs;
        ptr = head;
        if(delposs >=1 && delposs <= count){
            int i = 1;
            while(i <= count){
                if(delposs == 1){
                    node *temp = ptr->next;
                    head = NULL;
                    head = temp;
                    cout << "first value deleted.." << endl;
                    break;
                }
                else if(i == delposs-1){
                    node *temp = ptr;
                    ptr = ptr->next;
                    cout << ptr->data << endl;
                    temp->next = ptr->next;
                    ptr = NULL;
                    ptr = temp;
                    cout << "deleted successfully.." << endl;
                    break;
                }
                i++;
                ptr = ptr->next;
            }
           
            break;
        }else {
            cout << "doesn't match the position"<< endl;
        }
    }
   
   
   
}

int main() {
   
    node *head = NULL;
    int user,userVal,count;
   
    do{
        cout << "--------Select Option--------"<< endl;
        cout << "1.Insert"<<endl;
        cout << "2.Read"<<endl;
        cout << "3.Update"<<endl;
        cout << "4.Delete"<<endl;
        cout << "0.Exit"<<endl;
        cout << "------------------------------"<< endl;
        cout << "Choose : ";
       
        cin >> user;
       
        switch(user){
            case 1:
                int userop;
                while(true){
                    cout << "1. Insert at Start "<< endl;
                    cout << "2. Insert at any position "<< endl;
                    cout << "3. Insert at End. "<< endl;
                    cout << "------------------------------"<< endl;
                    cout << "Choose : ";
                    cin >> userop;
                   
                    if(userop >= 1 && userop <=3 ){
                       break;
                       
                    }else{
                        cout << "Doesn't match the option.."<< endl;
                    }
                }
                    switch(userop){
                            case 1:
                                cout << "Enter the value : ";
                                cin >> userVal;
                               
                                InsertSt(userVal,head);
                                break;
                            case 2:  
                                int poss;
                                if(head != NULL){
                                   
                                read(head);
                               
                                cout << endl;
                                cout << "Enter the value to add after : ";
                                cin >> poss;
                               
                                cout << "Enter the value : ";
                                cin >> userVal;
                               
                               
                                InsertAfterValue(userVal,poss,head);
                                }else {
                                    cout << "Need to fill nodes.."<< endl;
                                }
                               
                                break;
                            case 3:
                                cout << "Enter the value : ";
                                cin >> userVal;
                               
                                if(head != NULL){
                                    InsertEnd(userVal,head);
                                   
                                }else{
                                    cout << "Need to fulfill nodes..."<< endl;
                                }
                                break;
                        }
               
                break;
            case 2:
                if(head != NULL){
                    read(head);
                    cout << endl;
                   
                }else{
                    cout << "node is empty"<< endl;
                }
                break;
            case 3:
                if(head != NULL){
                    read(head);
                    cout << endl;
                    update(head);
                    cout << "Updated successfully..."<< endl;
                }else {
                    cout << "Need to insert values." << endl;
                }
                break;
            case 4:
                if(head != NULL){
                    read(head);
                    cout << endl;
                    deleteNode(head);
                }else {
                    cout << "There's no node to delete.." << endl;
                }
                break;
            default :
                cout << "Invalid input "<< endl;
                break;
        }
       
    }while(user != 0);
}
