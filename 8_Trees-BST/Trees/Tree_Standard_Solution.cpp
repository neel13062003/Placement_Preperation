1) Traversal


//O(n)=Time COmplexity  & O(n)=no. of node= O(height of tree). 
*** Recursive ****

vector<int>ans;
vector<int> inorderTraversal(TreeNode *root)
{

    if (root == NULL)
        return {};

    inorderTraversal(root->left);
    ans.push_back(root->val);
    inorderTraversal(root->right);

    return ans;
}


*** Recursive Using Function ***
class Solution{
    public:
    
    void PrintInorder(TreeNode* root,vector<int>&ans){
        if(!root){
            return;
        }
        PrintInorder(root->left,ans);
        ans.push_back(root->val);
        PrintInorder(root->right,ans);
    }
    
    vector<int>inorderTraversal(TreeNode* root){
        vector<int>ans;
        PrintInorder(root,ans);
        return ans;
    }
};


*** Iterative Using Stack ***
//Inorder=  left root right    
class Solution{
public: 
    vector<int>inorderTraversal(TreeNode* root){
        vector<int>inorder;
        if(root==NULL)return inorder;

        stack<TreeNode*>st;
        TreeNode* node=root;

        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }else{
                if(st.empty())break;
                node=st.top();
                st.pop();
                inorder.push_back(node->val);
                node=node->right;
            }
        }
        return inorder;
    }
};

*** Iterative Using Stack ***
//Preorder = root left right
class Solution{
    public:
        vector<int>preorderTraversal(TreeNode* root){
            vector<int>preorder;
            if(root==NULL)return preorder;

            stack<TreeNode*>st;
            //TreeNode* node=root;
            st.push(root);

            while(!st.empty()){
                root = st.top();
                st.pop();

                preorder.push_back(root->val);

                if(root->right != NULL){
                    st.push(root->right);
                }
                if(root->left != NULL){
                    st.push(root->left);
                }    
            }
            return preorder;
        } 
} 


//Iterative
//Using 2 Stack
class Solution {
public:    
    //left right root
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postorder;
        if(root==NULL) return postorder;
        stack<TreeNode*>st1,st2;
        st1.push(root);
        while(!st1.empty()){
            root=st1.top();
            st1.pop();
            st2.push(root);
            if(root->left!=NULL){
                  st1.push(root->left);  
            }
            if(root->right!=NULL){
                st1.push(root->right);
            }
        }
        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
    }
};