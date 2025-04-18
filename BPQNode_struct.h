#include <climits>
#include "Graph.h"  // for nodekey_t

// This is used for the items in the BetterPriorityQueue
struct BPQNode {
	int pri = INT_MAX;
	bool visited = false;
	nodekey_t gnode = INVALID_NODE_KEY;
	
	// bool operator<(const BPQNode &other) const {
	// 	return pri < other.pri;
	// }

	// bool operator>(const BPQNode &other) const {
	// 	return pri > other.pri;
	// }
	// i edited this portion because the current struct is not checking for cases where they are equal. 
	bool operator<(const BPQNode &other) const {
		if (pri == other.pri) {
			return gnode < other.gnode;
		} else {
			return pri < other.pri;
		}
	}
	
	bool operator>(const BPQNode &other) const {
		if (pri == other.pri) {
			return gnode > other.gnode;
		} else {
			return pri > other.pri;
		}
	}
	
	
	bool operator==(const BPQNode &other) const {
		return this->gnode == other.gnode;
	}
};