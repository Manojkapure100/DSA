#include <iostream>
#include "utils.h"
#include <queue>

using namespace std;

vector<vector<int>> returnBinaryTreeByLevel(btNode *root)
{
    if (root == NULL) return {};
    queue<btNode*> queue;
    vector<vector<int>> ans;
    vector<int> level;

    queue.push(root);
    queue.push(NULL);

    while (!queue.empty())
    {
        btNode *currentNode = queue.front();
        queue.pop();

        if (currentNode == NULL)
        {
            ans.push_back(level);
            level.clear();
            if (queue.empty())
            {
                break;
            }
            else
            {
                queue.push(NULL);
                continue;
            }
        }
        level.push_back(currentNode->val);
        if (currentNode->left != NULL)
            queue.push(currentNode->left);
        if (currentNode->right != NULL)
            queue.push(currentNode->right);
    }
    return ans;
}

void printBinaryTreeByLevel2(btNode *root)
{
    queue<btNode *> queue;

    queue.push(root);
    queue.push(NULL);

    while (!queue.empty())
    {
        btNode *currentNode = queue.front();
        queue.pop();

        if (currentNode == NULL)
        {
            if (queue.empty())
            {
                break;
            }
            else
            {
                cout << endl;
                queue.push(NULL);
                continue;
            }
        }

        cout << currentNode->val << "\t";
        if (currentNode->left != NULL)
            queue.push(currentNode->left);
        if (currentNode->right != NULL)
            queue.push(currentNode->right);
    }
}

int main()
{
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    btNode *root = buildTree(arr);
    vector<vector<int>> ans = returnBinaryTreeByLevel(root);
    printVector(ans);
    return 0;
}