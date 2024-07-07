class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int x = numBottles;
        int y = numBottles;

        while (y >= numExchange) {
            int z = y / numExchange;
            x += z;
            y = z + (y % numExchange);
        }

        return x;
    }
}

