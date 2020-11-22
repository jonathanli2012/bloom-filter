#include "city.h"
#include "bloom.h"
#include <iostream>

using namespace std;

int main() {
    BloomFilter* new_b = new BloomFilter();
    std::cout << "\nfilter print: " << new_b->expose_filter();
    new_b->add_string("goran");
    std::cout << "\nfilter print: " << new_b->expose_filter();
    new_b->add_string("jonathan");
    std::cout << "\nfilter print: " << new_b->expose_filter();
    new_b->add_string("shalini");
    std::cout << "\nfilter print: " << new_b->expose_filter();
    new_b->add_string("arvind");
    std::cout << "\nfilter print: " << new_b->expose_filter();
    new_b->add_string("connor");
    std::cout << "\nfilter print: " << new_b->expose_filter();
    new_b->add_string("woody");
    std::cout << "\nfilter print: " << new_b->expose_filter();

    std::cout << "\nexisting names lookup\n";
    std::cout << "filter count: " << new_b->filter_count() << "\n";
    std::cout << "lookup - goran: " << new_b->lookup("goran") << "\n";
    std::cout << "lookup - jonathan: " << new_b->lookup("jonathan") << "\n";
    std::cout << "lookup - shalini: " << new_b->lookup("shalini") << "\n";
    std::cout << "lookup - arvind: " << new_b->lookup("arvind") << "\n";
    std::cout << "lookup - connor: " << new_b->lookup("connor") << "\n";
    std::cout << "lookup - woody: " << new_b->lookup("woody") << "\n";

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
    return 0;
}