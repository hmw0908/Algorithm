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
	int nNecklace[N];											// 목걸이를 배열로 정의한다(0에서 n-1까지)
	for (int i = 0; i < n; i++)									// 목걸이 n개의 구슬을 1에서 n까지 초기화 한다
		nNecklace[i] = i + 1;
	while (n > 1) {
		int nHalf = n / 2;
		for (int nTo = 0, nFrom = n % 2 * 2; nTo < nHalf; nTo++, nFrom += 2)
			nNecklace[nTo] = nNecklace[nFrom];
		n = nHalf;
	}
	return nNecklace[0];
}

int SkipEraser2(int n)									// 순환 함수로 작성
{
	if (n == 1)											// 중단조건
		return 1;										// 단순해답
	return 2 * SkipEraser2(n / 2) + n % 2 * 2 - 1;		// 일반규칙
}
