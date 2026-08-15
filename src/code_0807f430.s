	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807f478
FUN_0807f478: @ 0x0807F478
	push {lr}
	adds r3, r0, #0
	ldr r0, _0807F4A0 @ =0x03002BF8
	ldr r0, [r0]
	cmp r0, #0
	beq _0807F4A4
	ldr r1, [r0, #0x18]
	cmp r1, #0
	beq _0807F4A4
	ldr r0, [r1]
	ldrh r0, [r0]
	movs r2, #1
_0807F490:
	cmp r0, r3
	bne _0807F490
	ldr r0, [r1, #4]
	ands r0, r2
	cmp r0, #0
	bne _0807F4A4
	adds r0, r1, #0
	b _0807F4A6
	.align 2, 0
_0807F4A0: .4byte 0x03002BF8
_0807F4A4:
	movs r0, #0
_0807F4A6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807f4ac
FUN_0807f4ac: @ 0x0807F4AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	str r1, [sp]
	mov sb, r3
	ldr r0, _0807F4CC @ =0x03002BF8
	ldr r0, [r0]
	cmp r0, #0
	bne _0807F4D0
	movs r0, #0
	b _0807F544
	.align 2, 0
_0807F4CC: .4byte 0x03002BF8
_0807F4D0:
	ldr r6, [r0, #0x18]
	movs r0, #0
	mov sl, r0
	adds r7, r2, #0
	muls r7, r2, r7
	cmp r6, #0
	beq _0807F542
	movs r0, #0x80
	lsls r0, r0, #1
	mov r1, sb
	subs r1, r0, r1
	str r1, [sp, #4]
_0807F4E8:
	ldr r0, [r6, #4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0807F53C
	ldr r2, [r6]
	movs r3, #8
	ldrsh r1, [r2, r3]
	mov r4, r8
	movs r3, #0
	ldrsh r0, [r4, r3]
	subs r5, r1, r0
	movs r4, #0xc
	ldrsh r1, [r2, r4]
	mov r2, r8
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r4, r1, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	ldr r2, [sp]
	ldr r3, _0807F554 @ =0xFFFFFF00
	adds r1, r2, r3
	subs r1, r0, r1
	movs r0, #0xff
	ands r1, r0
	cmp r1, sb
	ble _0807F52A
	ldr r0, [sp, #4]
	cmp r1, r0
	blt _0807F53C
_0807F52A:
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r4, #0
	muls r0, r4, r0
	adds r0, r1, r0
	cmp r0, r7
	bge _0807F53C
	adds r7, r0, #0
	mov sl, r6
_0807F53C:
	ldr r6, [r6, #0xc]
	cmp r6, #0
	bne _0807F4E8
_0807F542:
	mov r0, sl
_0807F544:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807F554: .4byte 0xFFFFFF00

	thumb_func_start FUN_0807f558
FUN_0807f558: @ 0x0807F558
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldr r0, _0807F56C @ =0x03002BF8
	ldr r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _0807F570
	movs r0, #0
	b _0807F590
	.align 2, 0
_0807F56C: .4byte 0x03002BF8
_0807F570:
	str r4, [r3]
	str r2, [r3, #8]
	ldr r0, [r1, #0x18]
	cmp r0, #0
	beq _0807F584
_0807F57A:
	cmp r0, r3
	beq _0807F58E
	ldr r0, [r0, #0xc]
	cmp r0, #0
	bne _0807F57A
_0807F584:
	ldr r0, [r5]
	ldr r0, [r0, #0x18]
	str r0, [r3, #0xc]
	ldr r0, [r5]
	str r3, [r0, #0x18]
_0807F58E:
	movs r0, #1
_0807F590:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807f598
FUN_0807f598: @ 0x0807F598
	push {lr}
	adds r3, r0, #0
	ldr r0, _0807F5B0 @ =0x03002BF8
	ldr r2, [r0]
	cmp r2, #0
	beq _0807F5C6
	ldr r1, [r2, #0x18]
	cmp r1, r3
	bne _0807F5C0
	ldr r0, [r1, #0xc]
	str r0, [r2, #0x18]
	b _0807F5C6
	.align 2, 0
_0807F5B0: .4byte 0x03002BF8
_0807F5B4:
	ldr r0, [r0, #0xc]
	str r0, [r1, #0xc]
	b _0807F5C6
_0807F5BA:
	cmp r0, r3
	beq _0807F5B4
	ldr r1, [r1, #0xc]
_0807F5C0:
	ldr r0, [r1, #0xc]
	cmp r0, #0
	bne _0807F5BA
_0807F5C6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807f5cc
FUN_0807f5cc: @ 0x0807F5CC
	movs r0, #0
	bx lr

	thumb_func_start FUN_0807f5d0
FUN_0807f5d0: @ 0x0807F5D0
	ldr r1, _0807F5D8 @ =0x03002BF8
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0807F5D8: .4byte 0x03002BF8

	thumb_func_start FUN_0807f5dc
FUN_0807f5dc: @ 0x0807F5DC
	movs r1, #0
	str r1, [r0, #0x18]
	str r1, [r0, #0x1c]
	ldr r1, _0807F5EC @ =0x03002BF8
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_0807F5EC: .4byte 0x03002BF8

	thumb_func_start FUN_0807f5f0
FUN_0807f5f0: @ 0x0807F5F0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _0807F62C @ =0x03002BF8
	ldr r0, [r0]
	cmp r0, #0
	bne _0807F63A
	movs r0, #2
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0807F638
	ldr r1, _0807F630 @ =FUN_0807f5cc
	ldr r2, _0807F634 @ =FUN_0807f5d0
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0807f5dc
	cmp r0, #0
	bge _0807F638
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0807F63A
	.align 2, 0
_0807F62C: .4byte 0x03002BF8
_0807F630: .4byte FUN_0807f5cc
_0807F634: .4byte FUN_0807f5d0
_0807F638:
	adds r0, r4, #0
_0807F63A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

