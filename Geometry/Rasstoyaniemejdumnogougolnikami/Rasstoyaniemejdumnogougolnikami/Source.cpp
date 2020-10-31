//��� ��������� ����� ������ ��� ��������������.
//���������� ���������� ����� ����� ����������������. 
//(� ����� ������� �������� ���������� ������ 1-�� �������������� � �������, ����� ���������� ������ 2-�� �������������� � �������.)
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)

typedef struct Point  //��������� �� ��������� 
{
	float x;   //���������� �� X
	float y;   //���������� �� Y
}Point;

float VectornoeProizvedenie(float x1, float y1, float x2, float y2)   //������� ��� ���������� ������������
{
	float VP;
	VP = x1*y2 - x2*y1;
	return VP;
}

int Peresechenie(Point a, Point b, Point c, Point d)//a=Mas1[i],b=Mas1[E],c=Mas2[j],d=Mas2[Q]
{                //������� ������� ������� ��������� �������� � ��������� �� ��������� ������������
	float x1, x2, y1, y2, v1, v2, v3, v4;
	v1 = VectornoeProizvedenie(x1 = (d.x - c.x), y1 = (d.y - c.y), x2 = (a.x - c.x), y2 = (a.y - c.y));
	v2 = VectornoeProizvedenie(x1 = (d.x - c.x), y1 = (d.y - c.y), x2 = (b.x - c.x), y2 = (b.y - c.y));
	v3 = VectornoeProizvedenie(x1 = (b.x - a.x), y1 = (b.y - a.y), x2 = (c.x - a.x), y2 = (c.y - a.y));
	v4 = VectornoeProizvedenie(x1 = (b.x - a.x), y1 = (b.y - a.y), x2 = (d.x - a.x), y2 = (d.y - a.y));
	if (v1*v2 <= 0 && v3*v4 <= 0)    //���� ������� ����������� �� ����� ���������������, ���� ����� ����� ������ ��� �����
		return 1;
	return 0;
}

float Proverkatochki(Point A, Point B) //A=Mas1[i], B=Mas2[j]
{          // ���������� ����� ������ � ������ ����������� �� ������� : Sqrt( (x1-x)^2+(y1-y)^2)
	float S;
	S = sqrt((B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y));
	return S;
}

float Rastoyanie(Point *Mas1, Point *Mas2, int a, int b, int c)   //������� ������ �������������� �� ����� � �������
{
	float X, Y;    //���������� ����� ��������������
	float Dlina=-1;
	if (Mas1[a].x == Mas1[b].x) // ������� ��� ���������
	{
		X = Mas1[a].x;
		Y = Mas2[c].y;
	}
	if (Mas1[a].y == Mas1[b].y)   //��� �����������
	{
		X = Mas2[c].x;
		Y = Mas1[a].y;
	}
	if ((Mas1[a].x != Mas1[b].x) && (Mas1[a].y != Mas1[b].y))//����� ������
	{
		X = ((Mas1[b].x - Mas1[a].x)*(Mas1[b].y - Mas1[a].y)*(Mas2[c].y - Mas1[a].y) + Mas1[a].x*(Mas1[b].y - Mas1[a].y)*(Mas1[b].y - Mas1[a].y) + Mas2[c].x*(Mas1[b].x - Mas1[a].x)*(Mas1[b].x - Mas1[a].x)) / ((Mas1[b].y - Mas1[a].y)*(Mas1[b].y - Mas1[a].y) + (Mas1[b].x - Mas1[a].x)*(Mas1[b].x - Mas1[a].x));
		Y = ((Mas1[b].y - Mas1[a].y)*(X - Mas1[a].x)) / ((Mas1[b].x - Mas1[a].x) + Mas1[a].y);
	}
	if (((X - Mas1[a].x)*(X - Mas1[b].x) <= 0) && ((Y - Mas1[a].y)*(Y - Mas1[b].y) <= 0))//��������� �������������� ����� �������
		Dlina = sqrt((X - Mas2[c].x)*(X - Mas2[c].x) + (Y - Mas2[c].y)*(Y - Mas2[c].y));//������� ����������
	return Dlina;

}

