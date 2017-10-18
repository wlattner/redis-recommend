FROM redis:latest as builder

RUN apt-get update; \
    apt-get install -y --no-install-recommends build-essential

ADD ./src /src
WORKDIR /src
RUN make all

FROM redis:latest
WORKDIR /data

RUN mkdir -p /var/lib/redis/modules
COPY --from=builder /src/redis-recommend.so /var/lib/redis/modules

CMD ["redis-server", "--loadmodule", "/var/lib/redis/modules/redis-recommend.so"]
