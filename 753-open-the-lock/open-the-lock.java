import java.util.*;

class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String> dead = new HashSet<>();
        for (String d : deadends) dead.add(d);
        Set<String> visited = new HashSet<>();
        visited.add("0000");
        Queue<String> queue = new LinkedList<>();
        queue.offer("0000");
        int depth = 0;
        
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String current = queue.poll();
                if (dead.contains(current)) continue;
                if (current.equals(target)) return depth;
                
                for (int j = 0; j < 4; j++) {
                    for (int d = -1; d <= 1; d += 2) {
                        int digit = (current.charAt(j) - '0' + d + 10) % 10;
                        String next = current.substring(0, j) + ("" + digit) + current.substring(j + 1);
                        if (!visited.contains(next)) {
                            visited.add(next);
                            queue.offer(next);
                        }
                    }
                }
            }
            depth++;
        }
        return -1;
    }
}
