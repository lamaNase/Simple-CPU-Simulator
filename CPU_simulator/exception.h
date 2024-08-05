#pragma once

#include <exception>
#include <string>

class InstructionValidationException : public std::exception {
private:
    std::string message;
public:
    InstructionValidationException(const std::string msg) : message(msg) {}
    const char* what() const noexcept override;
};
