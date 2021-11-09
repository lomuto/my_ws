# equals 오버라이딩 하려면 hashCode도 오버라이딩 해라

반대도 마찬가지...  
이거 몰라서 `hashCode`만 구현해놓고 hashMap 돌리면서 왜 안되지 이러고 있었음...  
HashMap에서 equals 호출하는데, 내가 구현을 안해놔서 참조값 비교로 boolean반환하고  
hashCode 값으로 비교를 안해서 HashMap에서 계속 뻑났음

조심하자
