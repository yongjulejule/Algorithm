# Shortest-paths problem (최단 경로 문제)
>Introduction to Algorithms 3rd edition 챕터 24를 정리한 내용

최단 경로 문제에서, 가중치가 있고 방향이 있는 그래프 $G = (V, E)$ 와  `edge` 를 실수의 가중치(weight)로 매핑하는 $w : E \rightarrow \mathbb{R}$ 함수가 주어진다. 경로 $p = <v_0, v_1, ... ,v_k>$ 의 가중치 $w(p)$ 는 구성하는 `edges`의 합이 된다. 
$\sum_{i=1}^k w(v_{i-1}, v_i)$  
이때 $u$ 부터 $v$ 까지의 최단 경로(shortest-path weight) $\delta(u, v)$ 는 다음과 같이 정의된다.
$\begin{equation} \delta(u, v) = \begin{cases} min\{w(p) : u \rightsquigarrow^{p}v \}, & \text{if there is a path from u to v}. \\ \infty, & \text {otherwise}. \end{cases} \end{equation}$
이때 $u$ 부터 $v$ 까지의 경로 $p$ 중 $w(p) = \delta(u, v)$ 를 만족하는 $p$가 []()된다.

edge의 가중치는 거리 뿐만 아니라 소요시간, 비용, 패널티, 손실 혹은 알고리즘에서 최소화 하기 위한 어떤 값이든 될 수 있다.

## Variants
이 챕터에선 single-source shortest-paths problem, 즉 주어진 그래프 $G = (V, E)$ 에서 시작점 $s \in V$ 부터 각 점 $v \in V$ 까지 최단 경로를 찾는 문제에 집중해서 알아보자. 이 single-source problem을 위한 알고리즘은 다음과 같은 varients를 포함하는 여러 문제를 해결할 수 있다.
**Single-destination shortest-paths problem:** 
	주어진 목적지 정점 $t$ 에 도착하는 각 정점 $v$ 로부터 최단경로를 구하는 문제. 그래프의 각 edge의 방향을 reversing하여 이 문제를 single-source problem으로 해결할 수 있다.
**Single-pair shortest-path problem:**
	주어진 $u$, $v$ 가 있을 때, $u$ 에서 $v$ 로 가는 최단경로를 구하는 문제. source vertex $u$ 에 대하여 single-source problem을 풀면, 이 문제 또한 해결할 수 있다. 게다가, 이 문제를 해결하기 위한 방법으로 알려진 모든 알고리즘들은 worst-case에서 점근적인(asymptotic) 런타임 소요 시간은 최상의 single-source algorithms과 동일하다.
**All-pairs shortest-paths problem:**
	정점 $u, v$ 의 모든 pair를 위해 $u$에서 $v$로 가는 최단경로를 찾는 문제. 비록 각 정점들에 대해 single-source algorithm을 실행하여 문제를 해결할 수 있지만, 보통 더 빠른 방법으로 해결할 수 있다. 게다가, 그 구조는 그 자체로 흥미로우며 그 내용은 따로 다루게 될 것이다.

## optimal substructure of a shortest path
촤단경로 알고리즘은 주로 두 정점의 최단거리는 다른 최단거리를 포함한다는 성질에 의존한다. 이는 DP 및 Greedy 에서 적용되는 성질과 유사하다. Dijkstra 알고리즘은 그리디 알고리즘이고, Floyd-Warshall 알고리즘은 DP 알고리즘이다. 다음과 같은 lemma는 최단 경로의 optimal-substructure property 를 더 정밀하게 해준다.

### *Lemma 24.1 (Subpaths of shortest paths are shortest paths)*
가중치가 있고 방향이 있는 그래프 $G = (V, E)$ 와 weight function $w : E \rightarrow \mathbb{R}$ 가 주어졌을 때, $p = < v_0, v_1, ... , v_k>$ 를 정점 $v_0$ 에서 $v_k$ 로 가는 최단경로라 하자. 그리고 임의의 $0 \leq i \leq j \leq k$ 를 만족하는 $i, j$ 에 대하여 $p_{ij} = <v_i, v_{i+1}, ..., v_j>$ 를 정점 $v_i$ 에서 $v_j$ 로 가는 subpath라고 하자. 그러면 $p_{ij}$는 $v_i$ 에서 $v_j$ 로 가는 최단 경로이다.

__*proof:*__
경로 $p$를 $v_0 \rightsquigarrow^{p_{0i}} v_i \rightsquigarrow^{p_{ij}} v_j \rightsquigarrow^{p_{jk}} v_k$ 로 분해하면, $w(p) = w(p_{0i}) + w(p_{ij}) + w(p_{jk})$ 가 된다. 이제, $v_i$ 에서 $v_j$ 로 가는 path $p_{ij}^`$ 가 존재하며 $w(p_{ij}^`) < w(p_{ij})$ 를 만족한다고 하자. 그러면 $v_0 \rightsquigarrow^{p_{0i}} v_i \rightsquigarrow^{p_{ij}^`} v_j \rightsquigarrow^{p_{jk}} v_k$ 는 $v_1$ 에서 $v_k$ 로 가면서 가중치 $w(p_{0i}) + w(p_{ij}^`) + w(p_{jk})$  를 가지는데, 이는 $w(p)$보다 작아지게 되며 이는 $p$가 $v_0$ 에서 $v_k$로 가는 가정에 모순된다.

## Negative-weight edges
![negative Edge](negativeEdge.png)
>*출처 : Introduction to Algorithms 3rd*
>*$e, f, g$는 negative-weight cycle을 가져서 weight가 $-\infty$ 이고, $h, i, j$ 는 negative-weight cycle을 가지지만 $s$에서 도달가능하지 않기 때문에 weight가 $\infty$ 이다. 

종종 single-source 최단경로 문제는 음의 가중치를 가진 edge를 포함할 수 있다. 만약 그래프 $G=(V, E)$ 가 source $s$로 부터 도달가능한 "음의 가중치 사이클(negative weight cycles)"이 존재하지 않는다면, 모든 $v \in V$ 에서 최단 경로 가중치 $\delta(s, v)$ 는 음의 가중치가 되더라도 잘 정의된다. 하지만 도달 가능한 "음의 가중치 사이클(negative weight cycles)"이 존재한다면, 최단경로의 가중치는 잘 정의되지 않는다. $s$에서 사이클 위의 다른 점으로 가는 path는 negative-weight cycle을 돌면서 더 짧은(shortest) path를 가지게 되기 때문이다. 따라서 $s$ 에서 $v$로 가는 경로에 negative-weight cycle이 존재한다면 $\delta(s, v) = -\infty$ 로 정의한다.

`Dijkstra` 알고리즘의 경우 모든 edge의 가중치는 음이 아니라고 가정하고, `Bellman-Ford` 알고리즘은 음의 가중치를 가지는 edge를 허용하며, source에서 도달가능한 negative-weight cycle이 없을 때 정확한 답을 구해준다. 보통, negative-weight cycle가 존재하면 알고리즘은 이를 탐지해내게 된다.

## Cycles

