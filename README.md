# Redis-Recommend

There is not much to see right now, but at some point, this Redis module will
do something.

## Build
```bash
make
```
or w/ Docker:
```bash
docker build -t redis-recommend:test .
```

## Usage
```bash
redis-server --loadmodule src/redis-recommend.so
```

```redis
> REC.ADDPREF user_1 movie_1 4
OK
```
