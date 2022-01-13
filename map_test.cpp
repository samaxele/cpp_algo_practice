#include <iostream>
#include "myCustomHeader.h"

using namespace std;

int main() {
    //unordered_map<ListNode*,int> node;
    map<ListNode*,bool> node;

    //Linked List generator
    vector<int> x = {2,5,7,6};
    ListNode* l1 = genListNode(x);
    printList(l1);  //now we have a Single Linked list L1

    ListNode *target = l1;
    while (target) {
        node[target] = true;
        cout << "node = " << target->val << ", map: " << node[target] << endl;   //1
        cout << "next = " << target->next->val << ", map: "  << node[target->next] << endl;   //1
        target = target->next;
    }

    return 0;
}