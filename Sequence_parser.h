#pragma once

#include <vector>

class Row;

class Sequence_parser{

protected:
    Row* Sequence;
    int length;
    int iteration;


public:
    Row* get_root(){ return this->Sequence; }
    int get_length() { return this->length; }
    int get_iteration() { return this->iteration; }
    
    int get_total();
    std::vector<std::vector<bool>> get_matricies(); // What datatype
    

};
