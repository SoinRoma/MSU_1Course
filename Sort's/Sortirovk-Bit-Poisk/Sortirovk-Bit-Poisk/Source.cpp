//���������� ��������� ���������
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#pragma warning (disable:4996)
int main(int argc, char* argv[])
{
		int n, i, j, first, end, temp, mid;
		int *Mas;
		FILE *Int = fopen("Int.txt", "r");  //���� ��� ��� ����� ,������ ��� ������
		FILE *Out = fopen("Out.txt", "w");
		if (Int == NULL)   //������� ����� �� �������
		{
			fprintf(Out, "0");
		}
		else
		{
			if (fscanf(Int, "%d", &n) == 1)
			{
				fprintf(Out, "%d\n", n);  //����� ����������� �������
				Mas = (int*)malloc(n*sizeof(int));
				for (i = 0; i < n; i++)  //��������� ������
				{
					fscanf(Int, "%d", &Mas[i]);
				}
				first = 0;  //������ �������
				end = n - 1;  //��������� �������
				for (j = 0; j < n; j++)  //���� ������� ������
				{
					for (i = 0; i < n;)
					{
						if ((end - first) == 1)  //�������� ���� ����� ������ � ��������� ��������� ���� ��������
						{
							if (Mas[i] > Mas[first])   //���� ������� ������� ������ �������
							{
								temp = Mas[end];
								Mas[end] = Mas[i];
								Mas[i] = temp;
								i++;
								end = n - 1;
								first = 0;
							}
							else                  //�����
							{
								temp = Mas[first];
								Mas[first] = Mas[i];
								Mas[i] = temp;
								i++;
								end = n - 1;
								first = 0;
							}
						}
						mid = (first + end) / 2;   //��������
						if (Mas[i] > Mas[mid])
						{
							first = mid;
						}
						else
						{
							end = mid;
						}
					}
				}
				for (i = 0; i < n; i++)    //����� ���������������� �������
					fprintf(Out, "%d\t", Mas[i]);
			}
			else
				fprintf(Out, "0");
		}
		fclose(Int);   //�������� ������
		fclose(Out);
	return 0;
}
























/*

if (fscanf(Int, "%f", &x) == 1)
{
	if (fscanf(Int, "%d", &n) == 1);
	{
		n++;
		Mas = (float*)malloc(n*sizeof(float));
		for (i = 1; i < n; i++)
		{
			fscanf(Int, "%f", &Mas[i]);
		}
		first = 0;
		end = n - 1;
		mid = (first + end) / 2;      //������� ��������
		while ((end - first) != 1)
		{
			if (x>Mas[mid])
				first = mid;
			else
				end = mid;

			mid = (first + end) / 2;

		}
		if (x >= Mas[mid])           //������� ���� first ���� end
			fprintf(Out, "%d", end);
		else
			fprintf(Out, "%d", first);
	}
}
fclose(Int);     //��������
fclose(Out);
		}/*/