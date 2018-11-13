
// *****************************************************************************
// Private functions implementation
// *****************************************************************************

static void taskHeartbeat_Init(unsigned portBASE_TYPE uxNumberToCreate)
{
    xCoRoutineCreate(prvMainCoRoutine, crf_HEART_BEAT_PRIORITY, crfFLASH_INDEX);
}

/*
    Process the heartbeat. This is done in the main event loop (as
    opposed to an interrupt) so we can see if the App has locked up.
*/
static void taskHeartbeat_Execute(void)
{
    portENTER_CRITICAL();
    {
        IO_RB15_Toggle();        //Toggle signal
    }
    portEXIT_CRITICAL();
}
