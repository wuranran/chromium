// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef REMOTING_HOST_BRANDING_H_
#define REMOTING_HOST_BRANDING_H_

#include "base/file_path.h"

namespace remoting {

#if defined(OS_WIN)
// Windows chromoting service name.
extern const char16 kWindowsServiceName[];
#endif

// Returns the location of the host configuration directory.
FilePath GetConfigDir();

} // namespace remoting

#endif // REMOTING_HOST_BRANDING_H_
