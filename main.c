#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

size_t binLen(long long i) {
    size_t x = 0;
    while (i != 0) {
        i/=2;x++;
    }
    return x;
}

void s(char* a, char* b) {
    char h = *a;
    *a = *b;
    *b = h;
}

void reverseArr(char array[]) {
    size_t l = strlen(array)-1;
    for (size_t i = 0; i < strlen(array)/2; i++) {
        s(&array[i], &array[l]);
        l--;
    }
}

void cleanArray(char array[]) {
    for (size_t i = 0; i < 1<<8; i++) {
        if ((array[i] != '0') && (array[i] != '1')) {
            array[i] = '\0';
        }
    }
}

void decBin(char* bin, unsigned long long i, size_t bits) {
    for (size_t j = 0; j < bits-binLen(i); j++) {
        bin[j] = 0x30;
    }
    char binChain[1<<8];
    while (i != 0) {
        char y[2];
        sprintf(y, "%lld", i%2);
        strcat(binChain, y);
        i/=2;
    }
    reverseArr(binChain);
    strcat(bin, binChain);
    cleanArray(bin);
}

unsigned long long ChainToLong(char finalChain[], size_t len) {
    unsigned long long result = 0, base = 1;
    for (size_t i = len; i > 0; i--) {
        if (finalChain[i] == 0x031) {
            result += base;
        }
        base *= 2;
    }
    return result;
}

unsigned long long Builder(long long firstValue, long long secondValue) {
    char firstChainBin[1<<8] = {0x0};
    decBin(firstChainBin, firstValue, 32);

    char secondChainBin[1<<8] = {0x0};
    decBin(secondChainBin, secondValue, 32);

    char finalChain[1<<16];
    strcat(finalChain, firstChainBin);
    strcat(finalChain, secondChainBin);
    //printf("%s", finalChain);
    return ChainToLong(finalChain, 63);
}

void Reverse(char* chain) {
    char fc[1<<8] = {0x0};

    for (size_t i = 0; i <= 31; i++) {
        fc[i] = chain[i];
    }
    
    unsigned long long fv = ChainToLong(fc, 31);
    char sc[1<<8];
    for (size_t j = 32; j <= 63; j++) {
        char tmp[2];
        sprintf(tmp, "%c", chain[j]);
        strcat(sc, tmp);
    }
    unsigned long long sv = ChainToLong(sc, 31);
    printf("\nFV: %lld | SV: %lld\n", fv, sv);
}

int main() {
    unsigned long long result = Builder(69, 420); // Values
    printf("%lld", result);
    char buf[2<<16] = {0x0};
    decBin(buf, result, 64);
    Reverse(buf);
    return 0;
}
