//�� ������� ����� ������ ������� �������� ����� ��������. ��������� �� ���?
// ����� ����� ��������� �������� �������
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#pragma warning (disable:4996)

int main(int argc, char * argv[])
{
	int k, n, i, j, p, flag = 1;   //  flag=1 ���������� ����������
	char *String;         //��������� ������
	//FILE *Int = fopen("Int.txt" , "r");  //���� ���� ��� �����,������ ��� ������
	//FILE *Out = fopen("Out.txt" , "w");
	FILE *Int = fopen(argv[1], "r");  //���� ���� ��� �����,������ ��� ������
	FILE *Out = fopen(argv[2], "w");
	if (Int == NULL)  //�������� �� �������
	{
		fprintf(Out, "0");
	}
	else
	{
		fscanf(Int, "%d", &k);//������ ���� �����
		fscanf(Int, "%d", &n);  //������ �������
		//p = 1 << n;  //���������� � �������
		String = (char*)malloc((p + 1)*sizeof(char));   //������ ��� ������ ����� (p+1) ������ ��� � ������ ���� �����
		fscanf(Int, "%s", String);
		for (i = 0; i < p - 1; i++)
		{
			for (j = i + 1; j < p; j++)   //������ ���� ����� ������ �������� � ����������
			{
				if ((i & j) == i && String[i] - '0' > String[j] - '0') 
// i �������� ��������� j � ���������� ������������  ��� ������ ���������� ���������� ����� ����� ���������� � ����� ��� � ������ ������� �� �������� �������
				{                   //�� ���� � ���
					flag = 0; 
					break;
				}
			}
		}
		if (flag == 0)     //�� ����������
			fprintf(Out, "0");
		else               //����������
			fprintf(Out, "1");

		fclose(Int);  //�������� ������
		fclose(Out);
	}
	return 0;
}