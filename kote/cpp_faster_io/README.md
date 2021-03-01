# Faster Input & Output

## sync_with_stdio(false)

Cpp handels both `Cpp` and `C` standard stream, such as cin,cout for `Cpp` and printf,scanf in `C`.

Both IO are different, while `Cpp`'s IO is thread-safe but `C` is not.

So `Cpp` has to spend its resources to watch those two different stream.

```cpp
ios::sync_with_stdio(0);
```

This will disables synchronization with input&output of `C` in `Cpp`, so that fasten the speed for `Cpp` to only take care of `cin`&`cout`.

**Using `scanf,printf,puts,getchar` are also prohibited.**

---

## cin.tie(false)

Input and output streams are both tied to another.  
This measn that...

```cpp
string name;

cout << "Enter name: ";
cin >> name;
cout << "Your name is: " << name;
```

Such situation guarentees that **Output stream to be flushed before Input stream takes its input.**

So that we can see

```
$ Enter name:|
```

waiting for input with printed letters.

BUT what if I untie `cin` from `cout`?  
`cout` won't be flushed automatically if `cin` starts to waiting for input.

```
$ kang
$ Enter name: Your name is: kang
```

This would what happen if I enter `kang` as name.

Benifit of doing this would be **fasten the processing speed with discarding buffer flushing for every input and output comes together.**
