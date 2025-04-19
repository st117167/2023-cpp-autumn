#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int strstr(char* str, char* podstr)
{
	if (str == podstr || *podstr == '\0')
	{
		return 0;
	}

	int i = 0;
	int j = 0;
	while (podstr[i] != '\0')
	{
		if (str[j] == '\0')
		{
			j = -1;
			break;
		}

		else if (str[j + i] == podstr[i])
		{
			i++;
		}
		else
		{
			j++;
			i = 0;
		}
	}

	return j;
}

int main(int argc, char** argv)
{
	FILE* f = fopen("in.txt", "r");
	char str[255] = { 0 };
	fscanf(f, "%s", &str);
	char podstr[255] = { 0 };
	fscanf(f, "%s", &podstr);
	fclose(f);

	int k = strstr(str, podstr);

	f = fopen("out.txt", "w");
	fprintf(f, "%d", k);
	fclose(f);

	return 0;
}
