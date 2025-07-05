#include<iostream>
#include<vector>
#include "utils.h"

using namespace std;

// 123654 --> 124653 --> 124356
// 123574 --> 123754

void swap(vector<int> &arr, int first, int second){
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

vector<int> getNextPermutation(std::vector<int> arr){
    // 1. find pivot element's position
    int pointer = arr.size() - 1;
    while(arr[pointer] < arr[pointer-1]){
    pointer --;
    }
    if(pointer == 0){
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end){
        swap(arr,start,end);
        start ++;
        end --;
    }
    return arr;
    }
    int pivotPointer = pointer -1;

    // 2. swap the smallest element (from right side of pivot element) with pivot element
    int lastPointer = arr.size() - 1;
    while(arr[pivotPointer+1] < arr[lastPointer]){
    lastPointer --;
    }
    swap(arr, pivotPointer, lastPointer);

    // 3. reverse rest of element (right side of pivot) from pivot element.
    int pointer2 = arr.size() - 1;
    while(pointer <= pointer2){ 
    swap(arr, pointer, pointer2);
    pointer++;
    pointer2--;
    }
    return arr;
}

vector<int> getNextPermutation2(vector<int> nums) {
    int size = nums.size() - 1;
    int pivotPosition = -1;
    // 1. find pivot position
    for (int i = size; i > 0; i--) {
        if (nums[i] > nums[i - 1]) {
            pivotPosition = i - 1;
            break;
        }
    }
    if (pivotPosition == -1) {
        int start = 0;
        int end = size;
        while (start <= end) {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end--;
        }
    } else {
        // 2. swap pivot number with smallest number on right side, but that
        // number should be bigger then pivot.
        for (int i = size; i > pivotPosition; i--) {
            if (nums[pivotPosition] < nums[i]) {
                int tmp = nums[pivotPosition];
                nums[pivotPosition] = nums[i];
                nums[i] = tmp;
                break;
            }
        }

        // 3. revese rest of element (right element from pivot)
        int start = pivotPosition + 1;
        int end = size;
        while (start <= end) {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end--;
        }
    }
    return nums;
}

int main(){
    std::vector<int> arr = {1,2,3};
    // std::vector<int> nextPermutation = getNextPermutation(arr);
    std::vector<int> nextPermutation = getNextPermutation2(arr);
    printVector(nextPermutation);
}