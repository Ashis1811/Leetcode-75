/*
2130. Maximum Twin Sum of a Linked List
In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.
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
            int pairSum(ListNode* head) {
                ListNode* slow = head;
                ListNode* fast = head;
                while( fast &&  fast->next)
                {
                    slow = slow->next;
                    fast = fast->next->next;
                }
                ListNode* secondHalf = slow;
                ListNode* prev = NULL;
                
                while(secondHalf)
                {
                    ListNode* nextnode = secondHalf->next;
                    secondHalf->next = prev;
                    prev = secondHalf;
                    secondHalf = nextnode;
                }
                ListNode* firstHalf = head;
                ListNode* reverse = prev;
                int maxSum = 0;
                while(reverse)
                {
                    int twin = firstHalf->val + reverse->val;
                    maxSum = max(maxSum, twin);
                    firstHalf = firstHalf->next;
                    reverse = reverse->next;
                }
                return maxSum;
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
    Solution solution;
    ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
        cout << "Original list ";
        printList(head);

        Solution solution;
        int result = solution.pairSum(head);
        cout<<"Reordered List : "<<result;
        
    return 0;
}
