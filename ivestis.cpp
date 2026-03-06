#include "ivestis.h"
#include <cctype>

bool arTikRaides(const std::string& tekstas) {

    for (char c : tekstas) {
        if (!isalpha(c)) {
            return false;
        }
    }

    return true;
}