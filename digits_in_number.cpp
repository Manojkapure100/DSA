#include<iostream>

void printDigits(int number){
    std::cout << "\nPrinting numbers in reverse order:";
    while(number != 0){
        int digit = number % 10;
        std::cout << "\t" << digit;
        number = number / 10;
    }
    std::cout << "\n";
}

void countDigits(int number){
    int count = 0;
    while(number != 0){
        int digit = number % 10;
        count ++;
        number = number / 10;
    }
    std::cout << "\n count of digits: " << count << "\n";
}

void sumOfDigits(int number){
    int sum = 0;
    while ( number != 0){
        int digit = number % 10;
        sum += digit;
        number = number / 10;
    }
    std::cout << "\n sum of digits: " << sum << "\n";
}

int main(){
    int number = 52342;
    printDigits(number);
    countDigits(number);
    sumOfDigits(number);
    return 0;
}