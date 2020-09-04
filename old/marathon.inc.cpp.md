---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"old/marathon.inc.cpp\"\nconstexpr double ticks_per_sec =\
    \ 2800000000;\nconstexpr double ticks_per_sec_inv = 1.0 / ticks_per_sec;\ninline\
    \ double rdtsc() {  // in seconds\n    uint32_t lo, hi;\n    asm volatile (\"\
    rdtsc\" : \"=a\" (lo), \"=d\" (hi));\n    return (((uint64_t)hi << 32) | lo) *\
    \ ticks_per_sec_inv;\n}\nconstexpr double TLE = 10.0;  // sec\n\n\n    vector<slide_t>\
    \ result = slides;\n    ll highscore = score;\n    cerr << \"[*] highscore = \"\
    \ << highscore << endl;\n\n    constexpr int TIME_LIMIT = 3000;  // msec\n   \
    \ chrono::high_resolution_clock::time_point clock_begin = chrono::high_resolution_clock::now();\n\
    \    double temperature = 1;\n    for (unsigned iteration = 0; ; ++ iteration)\
    \ {\n        if (iteration % 128 == 0) {\n            chrono::high_resolution_clock::time_point\
    \ clock_end = chrono::high_resolution_clock::now();\n            temperature =\
    \ 1 - chrono::duration_cast<chrono::milliseconds>(clock_end - clock_begin).count()\
    \ / TIME_LIMIT;\n            if (temperature < 0) {\n                cerr << \"\
    [*] iteration = \" << iteration << \": done\" << endl;\n                break;\n\
    \            }\n        }\n\n        int i = uniform_int_distribution<int>(0,\
    \ s - 1)(gen);\n        if (i == 0 or i == slides.size() - 1) continue;\n    \
    \    int j;\n        {\n            int i1 = (bernoulli_distribution(0.5)(gen)\
    \ ? i - 1 : i + 1);\n            int tag = choose_tag(slides[i1], photos, gen);\n\
    \            j = lookup_slide[choose(lookup_photo[tag], gen)];\n        }\n  \
    \      if (j == 0 or j == slides.size() - 1) continue;\n        if (i > j) swap(i,\
    \ j);\n\n        ll delta = 0;\n        delta -= get_score_delta(slides[i - 1],\
    \ slides[i], photos);\n        delta -= get_score_delta(slides[j], slides[j +\
    \ 1], photos);\n        delta += get_score_delta(slides[i - 1], slides[j], photos);\n\
    \        delta += get_score_delta(slides[i], slides[j + 1], photos);\n\n     \
    \   auto probability = [&]() {\n            constexpr double boltzmann = 3;\n\
    \            return exp(boltzmann * delta) * temperature;\n        };\n      \
    \  if (delta >= 0 or bernoulli_distribution(probability())(gen)) {\n         \
    \   reverse(slides.begin() + i, slides.begin() + j + 1);\n            if (delta\
    \ < 0) {\n                cerr << \"[*] iteration = \" << iteration << \": delta\
    \ = \" << delta << \": p = \" << probability() << endl;\n            }\n     \
    \       score += delta;\n            if (highscore < score) {\n              \
    \  highscore = score;\n                result = slides;\n                cerr\
    \ << \"[*] iteration = \" << iteration << \": highscore = \" << highscore << endl;\n\
    \            }\n        } else {\n        }\n    }\n\n    cerr << \"[*] highscore\
    \ = \" << highscore << endl;\n    return result;\n"
  code: "constexpr double ticks_per_sec = 2800000000;\nconstexpr double ticks_per_sec_inv\
    \ = 1.0 / ticks_per_sec;\ninline double rdtsc() {  // in seconds\n    uint32_t\
    \ lo, hi;\n    asm volatile (\"rdtsc\" : \"=a\" (lo), \"=d\" (hi));\n    return\
    \ (((uint64_t)hi << 32) | lo) * ticks_per_sec_inv;\n}\nconstexpr double TLE =\
    \ 10.0;  // sec\n\n\n    vector<slide_t> result = slides;\n    ll highscore =\
    \ score;\n    cerr << \"[*] highscore = \" << highscore << endl;\n\n    constexpr\
    \ int TIME_LIMIT = 3000;  // msec\n    chrono::high_resolution_clock::time_point\
    \ clock_begin = chrono::high_resolution_clock::now();\n    double temperature\
    \ = 1;\n    for (unsigned iteration = 0; ; ++ iteration) {\n        if (iteration\
    \ % 128 == 0) {\n            chrono::high_resolution_clock::time_point clock_end\
    \ = chrono::high_resolution_clock::now();\n            temperature = 1 - chrono::duration_cast<chrono::milliseconds>(clock_end\
    \ - clock_begin).count() / TIME_LIMIT;\n            if (temperature < 0) {\n \
    \               cerr << \"[*] iteration = \" << iteration << \": done\" << endl;\n\
    \                break;\n            }\n        }\n\n        int i = uniform_int_distribution<int>(0,\
    \ s - 1)(gen);\n        if (i == 0 or i == slides.size() - 1) continue;\n    \
    \    int j;\n        {\n            int i1 = (bernoulli_distribution(0.5)(gen)\
    \ ? i - 1 : i + 1);\n            int tag = choose_tag(slides[i1], photos, gen);\n\
    \            j = lookup_slide[choose(lookup_photo[tag], gen)];\n        }\n  \
    \      if (j == 0 or j == slides.size() - 1) continue;\n        if (i > j) swap(i,\
    \ j);\n\n        ll delta = 0;\n        delta -= get_score_delta(slides[i - 1],\
    \ slides[i], photos);\n        delta -= get_score_delta(slides[j], slides[j +\
    \ 1], photos);\n        delta += get_score_delta(slides[i - 1], slides[j], photos);\n\
    \        delta += get_score_delta(slides[i], slides[j + 1], photos);\n\n     \
    \   auto probability = [&]() {\n            constexpr double boltzmann = 3;\n\
    \            return exp(boltzmann * delta) * temperature;\n        };\n      \
    \  if (delta >= 0 or bernoulli_distribution(probability())(gen)) {\n         \
    \   reverse(slides.begin() + i, slides.begin() + j + 1);\n            if (delta\
    \ < 0) {\n                cerr << \"[*] iteration = \" << iteration << \": delta\
    \ = \" << delta << \": p = \" << probability() << endl;\n            }\n     \
    \       score += delta;\n            if (highscore < score) {\n              \
    \  highscore = score;\n                result = slides;\n                cerr\
    \ << \"[*] iteration = \" << iteration << \": highscore = \" << highscore << endl;\n\
    \            }\n        } else {\n        }\n    }\n\n    cerr << \"[*] highscore\
    \ = \" << highscore << endl;\n    return result;\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: old/marathon.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: old/marathon.inc.cpp
layout: document
redirect_from:
- /library/old/marathon.inc.cpp
- /library/old/marathon.inc.cpp.html
title: old/marathon.inc.cpp
---
