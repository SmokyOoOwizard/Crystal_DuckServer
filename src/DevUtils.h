//
// Created by smoky on 1/3/2022.
//

#ifndef CRYSTAL_DUCKSERVER_DEVUTILS_H
#define CRYSTAL_DUCKSERVER_DEVUTILS_H

#include <iostream>

#define STUB(return_type, function_name, ...) void function_name(__VA_ARGS__) { \
    __pragma (message ("FIXME: Finish " #function_name "\t" __FILE__)) \
    std::cerr << "FIXME: Finish " #function_name << std::endl; \
 }

#define STUB_WITH_TYPE(return_type, return_value, function_name, ...) return_type function_name(##__VA_ARGS__) { \
    __pragma (message ("FIXME: Finish " #function_name "\t" __FILE__)) \
    std::cerr << "FIXME: Finish " #function_name << std::endl; \
    return return_value; \
 }

#endif //CRYSTAL_DUCKSERVER_DEVUTILS_H
