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
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    public:
        void printNode(ListNode * head)
        {
            while(head != nullptr)
            {
                std::cout << head->val << "->";
                head = head->next;
            }
            std::cout << "null" << std::endl;
        }

        ListNode* deleteDuplicates(ListNode* head) {
            ListNode * curr = head;

            while ( curr != nullptr)
            {
                printNode(curr);
                ListNode * next_node = curr->next;
                if( next_node->val == curr->val)
                {
                    ListNode * tmp = curr;
                    curr = curr->next;
                    delete tmp;
                }
            }
            return curr;
        }
};


int main()
{
    // Estrutura de instanciacao de nos
    // ListNode* node = new ListNode(5); * -> pois eh um ponteiro para o no, new alocacao dinamica precisa de liberar na heap (free)
    ListNode * node3 = new ListNode(3);
    ListNode * node2 = new ListNode(2, node3);
    ListNode * node1 = new ListNode(1, node2);
    ListNode * node0 = new ListNode(1, node1);

    // (head)node1 -> node2 -> node3 -> nullptr

    Solution sol;
    sol.deleteDuplicates(node0);

}
