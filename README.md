# Ellis Op -- RPC

*Ellis Op* is an optional add-on to
[Project Ellis](https://github.com/project-ellis/ellis)
that provides an encoding-agnostic RPC system.

Actually it is more properly called an asynchronous procedure call system.  It
isn't necessarily remote.  Different modules can be registered for different
types of requests, and the requests may be handled either locally or remotely.
The caller does not know whether requests are handled locally or forwarded to
a remote server, it just gets asynchronous notification when a response is
available.

The requests and responses are ellis nodes that are automatically encoded
and decoded into whatever format is needed.

## Warning

This has just been migrated out of Ellis into a separate module, and needs
some work before it will compile, and even more work before it can be used.

## Build prerequisites

#### Build tools

Same as ellis.  See Project Ellis for more info: *meson* and *ninja*.

#### Libraries

* *ellis*
- *boost-asio*
- *boost-system*
- *nghttp2* (>= 1.18.0). If you need to compile, use these flags for
  configure:
  *--with-jemalloc --enable-asio-lib*
  Note that *--with-jemalloc* is technically optional but will improve
  performance.
- *openssl* (>= 1.0.2). (needed by nghttp2)

## Build instructions

Generally the same as ellis.  There are helpful hints in the project ellis
README file.  You'll need to build ellis first.

#### First time builds, including building ellis

```
export MYOPT=$HOME/opt
export LD_LIBRARY_PATH=\
$MYOPT/lib:$MYOPT/lib/x86_64-linux-gnu
export PKG_CONFIG_PATH=\
$MYOPT/lib/pkgconfig:\
$MYOPT/lib/x86_64-linux-gnu/pkgconfig
pushd ../ellis && meson --prefix $MYOPT build && ninja -C build install && popd
meson --prefix $MYOPT build
ninja -C build
```

#### Rebuilding

To rebuild at any time, you just need to rerun the last `ninja` command:

```
ninja -C build
```

#### Before checking in

```
ninja -C build test check
```
