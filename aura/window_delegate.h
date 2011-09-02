// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef AURA_WINDOW_DELEGATE_H_
#define AURA_WINDOW_DELEGATE_H_
#pragma once

namespace gfx {
class Canvas;
class Point;
}

namespace aura {

class KeyEvent;
class MouseEvent;

// Delegate interface for aura::Window.
class WindowDelegate {
 public:
  // Sent to the Window's delegate when the Window gains or loses focus.
  virtual void OnFocus() = 0;
  virtual void OnBlur() = 0;

  virtual bool OnKeyEvent(KeyEvent* event) = 0;

  // Returns the non-client component (see hit_test.h) containing |point|, in
  // window coordinates.
  virtual int GetNonClientComponent(const gfx::Point& point) const = 0;

  virtual bool OnMouseEvent(MouseEvent* event) = 0;

  // Asks the delegate to paint window contents into the supplied canvas.
  virtual void OnPaint(gfx::Canvas* canvas) = 0;

  // Called when the Window has been destroyed (i.e. from its destructor).
  // The delegate can use this as an opportunity to delete itself if necessary.
  virtual void OnWindowDestroyed() = 0;

 protected:
  virtual ~WindowDelegate() {}
};

}  // namespace aura

#endif  // AURA_WINDOW_DELEGATE_H_
