#include <iostream>
#include "utils.h"

using namespace std;

bool helper(btNode* root, int no)
{
    if (root->val != no) return false;

    bool left = (root->left != NULL) ? helper(root->left, no) : true;
    bool right = (root->right != NULL) ? helper(root->right, no) : true;

    if (left && right) return true;
    return false;
}

bool isUnivalTree(btNode* root)
{
    if (root == NULL)
        return true;
    int number = root->val;
    return helper(root, number);
}

int main()
{
    vector<int> arr = {1,1,1,-1,-1,1,-1,-1,1,-1,1,-1,-1};
    btNode* root = buildTree(arr);
    printBinaryTreeByLevel(root);
    bool ans = isUnivalTree(root);
    cout << "ans: " << ans << endl;
    return 0;
}