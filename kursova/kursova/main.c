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
					in();           //вводимо масив
					out();
					printf("Input element X:");
					scanf("%d", &X);
					printf("\nFounded elements at main diagonal: \n");
					main_diagonal_1();  // визначаємо місцезнаходження елемента на головній діагоналі
					printf("\n\nFounded elements at secondary diagonal: \n");
					second_diagonal_1(); // визначаємо місцезнаходження елемента на побічній діагоналі
					break;
				}
				case 2:
				{
					system("cls");
					in();       //вводимо масив
					out();
                    printf("Input element X:");
					scanf("%d", &X);

					printf("\nFounded elements at main diagonal: \n");
					main_diagonal_2(); // визначаємо місцезнаходження елемента на головній діагоналі
					printf("\n\nFounded elements at secondary diagonal: \n");
					second_diagonal_2();    // визначаємо місцезнаходження елемента на побічній діагоналі
					break;
				}
			}
			break;
		}
		case 2:
		{
		    system("cls");
            in();

            res1 = (clock_t*)malloc(t*sizeof(clock_t)); //виділення пам"яті для динамічних масивів, які ми
            res2 = (clock_t*)malloc(t*sizeof(clock_t)); //об"являли в common.c
            res3 = (clock_t*)malloc(t*sizeof(clock_t));
            res4 = (clock_t*)malloc(t*sizeof(clock_t));

            printf("\n Wait! Program is compiling!");
            printf("\n p=%d, n=%d, n=%d", p, n, n);

            printf("\n\n|---------------------Element is on main diagonal---------------------------|\n");
            printf("|---------------------------------------------------------------------------|\n");
            printf("|Comparisoning |     1/4    |     1/2    |     3/4    | Last     |No element|\n");
            printf("|Searching #1  |");

            X=p*n*n+1; //задається значення елемента, який вподальшому буде знаходитись в алгоритмах з
                        //виміру часу. він спеціально виходить за межі масива, для того, щоб ф-ція
                        //виконала точну кількість порівнянь і елемент не знайшовся раніше ніж потрібно.
                        //в подальшому значення Х заміниться значенням потрібного елемента масиву

            //визначаємо час роботи алгоритму для головної діагоналі алгоритму двійкового пошуку №1 на всіх частинах порівнянь
            time_in(4); //викликається ф-ція для визначення часу на 1/4 від загальної кількості порівнянь
            *(res1+0) = time_corr(&res1[0]);//запускається ф-ція для точного визначення часу роботи алгоритму,
            printf("   %.3f    |", (float)*(res1+0)/20);// присвоюється значення нульвому елементу динамічного
            time_in(2);  //визначення часу на 1/2 порівнянь                //масиву та виводимо це значення
            *(res1+0) = time_corr(&res1[0]);
            printf("   %.3f    |", (float)*(res1+0)/20);
            time_in(4/3); //визначення часу на 3/4 порівнянь
            *(res1+0) = time_corr(&res1[0]);
            printf("   %.3f    |", (float)*(res1+0)/20);
            time_in(1); //визначення часу при останньому порівнянні
            *(res1+0) = time_corr(&res1[0]);
            printf("   %.3f  |", (float)*(res1+0)/20);
            time_in(-1); //визначення часу коли елемент не знайдено
            *(res1+0) = time_corr(&res1[0]);
            printf("   %.3f  |", (float)*(res1+0)/20);
            free(*res1); //звільнюється пам"ять для одного з динамічних масивів

            //визначаємо час роботи алгоритму для головної діагоналі алгоритму двійкового пошуку №2 на всіх частинах порівнянь
            printf("\n|Searching #2  |"); // принцип аналогічний діям, зазначених вище
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

            //визначаємо час роботи алгоритму для побічної діагоналі алгоритму двійкового пошуку №1 на всіх частинах порівнянь
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

            //визначаємо час роботи алгоритму для побічної діагоналі алгоритму двійкового пошуку №2 на всіх частинах порівнянь
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