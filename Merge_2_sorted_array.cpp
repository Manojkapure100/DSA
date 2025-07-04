#include<iostream>
#include<vector>

void print(std::vector<int> array, std::string msg){
    std::cout << "\n When " << msg << ":\t";
    for (int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << "\t";
    }
    std::cout << "\n";
}

int main(){ 
    int elementsInArray = 1;
    std::vector<int> arr1 = {2,0};
    std::vector<int> arr2 = {1};
    int firstArrayPointer = elementsInArray - 1;
    int secondArrayPointer = elementsInArray - 1;
    int currentPointer = arr1.size() - 1;

    while(firstArrayPointer >= 0 && secondArrayPointer >= 0){
        if(arr1[firstArrayPointer] > arr2[secondArrayPointer]){
            arr1[currentPointer] = arr1[firstArrayPointer];
            firstArrayPointer -= 1;
            print(arr1, "1>2");
        } else if(arr1[firstArrayPointer] < arr2[secondArrayPointer]){
            arr1[currentPointer] = arr2[secondArrayPointer];
            secondArrayPointer -= 1;
            print(arr1, "1<2");
        } else {
            arr1[currentPointer] = arr1[firstArrayPointer];
            secondArrayPointer -= 1;
            print(arr1, "1=2");
        }
        currentPointer -= 1;
    }
    while(firstArrayPointer < 0 && secondArrayPointer >= 0){
        arr1[currentPointer] = arr2[secondArrayPointer];
        secondArrayPointer -= 1;
        currentPointer -= 1;
        print(arr1, "2nd array's elemet moving ");
    }
    print(arr1, "Result");
}