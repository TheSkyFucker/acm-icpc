# 演算法筆記

## **Graph Theory**

### [Bipartite Graph](http://www.csie.ntnu.edu.tw/~u91029/BipartiteGraph.html)   

#### [**Matching**](http://www.csie.ntnu.edu.tw/~u91029/Matching.html)  

- [x] **Bipartite Matching**（二分图最大匹配）
      - 扩充路径（**Augment Path**）
        - $O（VE）$
      - 同时增广（**Hopcroft Karp**）
        - $O（E\sqrt{V}）$ 
        - 寻找增广路集的每一个阶段所寻找到的 **最短增广路** 都具有相等的长度；
        - 随着算法的进行最短增广路的长度越来越长；
        - 故最多增广 $\sqrt{n}$ 次
      - 对称差集（Symmetric Difference）
      - 贪心预匹配（Greedy Matching）：图极密时可以加速不少
      - Problem Set
      | [670](http://uva.onlinejudge.org/external/6/670.html) | [259](http://uva.onlinejudge.org/external/2/259.html) | [753](http://uva.onlinejudge.org/external/7/753.html) | [10080](http://uva.onlinejudge.org/external/100/10080.html) | [10092](http://uva.onlinejudge.org/external/100/10092.html) |
      | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | :--------------------------------------- |
      |                                          | done                                     |                                          |                                          |                                          |
      | [**10418**](http://uva.onlinejudge.org/external/104/10418.html) | [**10243**](http://uva.onlinejudge.org/external/102/10243.html) | [**10984**](http://uva.onlinejudge.org/external/109/10984.html) | [**663**](http://uva.onlinejudge.org/external/6/663.html) | [**11148**](http://uva.onlinejudge.org/external/111/11148.html) |
      |                                          |                                          |                                          |                                          |                                          |

- [x] **Graph Matching** （一般图最大匹配）

      - 带花树（**Blossom Algorithm**）
        - $O(EV)$ （×个并查集的查询复杂度）
      - 贪心预匹配（greedy matching）：同样有效
      - 同时增广
        - $O（E \sqrt{V}）$ 
        - 作法及证明：[**《A Proof of the MV Matching Algorithm》**](http://www.cc.gatech.edu/~vazirani/new-proof.pdf) （40 pages，已弃
      - Problem Set

      | Timus [1099](http://acm.timus.ru/problem.aspx?space=1&num=1099) | UVa [11439](http://uva.onlinejudge.org/external/114/11439.html) | ICPC [3820](http://icpcarchive.ecs.baylor.edu/external/38/3820.pdf) |
      | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
      |                                          | done                                     | done                                     |



- [ ] **Hungarian Algorithm**（二分图最大权完美匹配、最大权最大匹配、最大权匹配）

      > [**《KM算法入门》**](https://www.cnblogs.com/logosG/p/logos.html)  （不太正确）

      - 等量修改某点的所有边，不会影响最大权完美匹配的位置（二分图、一般图均成立）
      - Problem Set

      | [**UVa11383**](http://uva.onlinejudge.org/external/113/11383.html) | [**Uva1411**](http://uva.onlinejudge.org/external/14/1411.html) | [**ICPC 3276**](http://icpcarchive.ecs.baylor.edu/external/32/3276.pdf) |
      | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
      | done                                     |                                          |                                          |

      ​

#### [**Domination**](http://www.csie.ntnu.edu.tw/~u91029/Domination.html)  



---

### [Level Graph](http://www.csie.ntnu.edu.tw/~u91029/BipartiteGraph.html#2)   

#### [**Path**](http://www.csie.ntnu.edu.tw/~u91029/Path2.html)   

#### [**Flow**](http://www.csie.ntnu.edu.tw/~u91029/Flow.html)   

