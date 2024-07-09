class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        total_wait_time = 0
        current_time = 0
        
        for arrival_time, prep_time in customers:
            if current_time < arrival_time:
                current_time = arrival_time
            
            wait_time = current_time - arrival_time + prep_time
            total_wait_time += wait_time
            
            current_time += prep_time
        
        return total_wait_time / len(customers)
