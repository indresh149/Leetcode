class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int periods = ceil(1.0* minutesToTest/minutesToDie);
        return ceil(log(buckets)/log(periods + 1));
    }
};