#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int len(char* str)
{
	int i = 0;
	while (str[i] != 0)
	{
		++i;
	}

	return i;
}

char* substr(char* str, int length, int index)
{
	if (length <= 0 || index >= len(str) || index < 0)
	{
		return 0;
	}

	char* sub = (char*)malloc(sizeof(char*) * (length + 1));

	for (int i = 0; i <= length; i++)
	{
		sub[i] = str[index + i];
	}
	sub[length] = '\0';

	return sub;
}

int main(int argc, char** argv)
{
	int i = 0;
	scanf("%d", &i);

	int length = 0;
	scanf("%d", &length);

	FILE* f = fopen("in.txt", "r");
	char str[255] = { 0 };
	fscanf(f, "%s", &str);
	fclose(f);

	char* k = substr(str, length, i);

	f = fopen("out.txt", "w");
	fprintf(f, "%s", k);
	fclose(f);

	free(k);

	return 0;
}
