// count prime number till given number
#include<iostream>
#include<vector>

int main(){
    int number = 100;
    int countPrime = 0;
    std::vector<bool> isPrime(number+1,true);
    for (int i = 2; i < number; i++){
        if(isPrime[i]){
            countPrime++;
            for(int j=i*2; j<number;j=j+i){
                isPrime[j] = false;
            }
        }
    }
    std::cout << "\nCount prime: " << countPrime << "\n";
    return countPrime;
}