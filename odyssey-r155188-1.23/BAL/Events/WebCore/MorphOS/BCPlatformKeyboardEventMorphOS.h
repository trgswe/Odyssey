/*
 * Copyright (C) 2008 Pleyo.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of Pleyo nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY PLEYO AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL PLEYO OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef PlatformKeyboardEvent_h
#define PlatformKeyboardEvent_h

#include "PlatformEvent.h"
#include <wtf/text/WTFString.h>
#include "BALBase.h"

namespace WebCore {

    class PlatformKeyboardEvent : public PlatformEvent {
    public:
        PlatformKeyboardEvent()
            : PlatformEvent(PlatformEvent::KeyDown)
            , m_windowsVirtualKeyCode(0)
	    , m_macCharCode(0)
	    , m_autoRepeat(false)
            , m_isKeypad(false)
	    , m_isSystemKey(false)
	    , m_balEventKey(0)
        {
        }

        PlatformKeyboardEvent(Type type, const String& text, const String& unmodifiedText, const String& keyIdentifier, int windowsVirtualKeyCode, int nativeVirtualKeyCode, int macCharCode, bool \
			  isAutoRepeat, bool isKeypad, bool isSystemKey, Modifiers modifiers, double timestamp)
            : PlatformEvent(type, modifiers, timestamp)
            , m_text(text)
            , m_unmodifiedText(unmodifiedText)
            , m_keyIdentifier(keyIdentifier)
            , m_windowsVirtualKeyCode(windowsVirtualKeyCode)
      //, m_nativeVirtualKeyCode(nativeVirtualKeyCode)
            , m_macCharCode(macCharCode)
            , m_autoRepeat(isAutoRepeat)
            , m_isKeypad(isKeypad)
            , m_isSystemKey(isSystemKey)
        {
        }

        void disambiguateKeyDownEvent(Type, bool backwardCompatibilityMode = false); // Only used on platforms that need it, i.e. those that generate KeyDown events.

        // Text as as generated by processing a virtual key code with a keyboard layout
        // (in most cases, just a character code, but the layout can emit several
        // characters in a single keypress event on some platforms).
        // This may bear no resemblance to the ultimately inserted text if an input method
        // processes the input.
        // Will be null for KeyUp and RawKeyDown events.
        String text() const { return m_text; }

        // Text that would have been generated by the keyboard if no modifiers were pressed
        // (except for Shift); useful for shortcut (accelerator) key handling.
        // Otherwise, same as text().
        String unmodifiedText() const { return m_unmodifiedText; }

        String keyIdentifier() const { return m_keyIdentifier; }

        // Most compatible Windows virtual key code associated with the event.
        // Zero for Char events.
        int windowsVirtualKeyCode() const { return m_windowsVirtualKeyCode; }
        void setWindowsVirtualKeyCode(int code) { m_windowsVirtualKeyCode = code; }
        int macCharCode() const { return m_macCharCode; }

        bool isAutoRepeat() const { return m_autoRepeat; }
        bool isKeypad() const { return m_isKeypad; }
		bool isSystemKey() const { return m_isSystemKey; }

        static bool currentCapsLockState();
        static void getCurrentModifierState(bool& shiftKey, bool& ctrlKey, bool& altKey, bool& metaKey);

        PlatformKeyboardEvent(BalEventKey*);
        BalEventKey* balEventKey() const;

    private:
        String m_text;
        String m_unmodifiedText;
        String m_keyIdentifier;
        int m_windowsVirtualKeyCode;
        int m_macCharCode;
        bool m_autoRepeat;
        bool m_isKeypad;
        bool m_isSystemKey;

        BalEventKey* m_balEventKey;
	};

} // namespace WebCore

#endif // PlatformKeyboardEvent_h
