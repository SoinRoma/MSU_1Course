//����� ����� � ������������ ����� ������������������
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#pragma warning (disable:4996)
int main(int argc, char * argv[])
{
	//if (argc > 1)
	//{
		double a=0.0, Sum=0.0, Pro=0.0;
		FILE *Int = fopen("Int.txt", "r");   //��������� ���� ���� ��� �����
		FILE *Out = fopen("Out.txt", "w");   // ������ ��� ������
		fscanf(Int, "%lf", &a);
		Sum = a;
		Pro = a;
		while (fscanf(Int, "%lf", &a) == 1)
		{
			Sum = Sum + a; // C����
			Pro = Pro*a;  //������������
		}
		fprintf(Out, "Summa = %lf\n", Sum);
		fprintf(Out, "Proizvedenie = %lf",Pro);
		fclose(Int);  //��������
		fclose(Out);  //��������
	//}
	return 0;
}



