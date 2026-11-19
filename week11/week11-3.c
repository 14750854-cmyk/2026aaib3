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
// LeetCode 21. Merge Two Sorted Lists
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(999); // 建立虛擬頭節點
        ListNode* now = ans;               // 用 now 指標來串接後面的節點

        // 兩邊都還有節點時，比較大小並接上較小的那一個
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) { // 左邊比較小
                now->next = new ListNode(list1->val);
                now = now->next;
                list1 = list1->next;
            } else { // 右邊比較小（或兩邊一樣大）
                now->next = new ListNode(list2->val);
                now = now->next;
                list2 = list2->next;
            }
        }

        // 迴圈結束後，把還沒走完的那一邊直接整串接在後面
        if (list1 != nullptr) now->next = list1;
        if (list2 != nullptr) now->next = list2;

        return ans->next; // 回傳虛擬頭節點的下一個，才是真正的開頭
    }
};
