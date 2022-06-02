#include <iostream>
#include <vector>
#include "Discrete.h"

void Initialization(unsigned int& a, unsigned int& b, unsigned int& c, size_t& size)
{
	std::cout << "Insert a, b, c : 0 < a <= b <= c" << std::endl << std::endl;
	do {
		std::cout << "Insert a : a >= 1  a = ";
		std::cin >> a;
	} while (a < 1);
	do {
		std::cout << "Insert b : b >= a  b = ";
		std::cin >> b;
	} while (b < a);
	do {
		std::cout << "Insert c : c >= b  c = ";
		std::cin >> c;
	} while (c < b);

	if (b == c)	{
		size = 2 * c + 1;
	}
	else {
		size = 2 * c + 2;
	}

	return;
}

void FullFillByOnes(const unsigned int& iStart, const unsigned int& iEnd, 
	const unsigned int& jStart, const unsigned int& jEnd, std::vector<std::vector<bool>>& AdjMatrix)
{
	for (int i = iStart; i <= iEnd; ++i) {
		for (int j = jStart; j <= jEnd; ++j) {
			AdjMatrix[i][j] = AdjMatrix[j][i] = 1;
		}
	}
}

void HalfFillByOnes(const unsigned int& iStart, const unsigned int& iEnd,
	const unsigned int& jStart, const unsigned int& jEnd, std::vector<std::vector<bool>>& AdjMatrix)
{
	for (int i = iStart; i <= iEnd; ++i) {
		for (int j = i + 1; j <= jEnd; ++j) {
			AdjMatrix[i][j] = AdjMatrix[j][i] = 1;
		}
	}
}

void FillAB(const unsigned int& a, const unsigned int& bEnd, std::vector<std::vector<bool>>& AdjMatrix)
{

	for (int i = 0; i < a - 1; ++i) {
		AdjMatrix[i][i + a] = AdjMatrix[i + a][i] = 1;
	}

	for (int i = 2 * a - 1; i <= bEnd; ++i) {
		AdjMatrix[a - 1][i] = AdjMatrix[i][a - 1] = 1;
	}
}

void AdjacencyMatrix(const unsigned int& a, const unsigned int& b, const unsigned int& c, std::vector<std::vector<bool>>& AdjMatrix, const size_t& size)
{
	int aStart = 0;
	int aEnd = a - 1;
	int bEnd = a + b - 1;
	int cEnd = b + c;
	int dEnd = 2 * c + 1;

	HalfFillByOnes(aStart,   aEnd, aStart,   aEnd, AdjMatrix); // a-a
	HalfFillByOnes(aEnd + 1, bEnd, aEnd + 1, bEnd, AdjMatrix); // b-b
	HalfFillByOnes(bEnd + 1, cEnd, bEnd + 1, cEnd, AdjMatrix); // c-c
	FullFillByOnes(aStart,   aEnd, bEnd + 1, cEnd, AdjMatrix); // a-c

	if (size % 2 == 0) {
		HalfFillByOnes(cEnd + 1, dEnd, cEnd + 1, dEnd, AdjMatrix); // d-d
		FullFillByOnes(aEnd + 1, bEnd, cEnd + 1, dEnd, AdjMatrix); // b-d
	}
	

	FillAB(a, bEnd, AdjMatrix);
	/*for (size_t i = 0; i <= c; ++i)
	{
		for (size_t j = i + 1; j <= c; ++j)
		{
			AdjMatrix[i][j] = AdjMatrix[j][i] = 1;
		}
	}

	for (size_t j = c + 1; j <= c + 1 + b - a; ++j)
	{
		AdjMatrix[a][j] = 1;
	}

	for (size_t i = a + 1; i <= c; ++i)
	{
		for (size_t j = c + b - a + 2; j <= c + b; ++j)
		{
			AdjMatrix[i][j] = 1;
		}
	}

	for (size_t i = c + 1; i < size; ++i)
	{
		for (size_t j = i + 1; j < size; ++j)
		{
			AdjMatrix[i][j] = AdjMatrix[j][i] = 1;
		}
	}*/


}

void PrintMatrix(const std::vector<std::vector<bool>>& AdjMatrix, const size_t& size)
{
	std::cout << std::endl << std::endl;

	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size; ++j) {
			std::cout << AdjMatrix[i][j] << "   ";
		}
		std::cout << std::endl << std::endl;
	}
}

void PrintVector(const std::vector<std::vector<bool>>& AdjMatrix, const size_t& size)
{
	std::cout << std::endl << std::endl;

	std::cout << "V(G) = {";
	for (size_t i = 1; i < size; ++i) {
		std::cout << i << ", ";
	}
	std::cout << size << " }" << std::endl << std::endl;

	std::cout << "E(G) = { ";
	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size; ++j) {
			if (AdjMatrix[i][j]) {
				std::cout << "(" << i + 1 << ", " << j + 1 << ") ";
			}
		}
		//std::cout << std::endl << std::endl;
	}
	std::cout << "}" << std::endl << std::endl << std::endl << std::endl;
}