# Things to mind in recursive function call

```cpp
#include <iostream>

using namespace std;

int foo() {
    cout << "This function doesn't have return value\n";
}

int main() {
    cout << foo();
}
```

Function `foo()` is defined as returning integer value, while has no return statement.  
That seems illegal but it compiles well, and aslo runs with no error.  
Exectuing this code will print following line

```
$ ./a.exe
This function doesn't have return value
1878006336
```

While I print the return value of function `foo`  
the result is some garbage number `1878006336`  
Meaning of that number varies from platform that currently running, but usually stands for **Left value in return register (`EAX` on x86)**  
There is still a chance that the number is just usless garbage, but it could be a **address of function foo's instruction**

</br>

```cpp
#include <algorithm>
#include <iostream>

using namespace std;

int flag = 0;

int foo() {
    flag += 2;
}

int main() {
    cout << foo();
}
```

```c
// Execute
$ ./a.exe
2
```

We can check that printed result is **2** : which is value of `flag`, from **basic arthimetic operation held by `EAX` register**

</br>

---

</br>   
   
## Common mistake
   
```c
int* R_bsearch(int* arr, int n, int key) {
    if (n < 1) {
        return -1;
    }

    int middle = n / 2;

    if (key == *(arr + middle))
        return arr + middle;
    else if (key > * (arr + middle))
        R_bsearch(arr + middle + 1, n-middle-1, key);
    else
        R_bsearch(arr, middle, key);

}

````

Problem of this function is that **it has no return statement for calling function itself recusively**
So calling `R_bsearch` in main function and print its return value could cause same problem.
### **So must state `return` keyword in recursive call so that retrurn value of very last call can climb up to initial call.**

</br>

But when it comes to *Traversing tree*, return statement is no needed.

```cpp
// Inorder
void TRAVERSE_TREE(NODE* ptr){

    if(!ptr)
        return;

    cout << ptr->value << " ";
    TRAVERSE_TREE(ptr->left_child);
    TRAVERSE_TREE(ptr->right_child);
}
````
