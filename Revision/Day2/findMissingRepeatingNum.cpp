// Optimal math approach TC - O(n)

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
    
    long long n = nums.size();
    
    long long sn = (long long)( n*(n+1) )/2;
    long long s2n = (long long)( n*(n+1)*(2*n+1) ) / 6;
    long long s=0,s2=0;
    
    for( long long i=0;i<n;i++){
        s += nums[i];
        s2 += 1LL * nums[i]*nums[i];
    }
    
    long long num1 = s-sn;
    long long  num2 = s2- s2n;
    long long x = (num2 + num1*num1)/(2*num1);
    long long y = x-num1;
    return {x,y};
}

};



// XOR approach, 
// 1. first xor nums[i] and (1->n) ( you will acutally get x^y),
// where x is repeating and y is missing num
// now for all nums[i] and (1->n) 2. find the diffrentiaiting bit from right (the first one)
// 3. put them into two buckets if the diff bit is 0 and if 1
// 4. once you xor all the zeros and ones seperateley you get x and y
// then check in the nums whichever is count 2 tht is repeating 


class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
    int n = nums.size();
    int num = 0;
    for(int i=0;i<n;i++){
        num = num ^ nums[i]^(i+1);
    }
    
    int bitnumber = 0;
    while(1){
        //and operator combined with bit mask and then right shift
        if( (num & (1<<bitnumber)) !=0){
            break;
        }
        bitnumber++;
    }

    //now we have the bit number we will find out whoch all have 0 and 1 
    //bit at this bitposition(bitnumber), all nums[i] and 1 -> namespace

    int zero = 0;
    int one = 0;
    for(int i=0;i<n;i++){
        //part of zero club
        if((nums[i] & (1<<bitnumber)) == 0){
            zero = zero^ nums[i] ;

        }else{
            //Part of 1 
            one = one ^ nums[i];

        }
    }
     for(int i=1;i<=n;i++){
        //part of zero club
        if((i & (1<<bitnumber)) == 0){
            zero = zero ^ i; 

        }else{
            //Part of 1 
            one = one ^ i;
        }
    }
    int count =0;
    for(int i=0;i<n;i++){
        if(nums[i]==zero){
            count++;
        }
    }
    if(count==2) return {zero,one};
    return {one,zero};

}

    
};