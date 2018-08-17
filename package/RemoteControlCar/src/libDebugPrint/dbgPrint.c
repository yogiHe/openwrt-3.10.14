/*
 * dbgPrint.c
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

/*********************************************************************
 * INCLUDES
 */
#include <stdio.h>
#include <stdarg.h>

#include "dbgPrint.h"
#include <fcntl.h>
#include <unistd.h>

#define BEIJINGLOCALTIME  28800
#define LOG_PATH "/tmp/log.txt"

/*********************************************************************
 * MACROS
 */

/*********************************************************************
 * LOCAL VARIABLE
 */

/*********************************************************************
 * LOCAL FUNCTIONS
 */

/*********************************************************************
 * API FUNCTIONS
 */
static DBG_L g_emdbg_level = PRINT_LEVEL_WARNING;
static DBG_SWITCH g_emdbg_swith = DBG_OFF;

int set_dbg_level(DBG_L level)
{
    if((level > PRINT_LEVEL_VERBOSE) || (level < PRINT_LEVEL_ERROR))
    {
        return 0;
    }
    g_emdbg_level = level;
    return 1;
}

static FILE *g_File = NULL;
int write_dbg2file(char *fmt)
{
    if(g_emdbg_swith == DBG_OFF)
        return -1;

    if(g_File == NULL)
        return -1;

    fseek(g_File, 0, SEEK_END);
    fwrite(fmt, 1, strlen(fmt), g_File);
    return 0;
}
/**************************************************************************************************
 * @fn          dbgPrint
 *
 * @brief       This function checks the print level and prints if required.
 *
 * input parameters
 *
 * @param       simpleDesc - A pointer to the simpleDesc descriptor to register.
 *
 * output parameters
 *
 * None.
 *
 * @return      None.
 **************************************************************************************************
 */
void dbg_print(DBG_L print_level, const char *fmt, ...)
{
    char buff[32];
    time_t t = time(NULL);
    char cmd[1024] = {0};
    char cmd_time[1024] = {0};

    if (print_level > g_emdbg_level)
    {
        return;
    }
    else
    {
        va_list argp;
        va_start(argp, fmt);
        ctime_r(&t,buff);
        buff[strlen(buff)-1] = '\0';
        snprintf(cmd, sizeof(cmd), "[%s] %s", buff, fmt);
        vprintf(cmd, argp);
        vsnprintf(cmd_time, sizeof(cmd_time), cmd, argp);
        write_dbg2file(cmd_time);
        va_end(argp);
    }
}

int LogPrintInit(void)
{
    int fd;
    fd = open(LOG_PATH, O_CREAT | O_RDWR, 0644);
    if (fd < 0)
    {
        return -1;
    }
    close(fd);
    LogPrintOn();
    return 0;
}

int LogPrintOn(void)
{
    if(g_emdbg_swith == DBG_ON)
        return 0;

    g_emdbg_swith = DBG_ON;

    g_File = fopen(LOG_PATH, "rb+");
    if(g_File == NULL)
    {
        return -1;
    }
    return 0;
}

int LogPrintOff(void)
{
    g_emdbg_swith = DBG_OFF;
    fclose(g_File);
    return 0;
}


