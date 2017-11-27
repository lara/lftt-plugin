#pragma once

#include <cstdint>
#include <cstddef>
#include <atomic>
#include <set>
#include <assert.h>
#include "LFTTTypeDef.h"
#include "LogicalStatus.h"

// This operation is included in the header so that other files can call it.
bool ExecuteTransaction(Desc* desc);