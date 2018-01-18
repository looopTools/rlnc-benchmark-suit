#include "../result.hpp"

// STDLIB includes:
#include <cstdint>

namespace rlnc_benchmark_suit
{
namespace encoder
{
    /// g = Generation size
    /// k = symbol size
    /// r = redunancy symbols
    /// systematic = Is systematic on or off
    template<typename Code>
    rlnc_benchmark_suit::result block_encoder_benchmark(uint32_t g,
                                                        uint32_t k, uint32_t r,
                                                        bool systematic)
    {
        // Seed the random generator
        srand(static_cast<uint32_t>(time(0)));


    }
}
}
