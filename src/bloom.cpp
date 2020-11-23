#include "bloom.h"

#define DIV_64_SHIFT 6

namespace std {

BloomFilter::BloomFilter(int filter_size) {
  filter_ = new uint64[filter_size];
  filter_count_ = 0;
  filter_size_ = filter_size;
  filter_bits_ = filter_size << DIV_64_SHIFT;
}

BloomFilter::~BloomFilter() {}

void BloomFilter::add_string(string str) {
  uint64 hashed_val = CityHash64(str.data(), str.length());
  uint64 bit_on = hashed_val % filter_bits_;
  uint64 filter_index = bit_on >> DIV_64_SHIFT;
  filter_[filter_index] |= 1 << (bit_on - (filter_index << DIV_64_SHIFT));
  filter_count_ += 1;
}

bool BloomFilter::lookup(string str) {
  uint64 hashed_val = CityHash64(str.data(), str.length());
  uint64 bit_on = hashed_val % filter_bits_;
  uint64 filter_index = bit_on >> DIV_64_SHIFT;
  return (filter_[filter_index] &
          (1 << (bit_on - (filter_index << DIV_64_SHIFT)))) > 0;
}

size_t BloomFilter::filter_count() { return filter_count_; }

string BloomFilter::expose_filter() {
  std::string s = std::bitset<64>(filter_[0]).to_string();
  for (int i = 1; i < filter_size_; i++) {
    s.append(std::bitset<64>(filter_[i]).to_string());
  }
  return s;
}

size_t filter_ratio() {
  return 0;
}
} // namespace std