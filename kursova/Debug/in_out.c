#include "Common.h"
#include "in_out.h"

//модуль з ф-ціями для вводу і виводу тривимірного масиву

void in()
{
    int y=0;
	for (i=0; i<p; i++)
		for (j=0; j<n; j++)
			for (k=0; k<n; k++)
			{
			arr[i][j][k]=p*n*n-y;
			y++;
            }
}

void out()
{
	for (i=0; i<p; i++)
	{
		printf("No %d", i+1);
		printf("\n");
		for (j=0; j<n; j++)
		{
			for (k=0; k<n; k++)
			printf("%3d  ", arr[i][j][k]);
		printf("\n");
		}
	printf("\n");
	}
}
