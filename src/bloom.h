#include <mutex>
#include <stdint.h>
#include <stdlib.h>
#include <bitset>
#include "cityhash/city.h"

/** @brief used to interface with cityhash types */
typedef uint64_t uint64;

/** @brief used to divide by 64 via logical shift */
#define DIV_64_SHIFT 6

namespace std {

class BloomFilter {

public:

  /**
   * @brief Constructor for BloomFilter type
   *
   * zeroes filter and associated filter metadata
   *
   * @param[in] filter_size - dynamically defines size of filter using
   * filter_size*64 bits.
   * filter_size must be < 67108864 //potentially 1048576
   * 
   * @return BloomFilter instance
   */
  BloomFilter(int filter_size);

  /**
   * @brief Destructor for BloomFilter type
   *
   * frees dynamically allocated memory for filter
   */
  ~BloomFilter();

  /**
   * @brief lookup a string in the bloom filter
   *
   * calls cityhash64() and checks the calculated filter_index from the hash
   * result
   *
   * @param[in] str
   * 
   * @return bool
   * true -> str may exist in the set
   * false -> str does not exist in the set
   */
  bool lookup(string str);

  /**
   * @brief Adds a string to the bloom filter
   *
   * calls cityhash64() and sets the calculated filter_index to 1 from the hash
   * result
   *
   * @param[in] str
   */
  void add_string(string str);

  /**
   * @brief filter_count
   * 
   * multiple calls to add_string with the same argument still increment this
   * counter
   * 
   * @return call count of add_string
   */
  size_t filter_count();

  /**
   * @brief creates filter string
   *
   * @return string representing the entire bloom filter in binary
   */
  string expose_filter();

  /**
   * @brief filter_ratio
   * 
   * @return bits filled with 1
   */
  size_t filter_ratio();

protected:

  /** @brief counts instances of add_string() calls */
  size_t filter_count_;

  /** @brief dynamically allocated uint64 array as bloom filter */
  uint64 *filter_;

  /** @brief filter_size represents length of filter array in elements */
  int filter_size_;

  /** @brief filter_bits represents length of filter in bits */
  int filter_bits_;
};
} // namespace std