class Solution {
    public boolean isAnagram(String s, String t) {
        char[] schars = s.toCharArray();
        Arrays.sort(schars);

        char[] tchars = t.toCharArray();
        Arrays.sort(tchars);

        if (schars.length != tchars.length) {
            return false;
        }
        for (int i = 0; i < schars.length; i++) {
            if (schars[i] != tchars[i]) {
                return false;
            }
        }

        return true;
    }
}
