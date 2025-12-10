#include "Row.h"

Row::Row(Row* row)
{
    this->set_parent(row);
    this->num_of_children = 0;
}

Row::Row(std::vector<int> sequence)
{
    this->set_parent(nullptr);
    this->set_sequence(sequence);
    this->num_of_children = 0;
}

void Row::add_children(Row* row)
{
    this->num_of_children++;
    this->children.push_back(row);
}

void Row::delete_node()
{
    if( this->num_of_children <= 1)
    {
        this->get_parent()->delete_node();
        delete this;
    }
    this->num_of_children--;
}

bool Row::is_done()
{
    return !this->operation.empty();
}

void Row::set_sequence(std::vector<int> sequence)
{
    this->sequence = sequence;
}
void Row::set_parent(Row* row)
{
    this->parent = row;
}

std::vector<int> Row::get_sequence()
{
    return this->sequence;
}
Row* Row::get_parent()
{
    return this->parent;
}
std::vector<Row*> Row::get_children()
{
    return this->children;
}
std::vector<bool> Row::get_operation()
{
    return std::vector<bool>();
}
int Row::get_num_children()
{
    return this->num_of_children;
}
