class Solution {
    public int checkRecord(int n) {
        if (n == 1) {
            return 3;
        } else {
            long mod = 1000000007;
            long al = 1, all = 0, anl = 3, nal = 1, nall = 1, nap = 2;
            long ans = al + all + anl + nal + nall + nap;
            while (n > 2) {
                long t1 = anl % mod;
                long t2 = al % mod;
                long t3 = (al + all + anl + nal + nall + nap) % mod;
                long t4 = nap % mod;
                long t5 = nal % mod;
                long t6 = (nap + nal + nall) % mod;
                ans = (t1 + t2 + t3 + t4 + t5 + t6) % mod;
                al = t1;
                all = t2;
                anl = t3;
                nal = t4;
                nall = t5;
                nap = t6;
                n--;
            }
            return (int) ans;
        }
    }
}