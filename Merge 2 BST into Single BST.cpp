#include<iostream>
#include "utils.h"

using namespace std;

btNode* buildBSTFromSortedArr(vector<int> arr, int start, int end){
    if(start > end) return NULL;

    int mid = start + (end - start) / 2;
    btNode* root = new btNode(arr[mid]);
    root->left = buildBSTFromSortedArr(arr, start, mid - 1);
    root->right = buildBSTFromSortedArr(arr, mid+1, end);
    return root;
}

void getInorder(btNode* root, vector<int> &arr){
    if(root == NULL) return;

    getInorder(root->left, arr);
    arr.push_back(root->val);
    getInorder(root->right, arr);
}

btNode* merge2Root(btNode* root1, btNode* root2){
    vector<int> finalArr;
    vector<int> root1Arr;
    vector<int> root2Arr;

    getInorder(root1, root1Arr);
    getInorder(root2, root2Arr);

    int i = 0;
    int j = 0;

    while (i < root1Arr.size() && j < root2Arr.size())
    {
        if(root1Arr[i] < root2Arr[j]){
            finalArr.push_back(root1Arr[i++]);
        } else {
            finalArr.push_back(root2Arr[j++]);
        }
    }

    while (i < root1Arr.size())
    {
        finalArr.push_back(root1Arr[i++]);
    }

    while (j < root2Arr.size())
    {
        finalArr.push_back(root2Arr[j++]);
    }
    
    return buildBSTFromSortedArr(finalArr, 0, finalArr.size() - 1);
}

btNode* insert(btNode* root, int value){
    if(root == NULL) return new btNode(value);
    if(value < root->val){
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

btNode* buildBSTFromUnsortedArr(vector<int> arr){
    btNode* root = NULL;
    for (auto value : arr)
    {
        root = insert(root, value);
    }
    return root;
}

int main(){
    vector<int> rootArr1 = {8,2,1,10};
    vector<int> rootArr2 = {5,3,0};

    btNode* root1 = buildBSTFromUnsortedArr(rootArr1);
    btNode* root2 = buildBSTFromUnsortedArr(rootArr2);

    btNode* finalRoot = merge2Root(root1, root2);
    vector<int> finalArr;

    getInorder(finalRoot, finalArr);
    for (auto value : finalArr)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}