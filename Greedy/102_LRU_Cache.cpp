#include<bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    struct Node{
        int key, value;
        Node *next, *prev;

        Node(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {}
    };

    int capacity;
    unordered_map<int,Node*> cacheMap;

    Node *head, *tail;


    void removeNode(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->next = nullptr;
        node->prev = nullptr;
    }

    void addNodeToFront(Node* node){
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cacheMap.find(key)==cacheMap.end())
            return -1;

        removeNode(cacheMap[key]);
        addNodeToFront(cacheMap[key]);

        return cacheMap[key]->value;
    }
    
    void put(int key, int value) {
        if(cacheMap.find(key)!=cacheMap.end()){
            cacheMap[key]->value = value;

            removeNode(cacheMap[key]);
            addNodeToFront(cacheMap[key]);
        }else{
            if(cacheMap.size()==capacity){
                Node* node = tail->prev;

                cacheMap.erase(node->key);

                removeNode(node);
                delete node;
            }

            Node* newNode = new Node(key, value);
            cacheMap[key] = newNode;

            addNodeToFront(newNode);
        }
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */