#include<iostream>
#include<vector>

using namespace std;

//this method returns which group/cluster x belongs to 
int find(vector<int>& parent, int x){
    return parent[x] = (parent[x]==x) ? x : parent[x] = find(parent, parent[x]);
}

void Union(vector<int>& parent, vector<int>& rank, vector<int>& sz, vector<int>& maximal, vector<int>& minimal, int a, int b){
    a = find(parent, a);
    b = find(parent, b);

    if (a==b) return;

    if (rank[a]<rank[b]){
        parent[a] = b;
        sz[b] += sz[a];
        maximal[b] = max(maximal[b], maximal[a]);
        minimal[b] = min(minimal[b], minimal[a]);
        rank[b]++;
    }
    else{
        parent[b] = a;
        sz[a] += sz[b];
        maximal[a] = max(maximal[b], maximal[a]);
        minimal[a] = min(minimal[b], minimal[a]);
        rank[a]++;
    }
}
 
int main(){
    int n, m;   // n-> number of elements, m-> number of queries
    cin >> n >> m;
    vector<int>parent(n+1);
    vector<int>rank(n+1, 0);
    vector<int>sz(n+1, 1);
    vector<int>maximal(n+1);
    vector<int>minimal(n+1);
    for (int i = 0; i<=n; i++){
        parent[i] = maximal[i] = minimal[i] = i;
    }
    while(m--){
        string str;
        cin >> str;
        if (str=="union"){
            int x, y;
            cin >> x >> y;
            Union(parent, rank, sz, maximal, minimal, x, y);
        }
        else{
            int x;
            cin >> x;
            x = find(parent, x);
            cout << minimal[x] << " " << maximal[x] << " " << sz[x] << endl;
        }
    }
}