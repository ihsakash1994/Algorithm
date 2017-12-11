#include<iostream>

using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* GetBSTNode(int data)
{
    BSTNode* root = new BSTNode();
    root->data = data;
    root->left = NULL;
    root->right = NULL;

    return root;
}

BSTNode* insert (BSTNode* root, data)
{
    if (root == NULL)
    {
        return GetBSTNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
}

bool find (BSTNode* root, data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data < root->data)
    {
        find(root->left, data);
    }
    else
    {
        find(root->right, data);
    }
}

int main()
{
    BSTNode* root = NULL;

}
