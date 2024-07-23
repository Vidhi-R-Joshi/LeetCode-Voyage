class Solution {
    public int[] frequencySort(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        Integer[] newNums = Arrays.stream(nums).boxed().toArray(Integer[]::new);

        Arrays.sort(newNums, new Comparator<Integer>() {
            public int compare(Integer n1, Integer n2) {
                int freqCompare = Integer.compare(freq.get(n1), freq.get(n2));
                return freqCompare != 0 ? freqCompare : Integer.compare(n2, n1);
            }
        });

        for (int i = 0; i < nums.length; i++) {
            nums[i] = newNums[i];
        }

        return nums;
    }
}

