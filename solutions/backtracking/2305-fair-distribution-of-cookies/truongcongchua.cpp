class Solution {
public:
    int minUnfairness = INT_MAX;

    void attempt(vector<int>& cookies, int n, int k, int i, vector<int>& totalCookies) {
        if (i == n) {
            int curUnfairness = *max_element(totalCookies.begin(), totalCookies.end());
            minUnfairness = min(minUnfairness, curUnfairness);
            return;
        }

        for (int child = 0; child < k; child++) {
            if (totalCookies[child] + cookies[i] > minUnfairness) continue;
            totalCookies[child] += cookies[i];
            attempt(cookies, n, k, i + 1, totalCookies);
            totalCookies[child] -= cookies[i];

            if (totalCookies[child] == 0) break;
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        minUnfairness = INT_MAX;
        int n = cookies.size();
        vector<int> totalCookies(k, 0);
        sort(cookies.begin(), cookies.end());
        attempt(cookies, n, k, 0, totalCookies);
        return minUnfairness;
    }
};