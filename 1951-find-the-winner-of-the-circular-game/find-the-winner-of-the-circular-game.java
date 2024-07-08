class Solution {
    public int findTheWinner(int n, int k) {
        ArrayList<Integer> x = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            x.add(i);
        }
        int index = 0;

        while (x.size() > 1) {
            index = (index + k - 1) % x.size();
            x.remove(index);
        }

        return x.get(0);
    }
}

