class Solution {
    public int findMaximizedCapital(int k, int w, int[] pr, int[] cp) {
        int n = pr.length;
        List<Project> projects = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            projects.add(new Project(cp[i], pr[i]));
        }
        Collections.sort(projects, (a, b) -> a.cost - b.cost);
        
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        int i = 0;
        while (k > 0) {
            while (i < n && w >= projects.get(i).cost) {
                minHeap.offer(-projects.get(i).profit);
                i++;
            }
            if (!minHeap.isEmpty()) {
                w += -minHeap.poll();
            }
            k--;
        }
        
        return w;
    }
    
    private static class Project {
        int cost;
        int profit;
        
        Project(int cost, int profit) {
            this.cost = cost;
            this.profit = profit;
        }
    }
}

