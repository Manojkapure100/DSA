#include<iostream>
#include<vector>
#include<algorithm>

int getDuplicate(std::vector<int> array){
    std::sort(array.begin(),array.end());
    int lastValue = -1;
    for(int i=0; i< array.size(); i++){
        if(array[i] == lastValue){
            return array[i];
        }
        lastValue = array[i];
    }
}

int getDuplicateUsingSlowFastPointer(std::vector<int> array){
    int slow = array[0];
    int fast = array[0];

    do{
        slow = array[slow]; // slow increasing by 1
        fast = array[array[fast]]; // fast increasing by 2
    }while(slow != fast);

    slow = array[0];

    while(slow != fast){
        slow = array[slow];
        fast = array[fast];
    }

    return slow;
}

int main(){
    std::vector<int> array = { 1,4,2,6,3,5,4 };
    // int duplicate = getDuplicate(array);
    int duplicate = getDuplicateUsingSlowFastPointer(array);
    std::cout << "\nDuplicate value: " << duplicate << "\n";
    return 0;
}