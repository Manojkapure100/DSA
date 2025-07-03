#include<iostream>
#include<vector>

std::vector<int> sortArray(std::vector<int> array){
        int numOfZero = 0, numOfOne = 0, numOfTwo = 0;
    for (int i = 0; i < array.size(); i++)
    {
        if(array[i]==0){
            numOfZero+=1;
        }else if(array[i]==1){
            numOfOne+=1;
        }else if(array[i]==2){
            numOfTwo+=1;
        }else{
            //nothing;
        }
    }
    // std::cout << "\n" << numOfZero << " " << numOfOne << " " << numOfTwo << "\n";
    for (int i = 0; i < array.size(); i++)
    {
        if(numOfZero!=0){
            array[i]=0;
            numOfZero-=1;
        }
        else if(numOfOne!=0){
            array[i]=1;
            numOfOne-=1;
        }
        else if(numOfTwo!=0){
            array[i]=2;
            numOfTwo-=1;
        }
    }
    return array;
}

std::vector<int> swapElement(std::vector<int> &array, int firstPosition, int secondPosition){
    int tmp = array[firstPosition];
    array[firstPosition] = array[secondPosition];
    array[secondPosition] = tmp;
    return array;
}

std::vector<int> sortArrayUsingDutchNationalFlagAlgo(std::vector<int> array){
    // 0 to low-1, low to mid-1, mid to high, high+1 to n-1
    int n = array.size();
    int mid = 0;
    int high = n-1;
    int low = 0;
    while(mid <= high)
    {
        if(array[mid]==0){
            swapElement(array, mid, low);
            low++;
            mid++;
        } else if (array[mid]==1){
            mid++;
        } else if (array[mid]==2){
            swapElement(array, mid, high);
            high--;
        } else {
            // not possible
        }
    }
    return array;
}

int main(){
    std::vector<int> array = {0,2,2,1,0,1,1,1,0};
    // array = sortArray(array);
    array = sortArrayUsingDutchNationalFlagAlgo(array);
    std::cout << "\n";
    for (int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}