#include<iostream>

using namespace std;

int fb(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return fb(n-1) + fb(n-2);
}

int main(){
    int number = 6;
    int result = fb(number);
    cout << "Result: " << result;
    return 0;
}