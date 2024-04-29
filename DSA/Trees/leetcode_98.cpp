#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversalUsingQueue(TreeNode *root)
{ // BFS
    queue<TreeNode *> q;
    q.push(root);
    while (q.size())
    {
        TreeNode *temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
    cout << endl;
}

TreeNode *construct(int arr[], int n)
{
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(arr[0]);
    q.push(root);
    int i = 1;
    int j = 2;
    while (q.size() > 0 && i < n)
    {
        TreeNode *temp = q.front();
        q.pop();
        TreeNode *l;
        TreeNode *r;
        if (arr[i] != INT_MIN)
        {
            l = new TreeNode(arr[i]);
        }
        else
        {
            l = NULL;
        }
        if (j != n && arr[j] != INT_MIN)
        {
            r = new TreeNode(arr[j]);
        }
        else
        {
            r = NULL;
        }
        temp->left = l;
        temp->right = r;
        if (l != NULL)
            q.push(l);
        if (r != NULL)
            q.push(r);
        i += 2;
        j += 2;
    }
    return root;
}

int maxVal(TreeNode *root, int maxNum)
{
    if (root == NULL)
    {
        return maxNum;
    }
    maxNum = max(maxNum, root->val);
    maxVal(root->left, maxNum);
    maxVal(root->right, maxNum);
    return maxNum;
}
int minVal(TreeNode *root, int minNum)
{
    if (root == NULL)
    {
        return minNum;
    }
    minNum = min(minNum, root->val);
    minVal(root->left, minNum);
    minVal(root->right, minNum);
    return minNum;
}
bool isValidBST(TreeNode *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    int maxValue = maxVal(root->left, INT_MIN);
    int minValue = minVal(root->right, INT_MAX);
    cout << maxValue << " " << minValue << endl;
    if (root->val > maxValue && root->val < minValue)
    {
        return true;
    }
    else
    {
        return false;
    }
}
    int main()
    {
        // construct
        int arr[] = {5, 4, 6, INT_MIN, INT_MIN, 3, 7};
        int n = sizeof(arr) / sizeof(arr[0]);
        TreeNode *root = construct(arr, n);
        levelOrderTraversalUsingQueue(root);
        cout << isValidBST(root);
    }