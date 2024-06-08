bool checkSubarraySum(int* nums, int numsSize, int k) {
    if(k==1 && numsSize>1){return true;}
    nums[0]=nums[0]%k;
    for(int i=1;i<numsSize;i++){
        nums[i]=nums[i-1] + nums[i]%k;
        if(nums[i]%k==0){return true;}
        for(int j=0;j<i-1;j++){
            if((nums[i]-nums[j])%k==0){return true;}
            else if((nums[i]-nums[j])<k && nums[i]-nums[i-2]>0){break;}
        }
    }
    return false;
}