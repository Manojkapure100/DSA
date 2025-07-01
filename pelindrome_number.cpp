#include<iostream>

int getRevNo(int n){
    int ans = 0;
    while(n!=0){
        int lastDigit = n % 10;
        ans = (ans*10)+lastDigit;
        n = n/10;
    }
    std::cout << "reverse: " << ans << "\n";
    return ans;
}

int main(){
    int number = 3235;
    int revNumber = getRevNo(number);
    if(number==revNumber){
        std::cout << "\n number " << number << " Pelindrome\n";
    } else {
       std::cout << "\n number " << number << " is not Pelindrome\n";
    }
    return 0;
}