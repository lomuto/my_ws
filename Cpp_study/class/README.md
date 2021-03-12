```cpp
class Vector{
    int mX;
    int mY;
};

```

위 멤버변수 mX와 mY는 기본적으로 **Private**  
C++에서는 접근권한 설정 따로 안해주면 default로 private 박아넣음

- 접근 제어자  
  public -> 누구나 접근 가능  
  protected -> 자식클래스에서 접근 가능  
  private -> 해당 클래스에서만 접근 가능  


동일 제어자를 가진 멤버끼리 묶음
