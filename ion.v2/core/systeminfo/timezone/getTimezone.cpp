#include "getTimezone.hpp"

std::string getTimezone::Timezone()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::string timezone = std::string(AY_OBFUSCATE("UTC"));

    return timezone;
}