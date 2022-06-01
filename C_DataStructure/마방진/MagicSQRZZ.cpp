#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

#define	N	30

void main()
{
	void makeMagicSquare(int nMagicSqr[N][N], int nN);
	void showMagicSquare(int nMagicSqr[N][N], int nN);
	void checkMagicSquare(int nMagicSqr[N][N], int nN);

	int nN;
	int nMagicSqr[N][N];
	while (1) {
		printf("? ");
		scanf("%d", &nN);
		if (nN % 2 == 0 || nN > N)
			break;
		makeMagicSquare(nMagicSqr, nN);
		showMagicSquare(nMagicSqr, nN);
		checkMagicSquare(nMagicSqr, nN);
		printf("\n");
	}
	printf("Bye, ....\n");
}

void makeMagicSquare(int nMagicSqr[N][N], int nN)
{
	for (int nRow = 0; nRow < nN; nRow++)
		for (int nCol = 0; nCol < nN; nCol++)
			nMagicSqr[nRow][nCol] = 0;
	int nRow, nCol, nCell = nN * nN;
	nMagicSqr[nRow = 0][nCol = nN / 2] = 1;
	for (int i = 2; i <= nCell; i++) {
		int nPrvRow = nRow, nPrvCol = nCol;
		nRow = (nRow - 1 + nN) % nN;
		nCol = (nCol + 1) % nN;
		if (nMagicSqr[nRow][nCol]) {
			nRow = (nPrvRow + 1) % nN;
			nCol = nPrvCol;
		}
		nMagicSqr[nRow][nCol] = i;
	}
}

void showMagicSquare(int nMagicSqr[N][N], int nN)
{
	printf("\n[마방진]\n");
	for (int nRow = 0; nRow < nN; nRow++) {
		for (int nCol = 0; nCol < nN; nCol++)
			printf("%2d ", nMagicSqr[nRow][nCol]);
		putchar('\n');
	}
}

void checkMagicSquare(int nMagicSqr[N][N], int nN)
{
	void checkMagicSquareRow(int nMagicSqr[N][N], int nN);
	void checkMagicSquareCol(int nMagicSqr[N][N], int nN);
	void checkMagicSquareDgl(int nMagicSqr[N][N], int nN, int nDir);

	checkMagicSquareRow(nMagicSqr, nN);
	checkMagicSquareCol(nMagicSqr, nN);
	printf("\n[대각선 검사]\n");
	checkMagicSquareDgl(nMagicSqr, nN, '\\');
	checkMagicSquareDgl(nMagicSqr, nN, '/');
}

void checkMagicSquareRow(int nMagicSqr[N][N], int nN)
{
	printf("\n[행 검사]\n");
	for (int nRow = 0; nRow < nN; nRow++) {
		printf("행%2d", nRow);
		int nSum = 0;
		for (int nCol = 0; nCol < nN; nCol++) {
			printf("%c ", nCol ? '+' : ':');
			printf("%2d ", nMagicSqr[nRow][nCol]);
			nSum += nMagicSqr[nRow][nCol];
		}
		printf("= %d\n", nSum);
	}
}

void checkMagicSquareCol(int nMagicSqr[N][N], int nN)
{
	printf("\n[열 검사]\n");
	for (int nCol = 0; nCol < nN; nCol++) {
		printf("열%2d", nCol);
		int nSum = 0;
		for (int nRow = 0; nRow < nN; nRow++) {
			printf("%c ", nRow ? '+' : ':');
			printf("%2d ", nMagicSqr[nRow][nCol]);
			nSum += nMagicSqr[nRow][nCol];
		}
		printf("= %d\n", nSum);
	}
}

void checkMagicSquareDgl(int nMagicSqr[N][N], int nN, int nDir)
{
	int nSum = 0, nDgnl = nDir == '/';
	int nCol = nDgnl * (nN - 1), nDelta = 1 - nDgnl * 2;
	printf("대 %c", nDir);
	for (int nRow = 0; nRow < nN; nRow++, nCol += nDelta) {
		printf("%c ", nRow ? '+' : ':');
		printf("%2d ", nMagicSqr[nRow][nCol]);
		nSum += nMagicSqr[nRow][nCol];
	}
	printf("= %d\n", nSum);
}

/*****
? 5

[마방진]
17  24   1   8  15
23   5   7  14  16
 4   6  13  20  22
10  12  19  21   3
11  18  25   2   9

[행 검사]
행 0: 17 + 24 +  1 +  8 + 15 = 65
행 1: 23 +  5 +  7 + 14 + 16 = 65
행 2:  4 +  6 + 13 + 20 + 22 = 65
행 3: 10 + 12 + 19 + 21 +  3 = 65
행 4: 11 + 18 + 25 +  2 +  9 = 65

[열 검사]
열 0: 17 + 23 +  4 + 10 + 11 = 65
열 1: 24 +  5 +  6 + 12 + 18 = 65
열 2:  1 +  7 + 13 + 19 + 25 = 65
열 3:  8 + 14 + 20 + 21 +  2 = 65
열 4: 15 + 16 + 22 +  3 +  9 = 65

[대각선 검사]
대 \: 17 +  5 + 13 + 21 +  9 = 65
대 /: 15 + 14 + 13 + 12 + 11 = 65

? 0
Bye, ....
*****/