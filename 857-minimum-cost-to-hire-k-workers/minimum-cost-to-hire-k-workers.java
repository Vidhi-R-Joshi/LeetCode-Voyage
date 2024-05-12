import java.util.*;

class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        int n = quality.length;
        List<double[]> x = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            x.add(new double[]{((double) wage[i]) / quality[i], quality[i]});
        }
        Collections.sort(x, (a, b) -> Double.compare(a[0], b[0]));
        PriorityQueue<Double> h = new PriorityQueue<>();
        double q = 0;
        for (int i = 0; i < k; i++) {
            h.offer(-x.get(i)[1]);
            q += x.get(i)[1];
        }
        double res = q * x.get(k - 1)[0];
        for (int i = k; i < n; i++) {
            q += x.get(i)[1] - (-h.poll());
            h.offer(-x.get(i)[1]);
            res = Math.min(res, x.get(i)[0] * q);
        }
        return res;
    }
}

