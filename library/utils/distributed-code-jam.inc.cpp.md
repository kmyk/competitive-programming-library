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


# :warning: utils/distributed-code-jam.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/distributed-code-jam.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2017-06-28 15:20:11 +0900




## Code

<a id="unbundled"></a>
{% raw %}
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
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "utils/distributed-code-jam.inc.cpp"
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
{% endraw %}

<a href="../../index.html">Back to top page</a>

