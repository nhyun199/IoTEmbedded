#include <stdio.h>
#include <string.h>

int Substitute(const char* source, char* destination, 
	char* source_charset, char* dest_charset)
{
	
}

char* Combine(const char* source, char* destination, char* add_charset)
{
	int len1 = strlen(source);
	int len2 = strlen(add_charset);

	for (int i = 0; i < len1; i++)
	{
		destination[i] = source[i];
	}

	for (int i = 0; i < len2; i++)
	{
		destination[len1 + i] = add_charset[i];
	}

	destination[len1 + len2] = '\0';
	return destination;
}

char* Maginify(char* source) // 소문자를 대문자로
{
	for (int i = 0; i < strlen(source); i++)
	{
		if (source[i] >= 'a' && source[i] <= 'z')
			source[i] -= 32;
	}
	return source;
}

char* Minify(char* source) // 대문자를 소문자로
{
	for (int i = 0; i < strlen(source); i++)
	{
		if (source[i] >= 'A' && source[i] <= 'Z')
			source[i] += 32;
	}
	return source;
}

char* Reverse(const char* source, char* destination)
{
	int len = strlen(source);
	char temp[100];

	for (int i = 0; i < len; i++)
	{
		temp[i] = source[i];
		destination[len - (i+1)] = temp[i];
	}

	destination[len] = '\0';

	return destination;
}

int main()
{
	// Substitute - 문자열 대체하기	

	// Adjust, Adapt - 원본 문자열 변경		

	// Put to another use - P로 시작하는 문자열 관련 함수 만들기

	// Eliminate - 특정 문자열 제거하기
	
	char source[] = "Hello World";
	char add_charset[] = "Everyone";
	char destination[100];

	//printf("%s\n", Combine(source, destination, add_charset));
	printf("%s\n", Reverse(source, destination));
	
	
}