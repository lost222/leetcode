#include <iostream>
using namespace std;

/* it is hard to keep a BST balance while inserting node
   so make sure it is already balance before insert
   by find middle val of a list , use it as root of BST,
   then make the left child tree and right child tree recursively
 */


//* Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    TreeNode* helper(ListNode* head){
        if(head == nullptr) { return nullptr;}
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre_slow = nullptr;
        while (fast->next != nullptr) {
            pre_slow = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast->next != nullptr) {
                fast = fast->next;
            }
        }

        //slow is the middle number. use as tree root
        auto* root = new TreeNode(slow->val);

        //split list, recursive program to 2 list, as left and right node
        if(pre_slow != nullptr){
            pre_slow->next = nullptr;
            root->left = helper(head);
            root->right = slow->next ? helper(slow->next) : nullptr ;
        }

        return root;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        return helper(head);
    }
};

void outList(ListNode * head) {
    while (head != nullptr) {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

void outBST(TreeNode *root){
    if(root == nullptr){
        cout<<"null"<<" ";
        return;
    }
    cout<<root->val<<" ";
    outBST(root->left);
    outBST(root->right);
}


int main() {
    ListNode list[6] = {0, 1, 2, 3, 4, 5};
    for(int i=0; i<5; i++){
        list[i].next = &(list[i+1]);
    }
    outList(list);
    Solution su;
    auto* BSTroot =  su.sortedListToBST(list);

    outBST(BSTroot);

    return 0;
}