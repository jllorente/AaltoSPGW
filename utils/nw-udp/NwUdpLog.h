/*----------------------------------------------------------------------------*
 *                                                                            *
 * Copyright (c) 2010-2011 Amit Chawre                                        *
 * All rights reserved.                                                       *
 *                                                                            *
 * Redistribution and use in source and binary forms, with or without         *
 * modification, are permitted provided that the following conditions         *
 * are met:                                                                   *
 *                                                                            *
 * 1. Redistributions of source code must retain the above copyright          *
 *    notice, this list of conditions and the following disclaimer.           *
 * 2. Redistributions in binary form must reproduce the above copyright       *
 *    notice, this list of conditions and the following disclaimer in the     *
 *    documentation and/or other materials provided with the distribution.    *
 * 3. The name of the author may not be used to endorse or promote products   *
 *    derived from this software without specific prior written permission.   *
 *                                                                            *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR       *
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  *
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.    *
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,           *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT   *
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  *
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY      *
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT        *
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF   *
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.          *
 *----------------------------------------------------------------------------*/

/**
 * @file NwUdpLog.h
 * @brief This files defines UDP entity.
*/

#include <stdio.h>
#include "NwTypes.h"
#include "NwLog.h"
#include "NwLogMgr.h"

#ifndef __NW_UDP_LOG_H__
#define __NW_UDP_LOG_H__

#define NW_UDP_LOG( _logLevel, ...)                                     \
  do {                                                                  \
    char _logStr[1024];                                                 \
    if(_gLogMgr.logLevel >= _logLevel)                                  \
    {                                                                   \
      snprintf(_logStr, 1024, __VA_ARGS__);                             \
      nwLogMgrLog(&_gLogMgr, " NW-UDP  ", _logLevel, (char*)basename(__FILE__), __LINE__, _logStr);\
    }                                                                   \
  } while(0)

#define NW_UDP_ENTER()                                              \
  do {                                                                  \
    NW_UDP_LOG(NW_LOG_LEVEL_DEBG, "Entering '%s'", __func__);       \
  } while(0)

#define NW_UDP_LEAVE()                                              \
  do {                                                                  \
    NW_UDP_LOG(NW_LOG_LEVEL_DEBG, "Leaving '%s'", __func__);       \
  } while(0)

/*---------------------------------------------------------------------------
 * IPv4 logging macros
 *--------------------------------------------------------------------------*/
#define NW_IPV4_ADDR                            "%u.%u.%u.%u"
#define NW_IPV4_ADDR_FORMAT(__addr)             (NwU8T)((__addr) & 0x000000ff),        \
                                                (NwU8T)(((__addr) & 0x0000ff00) >> 8 ), \
                                                (NwU8T)(((__addr) & 0x00ff0000) >> 16), \
                                                (NwU8T)(((__addr) & 0xff000000) >> 24)

#define NW_IPV4_ADDR_FORMATP(__paddr)           (NwU8T)(*((NwU8T*)(__paddr)) & 0x000000ff),     \
                                                (NwU8T)(*((NwU8T*)(__paddr + 1)) & 0x000000ff), \
                                                (NwU8T)(*((NwU8T*)(__paddr + 2)) & 0x000000ff), \
                                                (NwU8T)(*((NwU8T*)(__paddr + 3)) & 0x000000ff)

#endif
