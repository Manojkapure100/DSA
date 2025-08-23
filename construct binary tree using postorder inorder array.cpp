#include <iostream>
#include "utils.h"

using namespace std;

int search(vector<int> &inorder, int value, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == value)
        {
            return i;
        }
    }
    return -1;
}

btNode* helper(vector<int> &inorder, vector<int> &postorder, int &postindex, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int rootValue = postorder[postindex];                      
    btNode *root = new btNode(rootValue);                  
    int inorderIndex = search(inorder, rootValue, start, end); 

    postindex--; 

    // In postorder, root is at the end,
    // so we process postorder[] backwards,
    // and must build RIGHT subtree before LEFT.
    root->right = helper(inorder, postorder, postindex, inorderIndex + 1, end); 
    root->left = helper(inorder, postorder, postindex, start, inorderIndex - 1); 
    return root;
}

int main()
{
    vector<int> postorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    int postindex = postorder.size() - 1;
    int start = 0;
    int end = inorder.size() - 1;

    btNode *root = helper(inorder, postorder, postindex, start, end);
    printBinaryTreeByLevel(root);

    return 0;
}