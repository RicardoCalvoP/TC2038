#include <bits/stdc++.h>
#include <chrono>

using namespace std;

string format_with_commas(long num)
{
    string num_str = to_string(num);
    int insertPosition = num_str.length() - 3;

    while (insertPosition > 0)
    {
        num_str.insert(insertPosition, ",");
        insertPosition -= 3;
    }

    return num_str;
}

int fibonacci_naive(int n)
{
    return n;
}

int fibonacci_recursive(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return n;
        // return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    }
}

string fibonacci_dp(int n)
{
    long F[n + 1];
    F[0] = 0;
    F[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }

    return format_with_commas(F[n]);
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
    system("cls");
    solve(20);

    return 0;
}