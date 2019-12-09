---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: utils/marathon.inc.cpp
* category: utils


[Back to top page](../../index.html)



## Code
{% raw %}
```cpp
constexpr double ticks_per_sec = 2800000000;
constexpr double ticks_per_sec_inv = 1.0 / ticks_per_sec;
inline double rdtsc() {  // in seconds
    uint32_t lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return (((uint64_t)hi << 32) | lo) * ticks_per_sec_inv;
}
constexpr double TLE = 10.0;  // sec


    vector<slide_t> result = slides;
    ll highscore = score;
    cerr << "[*] highscore = " << highscore << endl;

    constexpr int TIME_LIMIT = 3000;  // msec
    chrono::high_resolution_clock::time_point clock_begin = chrono::high_resolution_clock::now();
    double temperature = 1;
    for (unsigned iteration = 0; ; ++ iteration) {
        if (iteration % 128 == 0) {
            chrono::high_resolution_clock::time_point clock_end = chrono::high_resolution_clock::now();
            temperature = 1 - chrono::duration_cast<chrono::milliseconds>(clock_end - clock_begin).count() / TIME_LIMIT;
            if (temperature < 0) {
                cerr << "[*] iteration = " << iteration << ": done" << endl;
                break;
            }
        }

        int i = uniform_int_distribution<int>(0, s - 1)(gen);
        if (i == 0 or i == slides.size() - 1) continue;
        int j;
        {
            int i1 = (bernoulli_distribution(0.5)(gen) ? i - 1 : i + 1);
            int tag = choose_tag(slides[i1], photos, gen);
            j = lookup_slide[choose(lookup_photo[tag], gen)];
        }
        if (j == 0 or j == slides.size() - 1) continue;
        if (i > j) swap(i, j);

        ll delta = 0;
        delta -= get_score_delta(slides[i - 1], slides[i], photos);
        delta -= get_score_delta(slides[j], slides[j + 1], photos);
        delta += get_score_delta(slides[i - 1], slides[j], photos);
        delta += get_score_delta(slides[i], slides[j + 1], photos);

        auto probability = [&]() {
            constexpr double boltzmann = 3;
            return exp(boltzmann * delta) * temperature;
        };
        if (delta >= 0 or bernoulli_distribution(probability())(gen)) {
            reverse(slides.begin() + i, slides.begin() + j + 1);
            if (delta < 0) {
                cerr << "[*] iteration = " << iteration << ": delta = " << delta << ": p = " << probability() << endl;
            }
            score += delta;
            if (highscore < score) {
                highscore = score;
                result = slides;
                cerr << "[*] iteration = " << iteration << ": highscore = " << highscore << endl;
            }
        } else {
        }
    }

    cerr << "[*] highscore = " << highscore << endl;
    return result;

```
{% endraw %}

[Back to top page](../../index.html)

