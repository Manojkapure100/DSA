#include<iostream>

using namespace std;

int NFactorial(int n){
    if(n==0){
        return 1;
    }
    return n * NFactorial(n-1);
}

int main(){
    int number = 5;
    int result = NFactorial(number);
    cout << "result: " << result;
    return 0;
}