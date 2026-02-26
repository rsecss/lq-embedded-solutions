#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "bsp_system.h"

#ifdef __cplusplus
extern "C" {
#endif

void scheduler_init(void);
void scheduler_run(void);

#ifdef __cplusplus
}
#endif

#endif /* SCHEDULER_H */
