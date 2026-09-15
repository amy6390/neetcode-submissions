class Solution {
    public String minWindow(String s, String t) {
        if (s.length() < t.length()) {
            return "";
        }
        String alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int[] tCharCnt = new int[52];
        for (int i = 0; i < 52; i++) {
            tCharCnt[i] = 0;
        }

        for (int i = 0; i < t.length(); i++) {
            String curr = t.substring(i, i + 1);
            int idx = alphabet.indexOf(curr);
            tCharCnt[idx]++;
        }

        int left = 0, right = t.length() - 1;
        int[] currCharCnt = new int[52];
        for (int i = 0; i < 52; i++) {
            currCharCnt[i] = 0;
        }
        for (int i = left; i <= right; i++) {
            String curr = s.substring(i, i + 1);
            currCharCnt[alphabet.indexOf(curr)]++;
        }

        int shortest_length = s.length() + 1;
        String res = "";

        while (right < s.length()) {
            boolean match_found = true;
            for (int i = 0; i < 52; i++) {
                if (currCharCnt[i] < tCharCnt[i]) {
                    match_found = false;
                    break;
                }
            }
            if (match_found && right - left + 1 < shortest_length) {
                shortest_length = right - left + 1;
                res = s.substring(left, right + 1);
            }

            if (right + 1 >= s.length()) {
                break;
            }
            right++;
            String curr = s.substring(right, right + 1);
            currCharCnt[alphabet.indexOf(curr)]++;
            
            while (left <= right && currCharCnt[alphabet.indexOf(s.substring(left, left + 1))] - 1 >= tCharCnt[alphabet.indexOf(s.substring(left, left + 1))]) {
                currCharCnt[alphabet.indexOf(s.substring(left, left + 1))]--;
                left++;
            }
        }

        return res;
    }
}
