#include "pch.h"
#include <iostream>
#include <time.h>
#include <stdio.h>

//	EXE 1
/*Объявить массив из n=20 целых чисел, проинициализировать нулями.
Функция ProcessArray() должна заполнить массив случайными цифрами от 1 до 5, 
вычислить и вернуть наименее часто встречающееся значение в массиве.
(если таких несколько - вернуть наименьшее из них) 
и сформировать выходной массив из всех элементов входного, 
отсорт. в порядке возрастания. 
Вывести все массивы.
*/

void OutputArray(int arr[], size_t arr_size)
{
	for (int i = 0; i < arr_size; i++) printf("%d ", arr[i]);
    printf("\n"); 
    printf("\n"); 
}

void SortArray(int arr[], int s_arr[], size_t arr_size)
{
int min = 0; 
int buf = 0; 

    for (int i = 0; i < arr_size; i++)
    {
    min = i; 
        for (int j = i + 1; j < arr_size; j++)
            min = ( arr[j] < arr[min] ) ? j : min;
            if (i != min)
            {
                buf = arr[i];
                arr[i] = arr[min];
                arr[min] = buf;
            }
    }
 
  s_arr = arr;
  OutputArray(s_arr, arr_size);
}


void processArray(int arr[], int output[], size_t arr_size)
{
srand(time(0));


int temp = 5;  //for condition temp_counter < temp
int temp_counter[5] = {0};
int past = 0;
int pk = 0;
int past_temp[20] = {0};
  
    //random
for (int i = 0; i < arr_size; i++) arr[i] = (int)(1 + (rand() % 5));
    printf("\n"); 
    printf("Array: \n"); 
    OutputArray(arr, arr_size);
    
    //sorting
    printf("Sort: \n"); 
    SortArray(arr, past_temp, arr_size);

    //searching 
    for(int i = 0; i < arr_size; i++)
    {
        switch(arr[i])
        {
            case 1: temp_counter[0]++; break;
            case 2: temp_counter[1]++; break;
            case 3: temp_counter[2]++; break;
            case 4: temp_counter[3]++; break;
            case 5: temp_counter[4]++; break;
        }
    }
    for(int i = 0; i < 5; i++)
    {
        temp = temp_counter[i];
        for(int j = 1; j < 5; j++)
            if(temp > temp_counter[j])
            {
                temp = temp_counter[j];                  
            }          
        printf("\n %d is count -> %d", temp_counter[i], (i + 1));   
    }
    printf("\n min count: %d", temp);
}


int main()
{
	/*  VARIABLES  */
	const size_t N = 20;

	int a[N] =  {0};
	int c[N];

	processArray(a, c, N);
}
