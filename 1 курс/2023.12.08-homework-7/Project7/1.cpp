#include<iostream>
#include<string>
#include<fstream>

bool palindromich(std::string str)
{
	int len_s = str.length();
	for (int i = 0; i < len_s; ++i)
	{
		if (str[i] != str[len_s - i - 1])
		{
			return 0;
		}
	}
	return 1;
}

int main(int argc, char** argv)
{
	std::ifstream fin("in.txt");
	std::string str = { 0 };
	while (!fin.eof())
	{
		fin >> str;
	}
	fin.close();

	int k = palindromich(str);

	std::ofstream fout("out.txt");

	if (k == 0)
	{
		fout << "No" << std::endl;
	}
	else
	{
		fout << "Yes" << std::endl;
	}
	fout.close();

	return 0;
}
