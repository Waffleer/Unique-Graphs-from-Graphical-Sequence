#include <iostream>
#include "Sequence_parser.h"
#include "Row.h"
#include <vector>

int main(int, char**){
    std::vector<int> init = {3, 3, 2, 2, 2};
    Row root(init);
    Row l1(&root);
    
    std::cout << "Hello, from unique_graphs_from_sequence!\n";
}
