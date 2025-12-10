#pragma once

#include <vector>


class Row{

protected:
    Row* parent; // If nullptr, it is a root
    std::vector<Row*> children;
    int num_of_children;
    std::vector<int> sequence;

public:
    Row(Row* parent); // Takes in parent Node
    Row(std::vector<int> sequence);

    std::vector<int> get_sequence();
    Row* get_parent();
    std::vector<Row*> get_children();
    std::vector<bool> get_operation();
    int get_num_children();
    
    void add_children(Row*);

    void delete_node();
private:
    // Helper functions for class
    void set_parent(Row* row);
    void set_sequence(std::vector<int> sequence);
};
