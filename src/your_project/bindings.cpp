#include <torch/extension.h>
#include <pybind11/pybind11.h>
#include "plugin_interface.h"
#include "plugin_loader.h"

class PyPluginInterface : public PluginInterface {
public:
    using PluginInterface::PluginInterface; 

    int aio_read(const pybind11::args& args) override {
        PYBIND11_OVERRIDE_PURE(
            int,                  
            PluginInterface,    
            aio_read,             
            args                    
        );
    }


    int aio_write(const pybind11::args& args) override {
        PYBIND11_OVERRIDE_PURE(
            int,
            PluginInterface,
            aio_write,
            args
        );
    }

    int deepspeed_memcpy(const pybind11::args& args) override {
        PYBIND11_OVERRIDE_PURE(
            int,
            PluginInterface,
            deepspeed_memcpy,
            args
        );
    }
};

PYBIND11_MODULE(_C, m) {
    py::class_<PluginInterface, PyPluginInterface>(m, "PluginInterface")
        .def(py::init<>())
        .def("aio_read", &PluginInterface::aio_read)
        .def("aio_write", &PluginInterface::aio_write)
        .def("deepspeed_memcpy", &PluginInterface::deepspeed_memcpy);

    py::class_<PluginLoader>(m, "PluginLoader")
        .def(py::init<>())
        .def("register_plugin", &PluginLoader::register_plugin)
        .def("get_plugin", &PluginLoader::get_plugin, py::return_value_policy::reference);
}