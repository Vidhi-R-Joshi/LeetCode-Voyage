int numTeams(int* rating, int ratingSize) {
    int cnt = 0;

    for (int j = 1; j < ratingSize - 1; j++) {
        int lS = 0, lL = 0, rS = 0, rL = 0;

        for (int i = 0; i < j; i++) {
            if (rating[i] < rating[j]) {
                lS++;
            } else {
                lL++;
            }
        }

        for (int k = j + 1; k < ratingSize; k++) {
            if (rating[k] < rating[j]) {
                rS++;
            } else {
                rL++;
            }
        }

        cnt += lS * rL + lL * rS;
    }

    return cnt;
}
