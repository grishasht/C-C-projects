#include "Common.h"
#include "Alg_2.h"

void main_diagonal_2() //алгоритм двійкового пошуку №2 для головної діагоналі
{
for (i=0; i<p; i++)
	{
	L=0; R=n-1;
		while (L<R)
		{
		I=(L+R)/2;
		if (arr[i][I][I]>X) L=I+1;
		else R=I;
		}
	if (arr[i][R][R]==X) printf("\nElement is found at position: %d %d %d", i+1, R+1, R+1);
	else printf("\nElement is not found!");
	}
}

void second_diagonal_2() //алгоритм двійкового пошуку №2 для побічної діагоналі
{
	for (i=0; i<p; i++)
	{
	L=0; R=n-1;
		while (L<R)
		{
		I=(L+R)/2;
		if (arr[i][I][n-1-I]>X) L=I+1;
		else R=I;
		}
	if (arr[i][R][n-1-R]==X) printf("\nElement is found at position: %d %d %d", i+1, R+1, n-R);
	else printf("\nElement is not found!");
	}
}
