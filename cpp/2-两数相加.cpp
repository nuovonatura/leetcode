/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val = l1->val + l2->val;
        ListNode *res = new ListNode(val % 10), *temp;
        int incre = val / 10;
        temp = res;
        
        while (l1->next || l2->next) {
            val = 0;
            if (l1->next) {
                l1 = l1->next;
                val += l1->val;
            }
            if (l2->next) {
                l2 = l2->next;
                val += l2->val;
            }
            val += incre;

            temp->next = new ListNode(val % 10);
            incre = val / 10;
            temp = temp->next;
        }

        if (incre == 1) {
            temp->next = new ListNode(1);
        }

        return res; 
    }
};
// @lc code=end

