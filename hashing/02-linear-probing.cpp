#include "linear-probing.h"
#include "hashing.h"

/*
Linear probing:
Loading factor = k = n/size
important -> k <= 0.5

Successful search = 1/k*log(1/(1-k))
Unsuccessful search = 1/(1-k)
*/
