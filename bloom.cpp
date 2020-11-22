#include "bloom.h"
#include "city.h"
#include <bitset>

namespace std {

BloomFilter::BloomFilter() {
 filter_ = std::make_pair(0,0);
 filter_count_ = 0;
}

BloomFilter::~BloomFilter() { }

void BloomFilter::add_string(string str) {
 uint128 hashed_val = CityHash128(str.data(), str.length());
 uint64 lower64 = Uint128Low64(hashed_val);
 uint64 upper64 = Uint128High64(hashed_val);

 filter_.first = filter_.first | lower64;
 filter_.second = filter_.second | upper64;
 filter_count_ += 1;
}

bool BloomFilter::lookup(string str) {
 uint128 hashed_val = CityHash128(str.data(), str.length());
 uint64 lower64 = Uint128Low64(hashed_val);
 uint64 upper64 = Uint128High64(hashed_val);
 bool condition_lower = (filter_.first & lower64) == lower64;
 bool condition_upper = (filter_.second & upper64) == upper64;
 if(condition_lower && condition_upper) {
     return true;
 }
 return false;
}

size_t BloomFilter::filter_count() {
    return filter_count_;
}

string BloomFilter::expose_filter() {
    std::string s = std::bitset< 64 >( filter_.first ).to_string();
    s.append(std::bitset< 64 >( filter_.second ).to_string());
    return s;
}
}