#pragma once

#include "../plugin_interface.h"
#include <map>

class Plugin1 : public PluginInterface {
public:
    Plugin1(const std::map<std::string, std::string>& args);

    int aio_read(const pybind11::args& args) override;
    int aio_write(const pybind11::args& args) override;
    int deepspeed_memcpy(const pybind11::args& args) override;
};