#include "Common.h"
#include "Alg_1.h"

void main_diagonal_1() // алгоритм двійкового пошуку №1 для головної діагоналі
{
	for (i=0; i<p; i++)
	{
	L=0; R=n-1;
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
	if (L<=R) printf("\nElement is found at position: %d  %d  %d", i+1, I+1, I+1);
	else printf("\nElement is not found!");
	}
}

void second_diagonal_1() //алгоритм двійкового пошуку №1 для побічної діагоналі
{
	for (i=0; i<p; i++)
	{
	L=0; R=n-1;
		while (L<=R)
		{
		I=(L+R)/2;
		if (arr[i][I][n-1-I]==X) break;
		else
		{
			if (arr[i][I][n-1-I]>X) L=I+1;
			else R=I-1;
		}
		}
	if (L<=R) printf("\nElement is found at position: %d  %d  %d", i+1, I+1, n-I);
	else printf("\nElement is not found!");
	}
}
