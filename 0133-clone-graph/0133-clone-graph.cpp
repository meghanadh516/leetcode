class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {

        // If the graph is empty
        if (node == nullptr) {
            return nullptr;
        }

        // If this node is already cloned
        if (mp.find(node) != mp.end()) {
            return mp[node];
        }

        // Create a copy of the current node
        Node* clone = new Node(node->val);

        // Store original -> clone
        mp[node] = clone;

        // Clone all neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};