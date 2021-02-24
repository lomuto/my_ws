# VScode C언어 중괄호 줄바꿈 서식 변경

Current Problem

```
for (int i = 0; i < 10; i++)
{
    // ...
}
```

What I wanted to look like

```
for (int i = 0; i < 10; i++) {
    // ...
}
```

1. Go Preferences -> Settings
2. Search for C_Cpp.clang_format_fallbackStyle
3. Click Edit, Copy to Settings
4. Change from "Visual Studio" to "{ BasedOnStyle: Google, IndentWidth: 4 }"
