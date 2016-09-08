/*----------------------------------------------------------------------------*
 *                                                                            *
 *                              n w - g t p v 2 c                             *
 *    G P R S   T u n n e l i n g    P r o t o c o l   v 2 c    S t a c k     *
 *                                                                            *
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
 * @file NwGtpv2cTrxn.h
 * @author Amit Chawre
 * @brief
 *
 * This header file contains required definitions and functions
 * prototypes used by gtpv2c transactions.
 *
 **/


#ifndef __NW_GTPV2C_TRXN_H__
#define __NW_GTPV2C_TRXN_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Constructotr
 */
NwGtpv2cTrxnT*
nwGtpv2cTrxnNew( NW_IN  NwGtpv2cStackT* pStack);

/**
 * Overloaded Constructotr
 */
NwGtpv2cTrxnT*
nwGtpv2cTrxnWithSeqNumNew( NW_IN  NwGtpv2cStackT* pStack,
                        NW_IN  NwU32T seqNum);

/**
 * Another overloaded constructor. Create transaction as outstanding
 * RX transaction for detecting duplicated requests.
 *
 * @param[in] thiz : Pointer to stack.
 * @param[in] teidLocal : Trxn teid.
 * @param[in] peerIp : Peer Ip address.
 * @param[in] peerPort : Peer Ip port.
 * @param[in] seqNum : Seq Number.
 * @return NW_GTPV2C_OK on success.
 */

NwGtpv2cTrxnT*
nwGtpv2cTrxnOutstandingRxNew( NW_IN  NwGtpv2cStackT* pStack,
                         NW_IN  NwU32T teidLocal,
                         NW_IN  NwU32T peerIp,
                         NW_IN  NwU32T peerPort,
                         NW_IN  NwU32T seqNum);

NwGtpv2cRcT
nwGtpv2cTrxnDelete( NW_INOUT NwGtpv2cTrxnT **ppTrxn);

/**
 * Start timer to wait before pruginf a req tran for which response has been sent
 *
 * @param[in] thiz : Pointer to transaction
 * @return NW_GTPV2C_OK on success.
 */

NwGtpv2cRcT
nwGtpv2cTrxnStartDulpicateRequestWaitTimer(NwGtpv2cTrxnT* thiz);

/**
 * Start timer to wait for rsp of a req message
 *
 * @param[in] thiz : Pointer to transaction
 * @param[in] timeoutCallbackFunc : Timeout handler callback function.
 * @return NW_GTPV2C_OK on success.
 */

NwGtpv2cRcT
nwGtpv2cTrxnStartPeerRspWaitTimer(NwGtpv2cTrxnT* thiz);


NwGtpv2cRcT
nwGtpv2cTrxnSendMsgRetransmission(NwGtpv2cTrxnT* thiz);

#ifdef __cplusplus
}
#endif

#endif /* __NW_GTPV2C_TRXN_H__ */

/*--------------------------------------------------------------------------*
 *                      E N D     O F    F I L E                            *
 *--------------------------------------------------------------------------*/
