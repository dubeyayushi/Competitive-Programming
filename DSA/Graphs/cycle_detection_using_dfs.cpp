#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
 
vector<list<int> >graph;
int v; // no of vertices

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if (bi_dir){
        graph[dest].push_back(src);
    }
}

void display(){
    for (int i = 0; i<graph.size(); i++){
        cout << i << "->";
        for (auto ele : graph[i]){
            cout << ele << " , ";
        }
        cout << endl;
    }
}

bool dfs(int src, int parent, unordered_set<int>& vis){
    vis.insert(src);
    for (auto neighbour : graph[src]){
        if (vis.count(neighbour) && neighbour!=parent){
            //cycle detected
            cout << "Cycle Detected" << endl;
            return true;
        }
        if (!vis.count(neighbour)){
            bool res = dfs(neighbour, src, vis);
            if (res==true) return true;
        }
    }
    return false;
}

bool hasCycle(){
    unordered_set<int>visited;
    bool result = false;
    for (int i = 0; i<v; i++){
        if (!visited.count(i)){
            result = dfs(i, -1, visited);
            if (result==true) return true;
        }
    }
    return false;
}

int main(){
    cin >> v;
    graph.resize(v, list<int> ());
    int e;
    cin >> e;
    while(e--){
        int s, d;
        cin >> s >> d;
        add_edge(s, d, false);
    }
    display();
    bool b = hasCycle();
    cout << b << endl;
}