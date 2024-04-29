#include<iostream>
using namespace std;
 
class Node{ //user defined data type
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
    }
};

class LinkedList{ // user defined data structure
public:
    Node* head;
    Node* tail;
    int size;
    LinkedList(){
        head = tail = NULL;
        size = 0;
    }
    void insertAtEnd(int val){
        Node* temp = new Node(val);
        if (size==0){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void insertAtHead(int val){
        Node* temp = new Node(val);
        if (size == 0){
            head = tail = temp;
        }
        else{
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void insertAtIndex(int val, int idx){
        if (idx<0 || idx>size){
            cout << "Invalid Index" << endl;
        }
        else if (idx==size){
            insertAtEnd(val);
        }
        else if (idx==0){
            insertAtHead(val);
        }
        else{
            Node* t = new Node(val);
            Node* temp = head;
            for (int i = 1; i<=idx-1; i++){
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }
    void getAtIdx(int idx){
        if (idx<0 || idx>=size){
            cout << "Invalid Index" << endl;
        }
        else if (idx==0){
            cout << head->val << endl;
        }
        else if (idx==size-1){
            cout << tail->val << endl;
        }
        else{
            Node* temp = head->next;
            for (int i = 1; i<idx; i++){
                temp = temp->next;
            }
            cout << temp->val << endl;
        }
    }
    void deleteAtHead(){
        if (size==0){
            cout << "List is empty";
        }
        else if (size==1){
            head = tail = NULL;
            size--;
        }
        else{
            head = head->next;
            size--;
        }
    }
    void deleteAtTail(){
        if (size==0){
            cout << "List is empty";
        }
        else if (size==1){
            head = tail = NULL;
            size--;
        }
        else{
            Node* temp = head;
            for (int i = 1; i<size-1; i++){
                temp = temp->next;
            }
            temp->next = NULL;
            size--;
        }
    }
    void deleteAtIdx(int idx){
        if (idx<0 || idx>=size){
            cout << "Invalid Index" << endl;
        }
        else if (idx==0){
            deleteAtHead();
        }
        else if (idx==size-1){
            deleteAtTail();
        }
        else{
            Node* temp = head;
            for (int i = 1; i<idx-1; i++){
                temp = temp->next;
            }
            temp->next = temp->next->next;
            size--;
        }
    }
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    Node* middle(){
        Node* temp = head;
        int size = 0;
        while(temp->next!=NULL){
            size++;
            temp = temp->next;
        }
        cout << "Size: " << size;
        temp = head;
        int count = 0;
        while(count<size/2){
            temp = temp->next;
            count++;
        }
        return temp;
    }
};

int main(){
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtHead(50);
    ll.insertAtIndex(40, 1);
    ll.display();
    Node* middle = ll.middle();
    cout << middle->val << endl;
}