//����� ������ N ����������� �����, � ������� ������� ���� �������� ���������� ���������� ���������� �����
//�������� 3684910=1000111111110001^2.
//�� ������� ����� � ������ ������ ������ ����������� �����.� �������� ����� ����� ������
//N ����������� ����� ����� ������.
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)
int main(int argc, char * argv[])
{
	//if (argc > 1)
	//{
		int i, n, j, p, n1, n2, t;
		FILE *Int = fopen("Int.txt", "r");   //��������� ���� ���� ��� �����
		FILE *Out = fopen("Out.txt", "w");   // ������ ��� ������
		if (fscanf(Int, "%d", &n) == 1)
		{
			for (i = 1, t = 0; t < n; i++)
			{
				p = 1;
				for (j = 0; j < 8; j++)
				{
					n1 = i&(1 << j);
					n2 = i&(1 << (15 - j));
					if (!(((n1 == 0) && (n2 == 0)) || ((n1 != 0) && (n2 != 0))))
						p = 0;
				}
				if (p == 1)
				{
					fprintf(Out, "%d", i);
					fprintf(Out, "\n");
					t++;
				}
			}
		}
		else
			fprintf(Out, "0");
		fclose(Int);
		fclose(Out);
	//}
	return 0;
}

