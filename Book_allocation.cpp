#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

// [2, 1, 3, 4]

bool isPossible(int maxAllocablePage, int totalStudentToAllocateBooks, int totalBooks, std::vector<int> pagesOfBooks){
    int totalStudents = 1;
    int allocatedPages = pagesOfBooks[0];
    for(int i=1; i<totalBooks; i++){
        if((allocatedPages+pagesOfBooks[i]) <= maxAllocablePage){
            allocatedPages+=pagesOfBooks[i];
        } else {
            totalStudents++;
            allocatedPages = pagesOfBooks[i];
        }
    }
    if(totalStudents==totalStudentToAllocateBooks){
        std::cout << "\nYes possible\n";
        return true;
    }else{
        std::cout << "\nnot possible\n";
        return false;
    }
}

int getAns(int totalStudents, int totalBooks, std::vector<int> pagesOfBooks){
    int ans = -1;
    if(totalStudents > totalBooks){
        return ans;
    }
    int start = *std::max_element(pagesOfBooks.begin(), pagesOfBooks.end());
    int end = std::accumulate(pagesOfBooks.begin(), pagesOfBooks.end(), 0);
    std::cout << "\n" << "start: " << start << " and end: " << end << "\n";
    while(start <= end){
        int mid = start + (end - start) / 2;
        std::cout << "\n" << "mid is possible: " << mid << "\n";
        if(isPossible(mid, totalStudents, totalBooks, pagesOfBooks)){
            ans = mid; 
            end = mid - 1;
        } else { 
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    int totalStudents = 2;
    int totalBooks = 4;
    std::vector<int> pagesOfBooks = {2,1,3,4};
    int ans = getAns(totalStudents,totalBooks,pagesOfBooks);
    std::cout << "\nAnswer: "<< ans << "\n";
    return 0;
}