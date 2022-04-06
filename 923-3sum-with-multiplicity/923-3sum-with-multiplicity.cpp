class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long> c;
        for (int a : arr) c[a]++;
        long res = 0;
        for (auto it : c)
            for (auto it2 : c) {
                int i = it.first, j = it2.first, k = target - i - j;
                if (!c.count(k)) continue;
                if (i == j && j == k)
                    res += c[i] * (c[i] - 1) * (c[i] - 2) / 6;
                else if (i == j && j != k)
                    res += c[i] * (c[i] - 1) / 2 * c[k];
                else if (i < j && j < k)
                    res += c[i] * c[j] * c[k];
            }
        return res % int(1e9 + 7);
    }
};

/*
    case 1:
    when i == j == k, we have to make 3 subset out of n numners which are equal, which will
    be equal to target, we can do it by taking n!/(3!*(n-3)!) = n*(n-1)*(n-2) / 6.
    
    case 2:
    only two numbers are equal, i == j != k n!/(2!*(n-2)!) * c[k] ,(c[k] : count of k)
    n*(n-2)/2 * c[k].
    
    case 3:
    all the number distincy, i < j < k, c[i] *c[j] *c[k].
    */