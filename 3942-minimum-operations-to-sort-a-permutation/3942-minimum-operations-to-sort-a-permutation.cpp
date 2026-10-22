class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int start_type = -1, start_shift = -1;

        int s0 = nums[0];
        bool ok0 = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != (i + s0) % n) {
                ok0 = false;
                break;
            }
        }
        if (ok0) {
            start_type = 0;
            start_shift = s0;
        } else {
            int s1 = (n - 1 - nums[0] % n + n) % n;
            bool ok1 = true;
            for (int i = 0; i < n; ++i) {
                int expected = (n - 1 - ((i + s1) % n) + n) % n;
                if (nums[i] != expected) {
                    ok1 = false;
                    break;
                }
            }
            if (ok1) {
                start_type = 1;
                start_shift = s1;
            }
        }

        if (start_type == -1) return -1;

        int start_id = start_type * n + start_shift;
        vector<int> dist(2 * n, -1);
        queue<int> q;

        dist[start_id] = 0;
        q.push(start_id);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == 0) return dist[u];
            int t = u / n;
            int s = u % n;
            int v1 = t * n + (s + 1) % n;
            if (dist[v1] == -1) {
                dist[v1] = dist[u] + 1;
                q.push(v1);
            }
            int v2 = (1 - t) * n + (n - s) % n;
            if (dist[v2] == -1) {
                dist[v2] = dist[u] + 1;
                q.push(v2);
            }
        }

        return dist[0];
    }
};