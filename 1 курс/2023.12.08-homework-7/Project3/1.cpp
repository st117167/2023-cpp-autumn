#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int len(char* str)
{
	int k = 0;
	while (str[k] != 0)
	{
		++k;
	}

	return k;
}

char* strmult(char* str, int n)
{
	int length = 0;
	char* a = (char*)malloc(sizeof(char*) * ((len(str)) * n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < len(str); ++j)
		{
			a[j + length] = str[j];
		}
		length = length + len(str);
	}
	a[length] = '\0';

	return a;
}

int main(int argc, char** argv)
{
	int n = 0;
	scanf("%d", &n);

	FILE* f = fopen("in.txt", "r");
	char str[255] = { 0 };
	fscanf(f, "%s", &str);

	char* k = strmult(str, n);

	f = fopen("out.txt", "w");
	fprintf(f, "%s", k);
	fclose(f);

	free(k);

	return 0;
}
