class Solution {
public:

    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {

            ListNode* forward = curr->next;

            curr->next = prev;

            prev = curr;

            curr = forward;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == nullptr)
            return nullptr;

        ListNode* temp = head;

        // Check if k nodes exist
        for (int i = 0; i < k; i++) {

            if (temp == nullptr)
                return head;

            temp = temp->next;
        }

        // Reverse remaining list first
        ListNode* newHead = reverseKGroup(temp, k);

        // Reverse current k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 0; i < k; i++) {

            ListNode* forward = curr->next;

            curr->next = prev;

            prev = curr;

            curr = forward;
        }

        // Connect
        head->next = newHead;

        return prev;
    }
};