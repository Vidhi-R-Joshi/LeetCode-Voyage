class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int x = 0;
        for (int i = 0; i < customers.length; i++) {
            if (grumpy[i] == 0) {
                x += customers[i];
            }
        }
        int y = 0;
        int z = 0;
        for (int i = 0; i < customers.length; i++) {
            z += grumpy[i] == 1 ? customers[i] : 0;
            if (i >= minutes) {
                z -= grumpy[i - minutes] == 1 ? customers[i - minutes] : 0;
            }
            y = Math.max(y, z);
        }
        return x + y;
    }
}

