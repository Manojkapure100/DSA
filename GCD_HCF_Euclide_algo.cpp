#include<iostream>

int bySimpleApproch(int n1,int n2){
    int ans = -1;
    while(n1 != 0 && n2 !=0){
        if(n1>n2){
            n1 = n1%n2;
        } else {
            n2 = n2%n1;
        }
    }
    ans = n1==0 ? n2 : n1;
    return ans;
}

int byRecursionApproch(int big, int small){
    if(small == 0){
        return big;
    }
    return byRecursionApproch(small, big % small);
}

int main(){
    int n1 = 20, n2=30;
    int ans = -1;
    ans = (n1==0) ? n2 : -1;
    ans = (n2==0) ? n1 : -1;
    if(ans!=-1){
        std::cout << "\nGCD or HCF of " << n1 << " and " << n2 << " is " << ans << "\n";
        return 0;
    }
    ans = bySimpleApproch(n1,n2);
    ans = byRecursionApproch(n1,n2);
    std::cout << "\nGCD or HCF of " << n1 << " and " << n2 << " is " << ans << "\n";
    return 0;
}