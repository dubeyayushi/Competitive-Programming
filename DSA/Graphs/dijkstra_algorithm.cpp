#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
#include<unordered_set>
#define ll long long int
#define pp pair<int, int>

using namespace std; 

vector<list<pp> >graph;

void add_edge(int x, int y, int w, bool bi_dir = true){
    graph[x].push_back({y, w});
    if (bi_dir) graph[y].push_back({x, w});
}

unordered_map<int, int> dijkstra(int src, int v){   // O(vlogv + elogv)
    priority_queue<pp, vector<pp>, greater<pp> >pq;
    unordered_set<int>visited;
    vector<int>via(v+1);
    unordered_map<int, int>mp;
    for (int i = 0; i<v; i++){  // O(v)
        mp[i] = INT_MAX;
    }
    pq.push({0, src});
    mp[src] = 0;
    while(!pq.empty()){    // O((v+e)logv) 
        pp curr = pq.top();
        if (visited.count(curr.second)){
            pq.pop();
            continue;
        }
        visited.insert(curr.second);
        pq.pop();
        for (auto neighbour : graph[curr.second]){  //O(v + e)
            if (!visited.count(neighbour.first) && mp[neighbour.first] > mp[curr.second] + neighbour.second){
                pq.push({mp[curr.second] + neighbour.second, neighbour.first});
                via[neighbour.first] = curr.second;
                mp[neighbour.first] = mp[curr.second] + neighbour.second;
            }
        }
    }
    return mp;
}

int main(){
    
    int v, e;
    cin >> v >> e;

    graph.resize(v, list<pp>());

    while(e--){
        int x, y, w;
        cin >> x >> y >> w;
        add_edge(x, y, w);
    }

    int src;
    cin >> src;
    unordered_map<int, int> sp = dijkstra(src, v);
    int dest;
    cin >> dest;
    cout << sp[dest] << endl;
    return 0;
}