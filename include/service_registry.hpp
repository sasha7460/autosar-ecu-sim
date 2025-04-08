//File: include/service_registry.hpp
#pragma once
#include <string>
#include <unordered_map>
#include <mutex>
#include<memory>
#include<condition_variable>

class ServiceRegistry{
    public:
        static ServiceRegistry& instance();

        void registerService(const std::string& name, void* servicePtr);
        void* discoverService(const std::string& name);
    
    private:
        std::unordered_map<std::string, void*> services_;
        std::mutex mutex_;
        std::condition_variable cond_;

};