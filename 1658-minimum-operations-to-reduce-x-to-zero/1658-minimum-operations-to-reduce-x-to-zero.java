class Solution {
    public int minOperations(int[] nums, int x) {
        int sum = -x, n = nums.length;
        for(int num : nums)
            sum += num;
        
        if(sum == 0)
            return n;
        
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int currSum = 0;
        int res = Integer.MIN_VALUE;

        for (int i = 0; i < nums.length; ++i) {

            currSum += nums[i];
            if (map.containsKey(currSum - sum)) {
                res = Math.max(res, i - map.get(currSum - sum));
            }

            map.put(currSum, i);
        }

        return res == Integer.MIN_VALUE ? -1 : nums.length - res;
    }
}