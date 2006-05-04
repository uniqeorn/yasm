/*
 * Null debugging format (creates NO debugging information)
 *
 *  Copyright (C) 2002  Peter Johnson
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND OTHER CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR OTHER CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include <util.h>
/*@unused@*/ RCSID("$Id$");

#define YASM_LIB_INTERNAL
#include <libyasm.h>


yasm_dbgfmt_module yasm_null_LTX_dbgfmt;


static /*@null@*/ /*@only@*/ yasm_dbgfmt *
null_dbgfmt_create(yasm_object *object, yasm_objfmt *of, yasm_arch *a)
{
    yasm_dbgfmt_base *dbgfmt = yasm_xmalloc(sizeof(yasm_dbgfmt_base));
    dbgfmt->module = &yasm_null_LTX_dbgfmt;
    return (yasm_dbgfmt *)dbgfmt;
}

static void
null_dbgfmt_destroy(/*@only@*/ yasm_dbgfmt *dbgfmt)
{
    yasm_xfree(dbgfmt);
}

static int
null_dbgfmt_directive(yasm_dbgfmt *dbgfmt, const char *name,
		      yasm_section *sect, yasm_valparamhead *valparams,
		      unsigned long line)
{
    return 1;
}

static void
null_dbgfmt_generate(yasm_dbgfmt *dbgfmt, yasm_errwarns *errwarns)
{
}


/* Define dbgfmt structure -- see dbgfmt.h for details */
yasm_dbgfmt_module yasm_null_LTX_dbgfmt = {
    "No debugging info",
    "null",
    null_dbgfmt_create,
    null_dbgfmt_destroy,
    null_dbgfmt_directive,
    null_dbgfmt_generate
};
