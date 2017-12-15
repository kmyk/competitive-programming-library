const int prime[2] = { 1e9+27, 1e9+33 };
const int base[2] = { 10007, 10009 };
array<int, 2> rolling_hash_push(array<int, 2> hash, char c) {
    repeat (i, 2) {
        hash[i] = (hash[i] *(ll) base[i] + c) % prime[i];
    }
    return hash;
}
