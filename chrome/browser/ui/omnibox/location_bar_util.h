// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_UI_OMNIBOX_LOCATION_BAR_UTIL_H_
#define CHROME_BROWSER_UI_OMNIBOX_LOCATION_BAR_UTIL_H_
#pragma once

#include <string>

#include "base/string16.h"

class Profile;

namespace location_bar_util {

// Returns the short name for a keyword.
std::wstring GetKeywordName(Profile* profile, const std::wstring& keyword);

// Build a short string to use in keyword-search when the field isn't
// very big.
string16 CalculateMinString(const string16& description);

}  // namespace location_bar_util

#endif  // CHROME_BROWSER_UI_OMNIBOX_LOCATION_BAR_UTIL_H_
