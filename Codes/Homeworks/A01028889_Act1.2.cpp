#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void Dynamic_Programming(int denominatios[], int change)
{
    if (change == 0)
        return;
    cout << "change: " << change << endl;
}

void Greedy(int denominations[], int change)
{
    int coins[change];
    int num_transaction = 0;
    while (change > 0)
    {
        for (int i = 0; i < 3; i++)
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
        cout << "Dinamic Programming Solution:" << endl;
        // Dynamic_Programming(denominations, to_evaluate_num_list[current_case]);
        cout
            << "Greedy Solution: " << endl;

        Greedy(denominations, to_evaluate_num_list[current_case]);
    }
}

int main()
{
    system("cls"); // Borrar contenido de terminal
    srand((unsigned)time(NULL));

    int denominations[] = {5, 2, 1}; // value of coins
    int num_cases = 4;               // number of cases to test

    Solution(denominations, num_cases);
    return 0;
}