/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.24 from the
 * contents of Win32.xs. Do not edit this file, edit Win32.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "Win32.xs"
#ifdef WIN32
#define _WIN32_WINNT 0x0500
#endif

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#line 19 "Win32.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)    S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage        S_croak_xs_usage
#endif

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#line 161 "Win32.c"
#ifdef WIN32
#include <windows.h>
#include <ShellAPI.h>
#include <Psapi.h>
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Padre__Util__Win32__recycle_file); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Padre__Util__Win32__recycle_file)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "filename");
    {
	char*	filename = (char *)SvPV_nolen(ST(0))
;
	SV *	RETVAL;
#line 20 "Win32.xs"
    SHFILEOPSTRUCT op;
    int result;

    /* default return is undef - for failuire */

    memset(&op,0,sizeof(op));
    op.wFunc  = FO_DELETE;
    op.fFlags = FOF_ALLOWUNDO;
    op.pFrom  = filename;

    result = SHFileOperation( &op );

    if(result != 0)
    {
        XSRETURN_UNDEF;
    }
    else
    {
        /* check if any errors */
        if(op.fAnyOperationsAborted)
        {
            RETVAL = newSViv(0);
        } 
        else
        {
            RETVAL = newSViv(1);
        }
    }
#line 208 "Win32.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Padre__Util__Win32__allow_set_foreground_window); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Padre__Util__Win32__allow_set_foreground_window)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "processid");
    {
	long	processid = (long)SvIV(ST(0))
;
	SV *	RETVAL;
#line 56 "Win32.xs"
    int result;
    result = AllowSetForegroundWindow( processid );
    RETVAL = newSViv( result );
#line 230 "Win32.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Padre__Util__Win32__execute_process_and_wait); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Padre__Util__Win32__execute_process_and_wait)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "file, params, directory, show");
    {
	char *	file = (char *)SvPV_nolen(ST(0))
;
	char *	params = (char *)SvPV_nolen(ST(1))
;
	char *	directory = (char *)SvPV_nolen(ST(2))
;
	int	show = (int)SvIV(ST(3))
;
	SV *	RETVAL;
#line 70 "Win32.xs"
    SHELLEXECUTEINFO info;
    BOOL result;

    memset(&info,0,sizeof(info));
    info.cbSize = sizeof(info);
    info.lpVerb = "open\0";
    info.lpDirectory = directory;
    info.lpFile = file;
    info.lpParameters = params;
    info.nShow = show;
    info.fMask = SEE_MASK_NOCLOSEPROCESS;

    result = ShellExecuteEx( &info );

    if( !result )
      XSRETURN_UNDEF;

    WaitForSingleObject(info.hProcess , INFINITE );
    CloseHandle(info.hProcess);

    RETVAL = newSViv( 1 );
#line 276 "Win32.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Padre__Util__Win32__get_current_process_memory_size); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Padre__Util__Win32__get_current_process_memory_size)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	SV *	RETVAL;
#line 99 "Win32.xs"
    PROCESS_MEMORY_COUNTERS stats;

    memset(&stats,0,sizeof(stats));
    stats.cb = sizeof(stats);

    GetProcessMemoryInfo( GetCurrentProcess(), &stats, stats.cb );

    RETVAL = newSViv( stats.PeakWorkingSetSize );
#line 301 "Win32.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#else
#define XSubPPtmpAAAB 1


XS_EUPXS(XS_Padre__Util__Win32__no_win32_noop); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Padre__Util__Win32__no_win32_noop)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	SV *	RETVAL;
#line 115 "Win32.xs"
    XSRETURN_UNDEF;
#line 322 "Win32.c"
    }
    XSRETURN(1);
}

#endif
#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Padre__Util__Win32); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Padre__Util__Win32)
{
    dVAR; dXSARGS;
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#endif
    XS_VERSION_BOOTCHECK;

#if XSubPPtmpAAAA
        newXS("Padre::Util::Win32::_recycle_file", XS_Padre__Util__Win32__recycle_file, file);
        newXS("Padre::Util::Win32::_allow_set_foreground_window", XS_Padre__Util__Win32__allow_set_foreground_window, file);
        newXS("Padre::Util::Win32::_execute_process_and_wait", XS_Padre__Util__Win32__execute_process_and_wait, file);
        newXS("Padre::Util::Win32::_get_current_process_memory_size", XS_Padre__Util__Win32__get_current_process_memory_size, file);
#endif
#if XSubPPtmpAAAB
        newXS("Padre::Util::Win32::_no_win32_noop", XS_Padre__Util__Win32__no_win32_noop, file);
#endif

    /* Initialisation Section */

#if XSubPPtmpAAAA
#endif
#if XSubPPtmpAAAB
#endif
#line 364 "Win32.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

