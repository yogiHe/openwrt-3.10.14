/*
 * dbgPrint.h
 *
 * This module contains the API for debug print.
 *
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef DBGPRINT_H
#define DBGPRINT_H

#ifdef __cplusplus
extern "C"
{
#endif
#define DBG_HELP_MSG "set the level of the debug message. \n             0: ERROR \n             1: WARNING \
    \n             2: INFO \n             3: INFO_LOW \n             4: VERBOSE"

typedef enum debug_level
{
    PRINT_LEVEL_ERROR,
    PRINT_LEVEL_WARNING,
    PRINT_LEVEL_INFO,
    PRINT_LEVEL_INFO_LOWLEVEL,
    PRINT_LEVEL_VERBOSE
}DBG_L;

typedef enum debug_switch
{
    DBG_ON,
    DBG_OFF,
}DBG_SWITCH;

//#define PRINT_LEVEL PRINT_LEVEL_INFO
//#define PRINT_LEVEL PRINT_LEVEL_VERBOSE

void dbg_print(DBG_L printf_level, const char *fmt, ...);
int set_logprint(int argc, char *argv[], char *ret_msg);
int LogPrintInit(void);
int LogPrintOn(void);
int LogPrintOff(void);


#ifdef __cplusplus
}
#endif

#endif /* DBGPRINT_H */