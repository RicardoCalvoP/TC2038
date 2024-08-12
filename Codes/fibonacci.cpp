#include <bits/stdc++.h>
#include <chrono>

using namespace std;

int fibonacci_naive(int n)
{
    return n;
}

int fibonacci_recursive(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    }
}

int fibonacci_dp(int n)
{
    int F[n + 1];
    F[0] = 0;
    F[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }
    return F[n];
}

void solve(int number)
{
    auto start = chrono::high_resolution_clock::now();
    cout << fibonacci_recursive(number) << "\n";
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time elapsed recursive: " << duration.count() << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    cout << fibonacci_dp(number) << "\n";
    end = chrono::high_resolution_clock::now();

    auto duration_nsdp = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Time elapsed DP: " << duration.count() << " nanosecods" << endl;

    start = chrono::high_resolution_clock::now();
    cout << fibonacci_naive(number) << "\n";
    end = chrono::high_resolution_clock::now();

    auto duration_ns = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Time elapsed naive: " << duration_ns.count() << " nanoseconds" << endl;
}

int main(int argc, char **argv)
{
    solve(46);

    return 0;
}