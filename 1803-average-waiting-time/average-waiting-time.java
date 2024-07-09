class Solution {
    public double averageWaitingTime(int[][] customers) {
        long totalWaitTime = 0;
        int currentTime = 0;
        
        for (int[] customer : customers) {
            int arrivalTime = customer[0];
            int prepTime = customer[1];
            
           
            if (currentTime < arrivalTime) {
                currentTime = arrivalTime;
            }
            
          
            int waitTime = currentTime - arrivalTime + prepTime;
            totalWaitTime += waitTime;
            
    
            currentTime += prepTime;
        }
        

        return (double) totalWaitTime / customers.length;
    }
}