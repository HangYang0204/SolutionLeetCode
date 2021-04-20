#include<vector>
#include<iostream>
#include<stack>
#include<queue>
using std::queue;
using std::stack;

class TreeNode{
public:
    int val;
    TreeNode* root;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class TreeTraversal{
    public:
    //print a tree
    void PrintBinaryTree(TreeNode* root){
        if(root != nullptr){
            std::cout << root->val << std::endl;
            if(root->left != nullptr) PrintBinaryTree(root->left);
            if(root->right != nullptr) PrintBinaryTree(root->right);
        } 
        else return;
    }
    //traversal a tree DFS
    void DFSBinaryTree(TreeNode* root){
        stack<TreeNode*> sk;
        if(root != nullptr) sk.push(root);
        while(!sk.empty()){
            TreeNode* curr = sk.top();
            std::cout << curr->val << std::endl;
            sk.pop();
            if(curr->right != nullptr) sk.push(curr->right);
            if(curr->left != nullptr) sk.push(curr->left);     
        }
    }
    //traversal by layer 
    void BinaryTreeTraversal(TreeNode* root){
        queue<TreeNode*> q;
        if(not root) return;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i< size; i++){
                TreeNode *curr = q.front();
                q.pop();
                std::cout << curr->val << std::endl;
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
            }                
        }
    }
    std::vector<int> inordertraversal(TreeNode* root){
        treeTraversal(root);
        return result;
    }
    private:
    void treeTraversal(TreeNode* root){
        if(not root){
            return;
        }
        treeTraversal(root->left);
        result.push_back(root->val);
        treeTraversal(root->right);
    }
    std::vector<int> result;
};

void Test1(){
    TreeNode* x = new TreeNode(3);
    TreeNode* x2 = new TreeNode(6);
    TreeNode* y = new TreeNode(5,x,x2);
    TreeNode* x3 = new TreeNode(9);
    TreeNode* y2 = new TreeNode(7,x3,nullptr);
    TreeNode* z = new TreeNode(1,y2,y);
    TreeTraversal ts;
    //ts.PrintBinaryTree(z);
    //ts.DFSBinaryTree(z);
    ts.BinaryTreeTraversal(z);
}

int main(){
    TreeNode* x = new TreeNode(3);
    TreeNode* y = new TreeNode(5,x,nullptr);
    TreeNode* z = new TreeNode(1,nullptr,y);
    TreeTraversal s;
    std::vector<int> res;
    // res = s.inordertraversal(z);
    // for(int i : res){
    //     std::cout << i << std::endl;
    // }

    Test1();
 
}
