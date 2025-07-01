#include<iostream>
#include<vector>
#include<algorithm>


bool isPossibleToPlaceCowAtGivenDistance(int minDiffrence, std::vector<int> stolePositions, int totalCowsToPlace, int totalStoll){
    int totalCowPlaced = 1;
    int lastCowPlaced = stolePositions[0];
    for(int i = 0; i < totalStoll; i++){
        if((stolePositions[i] - lastCowPlaced) >= minDiffrence){
            totalCowPlaced += 1;
            lastCowPlaced = stolePositions[i];
        }
        if(totalCowPlaced == totalCowsToPlace){
            std::cout << "\nYes it is possible\n";
            return true;
        }
    }
    std::cout << "\nNot possible\n";
    return false;
}

int getAnswer(std::vector<int> stolePositions, int totalCowsToPlace, int totalStoll){
    sort(stolePositions.begin(), stolePositions.end());
    int start = stolePositions[0];
    int end = stolePositions[totalStoll - 1];
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        std::cout << "\ncan we place cow at " << mid <<" number of distance\n";
        bool possible = isPossibleToPlaceCowAtGivenDistance(mid,stolePositions,totalCowsToPlace,totalStoll);
        if(possible){
            std::cout << "\nAssigning value " << mid << " to answer\n";
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main(){
    int totalCowsToPlace = 3;
    int totalStoll = 5;
    std::vector<int> stolePositions = {1,2,8,4,9};
    int ans = getAnswer(stolePositions,totalCowsToPlace,totalStoll);
    std::cout << "\nAnswer: " << ans << "\n";
    return 0;
}