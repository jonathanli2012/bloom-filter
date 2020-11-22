#include "bloom.h"
#include "city.h"
#include <iostream>

using namespace std;

int main() {
  BloomFilter *new_b = new BloomFilter(128);
  new_b->add_string("goran");
  new_b->add_string("jonathan");
  new_b->add_string("shalini");
  new_b->add_string("arvind");
  new_b->add_string("connor");
  new_b->add_string("woody");
  new_b->add_string("cow");
  new_b->add_string("cat");
  new_b->add_string("dog");
  new_b->add_string("sheep");
  new_b->add_string("gun");
  new_b->add_string("fat");
  std::cout << "\nfilter print: " << new_b->expose_filter();

  std::cout << "\nexisting names lookup\n";
  std::cout << "filter count: " << new_b->filter_count() << "\n";
  std::cout << "lookup - goran: " << new_b->lookup("goran") << "\n";
  std::cout << "lookup - jonathan: " << new_b->lookup("jonathan") << "\n";
  std::cout << "lookup - shalini: " << new_b->lookup("shalini") << "\n";
  std::cout << "lookup - arvind: " << new_b->lookup("arvind") << "\n";
  std::cout << "lookup - connor: " << new_b->lookup("connor") << "\n";
  std::cout << "lookup - woody: " << new_b->lookup("woody") << "\n";
  std::cout << "lookup - cow: " << new_b->lookup("cow") << "\n";
  std::cout << "lookup - cat: " << new_b->lookup("cat") << "\n";
  std::cout << "lookup - dog: " << new_b->lookup("dog") << "\n";
  std::cout << "lookup - sheep: " << new_b->lookup("sheep") << "\n";
  std::cout << "lookup - gun: " << new_b->lookup("gun") << "\n";
  std::cout << "lookup - fat: " << new_b->lookup("fat") << "\n";

  std::cout << "\nnonexisting names lookup\n";
  std::cout << "lookup - eric: " << new_b->lookup("eric") << "\n";
  std::cout << "lookup - kushal: " << new_b->lookup("kushal") << "\n";
  std::cout << "lookup - antioch: " << new_b->lookup("antioch") << "\n";
  std::cout << "lookup - alex: " << new_b->lookup("alex") << "\n";
  std::cout << "lookup - vivian: " << new_b->lookup("vivian") << "\n";
  std::cout << "lookup - potato: " << new_b->lookup("potato") << "\n";
  std::cout << "lookup - spot: " << new_b->lookup("spot") << "\n";
  std::cout << "lookup - mayo: " << new_b->lookup("mayo") << "\n";
  std::cout << "lookup - water: " << new_b->lookup("water") << "\n";
  std::cout << "lookup - waffles: " << new_b->lookup("waffles") << "\n";
  std::cout << "lookup - rifle: " << new_b->lookup("rifle") << "\n";
  std::cout << "lookup - swim: " << new_b->lookup("swim") << "\n";
  std::cout << "lookup - steak: " << new_b->lookup("steak") << "\n";
  std::cout << "lookup - cpp: " << new_b->lookup("cpp") << "\n";

  delete new_b;
  return 0;
}