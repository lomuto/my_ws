# Overlooked thought

## - Deleting a node

```cpp
...

free(nodePtr->next);
nodePtr->next = nodePtr->next->next
```

At the moment that `nodePtr` has been deallocated, its impossible to reach to `nodePtr->next->next` while `nodePtr->next` is NULL.

</br>   
   
```cpp
...

nodePtr->next = nodePtr->next->next
free(nodePtr->next);

````

This one will deallocate the next one of node to be deallocated.

---

</br>

### Solution...

```cpp
...

NODE* temp = nodePtr->next->next;
free(nodePtr->next);
nodePtr->next = temp;
````

Making a temporary pointer of NODE to linked, this will fix the problems of two
