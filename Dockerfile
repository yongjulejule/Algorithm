FROM ubuntu:16.04

LABEL org.opencontainers.image.source=https://github.com/yongjulejule/Algorithm

RUN apt update && apt install -y gcc && apt install -y g++ && apt install -y vim
