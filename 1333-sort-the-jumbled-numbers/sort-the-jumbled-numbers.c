/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct{
    int index;
    int val;
} Element;

int convert(int n, int* mapping, int size){
    if(n==0){
        return mapping[0];
    }
    int result =0;
    int multiplier = 1;

    while(n > 0){
        int d = n % 10;
        result = mapping[d] * multiplier + result;
        multiplier *= 10;
        n /= 10;
    }

    return result;
}

int cmp(const void* a, const void* b) {
    Element* elemA = (Element*)a;
    Element* elemB = (Element*)b;

    if (elemA->val != elemB->val) {
        return elemA->val - elemB->val;
    } else {
        return elemA->index - elemB->index;
    }
}

int* sortJumbled(int* mapping, int mappingSize, int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    Element dup[numsSize];
    for(int i=0; i<numsSize; i++){
        dup[i].index = i;
        dup[i].val = convert(nums[i],mapping,mappingSize);
    }

    qsort(dup, numsSize, sizeof(Element), cmp);

    int* result =(int*)malloc(numsSize*sizeof(int));
    for(int i=0; i<numsSize; i++){
        result[i] = nums[dup[i].index];
    }
    return result;
}