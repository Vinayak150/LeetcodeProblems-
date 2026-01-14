class Solution {
public:
    struct Event {
        long long y;
        int x1, x2;
        int type; // +1 add, -1 remove
    };

    struct SegTree {
        int n;
        vector<int> cover;
        vector<long long> len;
        vector<long long> xs;

        SegTree(const vector<long long>& xs) : xs(xs) {
            n = xs.size() - 1;
            cover.assign(4 * n, 0);
            len.assign(4 * n, 0);
        }

        void pull(int node, int l, int r) {
            if (cover[node] > 0) {
                len[node] = xs[r] - xs[l];
            } else if (l + 1 == r) {
                len[node] = 0;
            } else {
                len[node] = len[node * 2] + len[node * 2 + 1];
            }
        }

        void update(int node, int l, int r, int ql, int qr, int val) {
            if (qr <= l || r <= ql) return;
            if (ql <= l && r <= qr) {
                cover[node] += val;
                pull(node, l, r);
                return;
            }
            int mid = (l + r) / 2;
            update(node * 2, l, mid, ql, qr, val);
            update(node * 2 + 1, mid, r, ql, qr, val);
            pull(node, l, r);
        }

        long long query() const {
            return len[1];
        }
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<long long> xs;
        vector<Event> events;

        // Collect x-coordinates
        for (auto &s : squares) {
            long long x = s[0], l = s[2];
            xs.push_back(x);
            xs.push_back(x + l);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        auto xid = [&](long long x) {
            return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        };

        // Build events
        for (auto &s : squares) {
            long long x = s[0], y = s[1], l = s[2];
            int lx = xid(x);
            int rx = xid(x + l);
            events.push_back({y,     lx, rx, +1});
            events.push_back({y + l, lx, rx, -1});
        }

        sort(events.begin(), events.end(),
             [](const Event& a, const Event& b) {
                 return a.y < b.y;
             });

        SegTree st(xs);

        // ---------- FIRST PASS: compute total UNIQUE area ----------
        long double totalArea = 0;
        int i = 0;
        while (i < events.size()) {
            long long y = events[i].y;
            while (i < events.size() && events[i].y == y) {
                st.update(1, 0, st.n, events[i].x1, events[i].x2, events[i].type);
                i++;
            }
            if (i == events.size()) break;
            long long dy = events[i].y - y;
            totalArea += (long double)st.query() * dy;
        }

        long double half = totalArea / 2.0;

        // ---------- SECOND PASS: find balance y ----------
        st = SegTree(xs);  // reset tree
        long double area = 0;
        i = 0;

        while (i < events.size()) {
            long long y = events[i].y;
            while (i < events.size() && events[i].y == y) {
                st.update(1, 0, st.n, events[i].x1, events[i].x2, events[i].type);
                i++;
            }
            if (i == events.size()) break;

            long long nextY = events[i].y;
            long long dy = nextY - y;
            long double slice = (long double)st.query() * dy;

            if (area + slice >= half) {
                return (double)(y + (half - area) / st.query());
            }

            area += slice;
        }

        return (double)events.back().y;
    }
};
