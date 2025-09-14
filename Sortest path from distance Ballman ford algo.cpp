#include<iostream>
#include "utils.h"

using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dis(V, 1e8);
    dis[src] = 0;

    // n-1 relaxation to find sortest path
    for (int i = 0; i < V-1; i++)
    {
        for(auto edge : edges){
            int source = edge[0];
            int destination = edge[1];
            int weight = edge[2];

            if(dis[source] != 1e8 && dis[source] + weight < dis[destination]){
                dis[destination] = dis[source] + weight;
            }
        }
    }

    // nth relaxation if it contain nagative cycle
    for(auto edge : edges){
        int source = edge[0];
        int destination = edge[1];
        int weight = edge[2];

        if(dis[source] != 1e8 && dis[source] + weight < dis[destination]){
            return {-1};
        }
    }

    return dis;
}

int main(){
    int totalNode = 4;
    int source = 2;
    vector<vector<int>> edges;
    edges = {{1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}};
    // edges = {{2,1,1},{2,3,1}, {3,4,1}};
    vector<int> ans = bellmanFord(totalNode, edges, source);
    printVector(ans, "ans: ");
    return 0;
}