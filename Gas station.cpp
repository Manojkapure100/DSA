#include<iostream>
#include <vector>

using namespace std;

int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
    // if total gas is less then totalCost of travelling then there is no answer
    int totalCost = 0;
    int totalGas = 0;

    for(int value : gas){
        totalGas += value;
    }

    for(int value : cost){
        totalCost += value;
    }

    if(totalGas < totalCost){
        return -1;
    }

    // Atlease 1 solution is exist
    // go to each index, calculate current gas and using current gas try to go to next station
    // if we can't go with current gas then start from i+1 index with 0 currentGas
    int currentGas = 0;
    int start = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        // currentGas is currentGas + gas[i] - cost[i], if it is positive
        currentGas += (gas[i] - cost[i]);
        if(currentGas < 0){
            start = i+1;
            currentGas = 0;
        }
    }
    
    return start;
}

int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
    int start = 0;
    int currentGas = 0;
    int totalGas = 0;
    int totalCost = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        totalCost += cost[i];
        totalGas += gas[i];

        currentGas += (gas[i] - cost[i]);
        if(currentGas < 0){
            start = i+1;
            currentGas = 0;
        }
    }

    if(totalGas < totalCost){
        return -1;
    } else {
        return start;
    }
}

int main(){
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    int ans;
    // ans = canCompleteCircuit1(gas,cost);
    ans = canCompleteCircuit2(gas,cost);
    cout << "Ans: " << ans << endl;
    return 0;
}