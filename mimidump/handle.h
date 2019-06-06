/**
  BSD 3-Clause License
  Copyright (c) 2019, Mumbai. All rights reserved.
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
  * Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
  * Neither the name of the copyright holder nor the names of its
    contributors may be used to endorse or promote products derived from
    this software without specific prior written permission.
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef HANDLE_H
#define HANDLE_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winternl.h>
#include <ntstatus.h>

#if defined(_MSC_VER)
#pragma comment(lib, "ntdll.lib")
#endif

#define SystemHandleInformation 16
#define ObjectBasicInformation  0
#define ObjectNameInformation   1
#define ObjectTypeInformation   2

extern NTSTATUS NtDuplicateObject(
   HANDLE SourceProcessHandle,
   HANDLE SourceHandle,
   HANDLE TargetProcessHandle,
   PHANDLE TargetHandle,
   ACCESS_MASK DesiredAccess,
   ULONG Attributes,
   ULONG Options
);

/*typedef struct _UNICODE_STRING {
   USHORT Length;
   USHORT MaximumLength;
   LPWSTR Buffer;
} UNICODE_STRING, *PUNICODE_STRING;

typedef struct _SYSTEM_HANDLE {
   ULONG  ProcessId;
   BYTE   ObjectTypeNumber;
   BYTE   Flags;
   USHORT Handle;
   PVOID  Object;
   ACCESS_MASK GrantedAccess;
} SYSTEM_HANDLE, *PSYSTEM_HANDLE;
*/

/*
typedef struct _SYSTEM_HANDLE_INFORMATION {
   ULONG HandleCount;
   SYSTEM_HANDLE Handles[1];
} SYSTEM_HANDLE_INFORMATION, *PSYSTEM_HANDLE_INFORMATION;*/

typedef enum _POOL_TYPE {
   NonPagedPool,
   PagedPool,
   NonPagedPoolMustSucceed,
   DontUseThisType,
   NonPagedPoolCacheAligned,
   PagedPoolCacheAligned,
   NonPagedPoolCacheAlignedMustS
} POOL_TYPE, *PPOOL_TYPE;
/*
typedef struct _OBJECT_TYPE_INFORMATION {
   UNICODE_STRING Name;
   ULONG TotalNumberOfObjects;
   ULONG TotalNumberOfHandles;
   ULONG TotalPagedPoolStatus;
   ULONG TotalNonPagedPoolUsage;
   ULONG TotalNamePoolUsage;
   ULONG TotalHandleTableUsage;
   ULONG HighWaterNumberOfObjects;
   ULONG HighWaterNumberOfHandles;
   ULONG HighWaterPagedPoolUsage;
   ULONG HighWaterNonPagedPoolUsage;
   ULONG HighWaterNamePoolUsage;
   ULONG HighWaterHandleTableUsage;
   GENERIC_MAPPING GenericMapping;
   ULONG ValidAccess;
   BOOL  SecurityRequired;
   BOOL  MaintainHandleCount;
   USHORT MaintainTypeList;
   POOL_TYPE PoolType;
   ULONG PagedPoolUsage;
   ULONG NonPagedPoolUsage;
} OBJECT_TYPE_INFORMATION, *POBJECT_TYPE_INFORMATION;*/

#endif
