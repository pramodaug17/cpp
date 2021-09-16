FROM cpp-build-base:0.1.0 AS build

WORKDIR /cpp
COPY ./ ./
CMD ["make", "all"]