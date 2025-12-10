#include "Sequence_parser.h"
#include "Row.h"
#include <vector>
#include <algorithm>

Sequence_parser::Sequence_parser(std::vector<int> sequence)
{
    this->create_root(sequence);
    this->length = sequence.size();
}

std::vector<int> Sequence_parser::get_sequence()
{
    return this->Sequence->get_sequence();
}

int Sequence_parser::get_total()
{
    return 0;
}

void Sequence_parser::create_root(std::vector<int> sequence)
{
    this->Sequence = new Row(sequence);
}





// ---------------------------------------------------------------------------
// generate_edge_combinations
//
// Generates all possible ways to place `number` objects into `bins` bins,
// where:
//
//    • Only one object may occupy a bin (boolean occupancy)
//    • All objects must be placed
//    • Output is a vector<bool> of length `bins`
//
// A `true` means the bin contains one object.
// A `false` means the bin is empty.
//
// This is equivalent to generating all bitmasks with exactly `number` bits set.
// ---------------------------------------------------------------------------
std::vector<std::vector<bool>> generate_edge_combinations(int number, int bins) {
    std::vector<std::vector<bool>> results;

    // Invalid if we have more objects than bins or negative inputs
    if (number < 0 || bins <= 0)
        return results;

    // Build initial bitmask: number of 1s followed by 0s
    // Example: number=2, bins=4 → [1,1,0,0]
    std::vector<int> mask(bins, 0);
    for (int i = 0; i < number; i++)
        mask[i] = 1;

    // Sort so that next_permutation generates all unique combinations
    std::sort(mask.begin(), mask.end(), std::greater<int>());

    // Generate all unique permutations with exactly `number` ones
    do {
        std::vector<bool> occupancy(bins);
        for (int i = 0; i < bins; i++)
            occupancy[i] = (mask[i] == 1);

        results.push_back(occupancy);

    } while (std::prev_permutation(mask.begin(), mask.end()));

    return results;
}
