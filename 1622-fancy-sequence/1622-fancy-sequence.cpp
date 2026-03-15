#include <vector>

class Fancy {
private:
    long long a;
    long long b;
    const int MOD = 1e9 + 7;
    std::vector<long long> seq;

    
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    Fancy() {
        a = 1;
        b = 0;
    }
    
    void append(int val) {
        
        long long x = (val - b + MOD) % MOD; 
        x = (x * modInverse(a)) % MOD;
        seq.push_back(x);
    }
    
    void addAll(int inc) {
        b = (b + inc) % MOD;
    }
    
    void multAll(int m) {
        a = (a * m) % MOD;
        b = (b * m) % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= seq.size()) {
            return -1;
        }
        
        return (seq[idx] * a + b) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */