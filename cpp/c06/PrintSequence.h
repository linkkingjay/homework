// Prints the contents of any sequence.
#ifndef PRINTSEQUENCE_H
#define PRINTSEQUENCE_H
#include <algorithm>
#include <iostream>
#include <iterator>
template<typename Iter>
void print(Iter first, Iter last, const char* nm = "",
	   const char* sep = "\n",
	   std::ostream& os = std::cout) {
    if (nm != 0 && *nm != '\0')
	os << nm << ": " << sep;
    typedef typename
	std::iterator_traits<Iter>::value_type T;
    std::copy(first, last,
	    std::ostream_iterator<T>(std::cout, sep));
    os << std::endl;
}
#endif // PRINTSEQUENCE_H ///:~
