#include "quicksort.hpp"

void QuickSort::sort( std::vector< LabRat >& rats, int first, int last, bool reversed ) {
    if ( first < last ) {
        int n = qs_split( rats, first, last, reversed );
        sort( rats, first, n-1, reversed );
        sort( rats, n+1, last, reversed );
    }
}

int QuickSort::qs_split( std::vector< LabRat >& rats, int first, int last, bool reversed ) {
    int refIndex = first + rand()%(last - first);
    double refValue = rats[refIndex].genes() -> propability;
    qs_swap( rats, refIndex, last );

    int position = first;
    for ( int i = first; i <= last-1; i++ )
        if( reversed ? (rats[i].genes()->propability > refValue) : (rats[i].genes()->propability < refValue) ) {
            qs_swap( rats, i, position );
            position++;
        }
    qs_swap( rats, position, last );
    return position;
}

void QuickSort::qs_swap( std::vector< LabRat >& rats, int id1, int id2 ) {
    LabRat tmp = rats[id1];
    rats[id1] = rats[id2];
    rats[id2] = tmp;
}