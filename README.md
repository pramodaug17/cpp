# cpp
C++ related programs books, notes etc is be available here. You are welcome to contribute in this repository.

## Topics
Below are the list of topic covered
- [Design Pattern](src/design_pattern/README.md)

## Setup the project
To make it easy to setup this project, [Docker](https://www.docker.com) is being used. Ubuntu bionic version is used to build and test. With the help of docker, It is possible to use any OS and any hardware without being worried about installation of OS, supporting package and all.

### Steps to setup
- Install docker(free version). Download from [here](https://www.docker.com/products/docker-desktop)
- Base image or container need to be built using below command
  - ```docker build . -t cpp-build-base:0.1.0 -f 'ubuntuBionic.dockerfile'```
- Now, execute below command to build the container.
  - ```docker-compose build --no-cache```
- After first build, To build and execute cpp project use below command
  - ```docker-compose up```
- It is recommeded that you clean up the docker.
  - ```docker-compose down```
