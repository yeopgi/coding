#include<stdio.h>
#include<string.h>
int main(void)
{
	int test_case = 0;				//testcase 갯수
	int recur = 0;					//반복횟수
	//int st_leng = 0;				//문자열의 갯수
	char string1[20] = {0};		//문자열 s의 길이
	

	scanf("%d", &test_case);
	
	int st_leng = strlen(string1);
	for (int a = 0; a < test_case; a++)
	{
		scanf("%d %s", &recur, &string1);
		for (int i = 0; string1[i]!=NULL; i++)	//입력받은 문자열을 제어
		{
			for (int j = 0; j < recur; j++) printf("%c", string1[i]);
		}
		printf("\n");
	}
	return 0;
}