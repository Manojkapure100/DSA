#include<iostream>
#include <vector>
#include "utils.h"

using namespace std;

int main(){
    vector<int> a = {0};
    int i = 0;
    a[++i] = 2;
    printVector(a);
}