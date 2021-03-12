# Discarding Input

## clear

`std::cin.clear()` : Resets the status to good such as `std::cin.fail()`
</br>

---

## Ignore

`std::cin.ignore()` : Discards single character  
`std::cin.ingnore(n)` : Discards `n` characters, stops when incounters `EOF`

`std::cin.ignore(n,t)` Discards `n` characters untill incounters character `t`

`std::cin.ignore(LLONG_MAX, '\n')` : `LLONG_MAX` is a maximum number which has been pre-defined. **Discards all characters untill meets new-linew character**  
 </br>

---

## get, getline

`std::cin.get(buf,n)` : reads `n` characters until incounters new-line character and save them to `buf`  
**Leaves new-line character inside buffer**

`std::cin.get(buf,n,'a')` : same as method above, difference with reads from stdin untill meets character `a`.

`std::cin.getline()` : Same as `get` but **Discards new-line charater in stdin**
