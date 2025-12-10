#pragma once

#include <vector>

class Row;

class Sequence_parser{

protected:
    Row* Sequence;
    int length;
    int iteration;


public:
    Sequence_parser(std::vector<int> sequence);


    Row* get_root(){ return this->Sequence; }
    std::vector<int> get_sequence(){ return this->Sequence->get_sequence(); }
    int get_length() { return this->length; }
    int get_iteration() { return this->iteration; }
    
    int get_total();
    std::vector<std::vector<bool>> get_matricies(); // What datatype
    
private:
    void create_root();
    

};
