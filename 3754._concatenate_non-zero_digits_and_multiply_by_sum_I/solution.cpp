class Solution {
public:
    long long sumAndMultiply(int n) {
        
        long long result = 0;
        long long sum = 0;
        int mul = 1;
        
        while(n > 0){
            int temp = n % 10;
            n = n / 10;
            if(temp > 0){
                result += (temp * mul);
                mul *= 10;
                sum += temp;
            }
        }
        
        return result * sum;
    }
};
