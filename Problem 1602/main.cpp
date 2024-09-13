#include <bits/stdc++.h>

using namespace std;

#define MAX 2000000 // Corrigindo a definição de MAX

vector<int> primes;
vector<int> divisors(MAX + 1, 1);

// Função para calcular o crivo de Eratóstenes e pré-calcular divisores
void sieve() {
    vector<bool> is_prime(MAX + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= MAX; ++i) {

        if (is_prime[i]) {
            primes.emplace_back(i);
            for (int j = i; j <= MAX; j += i) {
                int count = 0;
                int num = j;
                while (num % i == 0) {
                    num /= i;
                    count++;
                }
                divisors[j] *= (count + 1);
                is_prime[j] = false; // Marcar como não primo para otimizar
            }
        }
    }
}

// Função para verificar se o número de divisores é primo
bool hiper_primes(int number) {
    return binary_search(primes.begin(), primes.end(), number);
}

int main() {
    sieve(); // Pré-calcula os primos e os divisores

    int number, count;

    while (cin >> number) {
        count = 0;

        for (int i = 2; i <= number; ++i) {
            if (hiper_primes(divisors[i]))
                count++;
        }

        cout << count << endl;
    }

    return 0;
}
