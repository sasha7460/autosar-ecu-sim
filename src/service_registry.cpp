//File: /src/service_registry.cpp
#include "../include/service_registry.hpp"
ServiceRegistry& ServiceRegistry::instance(){
    static ServiceRegistry registry;
    return registry;
}

void ServiceRegistry::registerService(const std::string& name, void* servicePtr){
    std::lock_guard<std::mutex> lock(mutex_);
    services_[name] = servicePtr;
    cond_.notify_all();
}

void* ServiceRegistry::discoverService(const std::string& name){
    std::unique_lock<std::mutex> lock(mutex_);
    cond_.wait(lock, [&] { return services_.find(name) != services_.end(); });
    return services_[name];
}