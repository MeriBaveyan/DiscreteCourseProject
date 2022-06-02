#ifndef DISCRETE_H
#define DISCRETE_H

void Initialization(unsigned int&, unsigned int&, unsigned int&, size_t&);
void AdjacencyMatrix(const unsigned int&, const unsigned int&, const unsigned int&, std::vector<std::vector<bool>>&, const size_t&);
void PrintMatrix(const std::vector<std::vector<bool>>&, const size_t&);
void PrintVector(const std::vector<std::vector<bool>>&, const size_t&);

#endif // DISCRETE_H
