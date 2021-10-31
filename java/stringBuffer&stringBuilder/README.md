# StringBuilder 와 StringBuffer

Java에서 String 개체는 immutable하다. (이유는 여러가지가 있고 OOP관점에서의 encapsulation과 thread Safety를 들 수 있을 것 같다. 멀티쓰레드 환경에서 문자열 출력할때 stringBuilder로 문자 받았다가 마지막에 한꺼번에 찍으니까)

Cpp에서 string 개체는 `append`와 같은 메소드를 통해 개체를 변경할 수 있는데, Java에서 String개체도 이와 비슷하게 할 수 있게끔 한것이 `StringBuilder`와 `StringBuffer`이다.

둘중에 그럼 뭐를 쓰느냐?  
**멀티스레드 환경에서는 StringBuffer**를 그게 아니면 StringBuilder를 쓰면된다.  
**StringBuffer는 synchronization이 되지만 그만큼 expensive해서 Builder보다 쪼금 느리다**

### **둘다 equals 메소드 구현 안돼있다!**

모든 개체형은 Object 클래스를 상속받는데 여기에 `equals`메소드가 있다. StringBuilder,Buffer 둘다 이 메소드 오버라이딩이 안되어있어서

`sb0.toString().equals(sb1.toString())`  
이렇게 문자열로 바꿔서 쓰던가 아니면 구현 해줘야함.
