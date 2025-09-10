#include<iostream>
#include "utils.h"

using namespace std;

bool DFS(int node, int color, vector<int> &colorArr, vector<vector<int>> &graph){
    colorArr[node] = color;

    for (int neighbour : graph[node]){
        if(colorArr[neighbour] == -1){
            int newColor = color == 1 ? 0 : 1;
            if(DFS(neighbour, newColor, colorArr, graph) == false){
                return false;
            }
        } else {
            if(colorArr[neighbour] == color){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    vector<int> colorArr(graph.size(), -1);

    for (int node = 0; node < graph.size(); node++)
    {
        if(colorArr[node] == -1){
            if(DFS(node, 0, colorArr, graph) == false){
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<int>> graph;
    graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    // graph = {{1,3},{0,2},{1,3},{0,2}};
    bool bipartite = isBipartite(graph);
    if(bipartite){
        cout << "It is bipartite";
    } else {
        cout << "It is not bipartite";
    }
    cout << endl;
    return 0;
}