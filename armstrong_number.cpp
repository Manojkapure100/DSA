#include<iostream>

int main(){
    int number = 153;
    bool isArmstrong = false;
    int duplicateNumber = number;
    int sum = 0;
    while(duplicateNumber != 0){
        int digit = duplicateNumber % 10;
        sum += (digit*digit*digit);
        duplicateNumber /= 10;
    }
    std::cout << "\nNumber " << number << " is armstrong: " << ((sum==number) ? "Yes" : "No") << "\n";
    return 0;
}