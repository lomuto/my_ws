# Prim 알고리즘의 증명

## Prim Algorithm의 step

1. 임의의 vertex 선택 후 tree의 root로 설정
2. vertex에 adjacent한 edge들 중 weight가 최소인 것 선택  
   2.1 이 edge가 cycle을 형성하지 않으면 set(tree) 에 포함  
   2.2 cycle을 형성한다면 다음 edge 확인

이 알고리즘이 항상 globally optimal한 결과를 찾아내는지 증명.

<!-- <br/>    -->

Prim Algorithm이 진행되는 어떤 단계에서 현재까지 완성된 set을 `T` 라 하고 **globally optimal한 여러 해들 중 하나를** Tmst 라 하자.  
**$$T \subseteq Tmst$$**  
이를 증명할 것.

<!-- <br/> -->

### base: $T = \emptyset$

$\emptyset \subseteq Tmst$ 을 성립하므로 참

---

<!-- <br/> -->

$T \subseteq Tmst$ 가 참이라고 하자. 이후의 단계에서 어떤 edge $e0$ 를 포함한 집합 $T'$을

$$
\{e0\} \cup T = T'
$$

이라 하자.

- case1: $T' \subseteq Tmst$  
  이 경우에는 문제가 없다. 참

- case2: $T' \nsubseteq Tmst$  
  이 case가 왜 모순인지 증명하기 앞서 어떤 edge $e1$이

  - $T$에 인접하고
  - $e1 \neq e0$
  - $e1 \nsubseteq T$
  - $\{e1\} \cup T \neq Cycle$

    를 만족한다 하자.

    1. $w(e1) < w(e0)$  
        만약 $e1$ 의 길이가 더 짧다면 adjacent 한 edge들 중 길이가 최소인걸 고르는 step에 어긋나므로 ($e0$ 이 아니라 $e1$을 골랐어야 했다)  
       **모순**

    2. $w(e1) > w(e0)$  
       만약 $e0$ 의 길이가 더 짧다면  
       $(T - \{e1\}) \cup e0$ 이 $Tmst$보다 더 optimal 하므로 전제조건에 어긋난다.  
       **모순**

    3. $w(e1) = w(e0)$  
       이 경우 $T'$ 도 optimal한 경우 이므로 $Tmst$ 에 포함되어 전제조건을 깨트린다.  
       **모순**  


고로 Prim Algorithm은 항상 globally optimal한 결과를 도출한다고 생각할 수 있다.
