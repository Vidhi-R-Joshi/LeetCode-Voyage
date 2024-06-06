import java.util.HashMap;
import java.util.TreeSet;

class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if (hand.length % groupSize != 0) {
            return false;
        }

        HashMap<Integer, Integer> countMap = new HashMap<>();
        TreeSet<Integer> sortedKeys = new TreeSet<>();

        for (int card : hand) {
            countMap.put(card, countMap.getOrDefault(card, 0) + 1);
            sortedKeys.add(card);
        }

        while (!sortedKeys.isEmpty()) {
            int currentCard = sortedKeys.first();
            for (int i = 0; i < groupSize; i++) {
                int cardToRemove = currentCard + i;
                if (!countMap.containsKey(cardToRemove) || countMap.get(cardToRemove) == 0) {
                    return false;
                }
                countMap.put(cardToRemove, countMap.get(cardToRemove) - 1);
                if (countMap.get(cardToRemove) == 0) {
                    sortedKeys.remove(cardToRemove);
                }
            }
        }

        return true;
    }
}

