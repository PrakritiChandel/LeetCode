class Solution {
public:
    void buildSegmentTree(int index, int l, int r, vector<int>& baskets,
                          vector<int>& segmentTree) {
        // base case
        if (l == r) {
            // when l is eq to r means you are at same ranege like 0 to 0 means
            // at first ele 1:1 means u are at first ele so add this in
            // segmentTree[index]
            segmentTree[index] =
                baskets[l]; // eiher baskets[l or r] as both are same
            return;
        }

        // if l and r not same then take mid and build recursvely call
        int mid = (l + r) / 2;

        // for left ele
        buildSegmentTree(2 * index + 1, l, mid, baskets, segmentTree);
        buildSegmentTree(2 * index + 2, mid + 1, r, baskets, segmentTree);

        // also I have to populate the curr node using index which is max among
        // both left and right
        segmentTree[index] =
            max(segmentTree[2 * index + 1], segmentTree[2 * index + 2]);
    }

    bool checkfruitinSegementTree(int index, int l, int r,
                                  vector<int>& segmentTree, int fruit) {
        // now we have the max basket size at top of tree bz it shows max from 0
        // to n-1 range but if the fruit is also bigger than this then no use to
        // check directly return false
        if (segmentTree[index] < fruit) {
            return false;
        }

        // and also check if you are at leaf end node then place the fruit into
        // segment tree and mark it
        if (l == r) {
            segmentTree[index] = -1;
            return true;
        }

        // or otherwise it is not the leaf node then it must be inbetween node
        // so
        int mid = l + (r - l) / 2;
        bool isPlaced = false;

        if (segmentTree[2 * index + 1] >= fruit) { // means going left
            isPlaced = checkfruitinSegementTree(2 * index + 1, l, mid,
                                                segmentTree, fruit);
        } else {
            // means going right
            isPlaced = checkfruitinSegementTree(2 * index + 2, mid + 1, r,
                                                segmentTree, fruit);
        }

        // also we have update the maximum among left and right as we earlier
        // marked it -1
        segmentTree[index] =
            max(segmentTree[2 * index + 1], segmentTree[2 * index + 2]);

        return isPlaced;
    }
    // TC - O(n * logn)
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        // the intuition is we have to use segment tree
        // Utilize a segment tree to efficiently find the maximum element
        // in a range from left to right, leveraging its ability to handle
        // range queries (e.g., min, max, sum) on a given interval [l, r].

        int n = fruits.size();

        // segement tree
        /*
        When implementing a segment tree using an array, a common approach is to
        store the root at index 1, its     left child at 2*i+1, and its right
        child at 2*i+2. This indexing scheme can result in some "empty" or
        unused slots in the array, especially at lower levels, to maintain the
        correct parent-child relationships and prevent index out-of-bounds
        errors. 4xN size provides a safe upper bound to accommodate these
        potential gaps and ensure all necessary nodes can be stored.
        */
        vector<int> segmentTree(4 * n, -1);

        // index,start range,end range, basket, segment tree
        buildSegmentTree(0, 0, n - 1, baskets, segmentTree);

        // now we have segement tree generated now we have to check that
        // the fruit will place in the segment tree or not
        int unPlaced = 0;
        for (int fruit : fruits) {
            if (checkfruitinSegementTree(0, 0, n - 1, segmentTree, fruit) ==
                false) {
                unPlaced++;
            }
        }
        return unPlaced;
    }
};