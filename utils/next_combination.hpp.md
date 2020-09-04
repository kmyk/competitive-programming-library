---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"utils/next_combination.hpp\"\n#include <algorithm>\n\n/**\n\
    \ * @note copied from the reference implementation of N2639\n * @see http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2639.pdf\n\
    \ */\ntemplate <class BidirectionalIterator>\nbool next_combination(BidirectionalIterator\
    \ first1, BidirectionalIterator last1, BidirectionalIterator first2, BidirectionalIterator\
    \ last2) {\n    if (first1 == last1 or first2 == last2) {\n        return false;\n\
    \    }\n    BidirectionalIterator m1 = last1;\n    BidirectionalIterator m2 =\
    \ last2;\n    -- m2;\n    while (-- m1 != first1 and not (*m1 < *m2)) {\n    }\n\
    \    bool result = (m1 == first1) and not (*first1 < *m2);\n    if (! result )\
    \ {\n        while (first2 != m2 and not (*m1 < *first2)) {\n            ++ first2;\n\
    \        }\n        first1 = m1;\n        std::iter_swap(first1, first2);\n  \
    \      ++ first1;\n        ++ first2;\n    }\n    if (first1 != last1 and first2\
    \ != last2) {\n        m1 = last1;\n        m2 = first2;\n        while (m1 !=\
    \ first1 and m2 != last2) {\n            std::iter_swap(-- m1, m2);\n        \
    \    ++ m2;\n        }\n        std::reverse(first1, m1);\n        std::reverse(first1,\
    \ last1);\n        std::reverse(m2, last2);\n        std::reverse(first2, last2);\n\
    \    }\n    return not result;\n}\n\ntemplate <class BidirectionalIterator>\n\
    bool next_combination(BidirectionalIterator first, BidirectionalIterator middle,\
    \ BidirectionalIterator last) {\n    return next_combination(first, middle, middle,\
    \ last);\n}\n\ntemplate <class BidirectionalIterator>\ninline bool prev_combination(BidirectionalIterator\
    \ first, BidirectionalIterator middle, BidirectionalIterator last) {\n    return\
    \ next_combination(middle, last, first, middle);\n}\n"
  code: "#pragma once\n#include <algorithm>\n\n/**\n * @note copied from the reference\
    \ implementation of N2639\n * @see http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2639.pdf\n\
    \ */\ntemplate <class BidirectionalIterator>\nbool next_combination(BidirectionalIterator\
    \ first1, BidirectionalIterator last1, BidirectionalIterator first2, BidirectionalIterator\
    \ last2) {\n    if (first1 == last1 or first2 == last2) {\n        return false;\n\
    \    }\n    BidirectionalIterator m1 = last1;\n    BidirectionalIterator m2 =\
    \ last2;\n    -- m2;\n    while (-- m1 != first1 and not (*m1 < *m2)) {\n    }\n\
    \    bool result = (m1 == first1) and not (*first1 < *m2);\n    if (! result )\
    \ {\n        while (first2 != m2 and not (*m1 < *first2)) {\n            ++ first2;\n\
    \        }\n        first1 = m1;\n        std::iter_swap(first1, first2);\n  \
    \      ++ first1;\n        ++ first2;\n    }\n    if (first1 != last1 and first2\
    \ != last2) {\n        m1 = last1;\n        m2 = first2;\n        while (m1 !=\
    \ first1 and m2 != last2) {\n            std::iter_swap(-- m1, m2);\n        \
    \    ++ m2;\n        }\n        std::reverse(first1, m1);\n        std::reverse(first1,\
    \ last1);\n        std::reverse(m2, last2);\n        std::reverse(first2, last2);\n\
    \    }\n    return not result;\n}\n\ntemplate <class BidirectionalIterator>\n\
    bool next_combination(BidirectionalIterator first, BidirectionalIterator middle,\
    \ BidirectionalIterator last) {\n    return next_combination(first, middle, middle,\
    \ last);\n}\n\ntemplate <class BidirectionalIterator>\ninline bool prev_combination(BidirectionalIterator\
    \ first, BidirectionalIterator middle, BidirectionalIterator last) {\n    return\
    \ next_combination(middle, last, first, middle);\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: utils/next_combination.hpp
  requiredBy: []
  timestamp: '2020-01-01 19:13:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: utils/next_combination.hpp
layout: document
redirect_from:
- /library/utils/next_combination.hpp
- /library/utils/next_combination.hpp.html
title: utils/next_combination.hpp
---
