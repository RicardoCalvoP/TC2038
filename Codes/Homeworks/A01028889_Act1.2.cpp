#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h> // For INT_MAX

using namespace std;

/*
Ricardo Calvo - A01028889
09/09/2024

Instrucciones
Utilizando las técnicas de programación de "programación dinámica", y la de "algoritmos avaros",
escribe un programa que resuelva el problema del cambio de monedas.

El programa recibe un numero entero N, seguido de N valores enteros (uno en cada línea)
que representan las diferentes denominaciones disponibles de las monedas.
Seguido de esto, el programa recibe dos números enteros: P y Q, (uno en cada línea) por la entrada estándar,
que representan P: el precio de un producto dado y Q: es el billete o moneda con el que se paga dicho producto.

La salida del programa es una lista de N valores correspondientes al número de monedas de cada denominación,
de mayor a menor, una en cada línea, que se tienen que dar para dar el cambio por el producto pagado,
 primero utilizando programación dinámica, y luego utilizando un algoritmo avaro.
 */
void Show(int list_numbers[], int size) // Complejidad O(n)
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << list_numbers[i] << ", ";
    }
    cout << list_numbers[size] << "]" << endl
         << endl;
}
void Show(int list_numbers[], int denominations[], int size) // Complejidad O(n)
{

    for (int i = 0; i < size; i++)
    {
        cout << list_numbers[i] << " coins of " << denominations[i] << endl;
    }
}

// Best case complexity O(n),
// or O(n*k) where n is the change needed and k is the num_of_domination
void Dynamic_Programming(int denominations[], int num_of_domination, int change)
{
    if (change == 0)
    {
        cout << "No change needed." << endl;
        return;
    }

    int dp[change + 1];       // Array to store the minimum number of coins for each amount
    int coinUsed[change + 1]; // Array to store the last coin used for each amount

    // Initialize dp and coinUsed arrays
    for (int i = 0; i <= change; i++)
    {
        dp[i] = INT_MAX - 1; // Avoid overflow
        coinUsed[i] = -1;
    }
    dp[0] = 0; // No coins needed for amount 0

    // Fill dp array
    for (int i = 1; i <= change; i++)
    {
        for (int j = 0; j < num_of_domination; j++)
        {
            if (i >= denominations[j] && dp[i - denominations[j]] != INT_MAX - 1)
            {
                if (dp[i] > dp[i - denominations[j]] + 1)
                {
                    dp[i] = dp[i - denominations[j]] + 1;
                    coinUsed[i] = j;
                }
            }
        }
    }

    int amount = change;
    int coin_count[num_of_domination] = {0}; // Array to store the count of each coin used

    // Reconstruct the solution
    while (amount > 0)
    {
        int coin_index = coinUsed[amount];
        coin_count[coin_index]++;
        amount -= denominations[coin_index];
    }

    // Print the number of coins of each denomination used
    Show(coin_count, denominations, num_of_domination);
}

// Complexity O(n)
void Greedy(int denominations[], int change)
{
    int coins[change];
    int num_transaction = 0;
    while (change > 0)
    {
        for (int i = 0; i < 6; i++)
        {
            if (change >= denominations[i])
            {
                coins[num_transaction] = denominations[i];
                change -= denominations[i];
                num_transaction++;
                break;
            }
        }
    }
    Show(coins, num_transaction - 1);
}

void Solution(int denominations[], int num_cases)
{
    int to_evaluate_num_list[num_cases]; // array where the prices are going to be stored

    // set changeto work with in list
    for (int i = 0; i < num_cases; i++)
    {
        to_evaluate_num_list[i] = (int)(1 + rand() % 100); // random number 1 - 100
    }

    // Cases

    for (int current_case = 0; current_case < num_cases; current_case++)
    {
        cout << "Case " << current_case + 1 << " change " << to_evaluate_num_list[current_case] << ":" << endl;
<<<<<<< HEAD
        cout << "Dinamic Programming Solution:" << endl;
        // Dynamic_Programming(denominations, to_evaluate_num_list[current_case]);
        cout
            << "Greedy Solution: " << endl;

        Greedy(denominations, to_evaluate_num_list[current_case]);
=======
        cout << "Dynamic Programming Solution:" << endl;
        // Dynamic Programming will send number of coins used to get to solution
        Dynamic_Programming(denomitations, 6, to_evaluate_num_list[current_case]);
        cout
            << "Greedy Solution: " << endl;

        // ---+
        Greedy(denomitations, to_evaluate_num_list[current_case]);
>>>>>>> bb2ef9438216b4f1cce21ea841fe8d5e48a6b882
    }
}

int main()
{
    system("cls"); // Borrar contenido de terminal
    srand((unsigned)time(NULL));

    int denominations[] = {50, 25, 20, 10, 5, 1}; // value of coins
    int num_cases = 4;                            // number of cases to test

    Solution(denominations, num_cases);
    return 0;
}