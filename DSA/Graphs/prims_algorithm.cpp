/*
    - Data Structures - visited set, priority queue, unordered map
    - insert the pair of <-1, src> in the priority queue
    - one by one remove the root element of the priority queue
    - if the root elelment is already visited then we will just continue
    - we mark the root visited
    - we store the weight of the pair in the ans
    - update the mapping
    - go to every neighbour of the curr element, and add only those which are non-visited and have a better weight proposition
*/


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

ll prims(int src, int v){
    priority_queue<pp, vector<pp>, greater<pp> >pq;
    unordered_set<int>visited;
    vector<int>parent(v+1);
    unordered_map<int, int>mp;
    for (int i = 1; i<=v; i++){
        mp[i] = INT_MAX;
    }
    pq.push({0, src});
    mp[src] = -1;
    int total_count = 0; // 0 -> v-1
    int result = 0;
    while(total_count<v && !pq.empty()){
        pp curr = pq.top();
        if (visited.count(curr.second)){
            pq.pop();
            continue;
        }
        visited.insert(curr.second);
        total_count++;
        result += curr.first;
        pq.pop();
        for (auto neighbour : graph[curr.second]){
            if (!visited.count(neighbour.first) && mp[neighbour.first] > neighbour.second){
                pq.push({neighbour.second, neighbour.first});
                parent[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second;
            }
        }
    }
    return result;
}

int main(){
    
    int v, e;
    cin >> v >> e;

    graph.resize(v+1, list<pp>());

    while(e--){
        int x, y, w;
        cin >> x >> y >> w;
        add_edge(x, y, w);
    }

    int src;
    cin >> src;

    cout << prims(src, v) << endl;
    return 0;
}