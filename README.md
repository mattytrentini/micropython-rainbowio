# micropython-rainbowio

A MicroPython native module to implement Adafruit's
[rainbowio.colorwheel](https://docs.circuitpython.org/en/latest/shared-bindings/rainbowio/index.html).

## How to Build (x64)

Ensure that you have appropriate build tools configured - or use the published
[build-micropython-natmod-unix](https://hub.docker.com/r/micropython/build-micropython-natmod-unix)
container and invoke make on the `rainbow` directory from the root of the repository:

```bash
> docker run -ti --rm -v $(pwd):/code -w /code micropython/build-micropython-natmod-unix make -C rainbowio
```

Note that the native module may be bound to a particular version of MicroPython
(see [Versioning and compatibility of .mpy
files](https://docs.micropython.org/en/latest/reference/mpyfiles.html#versioning-and-compatibility-of-mpy-files)
for more details).

To target a different MicroPython verison, the `micropython` submodule
will need to be updated. Currently v1.22.2 is used.

## How to Build (other platforms)

Building for other platforms should follow the same process but with appropriate build tools for the desired platform.

The architecture will need to be specified with the `ARCH` build option. For example, to build for ESP32:

```bash
> make -C rainbowio ARCH=xtensawin
```

See [Supported features and
limitations](https://docs.micropython.org/en/latest/develop/natmod.html#supported-features-and-limitations)
for a list of the supported architectures.

## Deployment

Ensure the built `rainbow.mpy` file is available on the path of your desired MicroPython instance.

For example, starting the MicroPython Unix port with `rainbowio.mpy` in the current directory:

```bash
> cd rainbowio
> docker run -ti --rm -v $(pwd):/code -w /code micropython/unix
MicroPython v1.22.0 on 2023-12-29; linux [GCC 12.2.0] version
Use Ctrl-D to exit, Ctrl-E for paste mode
>>> from rainbowio import colorwheel
>>> for color in range(5):
...     print(hex(colorwheel(color)))
0xff0000
0xfc0300
0xf90600
0xf60900
0xf30c00
```
