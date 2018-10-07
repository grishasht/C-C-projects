#include "Common.h"
#include "Alg_1t.h"

//�-��� ��� ������� ������� ��������� ��������� ������ �1
int main_diagonal_1t(float a) //�-��� �� ������� ������� �� ����� ������� �������� � ������ ���� � �-���
{                              //��� ����������� ����  ������ ����� � ���������
    int q;                    // � �������� � �� �������� ����� �� ��� ���� ������� ����� h ��� ����������
    float h;                  // ������� ��������

    h=log2(n);
	for (i=0; i<p; i++)
	{
	L=0; R=n-1;
	q=0;
		while (L<=R)
		{
		I=(L+R)/2;
		if (arr[i][I][I]==X) break;
		else
		{
			if (arr[i][I][I]>X) L=I+1;
			else R=I-1;
		}
		if (q==h/a) return (arr[i][I][I]);
		q++;
        }
	}
}

//�-��� ��� ������ ������� ��������� ��������� ������ �1
int second_diagonal_1t(float a) //������� ������ ������� �-��� ����
{
    float h;
	int q;

    h=log2(n);
	for (i=0; i<p; i++)
	{
	L=0; R=n-1;
    q=0;
		while (L<=R)
		{
		I=(L+R)/2;
		if (arr[i][I][n-1-I]==X) break;
		else
		{
			if (arr[i][I][n-1-I]<X) L=I+1;
			else R=I-1;
		}
		if (q == h/a) return arr[i][I][n-1-I];
		q++;
		}
	}
}
