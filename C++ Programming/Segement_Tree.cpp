#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<int> tree; // Segment tree array
    int n;            // Size of the original array

    // Function to build the segment tree
    void buildTree(const vector<int>& arr, int start, int end, int node) {
        if (start == end) {
            // Leaf node will have a single element
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            // Recursively build the left and right children
            buildTree(arr, start, mid, 2 * node + 1);
            buildTree(arr, mid + 1, end, 2 * node + 2);
            // Internal node will have the sum of both children
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // Function to update a value in the segment tree
    void updateTree(int start, int end, int idx, int value, int node) {
        if (start == end) {
            // Leaf node; update the element
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                // If the index is in the left child
                updateTree(start, mid, idx, value, 2 * node + 1);
            } else {
                // If the index is in the right child
                updateTree(mid + 1, end, idx, value, 2 * node + 2);
            }
            // Update the current node after updating the child nodes
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // Function to query the sum in a given range
    int queryTree(int start, int end, int l, int r, int node) {
        // If the range of the node is completely outside the query range
        if (start > r || end < l) {
            return 0;
        }
        // If the range of the node is completely inside the query range
        if (start >= l && end <= r) {
            return tree[node];
        }
        // If part of the range overlaps with the query range
        int mid = (start + end) / 2;
        int leftSum = queryTree(start, mid, l, r, 2 * node + 1);
        int rightSum = queryTree(mid + 1, end, l, r, 2 * node + 2);
        return leftSum + rightSum;
    }

public:
    // Constructor to build the segment tree
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, n - 1, 0);
    }

    // Function to update a value in the array
    void update(int idx, int value) {
        updateTree(0, n - 1, idx, value, 0);
    }

    // Function to get the sum of a range [l, r]
    int query(int l, int r) {
        return queryTree(0, n - 1, l, r, 0);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};  // Example array
    SegmentTree segTree(arr);               // Build the segment tree

    cout << "Sum of values in range [1, 3]: " << segTree.query(1, 3) << endl;  // Output: 15 (3 + 5 + 7)

    segTree.update(1, 10);  // Update index 1 to value 10
    cout << "Sum of values in range [1, 3] after update: " << segTree.query(1, 3) << endl;  // Output: 22 (10 + 5 + 7)

    return 0;
}
