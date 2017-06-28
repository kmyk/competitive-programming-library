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
