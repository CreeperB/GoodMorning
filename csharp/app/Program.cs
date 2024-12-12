public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> dict = new Dictionary<int, int>();
        int len = nums.Length;
        for(int i = 0; i < len; i++){
            if(nums[i] >= target) continue;
            for(int j = i; j < len; j++){
                if(nums[i] + nums[j] == target) return new int[] {i, j};
            }
        }
        return new int[] {};
    }
}