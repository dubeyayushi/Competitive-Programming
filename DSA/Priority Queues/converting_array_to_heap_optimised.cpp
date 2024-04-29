#include<iostream>
#include<vector>
using namespace std;
 
class MaxHeap{
    vector<int>hp;
    int i;
    void upheapify(int ci){
        while(ci>0){
            int pi = (ci-1)/2;
            if (hp[pi]<hp[ci]){
                swap(hp[pi], hp[ci]);
                ci = pi;
            }
            else{
                break;
            }
        }
    }

    void downheapify(int idx){
        while(idx<hp.size()){
            int lc = 2*idx+1;
            int rc = 2*idx+2;
            if (lc>=hp.size()){
                break;
            }
            int maxele = idx;
            if (hp[lc]>hp[maxele]){
                maxele = lc;
            }
            if (rc<hp.size() && hp[rc]>hp[maxele]){
                maxele = rc;
            }
            if (maxele!=idx){
                swap(hp[idx], hp[maxele]);
                idx = maxele;
            }
            else{
                break;
            }
        }
    }

public:
    void push(int element){
        hp.push_back(element);
        upheapify(hp.size()-1);
    }
    void pop(){
        //removes the highest priority element
        if (empty()){
            return;
        }
        swap(hp[0], hp[hp.size()-1]);
        hp.pop_back();
        if (!empty()){
            downheapify(0);
        }
    }
    int peek(){
        if (empty()){
            return INT_MIN;
        }
        return hp[0];
    }

    bool empty(){
        return hp.size()==0;
    }

    void display(){
        cout << "[" ;
        for(int i = 0; i<hp.size(); i++){
            cout << hp[i] << " ";
        }
        cout << "]" << endl;
    }
    MaxHeap(vector<int>v){
        hp = v;
        int n = hp.size();
        for (int i = n/2; i>=0; i--){
            downheapify(i);
        }
    }
};

int main(){
    vector<int> v = {9, 6, 1, 19, 3, 2, 8, 12, 5};
    MaxHeap hp(v);
    hp.display();
    hp.push(100);
    hp.display();
}