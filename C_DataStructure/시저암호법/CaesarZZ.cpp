#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#pragma warning(disable: 4996 4326 6031)

void main()
{
	char sMsg[80];
	int nKey = 3, nMore = true;
	while (nMore) {
		printf("? ");
		gets_s(sMsg);   // 한줄을 입력받을 때 사용하는 형태 gets_s
		switch (sMsg[0]) {
		case 0:
			nMore = false;
			break;
		case '@':
			printf("  Key ? ");
			gets_s(sMsg);
			nKey = atoi(sMsg);
			break;
		default:
			printf("  ");
			char Encrypt(char ch, int nKey);
			for (int i = 0; sMsg[i]; i++)
				putchar(Encrypt(sMsg[i], nKey));
			putchar('\n');
		}
		putchar('\n');
	}
	printf("Bye, ....\n\n");
}

char Encrypt(char chr, int nKey)
{
	if (isalpha(chr)) {
		//char cBgn = (chr & 0x60) + 1;
		char cBgn = (isupper(chr)) ? 'A' : 'a';
		chr = (chr - cBgn + nKey + 26) % 26 + cBgn;
	}
	return chr;
}
