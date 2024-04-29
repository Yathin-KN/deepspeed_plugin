#include "plugin_interface.h"
#include <map>
#include <iostream>
using namespace std;
class MyPlugin : public PluginInterface {
public:
    int aio_read(const pybind11::args& args) override {
        cout<<"Performing reading through plugin1"<<'\n';
        return 0;
    }

    int aio_write(const pybind11::args& args) override {
        return 0;
    }

    int deepspeed_memcpy(const pybind11::args& args) override {
        return 0;
    }
};

extern "C" PluginInterface* create_plugin(const std::map<std::string, std::string>& args) {
    return new MyPlugin();
}