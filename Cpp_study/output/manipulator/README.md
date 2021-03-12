# Manipulator

## **< iostream >**

</br>
- showpos / noshowpos

```cpp
std::cout << std::noshowpos << -123 // 123
```

</br>

---

</br>

- dec / hex / oct

```cpp
std::cout << std::hex << 59 // 3b
```

</br>

---

</br>

- uppercase / nouppercase

```cpp
std::cout << std::uppercase << std::hex << 59 // 3B
```

</br>

---

</br>

- showbase / noshowbase

```cpp
std::cout << std::showbase <<std::hex << 59 // 0x3b
```

</br>

---

</br>

- left / internal / right

```cpp
// setw(n) is in <iomanip>
std::cout << std::left <<std::setw(5) << 59 // |59   |

std::cout << std::internal <<std::setw(5) << -59 // |-  59|
```

</br>

---

</br>

- showpoint / noshowpoint

```cpp
std::cout << std::noshowpoint << 10.00  // 10

std::cout << std::noshowpoint << 12.29  // 12.29

std::cout << std::showpoint << 10.00  // 10
```

`noshowpoint` skips the unnecesssary point part. **Doesn't always skips the point part**

</br>

---

</br>

- fixed / scientific

```cpp
std::cout << std::scientific << 10.234   // 1.023400e+001
```

</br>

---

</br>

- boolalpha / noboolalpha

```cpp
std::cout << std::boolalpha << 1    // true

std::cout << std::noboolalpha << false    // 0
```

</br>

---

## **< iomanip >**

</br>

- setw(int n)

```cpp
std::cout << std::setw(3) << 1    // |  1|
```

</br>

---

</br>

- setprecision(int n)

```cpp
std::cout << std::setprecision(3) << 12.345    // 12.3

std::cout << std::setprecision(3) << 12345    // 12345
```

</br>
