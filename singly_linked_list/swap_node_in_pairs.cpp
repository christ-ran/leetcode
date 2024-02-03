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
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *rHead = nullptr;
        ListNode *rTail = nullptr;
        ListNode *temp = head;
        ListNode *after = temp;
        ListNode *jump = nullptr;

        while (temp && temp->next)
        {
            after = temp->next;
            jump = after->next;

            temp->next = nullptr;
            after->next = temp;

            if (rHead == nullptr)
            {
                rHead = after;
                rTail = temp;
            }
            else
            {
                rTail->next = after;
                rTail = temp;
            }

            temp = jump;
        }

        rTail->next = temp;

        return head = rHead;
    }
};