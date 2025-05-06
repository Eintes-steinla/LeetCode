class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *add = nullptr;
        int carry = 0;
        int sum;

        while (l1 != nullptr || l2 != nullptr || carry)
        {
            sum = carry;
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            ListNode *tmp = new ListNode;
            tmp->val = sum % 10;
            tmp->next = add;
            add = tmp;
            carry = sum / 10;
        }

        ListNode *result = nullptr;
        while (add != nullptr)
        {
            ListNode *tmp = add->next;
            add->next = result;
            result = add;
            add = tmp;
        }

        return result;
    }
};
