class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        
        const long long MOD = 1000000007;
        
        vector<long long> prefix(s.length() + 1, 0);
        vector<int> nonZero(s.length() + 1, 0);
        vector<int> digits;
        
        for(int i = 0; i < s.length(); i++){
        
            prefix[i + 1] = prefix[i] + (s[i] - '0');
        
            if(s[i] != '0'){
                nonZero[i + 1] = nonZero[i] + 1;
                digits.push_back(s[i] - '0');

            } else {
                nonZero[i + 1] = nonZero[i];
            }
        }
        
        int m = digits.size();
        vector<long long> concat(m + 1, 0);
        vector<long long> pow10(m + 1, 1);

        for(int i = 1; i <= m; i++){
            concat[i] = (concat[i - 1] * 10 + digits[i - 1]) % MOD;
            pow10[i] = pow10[i - 1] * 10 % MOD;
        }

        vector<int> result;
        for(auto& query: queries){
            int l = query[0];
            int r = query[1];

            int left = nonZero[l];
            int right = nonZero[r + 1];

            long long sum = prefix[r + 1] - prefix[l];
            long long num = 0; 

            if(left != right){
                num = concat[right] - (concat[left] * pow10[right-left]) % MOD;;

                if(num < 0){
                    num += MOD;
                }
            }
            result.push_back((num * sum) % MOD);
        }
        return result;
    }
};
