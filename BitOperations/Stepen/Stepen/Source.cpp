//���������� ����� � �������
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#pragma warning (disable:4996)
int main(int argc, char *argv[])
{
	//if (argc > 1)
	//{
	int x, n, y;
	FILE *Int = fopen("Int.txt", "r");  //���� ���� ��� �����,������ ��� ������
	FILE *Out = fopen("Out.txt", "w");
	if (Int == NULL)  //�������� �� �������
	{
		fprintf(Out, "0");
	}
	if (fscanf(Int, "%d", &x) == 1)//������ ���� �����
	{
		if (fscanf(Int, "%d", &n) == 1)  //������ �������
		{
			y = 1;
			while (n)
			{
				if (n & 1)
					y = y*x;
				n >>= 1;
				x = x*x;
			}
			fprintf(Out, "%d\n", y);  //���������� �����
		}
		else
			fprintf(Out, "0");
	}
	else
		fprintf(Out, "0");
	fclose(Int);  //�������� ������
	fclose(Out);

	//}
	return 0;
}