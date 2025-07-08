#include<iostream>
#include "utils.h"

using namespace std;

bool bothAreEqual(int arr1[], int arr2[]){
    for (int i = 0; i < 26; i++)
    {
        if(arr1[i] != arr2[i]){
            return false;
        }
    }
    
    return true;
}

int main(){
    string s1 = "ab";
    string s2 = "eidboaoo";
    bool result = false;

    int freq[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        int valueOfS1Frequency = s1[i] - 'a';
        freq[valueOfS1Frequency]++;
    }

    int windowSize = s1.size();
    for (int i = 0; i < s2.size(); i++)
    {
        int idx = i;
        int winIdx = 0;
        int winFreq[26] = {0};
        while(winIdx < windowSize && idx < s2.size()){
            winFreq[s1[idx] - 'a']++;
            winIdx++;
            idx++;
        }
        if(bothAreEqual(freq, winFreq)){
           result = true;
           break; 
        }
    }
    cout << result << endl;
    return 0;
}