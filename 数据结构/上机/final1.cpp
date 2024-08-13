#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    char val;
    TreeNode *left;
    TreeNode *right;
};
TreeNode *create(TreeNode *t);
void inOrder(TreeNode *t);
void preordersave(TreeNode *root, ofstream &outfile);

int main()
{
    // create a tree
    cout << "Please input the values of nodes in preorder: ";
    TreeNode *t1;
    t1 = create(t1);
    inOrder(t1);
    puts("");
    // save to file
    ofstream outfile("tree.txt");
    if (outfile.is_open())
    {
        preordersave(t1, outfile);
        outfile.close();
        cout << "Successfully wrote the tree values to file." << endl;
    }
    else
    {
        cout << "Unable to open the file." << endl;
    }
    // read from file
    puts("this is the tree from the file:\n");
    freopen("tree.txt", "r", stdin);
    TreeNode *t2;
    t2 = create(t2);
    inOrder(t2);
    cout << endl;
    getchar();
    return 0;
}

TreeNode *create(TreeNode *t)
{
    char ch;
    cin >> ch;
    if (ch == '#')
        t = NULL;
    else
    {
        t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        t->val = ch;
        t->left = create(t->left);
        t->right = create(t->right);
    }
    return t;
}
void inOrder(TreeNode *t)
{
    if (t != NULL)
    {
        inOrder(t->left);
        printf("%c", t->val);
        inOrder(t->right);
    }
}
void preordersave(TreeNode *root, ofstream &outfile)
{
    if (root == NULL)
    {
        outfile << "#";
        return;
    }
    else
    {
        outfile << root->val;
        preordersave(root->left, outfile);
        preordersave(root->right, outfile);
    }
}
// ABC##D##EF###
