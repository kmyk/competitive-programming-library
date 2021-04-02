---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template.cpp\"\n#include <bits/stdc++.h>\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i\
    \ = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) -\
    \ 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i)\
    \ >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#define dump(x)\
    \ cerr << #x \" = \" << x << endl\nusing namespace std;\ntemplate <class T> using\
    \ reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;\ntemplate\
    \ <class T, class U> inline void chmax(T & a, U const & b) { a = max<T>(a, b);\
    \ }\ntemplate <class T, class U> inline void chmin(T & a, U const & b) { a = min<T>(a,\
    \ b); }\ntemplate <typename X, typename T> auto make_table(X x, T a) { return\
    \ vector<T>(x, a); }\ntemplate <typename X, typename Y, typename Z, typename...\
    \ Zs> auto make_table(X x, Y y, Z z, Zs... zs) { auto cont = make_table(y, z,\
    \ zs...); return vector<decltype(cont)>(x, cont); }\ntemplate <typename T> ostream\
    \ & operator << (ostream & out, vector<T> const & xs) { REP (i, (int)xs.size()\
    \ - 1) out << xs[i] << ' '; if (not xs.empty()) out << xs.back(); return out;\
    \ }\ntemplate<typename Functor> struct fix_type { Functor functor; template<typename...\
    \ Args> decltype(auto) operator() (Args && ... args) const & { return functor(functor,\
    \ std::forward<Args>(args)...); } };\ntemplate<typename Functor> fix_type<typename\
    \ std::decay<Functor>::type> fix(Functor && functor) { return { std::forward<Functor>(functor)\
    \ }; }\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    constexpr char endl = '\\n';\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n#define REP(i, n) for (int i = 0; (i) < (int)(n);\
    \ ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define\
    \ REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m,\
    \ n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#define dump(x) cerr << #x \" = \" << x << endl\nusing namespace\
    \ std;\ntemplate <class T> using reversed_priority_queue = priority_queue<T, vector<T>,\
    \ greater<T> >;\ntemplate <class T, class U> inline void chmax(T & a, U const\
    \ & b) { a = max<T>(a, b); }\ntemplate <class T, class U> inline void chmin(T\
    \ & a, U const & b) { a = min<T>(a, b); }\ntemplate <typename X, typename T> auto\
    \ make_table(X x, T a) { return vector<T>(x, a); }\ntemplate <typename X, typename\
    \ Y, typename Z, typename... Zs> auto make_table(X x, Y y, Z z, Zs... zs) { auto\
    \ cont = make_table(y, z, zs...); return vector<decltype(cont)>(x, cont); }\n\
    template <typename T> ostream & operator << (ostream & out, vector<T> const &\
    \ xs) { REP (i, (int)xs.size() - 1) out << xs[i] << ' '; if (not xs.empty()) out\
    \ << xs.back(); return out; }\ntemplate<typename Functor> struct fix_type { Functor\
    \ functor; template<typename... Args> decltype(auto) operator() (Args && ... args)\
    \ const & { return functor(functor, std::forward<Args>(args)...); } };\ntemplate<typename\
    \ Functor> fix_type<typename std::decay<Functor>::type> fix(Functor && functor)\
    \ { return { std::forward<Functor>(functor) }; }\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    constexpr char endl = '\\n';\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: template.cpp
  requiredBy: []
  timestamp: '2019-12-12 02:11:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template.cpp
layout: document
redirect_from:
- /library/template.cpp
- /library/template.cpp.html
title: template.cpp
---
