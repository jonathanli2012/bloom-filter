#include "bloom.h"
#include "city.h"
#include <bitset>

#define FILTER_BITS 256
#define FILTER_INDEX_0 0
#define FILTER_INDEX_1 63
#define FILTER_INDEX_2 127
#define FILTER_INDEX_3 191
#define FILTER_SUB_SIZE_1 64
#define FILTER_SUB_SIZE_2 128
#define FILTER_SUB_SIZE_3 192

namespace std {

BloomFilter::BloomFilter() {
  filter_ = std::make_pair(std::make_pair(0, 0), std::make_pair(0, 0));
  filter_count_ = 0;
}

BloomFilter::~BloomFilter() {}

void BloomFilter::add_string(string str) {
  uint64 hashed_val = CityHash64(str.data(), str.length());
  uint64 bit_on = hashed_val % FILTER_BITS;

  if (bit_on < FILTER_SUB_SIZE_1) {
    filter_.first.first |= 1 << bit_on;
  } else if (bit_on < FILTER_SUB_SIZE_2) {
    filter_.first.second |= 1 << (bit_on - FILTER_SUB_SIZE_1);
  } else if (bit_on < FILTER_SUB_SIZE_3) {
    filter_.second.first |= 1 << (bit_on - FILTER_SUB_SIZE_2);
  } else {
    filter_.second.second |= 1 << (bit_on - FILTER_SUB_SIZE_3);
  }

  filter_count_ += 1;
}

bool BloomFilter::lookup(string str) {
  uint64 hashed_val = CityHash64(str.data(), str.length());
  uint64 bit_on = hashed_val % FILTER_BITS;

  if (bit_on < FILTER_SUB_SIZE_1) {
    return (filter_.first.first & (1 << bit_on)) > 0;
  } else if (bit_on < FILTER_SUB_SIZE_2) {
    return (filter_.first.second & (1 << (bit_on - FILTER_SUB_SIZE_1))) > 0;
  } else if (bit_on < FILTER_SUB_SIZE_3) {
    return (filter_.second.first & (1 << (bit_on - FILTER_SUB_SIZE_2))) > 0;
  } else {
    return (filter_.second.second & (1 << (bit_on - FILTER_SUB_SIZE_3))) > 0;
  }
  return false;
}
size_t BloomFilter::filter_count() { return filter_count_; }

string BloomFilter::expose_filter() {
  std::string s = std::bitset<64>(filter_.first.first).to_string();
  s.append(std::bitset<64>(filter_.first.second).to_string());
  s.append(std::bitset<64>(filter_.second.first).to_string());
  s.append(std::bitset<64>(filter_.second.second).to_string());
  return s;
}
} // namespace std