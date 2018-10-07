#include "Common.h"
#include "in_out.h"
#include "Alg_1t.h"
#include "Alg_2t.h"

clock_t *res1, *res2, *res3, *res4; //створення динамічних масивів

void time_in (float a) //функція, яка передає в змінні значення функцій з виміру часу для конкретних алгоритмів
{
    int i;
    for (i=0; i<t; i++)
    {
    in();
    *(res1+i) = end_1m(a);
    *(res2+i) = end_1s(a);
    *(res3+i) = end_2m(a);
    *(res4+i) = end_2s(a);
    }
}

//визначення часу на головній діагоналі першого алгоритму
clock_t end_1m(float a) //ф-ція, що визначає час на вказаному етапі роботи програми.
{                       //параметр а використовується для того , щоб передати значення в функцію, в якій визначається
    clock_t time_start, time_stop; //елемент, знайдений на певній кількості порівнянь, який буде знайдений в даній ф-ції
                                   //визначаєм час знаходження цього елементу на діагоналі та передаємо це значення
    X = main_diagonal_1t(a);       //змінним з ф-ції time_in

    for (i=0; i<p; i++)
	{
	L=0; R=n-1;
	time_start = clock();
		while (L<=R)
		{
		I=(L+R)/2;
		if (arr[i][I][I]==X) break;
		else
		{
			if (arr[i][I][I]>X) L=I+1;
			else R=I-1;
		}
		}
    time_stop = clock();
	}
return time_stop - time_start;
}

//визначення часу на побічній діагоналі першого алгоритму
clock_t end_1s(float a) // принцип роботи даної ф-ції такий самий як і end_1m
{
    clock_t time_start, time_stop;

    X = second_diagonal_1t(a);

    for (i=0; i<p; i++)
	{
	L=0; R=n-1;
	time_start = clock();
		while (L<=R)
		{
		I=(L+R)/2;
		if (arr[i][I][I]==X) break;
		else
		{
			if (arr[i][I][I]>X) L=I+1;
			else R=I-1;
		}
		}
    time_stop = clock();
	}
	return time_stop - time_start;
}

//визначення часу на головній діагоналі другого алгоритму
clock_t end_2m(float a) // принцип роботи даної ф-ції такий самий як і end_1m
{
    clock_t time_start, time_stop;

    X = main_diagonal_2t(a);

    for (i=0; i<p; i++)
	{
	L=0; R=n-1;
	time_start = clock();
		while (L<R)
		{
		I=(L+R)/2;
		if (arr[i][I][n-1-I]>X) L=I+1;
		else R=I;
		}
    time_stop = clock();
	}
	return time_stop - time_start;
}

//визначення часу на побічній діагоналі другого алгоритму
clock_t end_2s(float a) // принцип роботи даної ф-ції такий самий як і end_1m
{
    clock_t time_start, time_stop;

    X = second_diagonal_2t(a);

    for (i=0; i<p; i++)
	{
	L=0; R=n-1;
	time_start = clock();
		while (L<R)
		{
		I=(L+R)/2;
		if (arr[i][I][I]>X) L=I+1;
		else R=I;
		}
    time_stop = clock();
	}
	return time_stop - time_start;
}

//функія для точного визначення часу
clock_t time_corr(clock_t *res) //в дану ф-цію передаються масиви з ф-ції time_in над якими будуть
{                                  //виконуватись подальші дії і повертатиметься остаточний результат
    long int Sum,Min1,Min2,Min3,Max1,Max2,Max3;
    int imin1,imin2,imin3,imax1,imax2,imax3;

    Sum = *(res+2); Min1 = *(res+2); Max1 = *(res+2); imin1 = 2; imax1 = 2;
    for (i = 3; i < t; i++)
    {
        Sum = Sum + *(res+i);
        if (*(res+i) > Max1) { Max1 = *(res+i); imax1 = i; }
        else if (*(res+i) < Min1) { Min1 = *(res+i); imin1 = i; }
    }
    res[imin1]=-1; res[imax1]=-1;

     if (*(res+2) == -1) {Min2 = *(res+3); imin2 = 3;}
    else {Min2 = *(res+2); imin2 = 2;}
    Max2 = *(res+2); imax2 = 2;
    for (i = 3; i < t; i++)
    {
        if (*(res+i) > Max2) { Max2 = *(res+i); imax2 = i; }
        else if (*(res+i)<Min2 && *(res+i)!=-1) { Min2 = *(res+i); imin2 = i; }
    }
    res[imin2]=-1; res[imax2]=-1;

    if (*(res+2) == -1)
        if (*(res+3) == -1) {Min3 = *(res+4); imin3 = 4;}
        else {Min3 = *(res+3); imin3 = 3;}
    else {Min3 = *(res+2); imin3 = 2;}
    Max3 = *(res+2); imax3 = 2;
    for (i = 3; i < t; i++)
    {
        if (*(res+i) > Max3) { Max3 = *(res+i); imax3 = i; }
        else if (*(res+i)<Min3 && *(res+i)!=-1) { Min3 = *(res+i); imin3 = i; }
    }
    return Sum - Min1 - Min2 - Min3 - Max1 - Max2 - Max3;
}
