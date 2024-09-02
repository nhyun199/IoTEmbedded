#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char S[100001];
	fgets(S, sizeof(S), stdin);
	
	int len = strlen(S);
	
	if (S[len - 1] == '\n')
	{
		S[len - 1] == '\0';
		len--;
	}

	int index = 0;
	
	for (int i = 0; i < len; i++)
	{
		if (S[i] == '>')
		{
			index = i + 1;
		}

		if (i != 0 && (S[i] == '<' || S[i] == ' ' || S[i] == '\0'))
		{
			int end = i;
			while (index < end)
			{
				char temp = S[index];
				S[index] = S[end];
				S[end] = temp;
				end--;
				index++;
			}
		}
	}
	printf("%s", S);
}