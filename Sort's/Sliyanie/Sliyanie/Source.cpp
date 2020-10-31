//���������� ��������
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#pragma warning(disable:4996)

void SortSliyanie(int *Mas,int first, int end)     //������� ����������
{
	int mid,i,j,k;
	int *Mas2;
	if (first == end)  
		return;
	mid = (first + end) / 2; // ��������
	SortSliyanie(Mas, first, mid); // ����� ���� ����,���� �� ��������� ���� �������
	SortSliyanie(Mas, mid + 1, end);
	i = first;  // ������ ��������
	j = mid + 1; // ������
	Mas2 = (int*)malloc(end*sizeof(int)); // ������ ������
	for (k = 0; k <end - first + 1; k++) // ��� ���� ��������� ��������������� �������
	{
		if ((j > end) || ((i <= mid) && (Mas[i] < Mas[j]))) //���� ����� �� � ����� ����� ������� ����������� � ����� ������
		{
			Mas2[k] = Mas[i];
			i++;
		}
		else   // ����� ������ ��������
		{
			Mas2[k] = Mas[j];
			j++;
		}
	}
	for (k = 0; k < end - first + 1; k++) // ���������� ������ ������������ � ������ ������
		Mas[first + k] = Mas2[k];
}
//===========================================================================
int main(int argc,char *argv[])
{
	//if (argc>1)
	//{
		int n, i;
		int *Mas;
		FILE *Intt = fopen("Intt.txt", "r"); //�������� ������ ����� ��� ����� ������� ��� ������
		FILE *Out = fopen("Out.txt", "w");
		if (Intt == NULL) //�������� �� �������
		{
			fprintf(Out, "0");
		}
		else
		{
			if (fscanf(Intt, "%d", &n) == 1)
			{
				fprintf(Out, "%d", n);  //����� ����������� �������
				Mas = (int*)malloc(n*sizeof(int));
				for (i = 0; i < n; i++)   // ��������� ������
				{
					fscanf(Intt, "%d", &Mas[i]);
				}
				SortSliyanie(Mas, 0, n - 1); // ����� �������
				fprintf(Out, "\n");
				for (i = 0; i < n; i++) // ����� ���������������� �������
					fprintf(Out, " %d ", Mas[i]);
			}
			else    //���� ���� �����������
				fprintf(Out, "0");
		}
		fclose(Intt); //��������
		fclose(Out);
	//}
	return 0;
}
