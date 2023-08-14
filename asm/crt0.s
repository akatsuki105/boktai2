	.include "asm/macros.inc"

	.syntax unified
	
	.text
	.arm

	.global Init
Init:
  b _Init

_Pad_080000d4:
	.space 224, 0

	arm_func_start _Init
_Init:
	mov r0, #0x12
	msr cpsr_fc, r0
	ldr sp, _080001EC @ =0x03007FA0
	mov r0, #0x1f
	msr cpsr_fc, r0
	ldr sp, _080001E8 @ =0x03007DA0
	ldr r1, _08000340 @ =0x03007FFC
	add r0, pc, #0x18 @ =IntrMain
	str r0, [r1]
	ldr r1, _08000344 @ =AgbMain
	mov lr, pc
	bx r1
_080001E4:
	.byte 0xB9, 0xFF, 0xFF, 0xEA
_080001E8: .4byte 0x03007DA0
_080001EC: .4byte 0x03007FA0

	arm_func_start IntrMain
IntrMain: @ 0x080001F0
	mov r3, #0x4000000
	add r3, r3, #0x200
	ldr r2, [r3]
	ldrh r1, [r3, #8]
	mrs r0, spsr
	push {r0, r1, r2, r3, lr}
	mov r0, #0
	strh r0, [r3, #8]
	and r1, r2, r2, lsr #16
	mov ip, #0
	ands r0, r1, #4
	bne _080002C8
	add ip, ip, #4
	mov r0, #1
	strh r0, [r3, #8]
	ands r0, r1, #0x80
	bne _080002C8
	add ip, ip, #4
	ands r0, r1, #0x40
	bne _080002C8
	add ip, ip, #4
	ands r0, r1, #2
	bne _080002C8
	add ip, ip, #4
	ands r0, r1, #1
	bne _080002C8
	add ip, ip, #4
	ands r0, r1, #8
	bne _080002C8
	add ip, ip, #4
	ands r0, r1, #0x10
	bne _080002C8
	add ip, ip, #4
	ands r0, r1, #0x20
	bne _080002C8
	add ip, ip, #4
	ands r0, r1, #0x100
	bne _080002C8
	add ip, ip, #4
	ands r0, r1, #0x200
	bne _080002C8
	add ip, ip, #4
	ands r0, r1, #0x400
	bne _080002C8
	add ip, ip, #4
	ands r0, r1, #0x800
	bne _080002C8
	add ip, ip, #4
	ands r0, r1, #0x1000
	bne _080002C8
	add ip, ip, #4
	ands r0, r1, #0x2000
	strbne r0, [r3, #-0x17c]
_080002C4:
	bne _080002C4
_080002C8:
	strh r0, [r3, #2]
	ldr r0, _08000348 @ =0x030057D0
	ldr r0, [r0]
	ldrb r0, [r0, #0xa]
	mov r1, #8
	lsl r0, r1, r0
	orr r0, r0, #0x2000
	orr r1, r0, #0xc6
	and r1, r1, r2
	strh r1, [r3]
	mrs r3, cpsr
	bic r3, r3, #0xdf
	orr r3, r3, #0x1f
	msr cpsr_fc, r3
	ldr r1, _0800034C @ =0x03002CB0
	add r1, r1, ip
	ldr r0, [r1]
	stmdb sp!, {lr}
	add lr, pc, #0x0 @ =FUN_08000318
	bx r0

	arm_func_start FUN_08000318
FUN_08000318: @ 0x08000318
	ldm sp!, {lr}
	mrs r3, cpsr
	bic r3, r3, #0xdf
	orr r3, r3, #0x92
	msr cpsr_fc, r3
	pop {r0, r1, r2, r3, lr}
	strh r2, [r3]
	strh r1, [r3, #8]
	msr spsr_fc, r0
	bx lr
	.align 2, 0
_08000340: .4byte 0x03007FFC
_08000344: .4byte AgbMain
_08000348: .4byte 0x030057D0
_0800034C: .4byte 0x03002CB0

