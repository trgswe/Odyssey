/*
 * Copyright (C) 2011 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "SubresourceLoader.h"

#include <wtf/Ref.h>

namespace WebCore {

#if USE(NETWORK_CFDATA_ARRAY_CALLBACK)
void SubresourceLoader::didReceiveDataArray(CFArrayRef dataArray)
{
    // Reference the object in this method since the additional processing can do
    // anything including removing the last reference to this object; one example of this is 3266216.
    Ref<SubresourceLoader> protect(*this);

    ResourceLoader::didReceiveDataArray(dataArray);

    if (checkForHTTPStatusCodeError())
        return;

    // A subresource loader does not load multipart sections progressively.
    // So don't deliver any data to the loader yet.
    if (!m_loadingMultipartContent) {
        CFIndex arrayCount = CFArrayGetCount(dataArray);
        for (CFIndex i = 0; i < arrayCount; ++i)  {
            CFDataRef data = reinterpret_cast<CFDataRef>(CFArrayGetValueAtIndex(dataArray, i));
            sendDataToResource(reinterpret_cast<const char *>(CFDataGetBytePtr(data)), static_cast<int>(CFDataGetLength(data)));
        }
    }
}
#endif

}
