# About SORT Algorithm

Function `sort` is base on `quick sort`, pre-defined in `algorithm` header file.

```cpp
template<typename T>
void sort(T start, T end, Compare comp)
```

Argument `start` and `end` takes referenece type value, such as **`char*`,`int*`** or **`vector<T>::iterator`**

So when using `vector`

```cpp
vector<int> arr;
arr.reserve(N);
...
sort(arr.begin(),arr.end());
```

---

Leave third parameter as void, default action would be order by `ascending`

To control the sorting order, hand over `bool* (*)(T a,T b)` type function variable.

Let's say that I want to order vecotr string as **length of string, in alphabetic when both length are same.**. Then the function would be

```cpp
bool comapre(strin a, string b){
    if(a.size() == b.size())
        return a < b;
    else
        return a.size() < b.size();
}
```
