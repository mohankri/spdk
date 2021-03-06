/*	$NetBSD: sa.h,v 1.14 2008/10/20 16:16:27 tsutsui Exp $	*/

/*-
 * Copyright (c) 2001 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Nathan J. Williams.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *        This product includes software developed by the NetBSD
 *        Foundation, Inc. and its contributors.
 * 4. Neither the name of The NetBSD Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef NETBSD_SYS_SA_H
#define NETBSD_SYS_SA_H

#include <sys/satypes.h>
#include <sys/ucontext.h>

struct sa_t {
	ucontext_t *sa_context;
	int sa_id;
	int sa_cpu;
};

/* kernel known per upcall stack data */
struct sa_stackinfo_t {
	unsigned int sasi_stackgen; /* stack generation counter */
};

#define SA_UPCALL_NEWPROC		0
#define SA_UPCALL_PREEMPTED		1
#define SA_UPCALL_BLOCKED		2
#define SA_UPCALL_UNBLOCKED		3
#define SA_UPCALL_SIGNAL		4
#define SA_UPCALL_SIGEV			5
#define SA_UPCALL_USER 			6
#define SA_UPCALL_NUPCALLS		7

#define SA_UPCALL_STRINGS "newproc", "preempted", "blocked", "unblocked", \
    "signal", "sigev", "user"

#define SA_FLAG_PREEMPT	0x0001	/* Generate upcalls on a vanilla preempt() */

#define	SA_FLAG_STACKINFO 0x010000 /* Use stackinfo for upcall stack return */

#ifdef _KERNEL
extern int sa_system_disabled;
#endif /* _KERNEL */

#endif /* !NETBSD_SYS_SA_H */
