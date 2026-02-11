class Solution {
public:
    struct SegTree {
        int n;
        vector<int> minTree, maxTree, lazy;

        SegTree(int size) {
            n = size;
            minTree.assign(4*n, 0);
            maxTree.assign(4*n, 0);
            lazy.assign(4*n, 0);
        }

        void push(int node, int start, int end) {
            if (lazy[node] != 0) {
                minTree[node] += lazy[node];
                maxTree[node] += lazy[node];

                if (start != end) {
                    lazy[node*2] += lazy[node];
                    lazy[node*2+1] += lazy[node];
                }

                lazy[node] = 0;
            }
        }

        void update(int node, int start, int end, int l, int r, int val) {
            push(node, start, end);

            if (r < start || end < l)
                return;

            if (l <= start && end <= r) {
                lazy[node] += val;
                push(node, start, end);
                return;
            }

            int mid = (start + end) / 2;

            update(node*2, start, mid, l, r, val);
            update(node*2+1, mid+1, end, l, r, val);

            minTree[node] = min(minTree[node*2], minTree[node*2+1]);
            maxTree[node] = max(maxTree[node*2], maxTree[node*2+1]);
        }

        int findZero(int node, int start, int end, int r) {
            push(node, start, end);

            if (start > r)
                return -1;

            // If entire segment is strictly positive or strictly negative
            if (minTree[node] > 0 || maxTree[node] < 0)
                return -1;

            if (start == end)
                return start;

            int mid = (start + end) / 2;

            int left = findZero(node*2, start, mid, r);
            if (left != -1)
                return left;

            return findZero(node*2+1, mid+1, end, r);
        }
    };

    int longestBalanced(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int,int> last;
        SegTree seg(n+1);

        int ans = 0;

        for (int r = 0; r < n; r++) {

            int prev = -1;
            if (last.count(nums[r]))
                prev = last[nums[r]];

            int val = (nums[r] % 2 == 0) ? 1 : -1;

            // Range update: (prev+1 → r)
            seg.update(1, 0, n, prev + 1, r, val);

            last[nums[r]] = r;

            int l = seg.findZero(1, 0, n, r);
            if (l != -1)
                ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
