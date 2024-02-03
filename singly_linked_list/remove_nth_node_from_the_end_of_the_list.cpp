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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *pointer1 = head;
        ListNode *pointer2 = head;

        for (int i = 0; i < n; i++)
            pointer1 = pointer1->next;

        if (!pointer1)
            return head->next;

        while (pointer1->next)
        {
            pointer1 = pointer1->next;
            pointer2 = pointer2->next;
        }

        pointer2->next = pointer2->next->next;

        return head;
    }
};