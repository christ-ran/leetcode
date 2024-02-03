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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *small_head = nullptr;
        ListNode *small_tail = nullptr;

        ListNode *big_head = nullptr;
        ListNode *big_tail = nullptr;

        while (head)
        {
            ListNode *temp = head;
            head = head->next;

            temp->next = nullptr;

            bool is_small = temp->val < x;

            if (is_small)
            {
                if (small_head == nullptr)
                {
                    small_head = temp;
                    small_tail = temp;
                    continue;
                }

                small_tail->next = temp;
                small_tail = small_tail->next;
            }
            else
            {
                if (big_head == nullptr)
                {
                    big_head = temp;
                    big_tail = temp;
                    continue;
                }

                big_tail->next = temp;
                big_tail = big_tail->next;
            }
        }

        if (small_tail == nullptr)
            return head = big_head;

        small_tail->next = big_head;
        head = small_head;

        return head;
    }
};