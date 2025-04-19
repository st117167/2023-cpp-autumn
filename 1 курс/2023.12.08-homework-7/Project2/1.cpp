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

int strcmp(char* str1, char* str2)
{
	int length = len(str1) > len(str2) ? len(str1) : len(str2);
	int count = 0;

	for (int i = 0; i < length; i++)
	{
		if (str1[i] != str2[i])
		{
			if (str1[i] > str2[i])
			{
				return 1;
				break;
			}
			else
			{
				return -1;
				break;
			}
		}
		else
		{
			return 0;
		}
	}

	if (len(str1) == len(str2) && count == len(str1))
	{
		return 0;
	}
}

int main(int argc, char** argv)
{
	FILE* f = fopen("in.txt", "r");
	char str1[255] = { 0 };
	fscanf(f, "%s", &str1);
	char str2[255] = { 0 };
	fscanf(f, "%s", &str2);
	fclose(f);

	int k = strcmp(str1, str2);

	f = fopen("out.txt", "w");
	fprintf(f, "%d", k);
	fclose(f);

	return 0;
}
