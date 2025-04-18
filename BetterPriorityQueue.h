#include <queue>
#include <vector>
#include <string>
#include "BPQNode_struct.h"


using namespace std;

class BetterPriorityQueue : public priority_queue<BPQNode, vector<BPQNode>, greater<BPQNode>> {
    public:
        bool Contains(const BPQNode& node) const;
        bool Update(const BPQNode& node);
        string ToString() const;
        static string BPQNodeToString(const BPQNode& node);
    };
    