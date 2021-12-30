package pmemkv_sys

/*
#cgo LDFLAGS: -lpmemkv -ltbb
#include "libpmemkv.h"
#include <stdlib.h>
#include "cgo_helpers.h"
*/
import "C"
import "unsafe"

// KVAllCallback type as declared in https://google.com/search?q=.+KVAllCallback
type KVAllCallback func(context unsafe.Pointer, keybytes int32, key string)

// KVEachCallback type as declared in https://google.com/search?q=.+KVEachCallback
type KVEachCallback func(context unsafe.Pointer, keybytes int32, key string, valuebytes int32, value string)

// KVGetCallback type as declared in https://google.com/search?q=.+KVGetCallback
type KVGetCallback func(context unsafe.Pointer, valuebytes int32, value string)

// KVStartFailureCallback type as declared in https://google.com/search?q=.+KVStartFailureCallback
type KVStartFailureCallback func(context unsafe.Pointer, engine string, config string, msg string)

// KVEngineSys as declared in https://google.com/search?q=.+KVEngine
type KVEngineSys C.KVEngine