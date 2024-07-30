#include <stdio.h>
#include <string.h>

int Substitute(const char* source, char* destination,
	char* source_charset, char* dest_charset)
{
	destination[100];
	


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

int main()
{
	// SCAMPER 함수 구현해보기, pointer를 사용해보기
	// substitute combine adjust/adapt ... 

	// Substitute - 문자열 대체하기

	// Combine - 문자열 합치기

	// Adjust, Adapt - 원본 문자열 변경		

	// Put to another use - P로 시작하는 문자열 관련 함수 만들기

	// Eliminate - 특정 문자열 제거하기

	// Reverse, Rearrange - 문자열 순서 뒤집기
}