# Algorithm
Studying Algorithm

## BOJ

[백준 온라인 저지](https://acmicpc.net) 의 문제 풀이 디렉토리

### 환경

- Ubuntu 22.04 LTS
- [g++(GCC) vesion 11](https://gcc.gnu.org/)

Dockerfile 을 이용한 환경 구축

```bash
docker pull ghcr.io/yongjulejule/boj_env:v1.0.2
docker run --rm -itd --name boj ghcr.io/yongjulejule/boj_env:v1.0.2
```

BOJ에선 `g++ -O2 -Wall -lm -static -std=gnu++17 -DONLINE_JUDGE -DBOJ` 와 같이 컴파일 하는데 이 명령어를 `c`에 `alias` 해둠

컨테이너에서 컴파일

```bash
# 필요한 src 파일 컨테이너로 복사
# docker cp [path/to/file/in/host] [container_name]:/tmp/Main.cc
docker cp main.cpp boj:/tmp/Main.cc
docker exec boj c /tmp/main.cc
```


컨테이너에서 컴파일 및 실행

```bash
# 필요한 src 파일 컨테이너로 복사
# docker cp [path/to/file/in/host] [container_name]:/tmp/Main.cc
docker cp main.cpp boj:/tmp/Main.cc
# docker exec -it [container_name] <executable>
docker exec -it boj /bin/bash

# [in container]
cd /tmp
c main.cc
./Main
```
