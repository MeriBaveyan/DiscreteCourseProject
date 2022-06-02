#include <vector>
#include "Discrete.h"

int main()
{
	unsigned int a, b, c;
	size_t size;

	Initialization(a, b, c, size);

	std::vector<std::vector<bool>> AdjMatrix(size, std::vector<bool>(size, 0));
	AdjMatrix.reserve(size);
	AdjacencyMatrix(a, b, c, AdjMatrix, size);

	PrintMatrix(AdjMatrix, size);
	PrintVector(AdjMatrix, size);
}