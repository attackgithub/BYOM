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
#include "ps.h"

#if !defined(NOSPOOF)
void * get_proc_handle(void* phandle, char* pname) {
   SIZE_T              ln;
   BOOL                rt;
   STARTUPINFOEXA      si;
   PROCESS_INFORMATION pi;

   RtlSecureZeroMemory(&si, sizeof(STARTUPINFOEXA));
   RtlSecureZeroMemory(&pi, sizeof(PROCESS_INFORMATION));

   InitializeProcThreadAttributeList(NULL, 1, 0, &ln);
   if (ln<=0) return NULL;

   si.lpAttributeList = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, ln);
   if (!si.lpAttributeList) return NULL;

   rt = InitializeProcThreadAttributeList(si.lpAttributeList, 1, 0, &ln);
   if (rt<=0) {
    HeapFree(GetProcessHeap(), 0, si.lpAttributeList);
    return NULL;
   }

   rt = UpdateProcThreadAttribute(si.lpAttributeList, 0, PROC_THREAD_ATTRIBUTE_PARENT_PROCESS,
     &phandle, sizeof(HANDLE), NULL, NULL);
   if (rt<=0) {
    DeleteProcThreadAttributeList(si.lpAttributeList);
    HeapFree(GetProcessHeap(), 0, si.lpAttributeList);
   }
}
#endif
