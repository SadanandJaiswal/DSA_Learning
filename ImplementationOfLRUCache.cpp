#include<bits/stdc++.h>
using namespace std;

class LRUCache{
    private:
        struct Node{
            int key;
            int val;
            Node *prev;
            Node *next;
            Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
        };

        int capacity;
        Node *head, *tail;
        unordered_map<int, Node*> cache;

        void removeNode(Node* node){
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        void addNodeToFront(Node* node){
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
        }
    
    public:
        LRUCache(int capacity): capacity(capacity){
            head = new Node(-1,-1);
            tail = new Node(-1,-1);
            head->next = tail;
            tail->prev = head;
        }

        int get(int key){
            if(cache.find(key) != cache.end()){
                Node* node = cache[key];
                removeNode(node);
                addNodeToFront(node);
                return node->val;
            }
            return -1;
        }

        void put(int key, int val){
            if(cache.find(key) != cache.end()){
                Node* node = cache[key];
                node->val = val;
                removeNode(node);
                addNodeToFront(node);
            }else{
                if(cache.size() == capacity){
                    Node * nodeToRemove = tail->prev;
                    cache.erase(nodeToRemove->key);
                    removeNode(nodeToRemove);
                    delete nodeToRemove;
                }
                Node* node = new Node(key, val);
                cache[key] = node;
                addNodeToFront(node);
            }
        }

};