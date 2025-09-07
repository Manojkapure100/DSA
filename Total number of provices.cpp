#include<iostream>
#include<list>
#include <vector>

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
        this->virtisesList[firstNodeValue].push_back(secondNodeValue);
        this->virtisesList[secondNodeValue].push_back(firstNodeValue);
    }

    void dfs(int value, vector<int> &visited){
        visited[value] = true;
        for (int v : this->virtisesList[value])
        {
            if(!visited[v]){
                this->dfs(v, visited);
            }   
        }
    }

    int totalProvinces(){
        vector<int> visited(this->totalVertises, false);
        int count = 0;

        for(int i=0; i<this->totalVertises; i++){
            if(!visited[i]){
                count++;
                this->dfs(i, visited);
            }
        }

        return count;
    }
};

int findCircleNum(vector<vector<int>>& isConnected) {
    int size = isConnected.size();
    Graph g(size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(isConnected[i][j] == 1 && i != j){
                g.addEdge(i,j);
            }
        }
    }
    return g.totalProvinces();
}

int main(){
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    int ans = findCircleNum(isConnected);
    cout << "Total Provinces: " << ans << endl;
    return 0;
}