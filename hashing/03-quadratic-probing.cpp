#include "quadratic-probing.h"
#include "hashing.h"

/*
Quadratic probing:
Loading factor = k = n/size
important -> k <= 0.5

Successful search = log(1-k)/k
Unsuccessful search = 1/(1-k)
*/
