
// *****************************************************************************
// Private functions implementation
// *****************************************************************************

void taskHeartbeat_Init(unsigned portBASE_TYPE uxNumberToCreate)
{
    xCoRoutineCreate(prvMainCoRoutine, crf_HEART_BEAT_PRIORITY, crfFLASH_INDEX);
}

/*
    Process the heartbeat. This is done in the main event loop (as
    opposed to an interrupt) so we can see if the App has locked up.
*/
void taskHeartbeat_Execute(void)
{
    portENTER_CRITICAL();
    {
        IO_RB15_Toggle();        //Toggle signal
    }
    portEXIT_CRITICAL();
}

/*****************************************************************************

    FreeRTOS Task implementation: Co-routine running heart beat

 *****************************************************************************/

void prvMainCoRoutine(CoRoutineHandle_t xHandle, unsigned portBASE_TYPE uxIndex)
{
    /* Co-routines MUST start with a call to crSTART. */
    crSTART(xHandle);

    for (;;)
    {
        crDELAY(xHandle, Time_MillisecondsToTicks(1000));

        taskHeartbeat_Execute();
    }

    /* Co-routines MUST end with a call to crEND. */
    crEND();
}
