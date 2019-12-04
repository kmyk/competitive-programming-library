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


# :warning: utils/distributed-code-jam.inc.cpp
* category: utils


[Back to top page](../../index.html)



## Code
```cpp
template <class T> void PutGeneric(int target, T value);
template <> void PutGeneric(int target, char value) { PutChar(target, value); }
template <> void PutGeneric(int target, int value) { PutInt(target, value); }
template <> void PutGeneric(int target, long long value) { PutLL(target, value); }

template <class Container>
void PutVec(int target, Container & values) {
    PutInt(target, values.size());
    for (auto value : values) PutGeneric(target, value);
}

template <class T> T GetGeneric(int source);
template <> char GetGeneric(int source) { return GetChar(source); }
template <> int GetGeneric(int source) { return GetInt(source); }
template <> long long GetGeneric(int source) { return GetLL(source); }

template <class Container>
Container GetVec(int source) {
    int size = GetInt(source);
    Container values;
    values.resize(size);
    repeat (i, size) values[i] = GetGeneric<typename Container::value_type>(source);
    return values;
}

```

[Back to top page](../../index.html)

