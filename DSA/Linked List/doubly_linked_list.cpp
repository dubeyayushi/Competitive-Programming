#include<iostream>
using namespace std;
 
class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class doublyLinkedList{
public:
    Node* head;
    Node* tail;
    int size;
    doublyLinkedList(){
        head = tail = NULL;
        size = 0;
    }
    void insertAtHead(int val){
        Node* temp = new Node(val);
        if (size==0){
            head = tail = temp;
        }
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }
    void insertAtTail(int val){
        Node* temp = new Node(val);
        if (size==0){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }
    void insertAtIdx(int val, int idx){
        if (idx>=size){
            cout << "Invalid index" << endl;
        }
        else if (idx>(size-1)/2){
            Node* temp = tail;
            int count = size-1;
            while(count!=(size-1-idx)){
                temp = temp->prev;
                count--;
            }
            Node* newnode = new Node(val);
            newnode->prev = temp->prev;
            newnode->next = temp;
            size++;
        }
        else{
            Node* temp = head;
            int count = 0;
            while(count!=idx){
                temp = temp->next;
                count++;
            }
            Node* newnode = new Node(val);
            temp->prev->next = newnode;
            newnode->next = temp;
            newnode->prev = temp->prev;
            temp->prev = newnode;
            size++;
        }
    }
    void getAtIdx(int idx){
        if (idx>=size){
            cout << "Invalid index" << endl;
        }
        else if (idx>(size-1)/2){
            Node* temp = tail;
            int count = size-1;
            while(count!=(size-1-idx)){
                temp = temp->prev;
                count--;
            }
            cout << temp->val << endl;
        }
        else{
            Node* temp = head;
            int count = 0;
            while(count!=idx){
                temp = temp->next;
                count++;
            }
            cout << temp->val << endl;
        }
    }
    void deleteAtHead(){
        head = head->next;
        head->prev = NULL;
    }
    void deleteAtTail(){
        tail = tail->prev;
        tail->next = NULL;
    }
    void deleteAtIdx(int idx){
        Node* temp = head;
        int count = 0;
        while(count!=idx){
            temp = temp->next;
            count++;
        }
        temp->prev->next = temp->next;
        size--;
    }
    void display(){
        Node* temp = head;
        while(temp){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void displayReverse(){
        Node* temp = tail;
        while(temp){
            cout << temp->val << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};
int main(){
    doublyLinkedList ll;
    ll.insertAtTail(10);
    ll.insertAtTail(20);
    ll.insertAtHead(50);
    ll.insertAtIdx(40, 1);
    ll.display();
    ll.displayReverse();
    ll.getAtIdx(1);
    ll.deleteAtIdx(1);
    ll.display();
}