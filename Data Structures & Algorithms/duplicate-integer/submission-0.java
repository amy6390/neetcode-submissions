class Solution {
    public boolean hasDuplicate(int[] nums) {
        Set<Integer> unique = new HashSet<>();

        for (Integer i: nums) {
            unique.add(i);
        }

        if (unique.size() != nums.length) {
            return true;
        }
        return false;
    }
}