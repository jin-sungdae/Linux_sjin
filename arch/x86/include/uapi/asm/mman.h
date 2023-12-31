/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _ASM_X86_MMAN_H
#define _ASM_X86_MMAN_H

#define MAP_32BIT	0x40		/* only give out 32bit addresses */
#define MAP_ABOVE4G	0x80		/* only map above 4GB */

#ifdef CONFIG_X86_INTEL_MEMORY_PROTECTION_KEYS
#define arch_calc_vm_prot_bits(prot, key) (		\
		((key) & 0x1 ? VM_PKEY_BIT0 : 0) |      \
		((key) & 0x2 ? VM_PKEY_BIT1 : 0) |      \
		((key) & 0x4 ? VM_PKEY_BIT2 : 0) |      \
		((key) & 0x8 ? VM_PKEY_BIT3 : 0))
#endif

/* Flags for map_shadow_stack(2) */
#define SHADOW_STACK_SET_TOKEN	(1ULL << 0)	/* Set up a restore token in the shadow stack */

#include <asm-generic/mman.h>

#endif /* _ASM_X86_MMAN_H */
