# pair<T,T>

ㅠ.ㅠ

Suppose we want to save coordinate of 2DIM `(x,y)`

We might create a structure

```cpp
struct coordinate{
    int x;
    int y;
};
```

That is what pair is exactely.

```cpp
/*
*   struct coordinate{
*       int first;
*       int second;
*    };
*/
pair<int,int> coordinate;
```

Structure use `.` operator to approach its field, so do `pair.`

```cpp
coordinate.x;
```

Suppose we make a pointer of pair

```cpp
pair<int,int>* ptr_cor = new pair<int,int>{1,2};

cout << ptr_cor->first << ' ' << ptr_cor->second;
// 1 2
```

Use `->` operator to approach field if pointer pair just like structure, and use `unifrom initailizer` to init two pair as `1` and `2`.  
Each element of pair can be approached with `first` and `second`.

```cpp
/*
*   struct coordinate{
*       int first;
*       int second;
*    };
*
*    struct dim3{
*        struct coordinate first;
*        int second;
*    };
*/

pair<pair<int,int>,int> dim3;
```

This kind of crazy stuff is also available.
