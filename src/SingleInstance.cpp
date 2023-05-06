#include "SingleInstance.h"

SingleInstance* SingleInstance::instance = nullptr;
std::mutex SingleInstance::mtx;
