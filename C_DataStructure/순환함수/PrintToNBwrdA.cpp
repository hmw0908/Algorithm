#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main()
{
	while (1) {
		printf("n ? ");
		int n;
		scanf("%d", &n);
		if (n < 0)
			break;
		int PrintToNBwrd(int n);
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintToNBwrd(n));
	}
}

int PrintToNBwrd(int n)		// n-1���� ��ȯ�� ������ 1
{
	/***
	[����] n-1, 1
	[�Ϲݱ�Ģ] p(n) ::= n�� ���, t=p(n-1), t+n�� ��ȯ
	[�������] n�� 1�� ����
	[�ߴ�����] n==0
	[�ܼ���] ����� ����, 0�� ��ȯ
	***/
	if (n == 0)
		return 0;
	printf("%d ", n);
	return PrintToNBwrd(n - 1) + n;
}