#include <stdio.h>
#include <locale.h>
void main()
{ 
	setlocale(LC_ALL, "Russian");
	long int a, n, ch, ch_mb, b, k; //b - ����, k - ������, n - ����� ����, ch - ���� �����, ch_mp - �������������� �����
	do 
	{   printf("������� ����� ����������� ����� (����� ������������� �����)");
		scanf("%d", n);

	} while (n <= 0);

	//��������� ������� ����� � ���������������� ������� �����������
	//�������� �� ���������� ���� � ����� 
	do 
	{
		printf("������� �������������� �����");
		scanf("%d", ch_mb);
		//������� "����� � �����"
		printf("���������� %d ", b, " ����� ", " � %d ", k, " �����");
	} while (ch == ch_mb);




}
