#include<iostream>
#include<queue>
using namespace std;
 
void removeElementsAtEvenIndex(queue<int>&q){
    int n = q.size();
    for (int i = 0; i<n; i++){
        if(i%2!=0){
            q.push(q.front());
        }
        q.pop();
    }
}

void display(queue<int>&q){
    int n = q.size();
    for (int i = 0; i<n; i++){
        int x = q.front();
        cout << x << " ";
        q.pop();
        q.push(x);
    }
    cout << endl;
}

int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    display(q);
    removeElementsAtEvenIndex(q);
    display(q);
}