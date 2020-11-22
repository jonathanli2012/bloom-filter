#include <mutex>

#include <stdint.h>
#include <stdlib.h> // for size_t.
#include <utility>

typedef uint8_t uint8;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef std::pair<uint64, uint64> uint128;
typedef std::pair<uint128, uint128> filter_pair;
typedef std::array<uint64, 4> filter_256;

namespace std {

class BloomFilter {

public:
  BloomFilter(int filter_size);
  ~BloomFilter();
  bool lookup(string str);
  void add_string(string str);
  size_t filter_count();
  string expose_filter();

protected:
  size_t filter_count_;
  uint64 *filter_;
  int filter_size_;
  int filter_bits_;
};
} // namespace std