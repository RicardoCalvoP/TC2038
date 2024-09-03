#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*
Ricardo Calvo - A01028889
02/09/2024

Instrucciones:

Utilizando la tácnica de divide y vencerás, hacer un programa
que implemente los algoritmos de MergeSort y QuickSort.
El programa recibe por la entrada estándar un numero N que
indica el número de números que se deberán ordenar.
A continuación N valores reales (double), uno en cada linea.

Output: una lista de los N valores de MAYOR -> MENOR

*/

/*
----------------------
FUCNIONES MERGE SORT |
----------------------
*/

void Merge(double part_list_numbers[], double aux_list[], int low, int mid, int high)
{
    // Copiar los elementos del arreglo original al arreglo auxiliar
    for (int k = low; k <= high; k++)
    {
        aux_list[k] = part_list_numbers[k];
    }

    int i = low;     // Índice para la primera mitad
    int j = mid + 1; // Índice para la segunda mitad

    // Fusionar los dos subarreglos ordenados de regreso en part_list_numbers
    for (int k = low; k <= high; k++)
    {
        if (i > mid)
        {
            // Si se ha agotado la primera mitad, tomar de la segunda mitad
            part_list_numbers[k] = aux_list[j++];
        }
        else if (j > high)
        {
            // Si se ha agotado la segunda mitad, tomar de la primera mitad
            part_list_numbers[k] = aux_list[i++];
        }
        else if (aux_list[j] > aux_list[i]) // Linea donde se determina el mayor a menor
        {
            // Si el elemento en la segunda mitad es menor, tomarlo
            part_list_numbers[k] = aux_list[j++];
        }
        else
        {
            // De lo contrario, tomar el elemento de la primera mitad
            part_list_numbers[k] = aux_list[i++];
        }
    }
}

void Sort(double list_numbers[], double aux_list[], int low, int high)
{

    if (high <= low)
    {
        return;
    }

    int mid = low + (high - low) / 2;
    Sort(list_numbers, aux_list, low, mid);
    Sort(list_numbers, aux_list, mid + 1, high);

    Merge(list_numbers, aux_list, low, mid, high);
}

/*
----------------------
FUCNIONES QUICK SORT |
----------------------
*/
int Partition(double part_list_numbers[], int low, int high)
{
    int left_index = low;
    int right_index = high + 1;
    double pivot = part_list_numbers[low];

    while (true)
    {
        while (part_list_numbers[++left_index] > pivot)
        {
            if (left_index == high)
            {
                break;
            }
        }
        while (part_list_numbers[--right_index] < pivot)
        {
            if (right_index == low)
            {
                break;
            }
        }
        if (left_index >= right_index)
        {
            break;
        }
        // Intercambiar elementos
        swap(part_list_numbers[left_index], part_list_numbers[right_index]);
    }
    // Colocar el pivote en su posición correcta
    swap(part_list_numbers[low], part_list_numbers[right_index]);

    return right_index; // Devolver el índice del pivote
}

void Quick_sort(double list_numbers[], int low, int high)
{
    if (high <= low)
    {
        return;
    }

    // Encontrar el pivote
    int pivot = Partition(list_numbers, low, high);

    Quick_sort(list_numbers, low, pivot - 1);
    Quick_sort(list_numbers, pivot + 1, high);
}

/*
----------------------
FUCNIONES MAIN       |
----------------------
*/
void Show(double list_numbers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << list_numbers[i] << " -> ";
    }
    cout << list_numbers[size] << endl
         << endl;
}

void Solution()
{
    // Crear un tamaño random para la primera lista
    srand((unsigned)time(NULL));
    int size = 10 + rand() % 11; // Tamaño random del 10 - 20

    double list_numbers[size];
    for (int i = 0; i < size; i++)
    {
        // Agregamos num random del 0.01 - 100.00 en cada posición de list_numbers
        list_numbers[i] = (double)(1 + rand() % 10000) / 100;
    }
    // Mostrar arreglo antes de ser ordenador
    cout << "Original Array" << endl
         << endl;
    Show(list_numbers, size - 1);

    double aux_list[size]; // Creamos el arreglo auxiliar
    // Aplicamos Algoritmo Merge Sort al Arreglo
    Sort(list_numbers, aux_list, 0, size - 1);

    // Mostramos arreglo ya ordenado de mayor a menor
    cout << "Merge Sort Array" << endl
         << endl;
    Show(list_numbers, size - 1);

    // Crear un tamaño random para la segunda lista
    size = 10 + rand() % 11;

    double second_list_numbers[size];
    for (int i = 0; i < size; i++)
    {
        second_list_numbers[i] = (double)(1 + rand() % 10000) / 100;
    }

    // Mostrar arreglo antes de ser ordenador
    cout << "Original Array" << endl
         << endl;
    Show(second_list_numbers, size - 1);

    // Aplicamos Algoritmo Quick Sort al Arreglo
    Quick_sort(second_list_numbers, 0, size - 1);

    // Mostramos arreglo ya ordenado de mayor a menor
    cout << endl
         << "Quick Sort Array" << endl
         << endl;
    Show(second_list_numbers, size - 1);
}

int main()
{
    system("cls"); // Borrar contenido de terminal

    Solution();

    return 0;
}