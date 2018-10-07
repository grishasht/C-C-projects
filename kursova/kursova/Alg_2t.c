#include "Common.h"
#include "Alg_2t.h"

//�-��� ��� ������� ������� ��������� ��������� ������ �1
int main_diagonal_2t(float a) //�������� ���������� �-��� main_diagonal_1t
{
    int q;
    float h;

    h=log2(n);
    for (i=0; i<p; i++)
	{
	L=0; R=n-1;
	q=0;
		while (L<R)
		{
		I=(L+R)/2;
		if (arr[i][I][I]>X) L=I+1;
		else R=I;
		if (q == h/a) return arr[i][R][R];
		q++;
		}
	}
}

//�-��� ��� ������ ������� ��������� ��������� ������ �1
int second_diagonal_2t(float a)//�������� ���������� �-��� main_diagonal_1t
{
    int q;
    float h;

    h=log2(n);
	for (i=0; i<p; i++)
	{
	L=0; R=n-1;
	q=0;
		while (L<R)
		{
		I=(L+R)/2;
		if (arr[i][I][n-1-I]<X) L=I+1;
		else R=I;
		if (q == h/a) return arr[i][R][R];
		q++;
		}
	}
}
