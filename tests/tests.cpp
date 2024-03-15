#include "tests.h"

#include <iostream>
#include <cmath>

bool thAssert(bool v, const std::string & msg, const std::string & additional_msg, uint32_t line)
{
    if (!v)
    {
        std::cout << "  Assert '" << msg;
        if (!additional_msg.empty())
            std::cout << "': '" << additional_msg;

        std::cout << "', Line: " << line << "." << std::endl;
    }

    return v;
}

void thMessage(const std::string & msg, uint32_t line)
{
    std::cout << "  Msg: '" << msg << "', Line: " << line << "." << std::endl;
}
