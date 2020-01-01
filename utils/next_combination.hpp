#pragma once
#include <algorithm>

/**
 * @note copied from the reference implementation of N2639
 * @see http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2639.pdf
 */
template <class BidirectionalIterator>
bool next_combination(BidirectionalIterator first1, BidirectionalIterator last1, BidirectionalIterator first2, BidirectionalIterator last2) {
    if (first1 == last1 or first2 == last2) {
        return false;
    }
    BidirectionalIterator m1 = last1;
    BidirectionalIterator m2 = last2;
    -- m2;
    while (-- m1 != first1 and not (*m1 < *m2)) {
    }
    bool result = (m1 == first1) and not (*first1 < *m2);
    if (! result ) {
        while (first2 != m2 and not (*m1 < *first2)) {
            ++ first2;
        }
        first1 = m1;
        std::iter_swap(first1, first2);
        ++ first1;
        ++ first2;
    }
    if (first1 != last1 and first2 != last2) {
        m1 = last1;
        m2 = first2;
        while (m1 != first1 and m2 != last2) {
            std::iter_swap(-- m1, m2);
            ++ m2;
        }
        std::reverse(first1, m1);
        std::reverse(first1, last1);
        std::reverse(m2, last2);
        std::reverse(first2, last2);
    }
    return not result;
}

template <class BidirectionalIterator>
bool next_combination(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last) {
    return next_combination(first, middle, middle, last);
}

template <class BidirectionalIterator>
inline bool prev_combination(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last) {
    return next_combination(middle, last, first, middle);
}
