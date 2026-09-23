class Solution {
public:
    int maxStackHeight(vector<int>& R, vector<int>& H) {
        int n = R.size();

        vector<pair<int, int>> discs(n);
        for (int i = 0; i < n; i++) {
            discs[i] = {R[i], H[i]};
        }

        // Sort by radius ascending.
        // For equal radius, height descending so equal-radius
        // discs cannot be selected together.
        sort(discs.begin(), discs.end(), [](auto& a, auto& b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });

        // Coordinate compression of heights
        vector<int> heights;
        for (auto& [r, h] : discs)
            heights.push_back(h);

        sort(heights.begin(), heights.end());
        heights.erase(unique(heights.begin(), heights.end()), heights.end());

        // Fenwick Tree: stores maximum stack height
        vector<int> bit(heights.size() + 1, 0);

        auto query = [&](int idx) {
            int ans = 0;

            while (idx > 0) {
                ans = max(ans, bit[idx]);
                idx -= idx & -idx;
            }

            return ans;
        };

        auto update = [&](int idx, int value) {
            while (idx < (int)bit.size()) {
                bit[idx] = max(bit[idx], value);
                idx += idx & -idx;
            }
        };

        int ans = 0;

        for (auto& [radius, height] : discs) {
            int pos = lower_bound(
                heights.begin(),
                heights.end(),
                height
            ) - heights.begin() + 1;

            // Only heights strictly smaller than current height
            int best = query(pos - 1);

            int current = best + height;

            update(pos, current);

            ans = max(ans, current);
        }

        return ans;
    }
};