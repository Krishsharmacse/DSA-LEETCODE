class SegTree {
public:
    int n;
    vector<int> tree;

    SegTree(int sz) {
        n = sz;
        tree.assign(4 * n, 0);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return tree[node];

        int mid = (l + r) / 2;
        return max(query(node * 2, l, mid, ql, qr),
                   query(node * 2 + 1, mid + 1, r, ql, qr));
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<int> obstacles;
        int mx = 0;

        for (auto &q : queries) {
            mx = max(mx, q[1]);
            if (q[0] == 1)
                obstacles.push_back(q[1]);
        }

        mx++; // sentinel

        set<int> st;
        st.insert(0);
        st.insert(mx);

        for (int x : obstacles)
            st.insert(x);

        vector<int> coords(st.begin(), st.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < coords.size(); i++)
            pos[coords[i]] = i;

        SegTree seg(coords.size());

        // Build initial segment lengths
        int previous = 0;
        for (auto it = std::next(st.begin()); it != st.end(); ++it) {
            int cur = *it;
            seg.update(pos[cur], cur - previous);
            previous = cur;
        }

        vector<bool> ans;

        for (int i = queries.size() - 1; i >= 0; i--) {
            auto &q = queries[i];

            if (q[0] == 2) {
                int x = q[1], sz = q[2];

                auto it = st.upper_bound(x);
                int right = *it;

                --it;
                int left = *it;

                int idxLeft = pos[left];

                int best = seg.query(0, idxLeft);
                best = max(best, x - left);

                ans.push_back(best >= sz);
            }
            else {
                int x = q[1];

                auto it = st.find(x);
                auto nxt = std::next(it);
                auto prv = std::prev(it);

                int L = *prv;
                int R = *nxt;

                // Remove interval ending at x
                seg.update(pos[x], 0);

                // Merge intervals [L,x] and [x,R] -> [L,R]
                seg.update(pos[R], R - L);

                st.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};