int compare (const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

bool isNStraightHand(int* hand, int handSize, int groupSize) {
   qsort(hand, handSize, sizeof(int), compare);
   int  i, j, count;

    i = 0;
    while (1)
    {
        while (i < handSize && hand[i] == -1)
            i++;
        if (i == handSize)
            return (true);
        count = 1;
        j = i + 1;
        while (j < handSize && count < groupSize)
        {
            if (hand[j] == hand[i] + count)
            {
                hand[j] = -1;
                count++;
            }
            j++;
        }
        if (count != groupSize)
            return (false);
        i++;
    }
    return (true);
}