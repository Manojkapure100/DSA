#include<iostream>
#include<cmath>

int main(){
    int a = 20, b = 28;
    int ans = -1;
    ans = (a==0) ? b : -1;
    ans = (b==0) ? a : -1;
    if(ans!=-1){
        std::cout << "\nGCD or HCF of " << a << " and " << b << " is " << ans << "\n";
        return 0;
    }
    int maxPossibleGCD = std::min(a,b);
    for (int i = 1; i <= maxPossibleGCD; i++){
        if(a%i==0 && b%i==0){
            ans = i;
        }
    }
    std::cout << "\nGCD or HCF of " << a << " and " << b << " is " << ans << "\n";
}