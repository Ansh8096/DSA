#include<bits/stdc++.h>
using namespace std;
class LRUCache {
    public:
    class Node{
        public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };

    void deleteNode(Node* tempNode){
        Node* prevNode = tempNode->prev;
        Node* nextNode = tempNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* tempNode){
        Node* nextNode = head->next;
        head->next = tempNode; tempNode->prev = head;
        nextNode->prev = tempNode; tempNode->next = nextNode;
    }
    public:
    int cap;
    Node* head = new Node(-1,-1); 
    Node* tail = new Node(-1,-1); 
    unordered_map<int,Node*> mpp;
    LRUCache(int capacity) {
        // reinitializing all the values again, for a fresh start...
        cap = capacity;
        mpp.clear();
        head->next = tail; head->prev = NULL;
        tail->prev = head; tail->next = NULL;
    }
    
    int get(int key) {
        // when key is present in our LRuCache dataStructure... 
        if(mpp.find(key) != mpp.end()) {
            Node* reqNode = mpp[key];
            deleteNode(reqNode);
            insertAfterHead(reqNode);
            return reqNode->val;
        }
        // else...
        return -1;
    }
    
    void put(int key, int value) {
        // it is for updation...
        if(mpp.find(key) != mpp.end()){
            Node* reqNode = mpp[key];
            reqNode->val = value;
            deleteNode(reqNode);
            insertAfterHead(reqNode);
        }

        // for putting...
        else {
            if(mpp.size() == cap){
                mpp.erase(tail->prev->key);
                deleteNode(tail->prev);
            }

            Node* newNode = new Node(key,value);
            mpp.insert({key,newNode});
            insertAfterHead(newNode);
        }
    }
};
int main(){

    return 0;
}
