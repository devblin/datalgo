#ifndef QUADPROBE
#define QUADPROBE

int probe(int index, int i)
{
    return (index + (i * i)) % 10;
}

#endif