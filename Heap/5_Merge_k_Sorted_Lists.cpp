#include <bits/stdc++.h>
using namespace std;

// Approach 1: Merge one by one

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MergeKSortedListsMergeOneByOne {
public:
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode dummy(-1);
        ListNode* temp = &dummy;

        while(list1 && list2){  // N1 + N2 time
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        temp->next = list1? list1:list2;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        ListNode* head = lists[0];

        for(int i=1; i<lists.size(); i++){  // O(kN) time
            head = merge(head, lists[i]);
        }

        return head;
    }
};

// Time Complexity: O(kN) where k is the number of linked lists and N is the total number of nodes in all linked lists.
// Space Complexity: O(1) as we are not using any extra space.

// Approach 2: Using Min Heap
class MergeKSortedListsMinHeap {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(-1);
        ListNode* temp = &dummy;

        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> minHeap;

        for(int i=0; i<lists.size(); i++){
            if(lists[i]) 
                minHeap.push({lists[i]->val, lists[i]});
        }

        while(!minHeap.empty()){
            auto topElm = minHeap.top();
            minHeap.pop();

            ListNode* node = topElm.second;

            temp->next = node;
            temp = temp->next;

            if(node->next){
                minHeap.push({node->next->val, node->next});
            }
        }

        return dummy.next;
    }
};

// Time Complexity: O(Nlogk) where k is the number of linked lists and N is the total number of nodes in all linked lists.
// Space Complexity: O(k) for min heap.


class MergeKSortedListsDivideAndConquer {
public:
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode dummy(-1);
        ListNode* temp = &dummy;

        while(list1 && list2){
            if(list1->val<=list2->val){
                temp->next = list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        temp->next = list1?list1 : list2;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*> &lists, int s, int e){
        if(s>e) return nullptr;

        if(s==e) return lists[s];

        int mid = s + (e-s)/2;

        ListNode* list1 = mergeKLists(lists, s, mid);
        ListNode* list2 = mergeKLists(lists, mid+1, e);

        return merge(list1, list2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size()-1);
    }
};

// Time Complexity: O(Nlogk) where k is the number of linked lists and N is the total number of nodes in all linked lists.
// Space Complexity: O(logk) for recursive stack space.