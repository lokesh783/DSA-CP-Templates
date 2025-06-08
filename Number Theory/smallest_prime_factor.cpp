#include<bits/stdc++.h>
using namespace std;
#define SIEVE_SIZE 100001
bool isPrime[SIEVE_SIZE];
int spf[SIEVE_SIZE];

void smallest_prime_factor() {
    for(int i=0;i<SIEVE_SIZE;i++) isPrime[i] = true;
    for(int i=0;i<SIEVE_SIZE;i++) spf[i] = i;
    for(int i=2;i<SIEVE_SIZE;i++) {
        if(isPrime[i] == false) continue;
        for(int j=i*i;j<SIEVE_SIZE;j+=i) {
            isPrime[j] = false;
            spf[j] = min(spf[j], i);
        }
    }
}

