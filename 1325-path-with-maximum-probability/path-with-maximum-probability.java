public class Solution {
    public double maxProbability(int n, int[][] edges, double[] succProb, int start, int end) {
        List<List<Pair>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < edges.length; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            double prob = succProb[i];
            graph.get(a).add(new Pair(b, prob));
            graph.get(b).add(new Pair(a, prob));
        }

        double[] probabilities = new double[n];
        probabilities[start] = 1.0;

        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> Double.compare(b.probability, a.probability));
        pq.offer(new Pair(start, 1.0));

        while (!pq.isEmpty()) {
            Pair current = pq.poll();
            int node = current.node;
            double prob = current.probability;

            if (node == end) {
                return prob;
            }

            for (Pair neighbor : graph.get(node)) {
                int nextNode = neighbor.node;
                double edgeProb = neighbor.probability;
                double newProb = prob * edgeProb;

                if (newProb > probabilities[nextNode]) {
                    probabilities[nextNode] = newProb;
                    pq.offer(new Pair(nextNode, newProb));
                }
            }
        }

        return 0.0;
    }

    static class Pair {
        int node;
        double probability;

        Pair(int node, double probability) {
            this.node = node;
            this.probability = probability;
        }
    }
}
