#pragma once

#include <pybind11/pybind11.h>

class PluginInterface {
public:
    virtual ~PluginInterface() = default;

    virtual int aio_read(const pybind11::args& args) = 0;
    virtual int aio_write(const pybind11::args& args) = 0;
    virtual int deepspeed_memcpy(const pybind11::args& args) = 0;
};