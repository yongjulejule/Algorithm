FROM ubuntu:22.04

LABEL org.opencontainers.image.source=https://github.com/yongjulejule/Algorithm
LABEL org.opencontainers.image.authors=yongjule(lyjshow200@gmail.com)
LABEL org.opencontainers.image.version=1.0.0

RUN apt update && apt install -y gcc && apt install -y g++ && apt install -y vim
