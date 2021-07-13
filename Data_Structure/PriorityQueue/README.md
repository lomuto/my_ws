# Priority Queue

`priority_queue<T,vector<T>,compare> pq`

Unlike the other container's comparator, passing a function to third paramter `compare` is illegal.

```cpp
priority_queue<int, vector<int>, [](int a,int b){return a>b;}> pq;
// compile error
```

Instead of a function, `priority_queue` requires a `structure` or `class` with overridden `operator()`

```cpp
struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};

...

priority_queue<int, vector<int>, cmp> pq;
```

In this case, `vector<int>` container will be sorted as **ascending** order, which means...

### **`pop` from priority queue will be descending order(queue pops from very end)**
