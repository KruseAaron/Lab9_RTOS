#ifndef HEART_BEAT_H
#define	HEART_BEAT_H

#ifdef	__cplusplus
extern "C" {
#endif

    extern void taskHeartbeat_Init(unsigned portBASE_TYPE uxPriority);
    extern void taskHeartbeat_Execute(void);
    extern void prvMainCoRoutine(CoRoutineHandle_t xHandle, unsigned portBASE_TYPE uxIndex);

#ifdef	__cplusplus
}
#endif

#endif	/* HEART_BEAT_H */

