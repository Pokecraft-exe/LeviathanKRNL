#include "H/paging.h"

// mmu

int tlb_lookup(vaddr_t v, paddr_t *p)
{
   for (int i=0; i<CPU_MODEL_MAX_TLB_ENTRIES; i++)
   {
      if (hw_tlb[i].flags & TLB_ENTRY_FLAGS_INUSE && hw_tlb[i].entry_virtual_address == v)
      {
         *p = hw_tlb[i].relevant_physical_address;
         return 1;
      };
   };
   return 0;
}

asm volatile ("TLBFLSH   %0\n\t"::"r" (virtual_address));

 
void tlb_flush_single(vaddr_t v)
{
   for (int i=0; i<CPU_MODEL_MAX_TLB_ENTRIES; i++)
   {
      if (hw_tlb[i].flags & TLB_ENTRY_FLAGS_INUSE && hw_tlb[i].entry_virtual_address == v)
      {
         ht_tlb[i].flags &= ~TLB_ENTRY_FLAGS_INUSE;
         return;
      };
   };
}