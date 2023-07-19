#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <netinet/in.h>

uint32_t readAndSwapData(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        return 0;
    }

    uint32_t data;

    if (fread(&data, sizeof(uint32_t), 1, fp) != 1) {
        fclose(fp);
        return 0;
    }

    fclose(fp);

    return ntohl(data);
}

uint32_t addData(uint32_t num1, uint32_t num2) {
    return num1 + num2;
}

int main(int argc, char* argv[]) {
    uint32_t num1 = readAndSwapData(argv[1]);
    uint32_t num2 = readAndSwapData(argv[2]);

    uint32_t sum = addData(num1, num2);
    printf("%" PRIu32 "(0x%" PRIx32 ") + %" PRIu32 "(0x%" PRIx32 ") = %" PRIu32 "(0x%" PRIx32 ")\n",
           num1, num1, num2, num2, sum, sum);

    return 0;
}
