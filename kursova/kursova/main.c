#include "Common.h"
#include "in_out.h"

int main()
{
	int a, b;

	printf ("Please choose yours mode:\n");
	printf ("Press 1 if you want to test algorithmes\n");
	printf ("Press 2 if you want to see time of work algorithmes\n");
	printf ("And your choise is...   "); scanf("%d", &a);

	switch (a)
	{
		case 1:
		{
			system("cls");
			printf("Please choose algorithm you want:\n");
			printf("Press 1 if you want to find element whith algorithm 1\n");
			printf("Press 2 if you want to find element whith algorithm 2\n");
			printf ("And your choise is...   "); scanf("%d", &b);
			switch (b)
			{
				case 1:
				{
					system("cls");
					in();           //������� �����
					out();
					printf("Input element X:");
					scanf("%d", &X);
					printf("\nFounded elements at main diagonal: \n");
					main_diagonal_1();  // ��������� ��������������� �������� �� ������� �������
					printf("\n\nFounded elements at secondary diagonal: \n");
					second_diagonal_1(); // ��������� ��������������� �������� �� ������ �������
					break;
				}
				case 2:
				{
					system("cls");
					in();       //������� �����
					out();
                    printf("Input element X:");
					scanf("%d", &X);

					printf("\nFounded elements at main diagonal: \n");
					main_diagonal_2(); // ��������� ��������������� �������� �� ������� �������
					printf("\n\nFounded elements at secondary diagonal: \n");
					second_diagonal_2();    // ��������� ��������������� �������� �� ������ �������
					break;
				}
			}
			break;
		}
		case 2:
		{
		    system("cls");
            in();

            res1 = (clock_t*)malloc(t*sizeof(clock_t)); //�������� ���"�� ��� ��������� ������, �� ��
            res2 = (clock_t*)malloc(t*sizeof(clock_t)); //��"������ � common.c
            res3 = (clock_t*)malloc(t*sizeof(clock_t));
            res4 = (clock_t*)malloc(t*sizeof(clock_t));

            printf("\n Wait! Program is compiling!");
            printf("\n p=%d, n=%d, n=%d", p, n, n);

            printf("\n\n|---------------------Element is on main diagonal---------------------------|\n");
            printf("|---------------------------------------------------------------------------|\n");
            printf("|Comparisoning |     1/4    |     1/2    |     3/4    | Last     |No element|\n");
            printf("|Searching #1  |");

            X=p*n*n+1; //�������� �������� ��������, ���� ����������� ���� ����������� � ���������� �
                        //����� ����. �� ���������� �������� �� ��� ������, ��� ����, ��� �-���
                        //�������� ����� ������� �������� � ������� �� ��������� ����� �� �������.
                        //� ���������� �������� � ��������� ��������� ��������� �������� ������

            //��������� ��� ������ ��������� ��� ������� ������� ��������� ��������� ������ �1 �� ��� �������� ��������
            time_in(4); //����������� �-��� ��� ���������� ���� �� 1/4 �� �������� ������� ��������
            *(res1+0) = time_corr(&res1[0]);//����������� �-��� ��� ������� ���������� ���� ������ ���������,
            printf("   %.3f    |", (float)*(res1+0)/20);// ������������ �������� �������� �������� ����������
            time_in(2);  //���������� ���� �� 1/2 ��������                //������ �� �������� �� ��������
            *(res1+0) = time_corr(&res1[0]);
            printf("   %.3f    |", (float)*(res1+0)/20);
            time_in(4/3); //���������� ���� �� 3/4 ��������
            *(res1+0) = time_corr(&res1[0]);
            printf("   %.3f    |", (float)*(res1+0)/20);
            time_in(1); //���������� ���� ��� ���������� ��������
            *(res1+0) = time_corr(&res1[0]);
            printf("   %.3f  |", (float)*(res1+0)/20);
            time_in(-1); //���������� ���� ���� ������� �� ��������
            *(res1+0) = time_corr(&res1[0]);
            printf("   %.3f  |", (float)*(res1+0)/20);
            free(*res1); //����������� ���"��� ��� ������ � ��������� ������

            //��������� ��� ������ ��������� ��� ������� ������� ��������� ��������� ������ �2 �� ��� �������� ��������
            printf("\n|Searching #2  |"); // ������� ���������� ���, ���������� ����
            time_in(4);
            *(res3+0) = time_corr(&res3[0]);
            printf("   %.3f    |", (float)*(res3+0)/20);
            time_in(2);
            *(res3+0) = time_corr(&res3[0]);
            printf("   %.3f    |", (float)*(res3+0)/20);
            time_in(4/3);
            *(res3+0) = time_corr(&res3[0]);
            printf("   %.3f    |", (float)*(res3+0)/20);
            time_in(1);
            *(res3+0) = time_corr(&res3[0]);
            printf("   %.3f  |", (float)*(res3+0)/20);
            time_in(-1);
            *(res3+0) = time_corr(&res3[0]);
            printf("   %.3f  |", (float)*(res3+0)/20);
            free(*res3);
            printf("\n|---------------------------------------------------------------------------|\n");

            printf("\n\n|--------------------Element is on second diagonal--------------------------|\n");
            printf("|---------------------------------------------------------------------------|\n");
            printf("|Comparisoning |     1/4    |     1/2    |     3/4    | Last     |No element|\n");
            printf("|Searching #1  |");

            //��������� ��� ������ ��������� ��� ������ ������� ��������� ��������� ������ �1 �� ��� �������� ��������
            time_in(4);
            *(res2+0) = time_corr(&res2[0]);
            printf("   %.3f    |", (float)*(res2+0)/20);
            time_in(2);
            *(res2+0) = time_corr(&res2[0]);
            printf("   %.3f    |", (float)*(res2+0)/20);
            time_in(4/3);
            *(res2+0) = time_corr(&res2[0]);
            printf("   %.3f    |", (float)*(res2+0)/20);
            time_in(1);
            *(res2+0) = time_corr(&res2[0]);
            printf("   %.3f  |", (float)*(res2+0)/20);
            time_in(-1);
            *(res2+0) = time_corr(&res2[0]);
            printf("   %.3f  |", (float)*(res2+0)/20);
            free(*res2);

            //��������� ��� ������ ��������� ��� ������ ������� ��������� ��������� ������ �2 �� ��� �������� ��������
            printf("\n|Searching #2  |");
            time_in(4);
            *(res4+0) = time_corr(&res4[0]);
            printf("   %.3f    |", (float)*(res4+0)/20);
            time_in(2);
            *(res4+0) = time_corr(&res4[0]);
            printf("   %.3f    |", (float)*(res4+0)/20);
            time_in(4/3);
            *(res4+0) = time_corr(&res4[0]);
            printf("   %.3f    |", (float)*(res4+0)/20);
            time_in(1);
            *(res4+0) = time_corr(&res4[0]);
            printf("   %.3f  |", (float)*(res4+0)/20);
            time_in(-1);
            *(res4+0) = time_corr(&res4[0]);
            printf("   %.3f  |", (float)*(res4+0)/20);
            free(*res4);
            printf("\n|---------------------------------------------------------------------------|\n");

			break;
		}
	}

    printf("\n");
    system("pause");
	return 0;
}