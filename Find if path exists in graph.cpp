#include<iostream>
#include<list>
#include "utils.h"

using namespace std;

class Graph{
    int totalVertises;
    list<int> *virtisesList;

public:
    Graph(int numberOfVertisus){
        this->totalVertises = numberOfVertisus;
        this->virtisesList = new list<int>[numberOfVertisus];
    }

    void addEdge(int firstNodeValue, int secondNodeValue){
        virtisesList[firstNodeValue].push_back(secondNodeValue);
        virtisesList[secondNodeValue].push_back(firstNodeValue);
    }

    bool findDestination(int source, int destination){
        queue<int> q;
        vector<bool> visited(this->totalVertises,false);

        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int current = q.front();
            if(current == destination) return true;
            q.pop();
            for(int neighbour : virtisesList[current]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        return false;
    }
};

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    Graph g(n);
    for(vector<int> singleVector : edges){
        g.addEdge(singleVector[0], singleVector[1]);
    }
    return g.findDestination(source, destination);
}

int main(){
    int size = 3;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    int source = 0;
    int destination = 2;

    bool valid = validPath(size, edges, source, destination);

    if(valid){
        cout << "Path is valid";
    } else {
        cout << "Path is not valid";
    }
    cout << endl;
    return 0;
}