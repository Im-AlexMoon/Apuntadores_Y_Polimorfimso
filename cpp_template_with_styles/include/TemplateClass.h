#ifndef TEMPLATECLASS_H
#define TEMPLATECLASS_H

/**
 * @file TemplateClass.h
 * @brief Definición de TemplateClass.
 * @date YYYY-MM-DD
 * @author Autor
 */

#pragma once

#include <string>

class TemplateClass {
public:
    TemplateClass();
    ~TemplateClass();

    void doSomething() const;

private:
    int data_;
};

#endif // TEMPLATECLASS_H
