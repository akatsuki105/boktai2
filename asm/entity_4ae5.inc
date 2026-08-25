	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08001884
FUN_08001884: @ 0x08001884
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r3, #0
	ldr r3, [sp, #0x20]
	ldr r1, [sp, #0x24]
	lsrs r5, r5, #1
	movs r0, #0x20
	subs r0, r0, r5
	mov sb, r0
	subs r1, r1, r3
	cmp r1, #0
	beq _0800192E
	cmp r5, #0x1f
	bls _080018CC
	lsls r0, r3, #1
	adds r3, r2, r0
	adds r4, r4, r0
	lsls r1, r1, #1
	cmp r1, #0
	bge _080018B8
	adds r1, #3
_080018B8:
	lsls r2, r1, #9
	lsrs r2, r2, #0xb
	movs r0, #0x80
	lsls r0, r0, #0x13
	orrs r2, r0
	adds r0, r3, #0
	adds r1, r4, #0
	bl CpuSet
	b _0800192E
_080018CC:
	lsls r0, r3, #1
	adds r6, r6, r0
	mov r8, r6
	adds r2, r2, r0
	mov ip, r2
	adds r7, r4, r0
	cmp r1, #0
	ble _0800192E
	movs r0, #0xf8
	lsls r0, r0, #2
	mov sl, r0
	adds r6, r1, #0
_080018E4:
	mov r1, r8
	ldrh r0, [r1]
	ldr r3, _0800193C @ =0x00007C1F
	ands r3, r0
	mov r4, sl
	ands r4, r0
	mov r2, ip
	ldrh r1, [r2]
	adds r0, r1, #0
	ldr r2, _0800193C @ =0x00007C1F
	ands r0, r2
	adds r2, r0, #0
	muls r2, r5, r2
	mov r0, sb
	muls r0, r3, r0
	adds r2, r2, r0
	ldr r0, _08001940 @ =0x000F83E0
	ands r2, r0
	mov r0, sl
	ands r1, r0
	muls r1, r5, r1
	mov r0, sb
	muls r0, r4, r0
	adds r1, r1, r0
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r1, r0
	orrs r2, r1
	lsrs r2, r2, #5
	strh r2, [r7]
	movs r1, #2
	add r8, r1
	add ip, r1
	adds r7, #2
	subs r6, #1
	cmp r6, #0
	bne _080018E4
_0800192E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800193C: .4byte 0x00007C1F
_08001940: .4byte 0x000F83E0

	thumb_func_start FUN_08001944
FUN_08001944: @ 0x08001944
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r4, r2, #0
	ldr r0, [sp, #0x1c]
	lsrs r4, r4, #1
	subs r2, r0, r3
	cmp r2, #0
	beq _080019C8
	cmp r4, #0x1f
	bls _08001980
	lsls r0, r3, #1
	adds r1, r1, r0
	adds r3, r5, r0
	lsls r0, r2, #1
	cmp r0, #0
	bge _0800196C
	adds r0, #3
_0800196C:
	lsls r2, r0, #9
	lsrs r2, r2, #0xb
	movs r0, #0x80
	lsls r0, r0, #0x13
	orrs r2, r0
	adds r0, r1, #0
	adds r1, r3, #0
	bl CpuSet
	b _080019C8
_08001980:
	lsls r0, r3, #1
	adds r6, r1, r0
	adds r5, r5, r0
	cmp r2, #0
	ble _080019C8
	ldr r0, _080019D4 @ =0x00007C1F
	mov sb, r0
	ldr r1, _080019D8 @ =0x000F83E0
	mov r8, r1
	adds r3, r2, #0
	movs r0, #0xf8
	lsls r0, r0, #2
	mov ip, r0
	movs r7, #0xf8
	lsls r7, r7, #7
_0800199E:
	ldrh r2, [r6]
	adds r0, r2, #0
	mov r1, sb
	ands r0, r1
	adds r1, r0, #0
	muls r1, r4, r1
	mov r0, r8
	ands r1, r0
	mov r0, ip
	ands r2, r0
	adds r0, r2, #0
	muls r0, r4, r0
	ands r0, r7
	orrs r1, r0
	lsrs r1, r1, #5
	strh r1, [r5]
	adds r6, #2
	adds r5, #2
	subs r3, #1
	cmp r3, #0
	bne _0800199E
_080019C8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080019D4: .4byte 0x00007C1F
_080019D8: .4byte 0x000F83E0

	thumb_func_start FUN_080019dc
FUN_080019dc: @ 0x080019DC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r0, _08001A10 @ =0x000092B3
	bl GetFile
	adds r1, r0, #0
	adds r1, #0x14
	ldr r0, _08001A14 @ =0x00000434
	adds r4, r4, r0
	movs r0, #0xd0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0x32
	movs r3, #0
	bl FUN_08001944
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08001A10: .4byte 0x000092B3
_08001A14: .4byte 0x00000434

	thumb_func_start FUN_08001a18
FUN_08001a18: @ 0x08001A18
	push {lr}
	ldr r2, [r0, #0x2c]
	movs r3, #0xcf
_08001A1E:
	strh r1, [r2]
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _08001A1E
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0

	thumb_func_start FUN_08001a34
FUN_08001a34: @ 0x08001A34
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0x1a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08001A46
	ldr r0, [r4, #0x30]
	b _08001A48
_08001A46:
	ldr r0, [r4, #0x24]
_08001A48:
	ldr r1, [r4, #0x2c]
	ldr r2, _08001A60 @ =0x04000068
	bl CpuSet
	adds r1, r4, #0
	adds r1, #0x20
	movs r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08001A60: .4byte 0x04000068

	thumb_func_start FUN_08001a64
FUN_08001a64: @ 0x08001A64
	push {lr}
	ldr r0, _08001A78 @ =gClock
	ldrb r0, [r0, #0xe]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08001A7C
	movs r0, #0x40
	b _08001A7E
	.align 2, 0
_08001A78: .4byte gClock
_08001A7C:
	movs r0, #0x20
_08001A7E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08001a84
FUN_08001a84: @ 0x08001A84
	ldr r1, _08001A90 @ =0x00000642
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	bx lr
	.align 2, 0
_08001A90: .4byte 0x00000642

	thumb_func_start FUN_08001a94
FUN_08001a94: @ 0x08001A94
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08001AB0 @ =0x00000642
	adds r5, r6, r0
	ldrb r4, [r5]
	adds r0, r6, #0
	bl FUN_08001a64
	cmp r4, r0
	bge _08001AB4
	ldrb r0, [r5]
	adds r0, #4
	strb r0, [r5]
	b _08001AC4
	.align 2, 0
_08001AB0: .4byte 0x00000642
_08001AB4:
	adds r0, r6, #0
	bl FUN_08001a64
	strb r0, [r5]
	ldr r0, _08001ACC @ =0x00000644
	adds r1, r6, r0
	movs r0, #2
	strb r0, [r1]
_08001AC4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08001ACC: .4byte 0x00000644

	thumb_func_start FUN_08001ad0
FUN_08001ad0: @ 0x08001AD0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	bl FUN_08001a64
	ldr r1, _08001B00 @ =0x00000642
	adds r5, r7, r1
	ldrb r4, [r5]
	subs r6, r4, r0
	cmp r6, #0
	bge _08001AE6
	rsbs r6, r6, #0
_08001AE6:
	adds r0, r7, #0
	bl FUN_08001a64
	cmp r4, r0
	bge _08001B04
	adds r1, r6, #0
	cmp r1, #8
	ble _08001AF8
	movs r1, #8
_08001AF8:
	ldrb r0, [r5]
	adds r0, r0, r1
	b _08001B24
	.align 2, 0
_08001B00: .4byte 0x00000642
_08001B04:
	ldrb r4, [r5]
	adds r0, r7, #0
	bl FUN_08001a64
	cmp r4, r0
	ble _08001B1E
	adds r1, r6, #0
	cmp r1, #8
	ble _08001B18
	movs r1, #8
_08001B18:
	ldrb r0, [r5]
	subs r0, r0, r1
	b _08001B24
_08001B1E:
	adds r0, r7, #0
	bl FUN_08001a64
_08001B24:
	strb r0, [r5]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08001b2c
FUN_08001b2c: @ 0x08001B2C
	push {lr}
	adds r3, r0, #0
	ldr r0, _08001B40 @ =0x00000642
	adds r2, r3, r0
	ldrb r0, [r2]
	cmp r0, #1
	bls _08001B44
	subs r0, #2
	strb r0, [r2]
	b _08001B4E
	.align 2, 0
_08001B40: .4byte 0x00000642
_08001B44:
	movs r1, #0
	strb r1, [r2]
	ldr r2, _08001B54 @ =0x00000644
	adds r0, r3, r2
	strb r1, [r0]
_08001B4E:
	pop {r0}
	bx r0
	.align 2, 0
_08001B54: .4byte 0x00000644

	thumb_func_start FUN_08001b58
FUN_08001b58: @ 0x08001B58
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x34
	ldr r1, [r4, #0x24]
	ldr r2, [r4, #0x28]
	movs r3, #0xc8
	lsls r3, r3, #3
	adds r0, r4, r3
	ldrb r3, [r0]
	movs r0, #0
	mov r8, r0
	str r0, [sp]
	movs r6, #0xd0
	str r6, [sp, #4]
	adds r0, r5, #0
	bl FUN_08001884
	ldr r1, [r4, #0x2c]
	ldr r2, _08001BC4 @ =0x04000068
	adds r0, r5, #0
	bl CpuSet
	adds r0, r4, #0
	bl FUN_080019dc
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r3, _08001BC8 @ =0x00000434
	adds r2, r4, r3
	ldr r3, _08001BCC @ =0x00000642
	adds r1, r4, r3
	ldrb r3, [r1]
	mov r1, r8
	str r1, [sp]
	str r6, [sp, #4]
	adds r1, r5, #0
	bl FUN_08001884
	str r5, [r4, #0x30]
	adds r4, #0x20
	movs r0, #1
	strb r0, [r4]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08001BC4: .4byte 0x04000068
_08001BC8: .4byte 0x00000434
_08001BCC: .4byte 0x00000642

	thumb_func_start FUN_08001bd0
FUN_08001bd0: @ 0x08001BD0
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r6, #0x34
	str r6, [r0, #0x30]
	movs r4, #0
	movs r5, #0xd0
	ldr r1, [r0, #0x24]
	ldr r2, [r0, #0x28]
	movs r3, #0xc8
	lsls r3, r3, #3
	adds r7, r0, r3
	ldrb r3, [r7]
	str r4, [sp]
	str r5, [sp, #4]
	adds r0, r6, #0
	bl FUN_08001884
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3f
	bls _08001C06
	movs r0, #0x40
	strb r0, [r7]
_08001C06:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08001c10
FUN_08001c10: @ 0x08001C10
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	bl FUN_08017b70
	cmp r0, #0
	beq _08001C98
	ldr r0, _08001CA4 @ =0x0000064A
	adds r0, r0, r6
	mov r8, r0
	ldrh r0, [r0]
	cmp r0, #0
	bne _08001C42
	ldr r1, _08001CA8 @ =0x085AA624
	ldr r2, _08001CAC @ =0x00000644
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
_08001C42:
	ldr r7, _08001CB0 @ =0x00000642
	adds r3, r6, r7
	ldr r0, _08001CB4 @ =0x00000643
	adds r1, r6, r0
	ldrb r0, [r3]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08001C5E
	movs r1, #0xc8
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0x3f
	bhi _08001C7E
_08001C5E:
	movs r5, #0
	movs r4, #0xd0
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r0, r6, r2
	adds r1, r6, #0
	adds r1, #0x34
	ldr r7, _08001CB8 @ =0x00000434
	adds r2, r6, r7
	ldrb r3, [r3]
	str r5, [sp]
	str r4, [sp, #4]
	bl FUN_08001884
	mov r0, r8
	strh r5, [r0]
_08001C7E:
	ldr r2, _08001CB0 @ =0x00000642
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08001C90
	movs r7, #0x8d
	lsls r7, r7, #2
	adds r0, r6, r7
	str r0, [r6, #0x30]
_08001C90:
	ldrb r1, [r1]
	ldr r2, _08001CB4 @ =0x00000643
	adds r0, r6, r2
	strb r1, [r0]
_08001C98:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001CA4: .4byte 0x0000064A
_08001CA8: .4byte 0x085AA624
_08001CAC: .4byte 0x00000644
_08001CB0: .4byte 0x00000642
_08001CB4: .4byte 0x00000643
_08001CB8: .4byte 0x00000434

	thumb_func_start FUN_08001cbc
FUN_08001cbc: @ 0x08001CBC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	ldr r0, _08001D38 @ =0x00000654
	add r0, r8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	mov sb, r0
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, r8
	ldrb r2, [r0]
	ldr r0, _08001D3C @ =0x00000659
	add r0, r8
	ldrb r0, [r0]
	adds r0, r2, r0
	str r0, [sp, #4]
	cmp r0, #0xc
	ble _08001CF8
	ldr r1, _08001D40 @ =0x0000065A
	add r1, r8
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xd
	str r0, [sp, #4]
_08001CF8:
	mov r1, sb
	cmp r1, #0x1f
	ble _08001D4C
	adds r4, r2, #0
	mov r2, r8
	adds r2, #0x20
	str r2, [sp, #0xc]
	ldr r3, [sp, #4]
	cmp r4, r3
	bge _08001DF0
_08001D0C:
	ldr r0, _08001D44 @ =0x0000065C
	add r0, r8
	ldrh r0, [r0]
	asrs r0, r4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08001D2E
	lsls r2, r4, #5
	mov r7, r8
	ldr r0, [r7, #0x28]
	adds r0, r0, r2
	ldr r1, [r7, #0x2c]
	adds r1, r1, r2
	ldr r2, _08001D48 @ =0x04000008
	bl CpuSet
_08001D2E:
	adds r4, #1
	ldr r0, [sp, #4]
	cmp r4, r0
	blt _08001D0C
	b _08001DF0
	.align 2, 0
_08001D38: .4byte 0x00000654
_08001D3C: .4byte 0x00000659
_08001D40: .4byte 0x0000065A
_08001D44: .4byte 0x0000065C
_08001D48: .4byte 0x04000008
_08001D4C:
	movs r0, #0x20
	mov r1, sb
	subs r1, r0, r1
	str r1, [sp]
	adds r4, r2, #0
	mov r2, r8
	adds r2, #0x20
	str r2, [sp, #0xc]
	ldr r3, [sp, #4]
	cmp r4, r3
	bge _08001DF0
	ldr r7, _08001E14 @ =0x0000065C
	add r7, r8
	str r7, [sp, #8]
_08001D68:
	ldr r0, [sp, #8]
	ldrh r1, [r0]
	asrs r1, r4
	movs r0, #1
	ands r1, r0
	adds r2, r4, #1
	str r2, [sp, #0x10]
	cmp r1, #0
	beq _08001DE8
	lsls r1, r4, #5
	mov r3, r8
	ldr r0, [r3, #0x2c]
	adds r0, r0, r1
	str r0, [sp, #0x14]
	ldr r0, [r3, #0x24]
	adds r6, r0, r1
	ldr r0, [r3, #0x28]
	adds r5, r0, r1
	movs r7, #0xf8
	lsls r7, r7, #2
	mov sl, r7
	movs r0, #0xf
	mov ip, r0
_08001D96:
	ldrh r0, [r6]
	ldr r3, _08001E18 @ =0x00007C1F
	ands r3, r0
	mov r4, sl
	ands r4, r0
	ldrh r1, [r5]
	adds r0, r1, #0
	ldr r2, _08001E18 @ =0x00007C1F
	ands r0, r2
	mov r2, sb
	muls r2, r0, r2
	ldr r7, [sp]
	adds r0, r3, #0
	muls r0, r7, r0
	adds r2, r2, r0
	ldr r0, _08001E1C @ =0x000F83E0
	ands r2, r0
	mov r0, sl
	ands r1, r0
	mov r0, sb
	muls r0, r1, r0
	adds r1, r4, #0
	muls r1, r7, r1
	adds r0, r0, r1
	movs r1, #0xf8
	lsls r1, r1, #7
	ands r0, r1
	orrs r2, r0
	lsrs r2, r2, #5
	ldr r1, [sp, #0x14]
	strh r2, [r1]
	adds r1, #2
	str r1, [sp, #0x14]
	adds r6, #2
	adds r5, #2
	movs r2, #1
	rsbs r2, r2, #0
	add ip, r2
	mov r3, ip
	cmp r3, #0
	bge _08001D96
_08001DE8:
	ldr r4, [sp, #0x10]
	ldr r7, [sp, #4]
	cmp r4, r7
	blt _08001D68
_08001DF0:
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, r8
	mov r1, sp
	ldrb r1, [r1, #4]
	strb r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0xc]
	strb r0, [r2]
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001E14: .4byte 0x0000065C
_08001E18: .4byte 0x00007C1F
_08001E1C: .4byte 0x000F83E0

	thumb_func_start FUN_08001e20
FUN_08001e20: @ 0x08001E20
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r2, [r4, #0x1d]
	lsls r6, r2, #4
	ldrb r1, [r4, #0x1a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08001E3A
	lsls r1, r2, #5
	ldr r0, [r4, #0x30]
	b _08001E3E
_08001E3A:
	lsls r1, r2, #5
	ldr r0, [r4, #0x24]
_08001E3E:
	adds r5, r0, r1
	ldrb r3, [r4, #0x1d]
	ldrb r2, [r4, #0x1f]
	adds r0, r3, r2
	cmp r0, #0xd
	bgt _08001E4E
	lsls r1, r2, #4
	b _08001E54
_08001E4E:
	movs r0, #0xd
	subs r0, r0, r3
	lsls r1, r0, #4
_08001E54:
	ldr r0, [r4, #0x2c]
	ldr r2, [r4, #0x28]
	movs r3, #0x1c
	ldrsb r3, [r4, r3]
	str r6, [sp]
	str r1, [sp, #4]
	adds r1, r5, #0
	bl FUN_08001884
	ldrb r0, [r4, #0x1f]
	ldrb r1, [r4, #0x1d]
	adds r0, r0, r1
	movs r1, #0
	strb r0, [r4, #0x1d]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bls _08001E92
	strb r1, [r4, #0x1d]
	ldrb r0, [r4, #0x1e]
	ldrb r2, [r4, #0x1c]
	adds r0, r0, r2
	strb r0, [r4, #0x1c]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x40
	ble _08001E92
	strb r1, [r4, #0x1c]
	ldr r0, [r4, #0x28]
	str r0, [r4, #0x24]
	strb r1, [r4, #0x1b]
_08001E92:
	adds r1, r4, #0
	adds r1, #0x20
	movs r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08001ea4
FUN_08001ea4: @ 0x08001EA4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _08001EE4 @ =0x03004040
	ldr r0, _08001EE8 @ =0x0000063C
	adds r2, r4, r0
	ldrh r1, [r2]
	lsls r1, r1, #6
	adds r0, #2
	adds r3, r4, r0
	ldrh r0, [r3]
	asrs r1, r0
	movs r0, #0x40
	subs r0, r0, r1
	str r0, [r5]
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #1
	ldrh r3, [r3]
	lsls r0, r3
	cmp r1, r0
	blt _08001EF0
	movs r0, #0
	str r0, [r5]
	ldrb r0, [r4, #0x1b]
	cmp r0, #3
	bne _08001EEC
	movs r0, #0
	b _08001EEE
	.align 2, 0
_08001EE4: .4byte 0x03004040
_08001EE8: .4byte 0x0000063C
_08001EEC:
	movs r0, #6
_08001EEE:
	strb r0, [r4, #0x1b]
_08001EF0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0


	thumb_func_start FUN_08001ef8
FUN_08001ef8: @ 0x08001EF8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _08001F40 @ =0x03004040
	ldr r0, _08001F44 @ =0x0000063C
	adds r2, r4, r0
	ldrh r0, [r2]
	lsls r0, r0, #6
	ldr r1, _08001F48 @ =0x0000063E
	adds r3, r4, r1
	ldrh r1, [r3]
	asrs r0, r1
	str r0, [r5]
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #1
	ldrh r3, [r3]
	lsls r0, r3
	cmp r1, r0
	blt _08001F3A
	bl FUN_0822d00c
	movs r1, #0x40
	str r1, [r5]
	ldr r2, _08001F4C @ =0x03004494
	ldr r3, _08001F50 @ =0x00001084
	adds r1, r3, #0
	strh r1, [r2]
	strh r1, [r0]
	movs r0, #0
	strb r0, [r4, #0x1b]
_08001F3A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08001F40: .4byte 0x03004040
_08001F44: .4byte 0x0000063C
_08001F48: .4byte 0x0000063E
_08001F4C: .4byte 0x03004494
_08001F50: .4byte 0x00001084

	thumb_func_start FUN_08001f54
FUN_08001f54: @ 0x08001F54
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r3, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08001FD8 @ =gEntity4AE5
	ldr r4, [r0]
	cmp r4, #0
	beq _0800200C
	lsls r0, r3, #1
	ldr r3, _08001FDC @ =0x00000634
	adds r5, r4, r3
	adds r3, r5, r0
	movs r6, #0
	strh r1, [r3]
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _08002004
	ldrb r1, [r4, #0x1a]
	ands r0, r1
	cmp r0, #0
	beq _08001FE4
	mov r6, sp
	adds r6, #2
	mov r0, sp
	adds r1, r6, #0
	bl FUN_0823ce10
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, r5, r0
	ldrh r1, [r0]
	ldr r0, _08001FE0 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r4, #0x24]
	ldrh r0, [r6]
	lsls r0, r0, #1
	adds r0, r5, r0
	ldrh r1, [r0]
	ldr r0, _08001FE0 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r4, #0x28]
	mov r0, sp
	ldrh r0, [r0]
	cmp r0, #2
	beq _08001FC2
	ldrh r0, [r6]
	cmp r0, #2
	bne _08001FC8
_08001FC2:
	adds r0, r4, #0
	bl FUN_080019dc
_08001FC8:
	adds r0, r4, #0
	bl FUN_08001b58
	movs r0, #0
	strb r0, [r4, #0x1d]
	movs r0, #0x40
	strb r0, [r4, #0x1c]
	b _08001FFC
	.align 2, 0
_08001FD8: .4byte gEntity4AE5
_08001FDC: .4byte 0x00000634
_08001FE0: .4byte 0x000092B3
_08001FE4:
	ldrh r1, [r3]
	ldr r0, _08002014 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r4, #0x24]
	ldr r1, [r4, #0x2c]
	ldr r2, _08002018 @ =0x04000068
	bl CpuSet
	strb r6, [r4, #0x1d]
	strb r6, [r4, #0x1c]
_08001FFC:
	movs r0, #7
	strb r0, [r4, #0x1e]
	movs r0, #4
	strb r0, [r4, #0x1f]
_08002004:
	adds r1, r4, #0
	adds r1, #0x20
	movs r0, #1
	strb r0, [r1]
_0800200C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08002014: .4byte 0x000092B3
_08002018: .4byte 0x04000068
