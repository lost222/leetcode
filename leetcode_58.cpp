// 注意删除链表节点类问题，通常而言获得要删除节点的前一个节点是复杂度低的形式。
//注意。 你的代码能删除第一个节点吗？
// 如果head节点为空， head->next 指向第一个有数据的节点，则可以避免这个问题。不然确实需要条件判断。


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* cur = head;
        while(cur!=NULL){len++;cur=cur->next;}// 获得总长
        cur = head;
        if(len - n - 1 == -1){ // 让你删除第一个节点，需要特殊判断
            head = cur->next;
            delete cur;
            return head;
        }
        for(int i=0; i<len - n - 1; i++){
            cur = cur->next;
        }
        if (len==1){return NULL;}
        ListNode* toerase = cur->next;
        cur->next = toerase->next;
        delete toerase;
        return head;
        
    }
};
