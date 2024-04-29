#include<iostream>
#include<vector>
using namespace std;
 
#define ll long long int


int find(vector<int>&parent, int x){
    return parent[x] = (x==parent[x]) ? x : find(parent, parent[x]);
}

void Union(vector<int>&parent, vector<int>&rank, int a, int b){
    a = find(parent, a);
    b = find(parent, b);

    if (a==b) return;

    if (rank[b]<=rank[a]){
        parent[b] = a;
        rank[a]++;
    }
    else{
        parent[a] = b;
        rank[b]++;
    }
}

struct Edge{
    int src;
    int dest;
    int wt;
};

bool cmp(Edge e1, Edge e2){ // O(ElogE)
    return e1.wt<e2.wt;
}

ll kruskal (vector<Edge>&input, int v, int e){
    sort(input.begin(), input.end(), cmp);
    vector<int>parent(v+1);
    vector<int>rank(v+1, 0);
    for (int i = 0; i<v+1; i++){
        parent[i] = i;
    }
    int edgeCount = 0;  //v-1   // O(v x log*v) --> O(v)
    int i = 0;
    ll ans = 0;
    while(edgeCount<v-1 && i<input.size()){
        Edge curr = input[i];   // because array is sorted, we will get minimum weight
        int srcParent = find(parent, curr.src);
        int destParent = find(parent, curr.dest);
        if (srcParent!=destParent){
            // include edge as this will not make cycle
            Union(parent, rank, srcParent, destParent);
            ans += curr.wt;
            edgeCount++;
        }
        i++;    // doesn't matter you picked the last edge or not, we still need to go to the next edge
    }
    return ans;
}

int main(){
    int v, e;
    cin >> v >> e;

    vector<Edge>edges(e);
    for (int i = 0; i<e; i++){
        cin >> edges[i].src >> edges[i].dest >> edges[i].wt;
    }
    cout << kruskal(edges, v, e) << endl;   // total time complexity = O(v + ElogE)
}