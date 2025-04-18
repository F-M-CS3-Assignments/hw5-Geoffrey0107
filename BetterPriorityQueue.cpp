#include "BetterPriorityQueue.h"
#include <iostream>
#include <vector>

using namespace std;

// Checks if a node is already in the priority queue
bool BetterPriorityQueue::Contains(const BPQNode& node) const {
    for(size_t i = 0; i < this->c.size(); i++){
        if(this->c[i] == node){
            return true;
        }
    }
    return false;
}

// Updates the priority of a node only if the new priority is smaller 
bool BetterPriorityQueue::Update(const BPQNode& node){
    for(size_t i = 0; i < this->c.size(); i++){
        if(this->c[i] == node){
            if(this->c[i].pri > node.pri){ // only update if new priority is smaller
                this->c[i].pri = node.pri;
                make_heap(this->c.begin(), this->c.end(), this->comp);
                return true;
            }
        }
    }
    return false;
}

// Converts the whole priority queue to a readable string format
string BetterPriorityQueue::ToString() const{
    string result = "[";
    for(size_t i = 0; i < this->c.size(); i++){
        result.append(BPQNodeToString(this->c[i]));
        if(i<this->c.size() - 1){
            result.append(", ");
        }
    }
    result.append("]");
    return result;
}

// Converts a single BPQNode to string 
string BetterPriorityQueue::BPQNodeToString(const BPQNode& node){
    string result = "(" + to_string(node.gnode) + ", pri: " + to_string(node.pri) + ")";
    return result;
}
