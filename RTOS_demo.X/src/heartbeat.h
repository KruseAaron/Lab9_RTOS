#ifndef HEART_BEAT_H
#define	HEART_BEAT_H

#ifdef	__cplusplus
extern "C" {
#endif

    extern void taskHeartbeat_Init(unsigned portBASE_TYPE uxPriority);
    extern void taskHeartbeat_Execute(void);

#ifdef	__cplusplus
}
#endif

#endif	/* HEART_BEAT_H */