int main(int argc, char * argv[])
{
	//if (argc > 1)
	//{
		Point *Mas1 = NULL, *Mas2 =NULL;  //���������� �����
	float *Mas, R1, R2, R3, Rast1, Rast2;
	int n1,n2, i,j,E, Q, k=0;
	FILE *Int = fopen("Int.txt", "r");   //��������� ���� ���� ��� �����
	FILE *Out = fopen("Out.txt", "w");   // ������ ��� ������
	if (Int == NULL)    //���� ������, �� ������
	{
		fprintf(Out, "0");
	}
	else
	{
		if (fscanf(Int, "%d", &n1) == 0)  //����������� ��� �������
			fprintf(Out, "0");
		else
		{
			Mas1 = (Point*)malloc(n1*sizeof(Point));  //����������
			for (i = 0; i < n1; i++)
			{
				fscanf(Int, "%f", &Mas1[i].x);
				fscanf(Int, "%f", &Mas1[i].y);
			}
		}
		if(fscanf(Int,"%d", &n2)==0)   //����������� ��� �������
			fprintf(Out, "0");
		else
		{
			Mas2 = (Point*)malloc(n2*sizeof(Point));    //����������
			for (j = 0; j < n2; j++)
			{
				fscanf(Int, "%f", &Mas2[j].x);
				fscanf(Int, "%f", &Mas2[j].y);
			}
		}
		//--------------------------------------------
		for (i = 0; i<n1; i++)//���� �������� �� �����������
		{
			E = i + 1;  //����� ������� ����� ���� ���� �������������
			if (i == n1 - 1)
				E = 0;
			for (j = 0; j<n2; j++)
			{
				Q = j + 1;
				if (j == n2 - 1)
					Q = 0;
				if (Peresechenie(Mas1[i], Mas1[E], Mas2[j], Mas2[Q]) == 1)    //�������� �� ���������������
				{
					fprintf(Out, "%d", 0);//���� ����������� ������������ � ����� 0
					k = 1;  break;
				}
			}
			if (k == 1) break;  
		}
		//--------------------------------------------
		if (k == 0)   //���� ����������� �� ���� �� ���������� ������
		{
			Mas = (float*)malloc((n1*n2)*sizeof(float));     //�������������� ������ 
			for (i = 0; i < n1; i++)              //���������� �������� �� ������
			{
				for (j = 0; j < n2; j++)
				{
					Mas[k] = Proverkatochki(Mas1[i], Mas2[j]);      //����� �������� �� ����� � �����
					if ((i == 0) && (j == 0))
					{
						R1 = Mas[k];
					}
					k++;
				}
			}
			//-----------------------------------------------
			R2 = R1;
			for (i = 0; i < n2; i++)           //���� �������� �� ��������� ������������� �� ����� (������� ��� ������ �������)
			{
				Rast1 = Rastoyanie(Mas1, Mas2, 0, n1 - 1, i);    
				if ((Rast1 < R2) && (Rast1 != -1))
					R2 = Rast1;
			}
			for (i = 0; i < n2; i++)
			{
				for (j = 1; j < n1; j++)
				{
					Rast1 = Rastoyanie(Mas1, Mas2, j, j - 1, i);
					if ((Rast1 < R2) && (Rast1 != -1))//������� ����������� ����������
						R2 = Rast1;
				}
			}
			//----------------------------------------
			R3 = R2;
			for (i = 0; i < n2; i++)  //����� ��� ������� ������� ������������ �������
			{
				Rast2 = Rastoyanie(Mas2, Mas1, 0, n2 - 1, i);
				if ((Rast2 < R3) && (Rast2 != -1))
					R3 = Rast2;
			}
			for (i = 0; i < n1; i++)
			{
				for (j = 1; j < n2; j++)
				{
					Rast2 = Rastoyanie(Mas2, Mas1, j, j - 1, i);
					if ((Rast2 < R2) && (Rast2 != -1))//������� ����������� ����������
						R3 = Rast2;
				}
			}
			fprintf(Out, "%f", R3);   // ��� � ���� ��� ������������� �����. ���������� ����� ����� ����������������
		}
	}
	free(Mas1);  //����������� ������
	free(Mas2);
	fclose(Int);   //�������� ������
	fclose(Out);
	//}
	return 0;
}