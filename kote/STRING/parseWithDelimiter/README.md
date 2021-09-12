# 구분자로 문자열 파싱하기

`970029019201001402932103`  
이런 문자열이 있다고 하자.  
위 문자열을 `0` 이 아닌 연속된 digit의 문자열들만 솎아내고 싶다고 하자.

```cpp
vector<string> parseWithDelimiter(const string &src, char delimiter) {
    vector<string> ret;
    int stPos = 0;
    int endPos = 0;

    while (true) {
        stPos = src.find_first_not_of(delimiter, stPos);
        if (stPos == string::npos) {
            break;
        }

        endPos = src.find_first_of(delimiter, stPos);
        ret.push_back(src.substr(stPos, endPos - stPos));

        if (endPos == string::npos) {
            break;
        }

        stPos = endPos + 1;
    }

    return ret;
}
```

위와 같이 `stPos`, `endPos` 두개의 pivot을 두어서 조건에 맞게 delimiter의 위치를 찾아내고 조건에 맞게 substr을 수행하면 된다.
