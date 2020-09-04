---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: a double-ended priority queue
  bundledCode: "#line 1 \"old/double-ended-priority-queue.inc.cpp\"\n/**\n * @brief\
    \ a double-ended priority queue\n * @note the feature is the same to std::multiset,\
    \ but this is 7x faster for 10^7 operations\n * @note interval heap is more faster\n\
    \ * @sa https://topcoder.g.hatena.ne.jp/spaghetti_source/20121006#c1349522933\n\
    \ */\ntemplate <class T>\nclass four_priority_queues {\n    priority_queue<T>\
    \ max_heap, max_deleted;\n    priority_queue<T, vector<T>, greater<T> > min_heap,\
    \ min_deleted;\nprivate:\n    template <class Queue>\n    void flush(Queue & heap,\
    \ Queue & deleted) {\n        while (not deleted.empty()) {\n            assert\
    \ (not heap.empty());\n            if (deleted.top() != heap.top()) break;\n \
    \           deleted.pop();\n            heap.pop();\n        }\n    }\npublic:\n\
    \    void push(T a) {\n        max_heap.push(a);\n        min_heap.push(a);\n\
    \    }\n    T get_min() {\n        flush(min_heap, min_deleted);\n        return\
    \ min_heap.top();\n    }\n    T get_max() {\n        flush(max_heap, max_deleted);\n\
    \        return max_heap.top();\n    }\n    void pop_min() {\n        max_deleted.push(get_min());\n\
    \        min_heap.pop();\n    }\n    void pop_max() {\n        min_deleted.push(get_max());\n\
    \        max_heap.pop();\n    }\n    bool empty() {\n        flush(min_heap, min_deleted);\
    \  // NOTE: you can replace this with max_*\n        return min_heap.empty();\n\
    \    }\n};\n\nunittest {\n    default_random_engine gen;\n    REP (iteration,\
    \ 10) {\n        four_priority_queues<int> depq;\n        multiset<int> mlt;\n\
    \        REP (iteration, 100000) {\n            if (mlt.empty() or bernoulli_distribution(0.8)(gen))\
    \ {\n                int a = uniform_int_distribution<int>()(gen);\n         \
    \       mlt.insert(a);\n                depq.push(a);\n            } else {\n\
    \                if (bernoulli_distribution(0.5)(gen)) {\n                   \
    \ int a = *mlt.begin();\n                    int b = depq.get_min();\n       \
    \             assert (a == b);\n                    mlt.erase(mlt.begin());\n\
    \                    depq.pop_min();\n                } else {\n             \
    \       int a = *prev(mlt.end());\n                    int b = depq.get_max();\n\
    \                    assert (a == b);\n                    mlt.erase(prev(mlt.end()));\n\
    \                    depq.pop_max();\n                }\n            }\n     \
    \   }\n    }\n}\n"
  code: "/**\n * @brief a double-ended priority queue\n * @note the feature is the\
    \ same to std::multiset, but this is 7x faster for 10^7 operations\n * @note interval\
    \ heap is more faster\n * @sa https://topcoder.g.hatena.ne.jp/spaghetti_source/20121006#c1349522933\n\
    \ */\ntemplate <class T>\nclass four_priority_queues {\n    priority_queue<T>\
    \ max_heap, max_deleted;\n    priority_queue<T, vector<T>, greater<T> > min_heap,\
    \ min_deleted;\nprivate:\n    template <class Queue>\n    void flush(Queue & heap,\
    \ Queue & deleted) {\n        while (not deleted.empty()) {\n            assert\
    \ (not heap.empty());\n            if (deleted.top() != heap.top()) break;\n \
    \           deleted.pop();\n            heap.pop();\n        }\n    }\npublic:\n\
    \    void push(T a) {\n        max_heap.push(a);\n        min_heap.push(a);\n\
    \    }\n    T get_min() {\n        flush(min_heap, min_deleted);\n        return\
    \ min_heap.top();\n    }\n    T get_max() {\n        flush(max_heap, max_deleted);\n\
    \        return max_heap.top();\n    }\n    void pop_min() {\n        max_deleted.push(get_min());\n\
    \        min_heap.pop();\n    }\n    void pop_max() {\n        min_deleted.push(get_max());\n\
    \        max_heap.pop();\n    }\n    bool empty() {\n        flush(min_heap, min_deleted);\
    \  // NOTE: you can replace this with max_*\n        return min_heap.empty();\n\
    \    }\n};\n\nunittest {\n    default_random_engine gen;\n    REP (iteration,\
    \ 10) {\n        four_priority_queues<int> depq;\n        multiset<int> mlt;\n\
    \        REP (iteration, 100000) {\n            if (mlt.empty() or bernoulli_distribution(0.8)(gen))\
    \ {\n                int a = uniform_int_distribution<int>()(gen);\n         \
    \       mlt.insert(a);\n                depq.push(a);\n            } else {\n\
    \                if (bernoulli_distribution(0.5)(gen)) {\n                   \
    \ int a = *mlt.begin();\n                    int b = depq.get_min();\n       \
    \             assert (a == b);\n                    mlt.erase(mlt.begin());\n\
    \                    depq.pop_min();\n                } else {\n             \
    \       int a = *prev(mlt.end());\n                    int b = depq.get_max();\n\
    \                    assert (a == b);\n                    mlt.erase(prev(mlt.end()));\n\
    \                    depq.pop_max();\n                }\n            }\n     \
    \   }\n    }\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: old/double-ended-priority-queue.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: old/double-ended-priority-queue.inc.cpp
layout: document
redirect_from:
- /library/old/double-ended-priority-queue.inc.cpp
- /library/old/double-ended-priority-queue.inc.cpp.html
title: a double-ended priority queue
---
