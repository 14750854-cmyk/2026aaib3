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
    ListNode* reverseList(ListNode* head) {
        // (1) 準備好答案串列的開頭指標，一開始沒有任何節點，所以是 nullptr
        ListNode* ans = nullptr;

        // (2) 使用 now 指標從頭到尾把原本的 Linked List 走一次[cite: 1, 2]
        ListNode* now = head;
        while (now != nullptr) {
            // 每次走訪到一個節點，就建立一個相同數值的新節點[cite: 1, 2]
            // 並直接把它的 next 指向目前的 ans（插在最前面，達到反轉的效果）
            ans = new ListNode(now->val, ans);

            // 換下一個節點[cite: 1, 2]
            now = now->next;
        }

        return ans;
    }
};
