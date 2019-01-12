#include<iostream>
using namespace std;

class Node{
    //data
    public:
    int data;
    //pointer to the next node
    Node *next;
    //constructor that makes pointer point to NULL

    Node(){
        next = NULL;
    }

};

class Linkedlist{
    //pointer to the first element
    Node* head;
    //pointer to the last element
    Node* tail;
    //constructor to point them to NULL
    public:
    Linkedlist(){
        head = NULL;
        tail = NULL;
    }

    void Insert(int val){

        //creating a new node in heap
            Node* temp = new Node;
        //inserting data in the new node
            temp->data = val;
        //in case of insertion of first element
             if(head==NULL && tail==NULL){
            head = temp;
        }
       else{
       tail->next=temp;
       }
       tail = temp;
    }
    int CountItems(){
        //make the pointer counter
        Node* Count = head;
        //looping thr counter
        int i=1;
        while(Count->next != tail){
                i++;
            Count=Count->next;
        }
        return i+1;
    }
    void InsertAt(int pos, int val){
        //create a new node
        Node*temp = new Node;
        //insert data in it
        temp->data = val;
        //
        if(pos==1){
            head = temp;
            tail = temp;
        }
        else{
        //counter should be at last element)
            //moving the pointer
              Node* current = head;
              int i=1;
            while(i<pos-1){
                    i++;
                current = current->next;
            }
            temp->next = current->next;
            current->next=temp;
        }

    }

    void Display(){
        //initialize the pointer
            Node* current = head;
        while(current != NULL){
            cout<< current->data<< "->";
            current=current->next;
        }
        cout<< "NULL"<<endl;
    }
    void Delete(){
        //storing last element temporarily
        Node* temp = tail;
        //moving tail to the second last element
        Node* current = head;
        while(current->next != tail){
            current = current->next;
        }
        current->next = NULL;
        tail = current;
        delete temp;

    }
    void DeleteAt(int pos){
        //moving tail to the second last element
       //moving the pointer
          Node* current = head;
          int i=1;
        while(i<pos-1){
                i++;
            current = current->next;
        }
        //storing the node to be deleted in the temp
         Node* temp = current->next;
        //linking further nodes to the previous ones
         current->next = temp->next;
        delete temp;
    }

};




int main(){
    Linkedlist l1;
    int m,n,o,p,q,r,s,t;
    cout<< "please enter the '8' elements you want to take in the  list: "<<endl;
    cin>>m;
    cin>>n;
    cin>>o;
    cin>>p;
    cin>>q;
    cin>>r;
    cin>>s;
    cin>>t;
    l1.Insert(m);
    l1.Insert(n);
    l1.Insert(o);
    l1.Insert(p);
    l1.Insert(q);
    l1.Insert(r);
    l1.Insert(s);
    l1.Insert(t);
    l1.Display();

    int x,y;
    cout<< "please enter the position at which you want to insert and the elements you want to insert respectively: "<<endl;
    cin>>y;
    cin>>x;
    int a = l1.CountItems();
    if(y<=a){
        l1.InsertAt(y,x);
    }
    else cout<<"Linked List does not have that many elements "<<endl;

    l1.Display();
    l1.Delete();
    l1.Display();
    int b;
    cout<< "Please select the position you want the node to be deleted at: "<<endl;
    cin>> b;
    l1.DeleteAt(b);
    l1.Display();
    cout<< "The number of items in your list is "<< l1.CountItems()<<endl;
    return 0;
}
