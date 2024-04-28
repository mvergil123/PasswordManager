FROM ubuntu:latest


RUN apt update -y

RUN apt install build-essential -y
RUN apt install vim -y
RUN apt install tmux -y

ENTRYPOINT bash

WORKDIR /app


