//����� �������� ������ ������������ ������������� ��� ������� n n, ��������������� �������� ������ ������������ �������
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#pragma warning (disable:4996)
int main(int argc,char *argv[])
{
	//if (argc > 1)
	//{
		int *Mas;    //������
		int n, i, j;    //n-�����������
		FILE *Int = fopen("Int.txt", "r");  //��� ����� ���� ��� ����� ������ ��� ������
		FILE *Out = fopen("Out.txt", "w");
		if (Int == NULL)   //�������� �� �������
		{
			fprintf(Out, "0");
		}
		else
		{
			if (fscanf(Int, "%d", &n) == 1)
			{
				if (n == 0)
				{
					fprintf(Out, "0"); //���� n=0 �� ������
				}
				fprintf(Out, "%d\n", n + 1);  //����� ���������� ������������ (�� ���� ������)
				Mas = (int*)malloc(n*sizeof(int));   //���������� �������
				for (i = 1; i <= n; i++)
					Mas[i] = 0;
				Mas[0] = 1;     //������ ������� =1
				for (j = 1; j <= n; j++)
				{
					for (i = j; i >= 1; i--)
						Mas[i] = Mas[i - 1] + Mas[i];
				}
				for (i = 0; i <= n; i++)                // ����� ������������
					fprintf(Out, "%d\t", Mas[i]);
			}
			else
				fprintf(Out, "0");
		}
		fclose(Int);   //�������� ������
		fclose(Out);
	//}
		return 0;
}
