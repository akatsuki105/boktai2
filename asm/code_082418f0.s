	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start ReflectClock
ReflectClock: @ 0x08241F6C
	push {r4, r5, r6, lr}
	bl GetDate
	ldr r4, _08241FC8 @ =0x030046A0
	ldr r1, [r4]
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r1, r1, r2
	str r0, [r1]
	bl GetHour
	ldr r1, [r4]
	movs r5, #0xce
	lsls r5, r5, #1
	adds r1, r1, r5
	str r0, [r1]
	bl GetMinute
	adds r6, r0, #0
	ldr r2, [r4]
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r1, r2, r3
	str r6, [r1]
	ldr r1, _08241FCC @ =0x030047E0
	ldrb r3, [r1, #0xc]
	ldrb r1, [r1, #0xd]
	movs r4, #0
	adds r2, r2, r5
	ldr r2, [r2]
	cmp r2, r3
	blt _08241FB4
	cmp r2, r3
	bne _08241FB6
	cmp r6, r1
	bge _08241FB6
_08241FB4:
	movs r4, #1
_08241FB6:
	ldr r1, _08241FC8 @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r1, r1, r2
	str r4, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08241FC8: .4byte 0x030046A0
_08241FCC: .4byte 0x030047E0

	thumb_func_start clock_08241fd0
clock_08241fd0: @ 0x08241FD0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	bl GetDate
	adds r4, r0, #0
	bl GetHour
	adds r6, r0, #0
	bl GetMinute
	mov sb, r0
	ldr r0, _08242050 @ =0x030047E0
	ldrb r5, [r0, #0xc]
	ldrb r0, [r0, #0xd]
	mov r8, r0
	add r1, sp, #0xc
	add r2, sp, #0x10
	add r0, sp, #8
	adds r3, r4, #0
	bl FUN_0823db08
	add r0, sp, #0x14
	add r1, sp, #0x18
	add r2, sp, #0x1c
	ldr r7, _08242054 @ =0x030046A0
	ldr r3, [r7]
	movs r4, #0xcc
	lsls r4, r4, #1
	adds r3, r3, r4
	ldr r3, [r3]
	bl FUN_0823db08
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	ldr r3, [sp, #0x14]
	ldr r4, [sp, #0x18]
	str r4, [sp]
	ldr r4, [sp, #0x1c]
	str r4, [sp, #4]
	bl FUN_0823d9ec
	movs r3, #0
	cmp r0, #1
	bhi _0824209A
	cmp r0, #1
	bne _08242058
	ldr r0, [r7]
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _0824209A
	cmp r6, r5
	bgt _0824209A
	cmp r6, r5
	bne _08242094
	cmp sb, r8
	blt _08242094
	b _0824209A
	.align 2, 0
_08242050: .4byte 0x030047E0
_08242054: .4byte 0x030046A0
_08242058:
	movs r2, #0
	ldr r1, [r7]
	movs r4, #0xce
	lsls r4, r4, #1
	adds r0, r1, r4
	ldr r0, [r0]
	cmp r0, r5
	blt _08242078
	cmp r0, r5
	bne _0824207A
	movs r4, #0xd0
	lsls r4, r4, #1
	adds r0, r1, r4
	ldr r0, [r0]
	cmp r0, r8
	bge _0824207A
_08242078:
	movs r2, #1
_0824207A:
	movs r0, #0
	cmp r6, r5
	bgt _08242088
	cmp r6, r5
	bne _0824208A
	cmp sb, r8
	blt _0824208A
_08242088:
	movs r0, #1
_0824208A:
	cmp r2, #0
	beq _08242094
	cmp r0, #0
	beq _08242094
	movs r3, #1
_08242094:
	ldr r5, _08242114 @ =0x030046A0
	cmp r3, #0
	beq _082420D8
_0824209A:
	ldr r1, _08242114 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0xdc
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r2, #0
	strh r2, [r0]
	ldr r0, [r1]
	movs r3, #0xdd
	lsls r3, r3, #1
	adds r0, r0, r3
	strh r2, [r0]
	ldr r0, [r1]
	movs r4, #0xde
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r2, #0
	str r2, [r0]
	ldr r0, [r1]
	adds r3, #6
	adds r0, r0, r3
	str r2, [r0]
	ldr r0, [r1]
	adds r4, #0xf4
	adds r0, r0, r4
	strh r2, [r0]
	ldr r0, [r1]
	adds r3, #0xf2
	adds r0, r0, r3
	strh r2, [r0]
	adds r5, r1, #0
_082420D8:
	ldr r0, [r5]
	movs r4, #0xde
	lsls r4, r4, #1
	adds r0, r0, r4
	ldr r1, [r0]
	ldr r0, _08242118 @ =0x0000752F
	cmp r1, r0
	ble _08242100
	bl IsGunCooled
	cmp r0, #0
	beq _08242100
	ldr r0, [r5]
	adds r0, r0, r4
	movs r1, #0
	str r1, [r0]
	ldr r0, [r5]
	subs r4, #2
	adds r0, r0, r4
	strh r1, [r0]
_08242100:
	bl ReflectClock
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08242114: .4byte 0x030046A0
_08242118: .4byte 0x0000752F

	thumb_func_start FUN_0824211c
FUN_0824211c: @ 0x0824211C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08241f28
	adds r0, r4, #0
	bl clock_08241fd0
	ldr r0, _08242138 @ =0x03001708
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08242138: .4byte 0x03001708

	thumb_func_start FUN_0824213c
FUN_0824213c: @ 0x0824213C
	push {r4, lr}
	ldr r0, _08242170 @ =0x03001708
	ldr r0, [r0]
	cmp r0, #0
	bne _0824217E
	movs r0, #5
	movs r1, #0x30
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0824217C
	ldr r1, _08242174 @ =FUN_08241ef4
	ldr r2, _08242178 @ =FUN_08241f14
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0824211c
	cmp r0, #0
	bge _0824217C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0824217E
	.align 2, 0
_08242170: .4byte 0x03001708
_08242174: .4byte FUN_08241ef4
_08242178: .4byte FUN_08241f14
_0824217C:
	adds r0, r4, #0
_0824217E:
	pop {r4}
	pop {r1}
	bx r1
