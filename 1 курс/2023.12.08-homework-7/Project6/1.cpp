#include<iostream>
#include<string>
#include<fstream>

int WordCount(std::string filename)
{
	std::ifstream fin(filename);

	int n = 0;
	std::string word = "";
	while (!fin.eof())
	{
		fin >> word;
		n++;
	}
	fin.close();

	return n;
}

void WordsArr(std::string filename, std::string* WordsArr)
{
	std::ifstream fin(filename);

	int i = 0;
	while (!fin.eof())
	{
		fin >> WordsArr[i];
		i++;
	}
	fin.close();
}

bool isSyntax(char c)
{
	return (c == '.' || c == ',' ||
			c == ';' || c == ':' ||
			c == '!' || c == '?');
}

void Syntax(std::string* WordsArr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < WordsArr[i].length(); ++j)
		{
			if (isSyntax(WordsArr[i][j]))
			{
				WordsArr[i].erase(j, 1);
			}
		}
	}
}
std::string maxnumber(std::string* WordsArr, int n)
{
	std::string first = WordsArr[0];
	int word_count = 0;

	for (int i = 0; i < n; ++i)
	{
		int next_word_count = 0;
		for (int j = i; j < n; ++j)
		{
			if (WordsArr[i] == WordsArr[j])
			{
				++next_word_count;
			}
		}
		if (next_word_count > word_count)
		{
			word_count = next_word_count;
			first = WordsArr[i];
		}
	}
	return first;
}

int main(int argc, char** argv)
{
	int n = WordCount("in.txt");
	std::string* array = new std::string[n];

	WordsArr("in.txt", array);
	Syntax(array, n);

	std::ofstream fout("out.txt");
	fout << maxnumber(array, n);

	return EXIT_SUCCESS;
}