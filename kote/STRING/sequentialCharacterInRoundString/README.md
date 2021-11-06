# Sequential character in round string

Given string `cddvvddc`, found out sequential count of each characters in rounded string.

1. `ddvvdd` will be counted as `2,1,2` as `d` is seperated with `v`.
2. As it mentioned with `round string`, `c` is counted as `2`.

### sol 1

```java
String s = "cddvvddc";

int left = 0;
int right = s.length - 1;

if(s.charAt(left) == s.charAt(right)) {
    while(left < right) {
        if(s.charAt(left) != s.charAt(left+1)) {
            break;
        }

        left++;
    }

    if(left == right) {
        // string with same characters ex)"aaa"
    }

    while(left < right) {
        if(s.charAt(right) != s.charAt(right-1)) {
            break;
        }

        right--;
    }
}

//keep with up left and right pivot

for(int i=left; i<right; i++) {
    if(s.charAt(i) != s.charAt(i+1)) {
        break;
    }
}

```

This can be also solved with fancy stuff....

### sol 2

```java
String s = "cddvvddc";

// check whether string is consisted with same characters
// if so, return

StringBuilder sb = new StringBuilder(s);


while(sb.charAt(0) == sb.charAt(sb.size()-1)) {
    // pop from end of sb
    // push that character to start of sb
}

...
```

Empressive solution with moving character from end to start untill it is not same for start and end character.

After the loop, `sb` remain with such condition with different start and end.
