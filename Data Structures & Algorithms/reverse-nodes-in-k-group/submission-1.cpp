class Solution {
public:

    // Helper function to reverse a list
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

        // Step 1: Check if k nodes exist
        for (int i = 0; i < k; i++) {

            if (temp == nullptr)
                return head;

            temp = temp->next;
        }

        // Step 2: Recursively process remaining list
        ListNode* newHead = reverseKGroup(temp, k);

        // Step 3: Cut the list after k nodes
        ListNode* kth = head;
        for (int i = 1; i < k; i++) {
            kth = kth->next;
        }

        kth->next = nullptr;

        // Step 4: Reverse first k nodes using helper
        ListNode* reversedHead = reverseList(head);

        // Step 5: Connect lists
        head->next = newHead;

        return reversedHead;
    }
};