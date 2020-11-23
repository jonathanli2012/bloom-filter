#include <mutex>
#include <stdint.h>
#include <stdlib.h>
#include <bitset>
#include "cityhash/city.h"

typedef uint64_t uint64;

namespace std {

class BloomFilter {

public:
  BloomFilter(int filter_size);
  ~BloomFilter();
  bool lookup(string str);
  void add_string(string str);
  size_t filter_count();
  string expose_filter();
  size_t filter_ratio();

protected:
  size_t filter_count_;
  uint64 *filter_;
  int filter_size_;
  int filter_bits_;
};
} // namespace std