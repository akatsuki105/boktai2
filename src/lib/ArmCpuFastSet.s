.include "asm/macros.inc"

	.syntax unified

	.text

	arm_func_start _CpuFastSet
_CpuFastSet: @ 0x08251B20
	ldr ip, _08251B28 @ =CpuFastSet
	bx ip
	.align 2, 0
_08251B28: .4byte CpuFastSet
