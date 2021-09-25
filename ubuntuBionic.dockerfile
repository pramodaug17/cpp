FROM ubuntu:bionic

RUN apt-get update && \
	apt-get install -y gcc gcc-8 g++-8 build-essential git libtool pkg-config

