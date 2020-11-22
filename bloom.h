#include <mutex>

#include <stdlib.h>  // for size_t.
#include <stdint.h>
#include <utility>

typedef uint8_t uint8;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef std::pair<uint64, uint64> uint128;
typedef std::pair<uint128, uint128> filter_pair;
namespace std {

class BloomFilter {

 public:
  BloomFilter();
  ~BloomFilter();
  bool lookup(string str);
  void add_string(string str);
  size_t filter_count();
  string expose_filter();

 protected:
  size_t filter_count_;
  filter_pair filter_;
};
}