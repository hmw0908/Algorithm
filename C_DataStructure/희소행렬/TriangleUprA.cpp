#include <stdio.h>

#define	SIZE	10
#pragma warning (disable: 4326 4996)

int B[] = {	 0,	 1,  2,  3,  4,  5,  6,  7,  8,  9,	// 0,  1,  ...
			    11,	12, 13, 14, 15, 16, 17, 18,	19,	// 10, 11, ...
					22,	23, 24, 25, 26, 27,	28, 29,	// 19, 20, ...
						33,	34, 35, 36,	37, 38, 39,	// 27, 28, ...
							44,	45, 46, 47, 48,	49,	// 34, 35, ...
								55, 56, 57, 58, 59,
									66, 67, 68, 69,
										77, 78, 79,
											88, 89,
												99 };
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
		if (Aij(i, j, SIZE, value) == false)
			printf("���� ����, ....\n");
		else
			printf("A[%d][%d] = %d\n", i, j, value);
	}
	printf("Bye, ....\n\n");
}

int Aij(int i, int j, int n, int &nValue)
{
	/* ������ �����̸� nValue�� ���� �����ϰ� T/F�� return�Ѵ�. */
	if (i < 0 || j < 0 || i >= n || j >= n)
		return false;
	nValue = (i <= j)				// ����� �����ﰢ�̸�
		? B[n * i - i * (i + 1) / 2 + j]	// �����Ǵ� 1���� �迭����
		: 0;						// �࿭�� �Ʒ� �κ��� 0�̴�.
	return true;
}
