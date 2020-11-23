#include "bloom.h"

namespace std {

BloomFilter::BloomFilter(int filter_size) {

  //dynamically allocated uint64 array as bloom filter
  filter_ = new uint64[filter_size];

  //clearing filter
  for(int i = 0; i < filter_size;i++) {
    filter_[i] = 0;
  }

  filter_count_ = 0;
  filter_size_ = filter_size;
  filter_bits_ = filter_size << DIV_64_SHIFT;
}

BloomFilter::~BloomFilter() {
  delete[] filter_;
}

void BloomFilter::add_string(string str) {
  uint64 hashed_val = CityHash64(str.data(), str.length());
  //bit_on represents which bit index should be set to 1
  uint64 bit_on = hashed_val % filter_bits_;
  //calculates which array element in filter_ holds the bit_on index
  uint64 filter_index = bit_on >> DIV_64_SHIFT;
  //1 gets left shifted to the corresponding index
  //bit_on - (filter_index << DIV_64_SHIFT) localizes the bit to the array index
  filter_[filter_index] |= 1 << (bit_on - (filter_index << DIV_64_SHIFT));
  filter_count_ += 1;
}

bool BloomFilter::lookup(string str) {
  uint64 hashed_val = CityHash64(str.data(), str.length());
  //bit_on represents which bit index should be set to 1
  uint64 bit_on = hashed_val % filter_bits_;
  //calculates which array element in filter_ holds the bit_on index
  uint64 filter_index = bit_on >> DIV_64_SHIFT;
  //1 gets left shifted to the corresponding index
  //bit_on - (filter_index << DIV_64_SHIFT) localizes the bit to the array index
  return (filter_[filter_index] &
          (1 << (bit_on - (filter_index << DIV_64_SHIFT)))) != 0;
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