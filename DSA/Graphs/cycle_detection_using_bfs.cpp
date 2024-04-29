#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<queue>
using namespace std;
 
vector<list<int> >graph;
int v;  // number of vertices

void add_edge(int x, int y, bool bi_dir=true){
    graph[x].push_back(y);
    if (bi_dir) graph[y].push_back(x);
}

void display(){
    for (int i = 0; i<v; i++){
        cout << i << " -> ";
        for (auto neighbour : graph[i]){
            cout << neighbour << ", ";
        }
        cout << endl;
    }
}

bool bfs(int src){
    unordered_set<int>visited;
    queue<int>q;
    vector<int>parent(v, -1);
    visited.insert(src);
    q.push(src);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for (auto neighbour : graph[curr]){
            if (visited.count(neighbour) && parent[curr]!=neighbour){
                return true;
            }
            if (!visited.count(neighbour)){
                visited.insert(neighbour);
                q.push(neighbour);
                parent[neighbour] = curr;
            }
        }
    }
    return false;
}

int main(){
    cin >> v;
    graph.resize(v, list<int>());
    int e;
    cin >> e;
    while(e--){
        int x, y;
        cin >> x >> y;
        add_edge(x, y, false);
    }
    display();
    bool cycle = bfs(0);
    if (cycle){
        cout << "Cycle Detected" << endl;
    }
}