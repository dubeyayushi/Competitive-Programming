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

    void downheapify(int idx, int bound){
        while(idx<hp.size()){
            int lc = 2*idx+1;
            int rc = 2*idx+2;
            if (lc>=bound){
                break;
            }
            int maxele = idx;
            if (hp[lc]>hp[maxele]){
                maxele = lc;
            }
            if (rc<bound && hp[rc]>hp[maxele]){
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
        //hp.pop_back();
        i--;
        if (!empty()){
            downheapify(0, i);
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
        for(int j = 0; j<i; j++){
            cout << hp[j] << " ";
        }
        cout << "]" << endl;
    }
    MaxHeap(vector<int>v){
        hp = v;
        int n = hp.size();
        i = n;
        for (int j = n/2; j>=0; j--){
            downheapify(j, i);
        }
    }
    vector<int> heapsort(){
        int size = hp.size();
        while(size>0){
            int el = 0;
            swap(hp[el], hp[i]);
            i--;
            size--;
            downheapify(0, i);
        }
        return hp;
    }
};

void heapsort(vector<int> &v){
    MaxHeap hp(v);
    v = hp.heapsort();
}

int main(){
    vector<int> v = {9, 6, 1, 19, 3, 2, 8, 12, 5};
    MaxHeap hp(v);
    hp.display();
    hp.push(100);
    hp.display();
    heapsort(v);
    cout << "[" ;
    for(int j = 0; j<v.size(); j++){
        cout << v[j] << " ";
    }
    cout << "]" << endl;
}