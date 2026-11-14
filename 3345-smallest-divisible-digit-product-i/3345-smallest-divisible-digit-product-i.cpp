class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int current = n; ; ++current) {
            int product = 1;
            int temp = current;

            // Calculate the product of digits of current
            while (temp > 0) {
                product *= (temp % 10);
                temp /= 10;
            }

            // Check if the digit product is divisible by t
            if (product % t == 0) {
                return current;
            }
        }
    }
};