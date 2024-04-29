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

class Deque{
public:
    Node* head;
    Node* tail;
    int size;
    Deque(){
        head = tail = NULL;
        size = 0;
    }
    void pushFront(int val){
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
    void pushBack(int val){
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
    void popFront(){
        if (size==0){
            cout << "Deque is empty!" << endl;
            return;
        }
        head = head->next;
        head->prev = NULL;
        size--;
    }
    void popBack(){
        if (size==0){
            cout << "Deque is empty!" << endl;
            return;
        }
        tail = tail->prev;
        tail->next = NULL;
        size--;
    }
    int front(){
        if (size==0){
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return head->val;
    }
    int back(){
        if (size==0){
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return tail->val;
    }
    void display(){
        Node* temp = head;
        while(temp){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    Deque dq;
    dq.popBack();
    dq.pushFront(10);
    dq.pushBack(20);
    dq.pushFront(30);
    dq.display();
    dq.pushBack(40);
    dq.pushFront(50);
    dq.display();
    dq.pushFront(60);
    dq.display();
    dq.popBack();
    dq.popFront();
    dq.display();
}