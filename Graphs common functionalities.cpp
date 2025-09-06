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

    void printGraphNodes(){
        for (int i = 0; i < this->totalVertises; i++)
        {
            cout << i << " : ";
            for (int node: virtisesList[i])
            {
                cout << node << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void printBFS(){
        queue<int> q;
        vector<bool> visited(this->totalVertises, false);

        q.push(0);
        visited[0] = true;
        cout << "BFS: ";
        while(!q.empty()){
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int value : virtisesList[current])
            {
                if(visited[value] == false){
                    q.push(value);
                    visited[value] = true;
                }
            }
        }
        cout << endl;
    }

    void printDFSRecursivelyHelper(int nodeIndex, vector<bool> &visited){
        cout << nodeIndex << " ";
        visited[nodeIndex] = true;

        for (int ind : virtisesList[nodeIndex])
        {
            if(visited[ind] == false){
                printDFSRecursivelyHelper(ind, visited);
            }
        }
    }

    void printDFSRecursively(){
        vector<bool> visited(this->totalVertises, false);
        cout << "DFS: ";
        printDFSRecursivelyHelper(0, visited);
        cout << endl;
    }
};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,2);

    g.printGraphNodes();
    g.printBFS();
    g.printDFSRecursively();

    return 0;
}