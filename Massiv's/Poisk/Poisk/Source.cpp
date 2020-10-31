//�������� ������� �� �������. �������� ������� ���������� ������ �������, ��� � ���� ������ ����� �������� ������ ����� � 
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#pragma warning (disable:4996)
int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		int n = 0, first, i, end, mid;       //n-����������� first-������ ������� end-��������� mid- ��������
		float x, *Mas;                        // � -����� ������� ����� ���������
		FILE *Int = fopen(argv[1], "r");          //��� ����� ���� ��� ����� ������ ��� ������
		FILE *Out = fopen(argv[2], "w");
		if (Int == NULL)                 //�������� �� �������
		{
			fprintf(Out, "0");
		}
		else
		{
			if (fscanf(Int, "%f", &x) == 1)    //���� �����, ������� ����� ��������
			{
				if (fscanf(Int, "%d", &n) == 1)   //�����������
				{
					n++;
					Mas = (float*)malloc(n*sizeof(float));
					for (i = 1; i < n; i++)    // ��������� ������
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
				else
					fprintf(Out, "0");
			}
			else
				fprintf(Out, "0");
			fclose(Int);     //�������� ������
			fclose(Out);
		}
	}
	return 0;
}
