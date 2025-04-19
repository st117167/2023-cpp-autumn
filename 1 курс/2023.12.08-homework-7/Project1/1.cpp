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

char* strcat(char* str1, char* str2)
{
	int len1 = len(str1);
	int len2 = len(str2);
	for (int i = 0; i < len2 + 1; i++)
	{
		str1[len1] = str2[i];
		len1++;
	}

	return str1;
}

int main(int argc, char** argv)
{
	FILE* f = fopen("in.txt", "r");
	char str1[255] = { 0 };
	fscanf(f, "%s", &str1);
	char str2[255] = { 0 };
	fscanf(f, "%s", &str2);
	fclose(f);

	char* k = strcat(str1, str2);

	f = fopen("out.txt", "w");
	fprintf(f, "%s", k);
	fclose(f);

	return 0;
}
