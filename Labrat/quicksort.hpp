#ifndef QUICKSORT_HPP_
#define QUICKSORT_HPP_

// Maciej Zwoliński
// 22 / 05 / 2018

// This is the exact same quicksort implementation as in my other repo /Zwo1in/Sorts
// It was modified to sort LabRats populations

#include "labRat.hpp"
#include <vector>
class QuickSort {
    QuickSort();
    public:
    static void sort( std::vector< LabRat >& rats, int first, int last, bool reversed = false );
    static int qs_split( std::vector< LabRat >& rats, int first, int last, bool reversed );
    static void qs_swap( std::vector< LabRat >& rats, int id1, int id2 );
};

#endif