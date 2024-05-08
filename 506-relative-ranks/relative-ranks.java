import java.util.*;

class Solution {
    public String[] findRelativeRanks(int[] score) {
        int s = score.length;

        Integer[] index = new Integer[s];
        for (int i = 0; i < s; i++) {
            index[i] = i;
        }
        Arrays.sort(index, (a, b) -> Integer.compare(score[b], score[a]));

        String[] top3 = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        String[] answer = new String[s];

        for (int i = 0; i < s; i++) {
            if (i < 3) {
                answer[index[i]] = top3[i];
            } else {
                answer[index[i]] = String.valueOf(i + 1);
            }
        }

        return answer;
    }
}

