#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int T;
	scanf("%d", &T);
	getchar();

	char ch[1001];

	for (int i = 0; i < T; i++)
	{
		fgets(ch, sizeof(ch), stdin);
		int len = strlen(ch);

		if (ch[len - 1] == '\n')
		{
			ch[len - 1] = '\0';
			len--;
		}

		int index = 0;

		for (int j = 0; j <= len; j++)
		{
			if (ch[j] == ' ' || ch[j] == '\0')
			{
				int end = j - 1;
				while (index < end)
				{
					char temp = ch[index];
					ch[index] = ch[end];
					ch[end] = temp;
					end--;
					index++;
				}
				index = j + 1;
			}
		}
		printf("%s\n", ch);
	}
}