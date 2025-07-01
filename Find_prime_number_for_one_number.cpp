#include<iostream>
#include<cmath>

int main(){
    int number = 153;
    int isPrime = true;
    int rootOfNumber = (number > 0 ? std::sqrt(number) : 2);
    std::cout << "\n Number " << number << " is Prime? ";
    for (int i = 2; i < rootOfNumber; i++){
        if(number % i == 0){
            isPrime = false;
        }
    }
    std::cout << (isPrime ? "Yes" : "No") <<"\n";
    return isPrime;
}