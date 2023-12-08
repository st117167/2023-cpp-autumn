#include <iostream>

typedef unsigned int uint;

int main(int argc, char* argv[])
{
	const int BITS = sizeof(uint) * 8;
	uint n = 0;
	std::cin >> n;

	{
		int s = 0;
		for (int i = 0; i < BITS; i = i + 1)
		{
			s = s + ((n >> i) & 1);
		}
		std::cout << s << std::endl;
	}

	{
		if (n == 0)
		{
			n = ~n;
		}
		else
		{
			int start = BITS - 1;
			int end = 0;

			while ((n >> start & 1) == 0)
			{
				start -= 1;
			}

			while ((n >> end & 1) == 0)
			{
				end += 1;
			}

			start--;
			end++;
			uint mask = 0;
			mask = ~mask;
			mask = (mask >> (start - end + 1));
			mask = ~mask;
			mask = (mask >> (BITS - start - 1));
			n = n ^ mask;
			for (int i = BITS - 1; i >= 0; i = i - 1)
			{
				std::cout << (n >> i & 1) << (i % 4 == 0 ? " " : "");
			}
			std::cout << std::endl;
		}
	}

	{
		uint a = 0;
		uint b = 0;
		uint c = 0;
		std::cin >> a;
		std::cin >> b;
		bool up = 0;
		for (int i = 0; i < BITS; ++i)
		{
			bool bitA = ((a >> i) & 1);
			bool bitB = ((b >> i) & 1);
			bool current = bitA ^ bitB ^ up;
			up = (bitA & bitB) | (bitA & up) | (bitB & up);
			c = c | ((int)current << i);
		}
		std::cout << a << " + " << b << " = " << c << std::endl;
	}
	return 0;
}
