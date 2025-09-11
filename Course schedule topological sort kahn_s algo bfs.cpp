#include<iostream>
#include "utils.h"

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjencyList(numCourses); // pairs of pre and course
    vector<int> indegree(numCourses, 0); // to store incoming points to node

    for(int i=0; i<numCourses; i++){
        for(auto &pre : prerequisites){
            int course = pre[0];
            int requiredCourse = pre[1];
            adjencyList[requiredCourse].push_back(course);
            indegree[course]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    int completed = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        completed++;

        for(int course : adjencyList[node]){
            indegree[course]--;
            if(indegree[course] == 0){
                q.push(course);
            }
        }
    }

    return completed == numCourses;
    
}

int main(){
    vector<vector<int>> prerequisites;
    // prerequisites = {{1,0}};
    prerequisites = {{1,0},{0,1}};
    int numCourses = 2;

    if(canFinish(numCourses, prerequisites)){
        cout << "it can finish because it is topological";
    } else {
        cout << "it can't finish because it is not a topological";
    }
    cout << endl;

    return 0;
}