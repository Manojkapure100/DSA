#include<iostream>

int main(){
    int number = 79842;
    int revNumber = 0;
    while(number!=0){
        int lastDigit = number % 10;
        // if(revNumber > std::INT_MAX/10 || revNumber < std::INT_MIN/10){
        //     return 0;
        // }
        revNumber = (revNumber*10) + lastDigit;
        number = number / 10;
    }
    std::cout << "\nReverse number: " << revNumber <<"\n";
}