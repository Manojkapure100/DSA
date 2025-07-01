#include<iostream>
#include<cmath>

int getMeGCDOf(int a,int b){
    int ans = -1;
    for(int i=1;i<=std::min(a,b);i++){
        if(a%i==0 && b%i==0){
            ans = i;
        }
    }
    return ans;
}

int getMeRecursivelyGCDOf(int big,int small){
    if(small==0){
        return big;
    }
    return getMeRecursivelyGCDOf(small, big % small);
}

int getMeLCMOf(int a,int b){
    int GCD = getMeRecursivelyGCDOf(a,b);
    std::cout << "\nGCD: " << GCD <<"\n";
    int LCM = (a*b)/GCD;
    return LCM;
}

int main(){
    int a=20, b=28;
    int LCM = getMeLCMOf(a,b);
    std::cout << "\nLCM: " << LCM <<"\n";
    return 0;
}