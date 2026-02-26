#ifndef FILTER_H
#define FILTER_H

#include "bsp_system.h"

#ifdef __cplusplus
extern "C" {
#endif

void limit_filter(uint32_t *data, int32_t size, uint32_t min_value, uint32_t max_value);
uint32_t median_filter(uint32_t *data, int size);
uint32_t average_filter(uint32_t *data, int size);
uint32_t adc_filter(uint32_t current_value);

#ifdef __cplusplus
}
#endif

#endif /* FILTER_H */


