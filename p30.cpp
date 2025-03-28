/*
328. Odd Even Linked List
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.
*/

#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
     };
class Solution {
    public:
        ListNode* oddEvenList(ListNode* head) {
            if(! head || ! head->next) return head;
            ListNode* odd = head;
            ListNode* even = head->next;
            ListNode* evenHead = even;
            while(even && even->next)
            {
                odd->next = odd->next->next;
                even->next = even->next->next;
                odd = odd->next;
                even = even->next;
            }
            odd->next = evenHead;
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
        head->next->next->next->next = new ListNode(5);
        cout << "Original list ";
        printList(head);

        Solution solution;
        head = solution.oddEvenList(head);
        cout<<"Reordered List : ";
        printList(head);
        return 0;
    }
    