class Solution {
    public int numTeams(int[] rating) {
        int n = rating.length;
        int cnt = 0;

        for (int j = 1; j < n - 1; j++) {
            int lS = 0, lL = 0, rS = 0, rL = 0;

            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j]) {
                    lS++;
                } else {
                    lL++;
                }
            }

            for (int k = j + 1; k < n; k++) {
                if (rating[k] < rating[j]) {
                    rS++;
                } else {
                    rL++;
                }
            }

            cnt += lS * rL + lL * rS;
        }

        return cnt;
    }
}