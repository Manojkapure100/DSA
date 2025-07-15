#include<iostream>
#include <vector>

using namespace std;

int singleNonDuplicate(vector<int> arr) {
    if(arr.size() == 1) return arr[0];
    int start = 0;
    int end = arr.size() - 1;
    while(start <= end){
        if(arr[start] == 0 && arr[start] != arr[start+1]) return arr[start];
        if(arr[end] == arr.size() - 1 && arr[end] != arr[end-1]) return arr[end];

        int mid = start + (end - start) / 2;
        if(arr[mid-1] != arr[mid] && arr[mid] != arr[mid+1]){
            return arr[mid];
        }
        if(mid%2==0){ // both side even
            if(arr[mid] == arr[mid+1]){ // if right side matched, and we remove matched element then with rest of element, then right will become odd, we have to go to right then
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        } else { // odd
            if(arr[mid] == arr[mid+1]){ // if right side matched, then right become even, we have to go to left then
                end = mid - 1;
            } else{
                start = mid + 1;
            }
        }
    }
}

int main(){
    vector<int> arr = {1,1,2,2,3,3,4,5,5};
    int result = singleNonDuplicate(arr);
    cout << "single arr: " << result << endl;
    return 0;
}