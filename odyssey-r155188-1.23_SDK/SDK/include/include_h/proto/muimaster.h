#ifndef PROTO_MUIMASTER_H
#define PROTO_MUIMASTER_H

/***************************************************************************

 Magic User Interface - MUI
 Copyright (C) 1992-2006 by Stefan Stuntz <stefan@stuntz.com>
 Copyright (C) 2006-2019 by Thore Boeckelmann, Jens Maus
 All Rights Reserved.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 IN NO EVENT WILL THE AUTHORS BE LIABLE FOR DIRECT, INDIRECT, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES RESULTING FROM ANY CLAIM ARISING OUT OF THE
 INFORMATION PRESENTED HEREIN, EVEN IF IT HAS BEEN ADVISED OF THE
 POSSIBILITIES OF SUCH DAMAGES.

***************************************************************************/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef LIBRARIES_MUI_H
#include <libraries/mui.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
extern struct Library * MUIMasterBase;
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/muimaster.h>
 #ifdef __USE_INLINE__
  #include <inline4/muimaster.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_MUIMASTER_PROTOS_H
  #define CLIB_MUIMASTER_PROTOS_H 1
 #endif /* CLIB_MUIMASTER_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  extern struct MUIMasterIFace *IMUIMaster;
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_MUIMASTER_PROTOS_H
  #include <clib/muimaster_protos.h>
 #endif /* CLIB_MUIMASTER_PROTOS_H */
 #if defined(__GNUC__)
  #ifdef __AROS__
   #include <defines/muimaster.h>
  #else
   #ifndef __PPC__
    #include <inline/muimaster.h>
   #else
    #include <ppcinline/muimaster.h>
   #endif /* __PPC__ */
  #endif /* __AROS__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/muimaster_protos.h>
  #endif /* __PPC__ */
 #else
  #include <pragmas/muimaster_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_MUIMASTER_H */
