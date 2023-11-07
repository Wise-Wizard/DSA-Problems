class Solution
{
private:
    ListNode *reverse(ListNode *head, int k)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *forward = nullptr;
        int count = 0;
        while (count < k && curr)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }
        return prev;
    }

    ListNode *solve(ListNode *head, int k)
    {
        ListNode *nextNode = head;
        int count = 0;
        while (count < k)
        {
            if (nextNode == NULL)
            {
                return head;
            }
            nextNode = nextNode->next;
            count++;
        }
        ListNode *newHead = reverse(head, k);
        head->next = solve(nextNode, k);
        return newHead;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // Edge case: If there are fewer than k nodes, no need to reverse
        ListNode *curr = head;
        int count = 0;
        while (count < k && curr)
        {
            curr = curr->next;
            count++;
        }
        if (count < k)
        {
            return head;
        }

        return solve(head, k);
    }
};
