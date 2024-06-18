import java.util.*;

class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        List<Job> jobs = new ArrayList<>();
        for (int i = 0; i < difficulty.length; i++) {
            jobs.add(new Job(difficulty[i], profit[i]));
        }
        Collections.sort(jobs, (a, b) -> a.difficulty - b.difficulty);
        
        Arrays.sort(worker);
        
        int x = 0;
        int y = 0;
        int j = 0;
        
        for (int i = 0; i < worker.length; i++) {
            while (j < jobs.size() && jobs.get(j).difficulty <= worker[i]) {
                y = Math.max(y, jobs.get(j).profit);
                j++;
            }
            x += y;
        }
        
        return x;
    }
    
    private static class Job {
        int difficulty;
        int profit;
        
        Job(int difficulty, int profit) {
            this.difficulty = difficulty;
            this.profit = profit;
        }
    }
}

