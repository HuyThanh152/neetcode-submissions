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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Tạo dummy node để dễ xử lý khi left = 1
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        // 1. Di chuyển prev đến node ngay trước vị trí left
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        // 2. Đảo ngược các node từ left đến right (kỹ thuật Insert Node)
        ListNode* curr = prev->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy.next;
    }
};
