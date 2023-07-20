public class TwoSum {
    public static int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }
        }
        // If no pair is found, return an empty array or null.
        return new int[0]; // You can also return 'null' instead of 'new int[0]' if that's preferred.
    }

    public static void main(String[] args) {
        int[] nums = {2, 7, 11, 15};
        int[] result = twoSum(nums, 9);
        
        // Check if the result array is empty before accessing its elements.
        if (result.length == 2) {
            System.out.println(result[0] + " " + result[1]);
        } else {
            System.out.println("No two elements found that add up to the target.");
        }
    }
}
