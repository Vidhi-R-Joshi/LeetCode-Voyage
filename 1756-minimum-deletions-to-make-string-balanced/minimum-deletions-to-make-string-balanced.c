int minimumDeletions(char *s) {
    int n = strlen(s);
    int cnt_a[n + 1];
    int cnt_b[n + 1];
    
    cnt_a[0] = 0;
    cnt_b[0] = 0;

    for (int i = 1; i <= n; i++) {
        cnt_a[i] = cnt_a[i - 1] + (s[i - 1] == 'a' ? 1 : 0);
        cnt_b[i] = cnt_b[i - 1] + (s[i - 1] == 'b' ? 1 : 0);
    }

    int min_dels = INT_MAX;

    for (int i = 0; i <= n; i++) {
        int dels = cnt_b[i] + (cnt_a[n] - cnt_a[i]);
        if (dels < min_dels) {
            min_dels = dels;
        }
    }

    return min_dels;
}

