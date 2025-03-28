/*
2095. Delete the Middle Node of a Linked List

You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* deleteMiddle(ListNode* head) {
            if (head == NULL || head->next == NULL) {
                head = NULL;
                return head;
            }
            int n = 0;
            ListNode* current=head;
            while (current != NULL) {
                n++;
                current = current->next;
            }
            ListNode* slow = head;
            ListNode* fast = head;
            ListNode* temp = head;
            while (fast->next != NULL && fast->next->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }
            cout << slow->val << temp->next->val;
            ListNode* t = NULL;
            if (n % 2 != 0) {
                while (temp != slow) {
                    if (temp->next == slow) {
                        t = temp;
                        break;
                    }
                    temp = temp->next;
                    //  cout<<temp->val;
                }
                 temp->next = temp->next->next;
            }
            else{
                while (temp != slow) {
                    temp = temp->next;
                }
                 temp->next = temp->next->next;
            }
            return head;
        }
    };

    void printList(ListNode* head)
    {
        ListNode* temp = head;
        while(temp != NULL)
        {
            cout << temp->val;
            temp = temp->next;
        }
        cout<<"NULL" << endl;
    }

    int main()
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        cout << "Original list ";
        printList(head);

        Solution solution;
        head = solution.deleteMiddle(head);
        cout<<"After delete middle node ";
        printList(head);
        return 0;
    }
    