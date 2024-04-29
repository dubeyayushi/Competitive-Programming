#include<iostream>
#include<vector>

using namespace std;

//this method returns which group/cluster x belongs to 
int find(vector<int>& parent, int x){
    return parent[x] = (parent[x]==x) ? x : parent[x] = find(parent, parent[x]);
}

void Union(vector<int>& parent, vector<int>& rank, int a, int b){
    a = find(parent, a);
    b = find(parent, b);

    if (a==b) return;

    if (rank[a]<rank[b]){
        parent[a] = b;
        rank[b]++;
    }
    else{
        parent[b] = a;
        rank[a]++;
    }
}
 
int main(){
    int n, m;   // n-> number of elements, m-> number of queries
    cin >> n >> m;
    vector<int>parent(n+1);
    vector<int>rank(n+1, 0);
    for (int i = 0; i<=n; i++){
        parent[i] = i;
    }
    while(m--){
        string str;
        cin >> str;
        if (str=="union"){
            int x, y;
            cin >> x >> y;
            Union(parent, rank, x, y);
        }
        else{
            int x;
            cin >> x;
            cout << find(parent, x) << endl;
        }
    }
}