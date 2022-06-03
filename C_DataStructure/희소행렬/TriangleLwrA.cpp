#include <stdio.h>

#define	SIZE	10
#pragma warning (disable: 4326 4996)

int B[] = {	00,										// 0
			10,	11,									// 1, 2
			20,	21,	22,								// 3, 4, 5
			30,	31,	32,	33,							// 6, 7, 8, 9
			40,	41,	42,	43,	44,						// 10, 11, ...
			50,	51,	52,	53,	54,	55,
			60,	61,	62,	63,	64,	65,	66,
			70,	71,	72,	73,	74,	75,	76,	77,
			80,	81,	82,	83,	84,	85,	86,	87,	88,
			90,	91,	82,	93,	94,	95,	96,	97,	98,	99 };
	// 2���� �����ﰢ����� �̷��� 1���� B�� �����߽��ϴ�.
	// ���� �������� ���� ���� 0���� �����մϴ�.

void main()
{
	while (1) {
		int i, j, value;
		printf("index> ");
		scanf("%d", &i);
		if (i < 0)
			break;
		scanf("%d", &j);
		int Aij(int i, int j, int n, int &nValue);
		if (Aij(i, j, SIZE,  value) == false)
			printf("���� ����, ....\n");
		else
			printf("A[%d][%d] = %d\n", i, j, value);
		putchar('\n');
	}
	printf("Bye, ....\n\n");
}

int Aij(int i, int j, int n, int &nValue)
{	// ������ �����̸� nValue�� ���� �����ϰ� T/F�� return�Ѵ�.
	if (i < 0 || i >= n || j < 0 || j >= n)
		return false;
	nValue = (i >= j)				// ����� �����ﰢ�̸�
		? B[i * (i + 1) / 2 + j]	// �����Ǵ� 1���� �迭����
		: 0;						// �࿭�� �� �κ��� 0�̴�.
	return true;
}
