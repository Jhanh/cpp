#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
#define limit 10000001

// Time complexity: O(N * log(logN))
// Space complexity: O(N) với N = limit

vector<bool> prime(limit, true);
void eratosthenes(){
    prime[0] = prime[1] = false;

    for (int i = 2; i*i < limit; i++){
        if (prime[i] == true){
            for (int j = i*i; j < limit; j += i){
                prime[j] = false;
            }
        }
    }
}

int main(){
    eratosthenes();
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        if (prime[i] == true){
            cout << i << '\n';
        }
    }

    return 0;
}
