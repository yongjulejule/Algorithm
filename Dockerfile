FROM ubuntu:22.04

LABEL org.opencontainers.image.source=https://github.com/yongjulejule/Algorithm
LABEL org.opencontainers.image.authors=yongjule(lyjshow200@gmail.com)
LABEL org.opencontainers.image.version=1.0.1
LABEL org.opencontainers.image.description="백준 온라인 저지의 c++ 컴파일 환경을 만드는 Docker Image"

RUN apt update && apt install -y gcc && apt install -y g++ && apt install -y vim


RUN /bin/bash -c "echo alias c=\'g++ -O2 -Wall -lm -static -std=gnu++17 -DONLINE_JUDGE -DBOJ\' >> /root/.bashrc && source /root/.bashrc"
