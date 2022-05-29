#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)
#define N	1000


void main()
{
	while (1) {
		printf("? ");
		int n;
		scanf("%d", &n);
		if (n <= 0 || n > N)
			break;
		int SkipEraser1(int n);
		int SkipEraser2(int n);
		printf("Simulation: %d\n",   SkipEraser1(n));
		printf(" Recursion: %d\n\n", SkipEraser2(n));
	}
	printf("Bye, ...\n");
}

int SkipEraser1(int n)
{
	int nNecklace[N];											// ����̸� �迭�� �����Ѵ�(0���� n-1����)
	for (int i = 0; i < n; i++)									// ����� n���� ������ 1���� n���� �ʱ�ȭ �Ѵ�
		nNecklace[i] = i + 1;
	while (n > 1) {
		int nHalf = n / 2;
		for (int nTo = 0, nFrom = n % 2 * 2; nTo < nHalf; nTo++, nFrom += 2)
			nNecklace[nTo] = nNecklace[nFrom];
		n = nHalf;
	}
	return nNecklace[0];
}

int SkipEraser2(int n)									// ��ȯ �Լ��� �ۼ�
{
	if (n == 1)											// �ߴ�����
		return 1;										// �ܼ��ش�
	return 2 * SkipEraser2(n / 2) + n % 2 * 2 - 1;		// �Ϲݱ�Ģ
}
