#include <stdio.h>

#define	SIZE	10
#pragma warning (disable: 4326 4996)

int B[] = {	00, 01,										// 0, 1,
			10, 11, 12,									// 2, 3, 4,
				21, 22,	23,								// 5, 6, 7,
					32,	33,	34,							// 8, ....
						43,	44,	45,
							54,	55,	56,
								65,	66,	67,
									76,	77,	78,
										87,	88,	89,
											98,	99	};

void main()
{
	while (1) {
		int i, j, value;
		printf("index> ");
		scanf("%d", &i);
		if (i < 0)
			break;
		scanf("%d", &j);
		int Aij(int i, int j, int nSize, int *pValue);
		if (Aij(i, j, SIZE, &value) == false)
			printf("���� ����, ....\n");
		else
			printf("A[%d][%d] = %d\n", i, j, value);
		putchar('\n');
	}
	printf("Bye, ....\n\n");
}

int Aij(int i, int j, int nSize, int *pValue)
{	// 2���� �迭 A�� 1���� �迭 B�� ������ �� A[i][j]�� �ش��ϴ� B[?]�� pValue�� �����ϰ� T/F�� ��ȯ�Ѵ�.
	if (i < 0 || i >= nSize || j < 0 || j >= nSize)
		return false;
	*pValue = (i - 1 <= j && j <= i + 1)	// ���
		? B[2 * i + j]						// ��� ���� ���ҷ� ����
		: 0;								// ��� �̿��� ����
	return true;
}
