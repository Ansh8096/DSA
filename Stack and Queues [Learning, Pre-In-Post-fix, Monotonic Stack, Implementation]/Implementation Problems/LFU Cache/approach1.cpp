#include<bits/stdc++.h>
using namespace std;
class LFUCache {
    class Node {
        public:
        int key;
        int val;
        int freq;
        Node *next;
        Node *prev;
        Node(int _key, int _val){
            key = _key;
            val = _val;
            freq = 1;
        }
    };

    class List{
        public:
        int size;
        Node* head;
        Node* tail;
        List(){
            head = new Node(-1,-1);
            tail = new Node(-1,-1);
            head->next = tail; head->prev = NULL;
            tail->prev= head; tail->next = NULL;
            size = 0;
        }
        
        void deleteNode(Node* tempNode){
        Node* prevNode = tempNode->prev;
        Node* nextNode = tempNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
        }

        void insertAfterHead(Node* tempNode){
            Node* nextNode = head->next;
            head->next = tempNode; tempNode->prev = head;
            nextNode->prev = tempNode; tempNode->next = nextNode;
            size++;
        }
    };

    public:
    unordered_map<int,List*> freqListMap;
    unordered_map<int,Node*> keyNodeMap;
    int maxCacheSize;
    int currSize;
    int minFreq;
    LFUCache(int capacity) {
        freqListMap.clear();
        keyNodeMap.clear();
        currSize = 0;
        minFreq = 0;
        maxCacheSize = capacity;
    }
    void updateTheNodeInList(Node* node){
        int currNodeFreq = node->freq;
        keyNodeMap.erase(node->key);
        // 'freqListMap[currNodeFreq]' will give us the list stored in map, 
        // And 'deleteNode()' will delete that particular node from that list...  
        freqListMap[currNodeFreq]->deleteNode(node);
        if(currNodeFreq == minFreq && freqListMap[currNodeFreq]->size == 0){ // 'freqListMap[currNodeFreq]->size' it will give us the size of that particular list... 
            minFreq++;
        }

        // Creating the higher freq. list for the node...
        List* nextHigherFreqList = new List();
        // checking if the nextHigherFreqList is already present or not.if present we will do insert node in this list only...
        if(freqListMap.find(currNodeFreq+1) != freqListMap.end()){
            nextHigherFreqList = freqListMap[currNodeFreq+1];
        }

        // Increasing the freq. of the node,because it is accessed... 
        node->freq++;
        nextHigherFreqList->insertAfterHead(node); // insering this node in the 'nextHigherFreqList' ... 
        
        // Updating both the maps , with the new details(i.e list,freq etc)... 
        freqListMap[node->freq] = nextHigherFreqList;
        keyNodeMap[node->key] = node;
    }

    int get(int key) {
        if(keyNodeMap.find(key) != keyNodeMap.end()) {
            Node* reqNode = keyNodeMap[key];
            updateTheNodeInList(reqNode);
            return reqNode->val; 
        }
        return -1;
    }
    
    void put(int key, int value) {
        // edge case:--
        if (maxCacheSize == 0) return;
        // when the node is already present , we w=just need to update its value and freq. : 
        if(keyNodeMap.find(key) != keyNodeMap.end()){
        Node* reqNode = keyNodeMap[key];
        reqNode->val = value;
        updateTheNodeInList(reqNode);
        } 

        // If the node is node present previously...
        else {
            // when the size of LFUcache is full , we will be removing the LFU...
            if(currSize == maxCacheSize){
                // getting the minFreqList...
                List* minFreqList = freqListMap[minFreq];
                // Removing the LFU node from the map with the help of its key... 
                int keyOfLFUnodetoBeRemoved = minFreqList->tail->prev->key;
                keyNodeMap.erase(keyOfLFUnodetoBeRemoved);
                
                // Removing the LFU node from the minFreqList also...
                minFreqList->deleteNode(minFreqList->tail->prev);
                // decreasing the currSize of our LFU... 
                currSize--;
            }
            
            // If the LFU size is not full, and we will insert the node in the list that has freq. = 1 ,
            // If this list is not there we will create it... 
            minFreq = 1; currSize++; // increasing size, because we are inserting the node...
            Node *newNode = new Node(key, value); 

            // creating the freqList (frq. = 1),
            //  or getting the reference of the existing one... 
            List *newList = new List();
            if (freqListMap.find(minFreq) != freqListMap.end()){ 
                newList = freqListMap[newNode->freq];
            }

            // Inserting the newNode in our list... 
            newList->insertAfterHead(newNode);

            // Updating both the maps , with the new details(i.e list,freq etc)... 
            freqListMap[minFreq] = newList;
            keyNodeMap[key] = newNode; 
        }
    }
};
int main(){

    return 0;
}
