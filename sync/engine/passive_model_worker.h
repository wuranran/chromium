// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SYNC_ENGINE_PASSIVE_MODEL_WORKER_H_
#define SYNC_ENGINE_PASSIVE_MODEL_WORKER_H_
#pragma once

#include "base/basictypes.h"
#include "base/compiler_specific.h"
#include "sync/engine/model_safe_worker.h"
#include "sync/util/syncer_error.h"

class MessageLoop;

namespace browser_sync {

// Implementation of ModelSafeWorker for passive types.  All work is
// done on the same thread DoWorkAndWaitUntilDone (i.e., the sync
// thread).
class PassiveModelWorker : public ModelSafeWorker {
 public:
  explicit PassiveModelWorker(const MessageLoop* sync_loop);

  // ModelSafeWorker implementation. Called on the sync thread.
  virtual SyncerError DoWorkAndWaitUntilDone(
      const WorkCallback& work) OVERRIDE;
  virtual ModelSafeGroup GetModelSafeGroup() OVERRIDE;

 private:
  virtual ~PassiveModelWorker();

  const MessageLoop* const sync_loop_;

  DISALLOW_COPY_AND_ASSIGN(PassiveModelWorker);
};

}  // namespace browser_sync

#endif  // SYNC_ENGINE_PASSIVE_MODEL_WORKER_H_
