/*
206. Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.
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
            ListNode* reverseList(ListNode* head) {
                ListNode* prev = NULL;
                ListNode* curr = head;
                ListNode* forward = NULL;
                while(curr != NULL)
                {
                    forward = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = forward;
                }
                return prev;
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
        head = solution.reverseList(head);
        cout<<"Reordered List : ";
        printList(head);
        return 0;
    
}
