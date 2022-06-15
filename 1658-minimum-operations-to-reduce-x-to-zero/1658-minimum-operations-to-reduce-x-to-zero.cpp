class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int len = nums.size();
        int cumulative = 0;

        vector<int> prefixSum(len + 1, 0);
        for (int i = 0; i < len; ++i)
            prefixSum[i + 1] = nums[i] + prefixSum[i];

        int res = binarySearch(prefixSum, x);

        for (int i = 1; i <= len; ++i) {
            cumulative += nums[len - i];

            int search = binarySearch(prefixSum, x - cumulative);

            if (search == INT32_MAX || search > len - i) continue;

            res = min(res, i + search);
        }

        return res == INT32_MAX ? -1 : res;
    }

    int binarySearch(vector<int>& prefixSum, int val) {
        int left = 0, right = prefixSum.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefixSum[mid] < val)
                left = mid + 1;
            else
                right = mid;
        }

        return prefixSum[left] == val ? left : INT32_MAX;
    }
};