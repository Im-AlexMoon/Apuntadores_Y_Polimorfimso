/**
 * @file TemplateClass.cpp
 * @brief Implementación de TemplateClass.
 * @date YYYY-MM-DD
 */

#include "TemplateClass.h"
#include <iostream>

TemplateClass::TemplateClass() : data_(0) {}

TemplateClass::~TemplateClass() {}

void TemplateClass::doSomething() const {
    std::cout << "Doing something, data_=" << data_ << std::endl;
}
