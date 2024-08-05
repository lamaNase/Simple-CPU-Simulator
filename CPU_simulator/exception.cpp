#include "exception.h"

const char* InstructionValidationException::what() const noexcept {
        return message.c_str();
}
