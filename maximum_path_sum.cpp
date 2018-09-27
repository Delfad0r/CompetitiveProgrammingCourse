/*
The function dfs returns a pair of integers: the first element
is the maximum path sum in the subtree rooted at root, while
the second element is maximum sum of a path starting at root
and contained in the subtree rooted at root. The recursive
implementation is straightforward. 
*/

typedef pair<int, int> II;

II dfs(struct Node* root) {
    if(!root) {
        return II(0, 0);
    }
    II a = dfs(root->left), b = dfs(root->right);
    return II(max(max(a.first, b.first), root->data + a.second + b.second), max(0, root->data + max(a.second, b.second)));
}

int maxPathSum(struct Node* root) {
    return dfs(root).first;
}
