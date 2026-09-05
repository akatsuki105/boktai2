	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0800c40c
FUN_0800c40c: @ 0x0800C40C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	adds r6, r4, #0
	bl FUN_08236524
	ldrh r1, [r5, #0x3e]
	cmp r1, #0
	beq _0800C458
	ldrh r0, [r4, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0800C432
	movs r0, #0
	strh r0, [r4, #2]
	b _0800C454
_0800C432:
	movs r0, #0xa
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0xb8
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	movs r1, #4
	ldr r0, [r7, #0x34]
	ands r0, r1
	cmp r0, #0
	bne _0800C454
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0800C454:
	movs r0, #0
	strh r0, [r5, #0x3e]
_0800C458:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800c460
FUN_0800c460: @ 0x0800C460
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r0, r6, #0
	adds r0, #0x2c
	bl FUN_08236424
	adds r0, r6, #0
	adds r0, #0x8c
	bl FUN_0822a4e0
	adds r0, r6, #0
	adds r0, #0x7c
	bl FUN_082342a8
	movs r2, #1
	lsls r2, r5
	ldr r1, [r4, #0x1c]
	bics r1, r2
	str r1, [r4, #0x1c]
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800c490
FUN_0800c490: @ 0x0800C490
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	movs r0, #0xa5
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r6, #0x14
	movs r7, #0x1e
	str r7, [sp]
	movs r5, #0x10
	str r5, [sp, #4]
	movs r4, #8
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0
	mov sl, r0
	str r0, [sp, #0x10]
	movs r0, #0x80
	lsls r0, r0, #1
	mov sb, r0
	str r0, [sp, #0x14]
	movs r0, #0x18
	mov r8, r0
	str r0, [sp, #0x18]
	str r5, [sp, #0x1c]
	movs r0, #3
	movs r1, #3
	adds r2, r6, #0
	movs r3, #0x3c
	bl FUN_08014da0
	str r7, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sl
	str r0, [sp, #0x10]
	mov r0, sb
	str r0, [sp, #0x14]
	mov r0, r8
	str r0, [sp, #0x18]
	str r5, [sp, #0x1c]
	movs r0, #8
	movs r1, #7
	adds r2, r6, #0
	movs r3, #0x3c
	bl FUN_08014da0
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800c50c
FUN_0800c50c: @ 0x0800C50C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r7, r0, #0
	ldr r0, _0800C5B8 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0
	mov sb, r1
	cmp r0, #0
	beq _0800C52A
	adds r0, #0x2c
	mov sb, r0
_0800C52A:
	movs r4, #0
	ldr r6, [r7, #0x20]
	mov r8, r4
	ldrb r2, [r7, #0x18]
	cmp r8, r2
	blt _0800C538
	b _0800C66E
_0800C538:
	movs r0, #4
	mov sl, r0
	adds r5, r6, #0
_0800C53E:
	movs r1, #1
	mov r2, r8
	lsls r1, r2
	ldr r0, [r7, #0x1c]
	ands r0, r1
	cmp r0, #0
	bne _0800C54E
	b _0800C65E
_0800C54E:
	movs r1, #2
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bgt _0800C5C0
	ldrh r0, [r5, #8]
	cmp r0, #0
	beq _0800C5A6
	ldrh r0, [r5]
	str r0, [sp]
	movs r2, #0x14
	ldrsh r0, [r5, r2]
	str r0, [sp, #4]
	movs r1, #0x16
	ldrsh r0, [r5, r1]
	str r0, [sp, #8]
	movs r2, #0x18
	ldrsh r0, [r5, r2]
	str r0, [sp, #0xc]
	movs r1, #0xc
	ldrsh r0, [r5, r1]
	str r0, [sp, #0x10]
	movs r2, #0xe
	ldrsh r0, [r5, r2]
	str r0, [sp, #0x14]
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	str r0, [sp, #0x18]
	movs r2, #0x12
	ldrsh r0, [r5, r2]
	str r0, [sp, #0x1c]
	ldr r1, _0800C5BC @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r5, #8]
	bl Script_ExecById
	movs r0, #0
	strh r0, [r5, #8]
_0800C5A6:
	adds r0, r6, #0
	bl FUN_0800c490
	adds r0, r7, #0
	adds r1, r6, #0
	mov r2, r8
	bl FUN_0800c460
	b _0800C65E
	.align 2, 0
_0800C5B8: .4byte 0x03002BE0
_0800C5BC: .4byte 0xFFFF0000
_0800C5C0:
	ldrb r1, [r5, #0xa]
	cmp r1, #0
	beq _0800C5E8
	ldrh r0, [r5, #0x32]
	mov r2, sl
	orrs r0, r2
	strh r0, [r5, #0x32]
	subs r0, r1, #1
	strb r0, [r5, #0xa]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800C5F2
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r1, _0800C5E4 @ =0x0000011B
	bl FUN_0822b20c
	b _0800C5F2
	.align 2, 0
_0800C5E4: .4byte 0x0000011B
_0800C5E8:
	ldrh r1, [r5, #0x32]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r5, #0x32]
_0800C5F2:
	mov r0, sb
	cmp r0, #0
	beq _0800C65E
	cmp r4, #0
	bne _0800C65E
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0x1c
	ldrsh r0, [r5, r2]
	cmp r1, r0
	blt _0800C640
	movs r2, #0x24
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bgt _0800C640
	mov r0, sb
	movs r2, #2
	ldrsh r1, [r0, r2]
	movs r2, #0x1e
	ldrsh r0, [r5, r2]
	cmp r1, r0
	blt _0800C640
	movs r2, #0x26
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bgt _0800C640
	mov r0, sb
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r2, #0x20
	ldrsh r0, [r5, r2]
	cmp r1, r0
	blt _0800C640
	movs r2, #0x28
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bgt _0800C640
	movs r0, #1
	b _0800C642
_0800C640:
	movs r0, #0
_0800C642:
	cmp r0, #0
	beq _0800C65E
	adds r4, r7, #0
	adds r4, #0x24
	adds r1, r6, #0
	adds r1, #0x14
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	movs r4, #1
_0800C65E:
	movs r0, #1
	add r8, r0
	adds r5, #0xd4
	adds r6, #0xd4
	ldrb r1, [r7, #0x18]
	cmp r8, r1
	bge _0800C66E
	b _0800C53E
_0800C66E:
	movs r0, #0
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800c680
FUN_0800c680: @ 0x0800C680
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x20]
	cmp r1, #0
	beq _0800C6BA
	adds r6, r1, #0
	movs r5, #0
	b _0800C6AA
_0800C690:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r4, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _0800C6A6
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl FUN_0800c460
_0800C6A6:
	adds r5, #1
	adds r6, #0xd4
_0800C6AA:
	ldrb r0, [r4, #0x18]
	cmp r5, r0
	blt _0800C690
	ldr r0, [r4, #0x20]
	bl Free
	movs r0, #0
	str r0, [r4, #0x20]
_0800C6BA:
	ldr r1, _0800C6C8 @ =0x03002B34
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0800C6C8: .4byte 0x03002B34

	thumb_func_start FUN_0800c6cc
FUN_0800c6cc: @ 0x0800C6CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	ldr r0, _0800C788 @ =0x03002B34
	str r7, [r0]
	movs r0, #0x6d
	movs r1, #8
	bl VM_GetKeywordValue
	movs r5, #0
	strb r0, [r7, #0x18]
	str r5, [r7, #0x1c]
	movs r0, #0x70
	movs r1, #5
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x66
	movs r1, #0xa
	bl VM_GetKeywordValue
	mov r8, r0
	movs r0, #0x69
	movs r1, #0xa
	bl VM_GetKeywordValue
	adds r6, r0, #0
	adds r4, r7, #0
	adds r4, #0x24
	ldr r2, _0800C78C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0xa4
	orrs r0, r3
	ldr r1, _0800C790 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0800C794 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r4, #0
	movs r1, #0
	adds r2, r7, #0
	bl FUN_0823651c
	str r5, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	mov r1, sb
	mov r2, r8
	movs r3, #0
	bl FUN_082364f8
	ldrb r0, [r7, #0x18]
	movs r4, #0xd4
	muls r0, r4, r0
	bl Malloc
	adds r3, r0, #0
	str r3, [r7, #0x20]
	cmp r3, #0
	beq _0800C798
	ldrb r0, [r7, #0x18]
	adds r1, r0, #0
	muls r1, r4, r1
	adds r0, r3, #0
	bl ClearMemory
	movs r0, #0
	b _0800C79C
	.align 2, 0
_0800C788: .4byte 0x03002B34
_0800C78C: .4byte 0xFFFF0000
_0800C790: .4byte 0x0000FFFF
_0800C794: .4byte 0x00002001
_0800C798:
	movs r0, #1
	rsbs r0, r0, #0
_0800C79C:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800c7ac
FUN_0800c7ac: @ 0x0800C7AC
	push {r4, lr}
	ldr r0, _0800C7E0 @ =0x03002B34
	ldr r0, [r0]
	cmp r0, #0
	bne _0800C7EE
	movs r0, #8
	movs r1, #0x74
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800C7EC
	ldr r1, _0800C7E4 @ =FUN_0800c50c
	ldr r2, _0800C7E8 @ =FUN_0800c680
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0800c6cc
	cmp r0, #0
	bge _0800C7EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800C7EE
	.align 2, 0
_0800C7E0: .4byte 0x03002B34
_0800C7E4: .4byte FUN_0800c50c
_0800C7E8: .4byte FUN_0800c680
_0800C7EC:
	adds r0, r4, #0
_0800C7EE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800c7f4
FUN_0800c7f4: @ 0x0800C7F4
	push {r4, lr}
	movs r1, #0
	ldrb r2, [r0, #0x18]
	cmp r1, r2
	bge _0800C816
	movs r4, #1
	ldr r3, [r0, #0x1c]
_0800C802:
	adds r0, r4, #0
	lsls r0, r1
	ands r0, r3
	cmp r0, #0
	bne _0800C810
	adds r0, r1, #0
	b _0800C81A
_0800C810:
	adds r1, #1
	cmp r1, r2
	blt _0800C802
_0800C816:
	movs r0, #1
	rsbs r0, r0, #0
_0800C81A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800c820
FUN_0800c820: @ 0x0800C820
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	str r0, [sp, #0x1c]
	adds r4, r1, #0
	adds r6, r2, #0
	str r3, [sp, #0x20]
	ldr r7, [sp, #0x50]
	ldr r0, _0800C870 @ =0x03002B34
	ldr r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _0800C842
	b _0800CA0A
_0800C842:
	mov r0, sl
	bl FUN_0800c7f4
	str r0, [sp, #0x24]
	cmp r0, #0
	bge _0800C850
	b _0800CA0A
_0800C850:
	movs r0, #0xd4
	ldr r2, [sp, #0x24]
	adds r1, r2, #0
	muls r1, r0, r1
	mov r3, sl
	ldr r0, [r3, #0x20]
	adds r5, r0, r1
	strh r4, [r5]
	strh r6, [r5, #2]
	cmp r7, #0
	beq _0800C874
	ldr r0, [sp, #0x1c]
	bl FUN_08241574
	str r0, [r5, #4]
	b _0800C876
	.align 2, 0
_0800C870: .4byte 0x03002B34
_0800C874:
	str r7, [r5, #4]
_0800C876:
	ldr r0, [r5, #4]
	cmp r0, #0
	bge _0800C87E
	b _0800CA0A
_0800C87E:
	ldr r0, [sp, #0x54]
	strh r0, [r5, #8]
	adds r7, r5, #0
	adds r7, #0x14
	adds r6, r5, #0
	adds r6, #0x2c
	add r4, sp, #0x14
	movs r0, #0x1c
	adds r0, r0, r5
	mov r8, r0
	movs r1, #0x24
	adds r1, r1, r5
	mov sb, r1
	adds r2, r5, #0
	adds r2, #0x7c
	str r2, [sp, #0x28]
	adds r3, r5, #0
	adds r3, #0xb8
	str r3, [sp, #0x2c]
	ldr r3, [sp, #0x58]
	adds r1, r5, #0
	adds r1, #0xc
	movs r2, #3
_0800C8AC:
	ldm r3!, {r0}
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800C8AC
	ldr r2, [sp, #0x1c]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x14]
	str r1, [r5, #0x18]
	ldr r2, _0800C990 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x82
	orrs r0, r3
	ldr r1, _0800C994 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldrh r1, [r5]
	ldr r2, _0800C998 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r3, sp, #0xc
	str r3, [sp, #4]
	str r4, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	ldr r1, _0800C99C @ =FUN_0800c40c
	adds r0, r6, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r0, r6, #0
	bl FUN_08236400
	ldr r1, _0800C9A0 @ =0x0000FF5C
	ldr r0, _0800C9A4 @ =0x0000FF80
	strh r0, [r5, #0x1e]
	strh r1, [r5, #0x20]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	ldrh r0, [r7, #2]
	mov r1, r8
	ldrh r1, [r1, #2]
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2, #2]
	ldrh r0, [r7, #4]
	ldrh r3, [r2, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r1, #0xa4
	movs r0, #0x80
	strh r0, [r5, #0x26]
	strh r1, [r5, #0x28]
	ldrh r0, [r5, #0x14]
	adds r0, #0xa4
	strh r0, [r5, #0x24]
	ldrh r0, [r7, #2]
	mov r1, sb
	ldrh r1, [r1, #2]
	adds r0, r0, r1
	mov r2, sb
	strh r0, [r2, #2]
	ldrh r0, [r7, #4]
	ldrh r3, [r2, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	ldrh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800C98C
	cmp r1, #0
	blt _0800C98C
	ldr r0, _0800C9A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800C98C
	ldr r0, _0800C9AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800C9B0
_0800C98C:
	movs r4, #0
	b _0800C9BE
	.align 2, 0
_0800C990: .4byte 0xFFFF0000
_0800C994: .4byte 0x0000FFFF
_0800C998: .4byte 0x00004001
_0800C99C: .4byte FUN_0800c40c
_0800C9A0: .4byte 0x0000FF5C
_0800C9A4: .4byte 0x0000FF80
_0800C9A8: .4byte 0x030046A8
_0800C9AC: .4byte 0x030046AC
_0800C9B0:
	ldr r0, _0800C9D0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0800C9BE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800C9D4
	adds r0, #4
	b _0800C9E0
	.align 2, 0
_0800C9D0: .4byte 0x030046A4
_0800C9D4:
	ldr r0, _0800CA10 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800C9E0:
	ldrb r0, [r0]
	movs r3, #0xf
	ands r3, r0
	cmp r3, #0xe
	bgt _0800C9EC
	adds r3, #1
_0800C9EC:
	movs r0, #0xff
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	ldr r0, [sp, #0x28]
	adds r1, r4, #0
	movs r2, #0
	bl FUN_08234270
	ldr r1, _0800CA14 @ =0x000004B3
	ldr r0, [sp, #0x2c]
	bl Video_GetActorSprite
	cmp r0, #0
	bne _0800CA18
_0800CA0A:
	movs r0, #1
	rsbs r0, r0, #0
	b _0800CA46
	.align 2, 0
_0800CA10: .4byte 0x030046A4
_0800CA14: .4byte 0x000004B3
_0800CA18:
	adds r4, r5, #0
	adds r4, #0x8c
	adds r0, r4, #0
	ldr r1, [sp, #0x2c]
	movs r2, #0
	bl FUN_0822a470
	mov r1, sp
	ldrh r1, [r1, #0x20]
	strh r1, [r4, #0x10]
	adds r3, r5, #0
	adds r3, #0xa8
	ldr r1, [r5, #0x14]
	ldr r2, [r5, #0x18]
	str r1, [r3]
	str r2, [r3, #4]
	movs r2, #1
	ldr r3, [sp, #0x24]
	lsls r2, r3
	mov r3, sl
	ldr r1, [r3, #0x1c]
	orrs r1, r2
	str r1, [r3, #0x1c]
_0800CA46:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800ca58
FUN_0800ca58: @ 0x0800CA58
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	mov sl, r0
	movs r0, #0x6c
	movs r1, #0x64
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x74
	movs r1, #1
	bl VM_GetKeywordValue
	mov r8, r0
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800CABC
	add r5, sp, #0x1c
	add r4, sp, #0xc
_0800CAA4:
	bl VM_GetPC
	cmp r0, #0
	beq _0800CAB0
	bl Script_GetValue
_0800CAB0:
	str r0, [r4]
	adds r4, #4
	add r0, sp, #0x18
	cmp r4, r0
	ble _0800CAA4
	b _0800CACC
_0800CABC:
	add r5, sp, #0x1c
	movs r1, #0
	add r0, sp, #0x18
_0800CAC2:
	str r1, [r0]
	subs r0, #4
	add r2, sp, #0xc
	cmp r0, r2
	bge _0800CAC2
_0800CACC:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800CB14
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800CB0C @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800CB10 @ =0x0000FFFF
	ldr r1, [sp, #0x1c]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r5, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r5, #4]
	b _0800CB1E
	.align 2, 0
_0800CB0C: .4byte 0xFFFF0000
_0800CB10: .4byte 0x0000FFFF
_0800CB14:
	ldr r1, _0800CB68 @ =0xFFFF0000
	str r0, [sp, #0x1c]
	ldr r0, [r5, #4]
	ands r0, r1
	str r0, [r5, #4]
_0800CB1E:
	ldr r0, _0800CB6C @ =0xFFFFFF00
	adds r4, r0, #0
	ldrh r1, [r5]
	ands r1, r4
	movs r0, #0x80
	orrs r1, r0
	ldr r3, _0800CB68 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r0, sp, #0x1c
	ldrh r2, [r0, #4]
	ands r2, r4
	movs r1, #0x80
	orrs r2, r1
	ldr r1, [r0, #4]
	ands r1, r3
	orrs r1, r2
	str r1, [r0, #4]
	str r7, [sp]
	str r6, [sp, #4]
	add r1, sp, #0xc
	str r1, [sp, #8]
	mov r1, sl
	mov r2, sb
	mov r3, r8
	bl FUN_0800c820
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800CB68: .4byte 0xFFFF0000
_0800CB6C: .4byte 0xFFFFFF00

	thumb_func_start FUN_0800cb70
FUN_0800cb70: @ 0x0800CB70
	ldr r0, _0800CB78 @ =0x03002B38
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0800CB78: .4byte 0x03002B38

	thumb_func_start FUN_0800cb7c
FUN_0800cb7c: @ 0x0800CB7C
	push {r4, r5, lr}
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0800CBC8
	adds r0, r4, #0
	adds r0, #0xa8
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0xf0
	bl FUN_0822a4e0
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_082342a8
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08236424
	ldrh r1, [r4, #0x28]
	movs r0, #1
	ands r0, r1
	adds r5, r4, #0
	adds r5, #0x48
	cmp r0, #0
	bne _0800CBBE
	adds r0, r5, #0
	bl FUN_08002a58
_0800CBBE:
	adds r0, r5, #0
	bl FUN_0823b284
	movs r0, #0
	strb r0, [r4]
_0800CBC8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800cbd0
FUN_0800cbd0: @ 0x0800CBD0
	push {r4, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #4]
	ldrh r1, [r1, #4]
	cmp r0, r1
	beq _0800CBFE
	movs r0, #7
	ldr r1, [r3, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0800CBFE
	adds r4, r2, #0
	adds r4, #0x40
	ldrb r0, [r4]
	cmp r0, #0
	bne _0800CBFE
	movs r0, #1
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r3, #0x38]
	str r0, [r2, #0x24]
	movs r0, #0xa
	strb r0, [r4]
_0800CBFE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800cc04
FUN_0800cc04: @ 0x0800CC04
	bx lr
	.align 2, 0

	thumb_func_start FUN_0800cc08
FUN_0800cc08: @ 0x0800CC08
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r0, #0x90
	lsls r0, r0, #1
	adds r6, r3, r0
	adds r0, r3, #0
	adds r0, #0x31
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r2, #3
	ldr r0, _0800CC64 @ =0x030046A4
	ldr r4, [r0]
	ands r1, r2
	lsls r1, r1, #1
	adds r0, r4, #0
	adds r0, #0x1c
	adds r0, r0, r1
	movs r1, #0
	ldrsh r5, [r0, r1]
	adds r1, r3, #0
	adds r1, #0x50
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800CC5E
	cmp r1, #0
	blt _0800CC5E
	ldr r0, _0800CC68 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800CC5E
	ldr r0, _0800CC6C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800CC70
_0800CC5E:
	movs r0, #0
	b _0800CC7C
	.align 2, 0
_0800CC64: .4byte 0x030046A4
_0800CC68: .4byte 0x030046A8
_0800CC6C: .4byte 0x030046AC
_0800CC70:
	lsls r0, r1, #1
	adds r1, r4, #0
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r0, r2
_0800CC7C:
	adds r4, r0, r5
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800CC8E
	adds r3, r0, #4
	b _0800CC9A
_0800CC8E:
	ldr r0, _0800CCC4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r3, r1, r0
_0800CC9A:
	cmp r3, #0
	beq _0800CCC8
	ldrb r4, [r3]
	lsrs r0, r4, #4
	cmp r0, #0
	bne _0800CCC8
	movs r0, #0xf
	ldrb r2, [r6]
	adds r1, r0, #0
	ands r1, r4
	ands r0, r2
	cmp r1, r0
	bhs _0800CCC8
	ldrh r1, [r3, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0800CCC8
	movs r0, #1
	b _0800CCCA
	.align 2, 0
_0800CCC4: .4byte 0x030046A4
_0800CCC8:
	movs r0, #0
_0800CCCA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800ccd0
FUN_0800ccd0: @ 0x0800CCD0
	push {r4, r5, lr}
	adds r4, r1, #0
	ldrb r5, [r4, #3]
	cmp r5, #1
	bne _0800CD24
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _0800CCE6
	ldr r0, _0800CD20 @ =0x00000219
	bl PlaySound_082406e0
_0800CCE6:
	ldrb r1, [r4, #2]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r4, #2]
	adds r0, r4, #0
	adds r0, #0x42
	ldrh r0, [r0]
	strh r0, [r4, #0x38]
	movs r0, #3
	strb r0, [r4, #3]
	str r2, [r4, #4]
	strb r5, [r4, #1]
	adds r1, r4, #0
	adds r1, #0x41
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	movs r0, #1
	b _0800CD64
	.align 2, 0
_0800CD20: .4byte 0x00000219
_0800CD24:
	movs r0, #1
	ldrb r1, [r4, #2]
	ands r0, r1
	cmp r0, #0
	bne _0800CD62
	cmp r1, #0
	bne _0800CD38
	ldr r0, _0800CD6C @ =0x00000219
	bl PlaySound_082406e0
_0800CD38:
	ldrb r1, [r4, #2]
	movs r0, #1
	orrs r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r4, #2]
	adds r0, r4, #0
	adds r0, #0x42
	ldrh r0, [r0]
	strh r0, [r4, #0x38]
	adds r1, r4, #0
	adds r1, #0x41
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
_0800CD62:
	movs r0, #0
_0800CD64:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800CD6C: .4byte 0x00000219

	thumb_func_start FUN_0800cd70
FUN_0800cd70: @ 0x0800CD70
	push {lr}
	adds r2, r1, #0
	ldrb r3, [r2, #3]
	cmp r3, #0
	beq _0800CD7E
	movs r0, #0
	b _0800CDAE
_0800CD7E:
	movs r0, #2
	movs r1, #2
	strb r0, [r2, #3]
	str r3, [r2, #4]
	movs r0, #1
	strb r0, [r2, #1]
	ldrb r0, [r2, #2]
	orrs r1, r0
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	strb r1, [r2, #2]
	strh r3, [r2, #0x38]
	adds r1, r2, #0
	adds r1, #0x41
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x8c
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	movs r0, #1
_0800CDAE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800cdb4
FUN_0800cdb4: @ 0x0800CDB4
	push {r4, lr}
	adds r2, r1, #0
	ldrh r1, [r2, #0x3e]
	subs r1, #1
	movs r3, #0
	strh r1, [r2, #0x3e]
	movs r4, #0xa
	movs r0, #0xa
	strh r0, [r2, #0x3a]
	lsls r1, r1, #0x10
	cmp r1, #0
	bgt _0800CE02
	strh r3, [r2, #0x3e]
	ldrb r0, [r2, #3]
	cmp r0, #1
	bhi _0800CE18
	ldrb r1, [r2, #2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2, #2]
	movs r0, #6
	strb r0, [r2, #3]
	str r3, [r2, #4]
	movs r0, #1
	strb r0, [r2, #1]
	adds r0, r2, #0
	adds r0, #0x41
	strb r4, [r0]
	adds r0, #0x4b
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	movs r0, #0x85
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r0, #1
	b _0800CE1A
_0800CE02:
	adds r0, r2, #0
	adds r0, #0x41
	strb r4, [r0]
	adds r0, #0x4b
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	ldr r0, _0800CE20 @ =0x00000217
	bl PlaySound_082406e0
_0800CE18:
	movs r0, #0
_0800CE1A:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800CE20: .4byte 0x00000217

	thumb_func_start FUN_0800ce24
FUN_0800ce24: @ 0x0800CE24
	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	ldrb r0, [r6, #3]
	cmp r0, #0
	bne _0800CF14
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r3, r6, r0
	ldr r0, _0800CE60 @ =0x03002BE0
	ldr r1, [r0]
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800CE5C
	cmp r1, #0
	blt _0800CE5C
	ldr r0, _0800CE64 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800CE5C
	ldr r0, _0800CE68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800CE6C
_0800CE5C:
	movs r0, #0
	b _0800CE7A
	.align 2, 0
_0800CE60: .4byte 0x03002BE0
_0800CE64: .4byte 0x030046A8
_0800CE68: .4byte 0x030046AC
_0800CE6C:
	ldr r0, _0800CEA0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0800CE7A:
	ldrh r1, [r3, #2]
	movs r2, #2
	bl FUN_08232888
	cmp r0, #0
	blt _0800CF04
	adds r1, r6, #0
	adds r1, #0x31
	strb r0, [r1]
	ldr r0, [r6, #0x20]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0800CEA4
	adds r0, r6, #0
	adds r0, #0x30
	strb r1, [r0]
	adds r7, r0, #0
	b _0800CEAE
	.align 2, 0
_0800CEA0: .4byte 0x030046A4
_0800CEA4:
	adds r1, r6, #0
	adds r1, #0x30
	movs r0, #1
	strb r0, [r1]
	adds r7, r1, #0
_0800CEAE:
	adds r0, r6, #0
	bl FUN_0800cc08
	cmp r0, #0
	beq _0800CF04
	movs r5, #4
	ldrb r1, [r6, #2]
	movs r0, #4
	movs r4, #0
	orrs r0, r1
	strb r0, [r6, #2]
	adds r1, r6, #0
	adds r1, #0x41
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x8c
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	strb r5, [r6, #3]
	str r4, [r6, #4]
	movs r0, #1
	strb r0, [r6, #1]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #2
	bne _0800CEF4
	ldr r0, _0800CEF0 @ =0x00000216
	bl PlaySound_082406e0
	b _0800CEFA
	.align 2, 0
_0800CEF0: .4byte 0x00000216
_0800CEF4:
	ldr r0, _0800CF00 @ =0x00000215
	bl PlaySound_082406e0
_0800CEFA:
	movs r0, #1
	b _0800CF24
	.align 2, 0
_0800CF00: .4byte 0x00000215
_0800CF04:
	movs r0, #0xa
	strh r0, [r6, #0x3a]
	ldr r0, _0800CF10 @ =0x00000217
	bl PlaySound_082406e0
	b _0800CF22
	.align 2, 0
_0800CF10: .4byte 0x00000217
_0800CF14:
	cmp r0, #1
	bne _0800CF22
	movs r0, #0xa
	strh r0, [r6, #0x3a]
	ldr r0, _0800CF2C @ =0x00000217
	bl PlaySound_082406e0
_0800CF22:
	movs r0, #0
_0800CF24:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800CF2C: .4byte 0x00000217

	thumb_func_start FUN_0800cf30
FUN_0800cf30: @ 0x0800CF30
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	cmp r2, #0
	blt _0800CF44
	movs r1, #1
	ldr r0, [r4, #4]
	ands r0, r1
	ands r1, r2
	cmp r1, r0
	bne _0800CF7E
_0800CF44:
	adds r6, r4, #0
	adds r6, #0x48
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r5, [r0, #2]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_08234224
	cmp r0, #0
	beq _0800CF60
	adds r0, #4
	b _0800CF6C
_0800CF60:
	ldr r0, _0800CF84 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800CF6C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	movs r2, #0xa
	ldrsh r0, [r6, r2]
	subs r0, r0, r1
	cmp r0, #0xff
	bgt _0800CF88
_0800CF7E:
	movs r0, #0
	b _0800CF96
	.align 2, 0
_0800CF84: .4byte 0x030046A4
_0800CF88:
	movs r0, #0
	strh r1, [r4, #0x32]
	movs r1, #5
	strb r1, [r4, #3]
	str r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #1]
_0800CF96:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800cf9c
FUN_0800cf9c: @ 0x0800CF9C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800CFBE
	movs r0, #0
	strb r0, [r4, #1]
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r2, #6]
	orrs r0, r1
	strh r0, [r2, #6]
_0800CFBE:
	ldrh r0, [r4, #0x2a]
	movs r1, #1
	orrs r1, r0
	strh r1, [r4, #0x2a]
	movs r2, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _0800D062
	str r2, [r4, #0x1c]
	ldr r0, [r4, #0x24]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800CFE4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800ccd0
	adds r2, r0, #0
_0800CFE4:
	cmp r2, #0
	bne _0800D02C
	ldr r0, [r4, #0x24]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0800CFFC
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800cd70
	adds r2, r0, #0
_0800CFFC:
	cmp r2, #0
	bne _0800D02C
	ldr r0, [r4, #0x24]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800D014
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800cdb4
	adds r2, r0, #0
_0800D014:
	cmp r2, #0
	bne _0800D02C
	ldr r0, [r4, #0x24]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800D02C
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800ce24
	adds r2, r0, #0
_0800D02C:
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _0800D036
	movs r0, #0x78
	b _0800D05C
_0800D036:
	movs r0, #8
	ldrb r1, [r4, #2]
	ands r0, r1
	cmp r0, #0
	beq _0800D044
	movs r0, #0x7b
	b _0800D05C
_0800D044:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D050
	movs r0, #0x7c
	b _0800D05C
_0800D050:
	movs r0, #1
	ands r1, r0
	movs r0, #0x7a
	cmp r1, #0
	beq _0800D05C
	movs r0, #0x79
_0800D05C:
	strh r0, [r4, #0x2e]
	cmp r2, #0
	bne _0800D06C
_0800D062:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0800cf30
_0800D06C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800d074
FUN_0800d074: @ 0x0800D074
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D086
	movs r0, #0
	strb r0, [r4, #1]
_0800D086:
	movs r2, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _0800D122
	str r2, [r4, #0x1c]
	ldr r0, [r4, #0x24]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D0A4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800ccd0
	adds r2, r0, #0
_0800D0A4:
	cmp r2, #0
	bne _0800D0EC
	ldr r0, [r4, #0x24]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0800D0BC
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800cd70
	adds r2, r0, #0
_0800D0BC:
	cmp r2, #0
	bne _0800D0EC
	ldr r0, [r4, #0x24]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800D0D4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800cdb4
	adds r2, r0, #0
_0800D0D4:
	cmp r2, #0
	bne _0800D0EC
	ldr r0, [r4, #0x24]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800D0EC
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800ce24
	adds r2, r0, #0
_0800D0EC:
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _0800D0F6
	movs r0, #0x78
	b _0800D11C
_0800D0F6:
	movs r0, #8
	ldrb r1, [r4, #2]
	ands r0, r1
	cmp r0, #0
	beq _0800D104
	movs r0, #0x7b
	b _0800D11C
_0800D104:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D110
	movs r0, #0x7c
	b _0800D11C
_0800D110:
	movs r0, #1
	ands r1, r0
	movs r0, #0x7a
	cmp r1, #0
	beq _0800D11C
	movs r0, #0x79
_0800D11C:
	strh r0, [r4, #0x2e]
	cmp r2, #0
	bne _0800D12C
_0800D122:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0800cf30
_0800D12C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800d134
FUN_0800d134: @ 0x0800D134
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D14A
	movs r0, #0
	strb r0, [r4, #1]
	movs r0, #0x86
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0800D14A:
	ldrh r1, [r4, #0x2a]
	movs r0, #0x10
	movs r2, #0
	orrs r0, r1
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0x34]
	subs r0, #2
	strh r0, [r4, #0x34]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0800D174
	strh r2, [r4, #0x34]
	movs r0, #1
	strb r0, [r4, #3]
	str r2, [r4, #4]
	strb r0, [r4, #1]
	adds r0, r4, #0
	adds r0, #0x50
	movs r1, #0x80
	bl FUN_08003014
_0800D174:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800d17c
FUN_0800d17c: @ 0x0800D17C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D192
	movs r0, #0
	strb r0, [r4, #1]
	ldr r0, _0800D1C8 @ =0x0000021A
	bl PlaySound_082406e0
_0800D192:
	ldrh r1, [r4, #0x2a]
	movs r0, #0x10
	movs r2, #0
	orrs r0, r1
	strh r0, [r4, #0x2a]
	movs r0, #0x36
	ldrsh r1, [r4, r0]
	movs r3, #0x20
	ldrsh r0, [r5, r3]
	adds r1, r1, r0
	ldrh r0, [r4, #0x34]
	adds r0, #2
	strh r0, [r4, #0x34]
	movs r3, #0x34
	ldrsh r0, [r4, r3]
	cmp r0, r1
	blt _0800D1C0
	strh r1, [r4, #0x34]
	strb r2, [r4, #3]
	movs r0, #0
	str r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #1]
_0800D1C0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800D1C8: .4byte 0x0000021A

	thumb_func_start FUN_0800d1cc
FUN_0800d1cc: @ 0x0800D1CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r4, r1, #0
	adds r3, r4, #0
	adds r3, #0x48
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D1E6
	movs r0, #0
	strb r0, [r4, #1]
_0800D1E6:
	ldrh r1, [r4, #0x2a]
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r4, #0x2a]
	adds r0, r4, #0
	adds r0, #0x31
	mov r5, sp
	ldrb r6, [r0]
	ldr r2, _0800D214 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800D218
	asrs r1, r0, #0xc
	b _0800D21E
	.align 2, 0
_0800D214: .4byte 0x085B0A08
_0800D218:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0800D21E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x10
	muls r0, r1, r0
	cmp r0, #0
	blt _0800D238
	asrs r0, r0, #0xc
	b _0800D23E
_0800D238:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0800D23E:
	strh r0, [r5, #4]
	adds r2, r3, #0
	adds r2, #8
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r5, [r3, #8]
	adds r0, r0, r5
	strh r0, [r3, #8]
	ldrh r0, [r1, #2]
	ldrh r5, [r2, #2]
	adds r0, r0, r5
	strh r0, [r2, #2]
	ldrh r1, [r1, #4]
	ldrh r0, [r2, #4]
	adds r1, r1, r0
	strh r1, [r2, #4]
	ldrh r0, [r3, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0800D282
	cmp r1, #0
	blt _0800D282
	ldr r0, _0800D288 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800D282
	ldr r0, _0800D28C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800D290
_0800D282:
	movs r0, #0
	b _0800D29E
	.align 2, 0
_0800D288: .4byte 0x030046A8
_0800D28C: .4byte 0x030046AC
_0800D290:
	ldr r0, _0800D2E8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0800D29E:
	movs r1, #0x8f
	lsls r1, r1, #1
	adds r2, r4, r1
	movs r6, #0
	movs r7, #0
	strh r0, [r2]
	ldr r0, [r4, #4]
	cmp r0, #0xf
	bls _0800D358
	ldrh r2, [r3, #8]
	ldr r1, _0800D2EC @ =0xFFFFFF00
	adds r0, r1, #0
	ands r0, r2
	adds r0, #0x80
	strh r0, [r3, #8]
	ldrh r0, [r3, #0xc]
	ands r1, r0
	adds r1, #0x80
	strh r1, [r3, #0xc]
	adds r5, r4, #0
	adds r5, #0x30
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _0800D2F0
	strb r6, [r4, #3]
	str r7, [r4, #4]
	movs r0, #1
	strb r0, [r4, #1]
	subs r0, #6
	ldrb r1, [r4, #2]
	ands r0, r1
	strb r0, [r4, #2]
	b _0800D326
	.align 2, 0
_0800D2E8: .4byte 0x030046A4
_0800D2EC: .4byte 0xFFFFFF00
_0800D2F0:
	adds r0, r4, #0
	bl FUN_0800cc08
	cmp r0, #0
	beq _0800D302
	movs r0, #4
	strb r0, [r4, #3]
	str r7, [r4, #4]
	b _0800D322
_0800D302:
	strb r6, [r5]
	movs r0, #5
	rsbs r0, r0, #0
	ldrb r1, [r4, #2]
	ands r0, r1
	strb r0, [r4, #2]
	movs r2, #1
	rsbs r2, r2, #0
	mov r0, r8
	adds r1, r4, #0
	bl FUN_0800cf30
	cmp r0, #0
	bne _0800D326
	strb r6, [r4, #3]
	str r0, [r4, #4]
_0800D322:
	movs r0, #1
	strb r0, [r4, #1]
_0800D326:
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _0800D330
	movs r0, #0x78
	b _0800D356
_0800D330:
	movs r0, #8
	ldrb r1, [r4, #2]
	ands r0, r1
	cmp r0, #0
	beq _0800D33E
	movs r0, #0x7b
	b _0800D356
_0800D33E:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D34A
	movs r0, #0x7c
	b _0800D356
_0800D34A:
	movs r0, #1
	ands r1, r0
	movs r0, #0x7a
	cmp r1, #0
	beq _0800D356
	movs r0, #0x79
_0800D356:
	strh r0, [r4, #0x2e]
_0800D358:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800d364
FUN_0800d364: @ 0x0800D364
	push {r4, r5, r6, lr}
	adds r2, r1, #0
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r5, r2, r0
	adds r4, r2, #0
	adds r4, #0x48
	ldrb r0, [r2, #1]
	cmp r0, #0
	beq _0800D37C
	movs r0, #0
	strb r0, [r2, #1]
_0800D37C:
	ldrh r0, [r2, #0x2a]
	movs r1, #0x10
	movs r6, #0
	orrs r1, r0
	strh r1, [r2, #0x2a]
	ldrh r0, [r4, #0xa]
	subs r0, #0x10
	strh r0, [r4, #0xa]
	ldrh r3, [r2, #0x32]
	lsls r0, r0, #0x10
	lsls r1, r3, #0x10
	cmp r0, r1
	bge _0800D3EA
	strh r3, [r4, #0xa]
	asrs r0, r1, #0x18
	movs r1, #0xf
	ands r0, r1
	adds r3, r0, #1
	cmp r3, #0xf
	ble _0800D3A6
	movs r3, #0xf
_0800D3A6:
	ldrb r0, [r5, #4]
	movs r1, #0xf0
	ands r1, r0
	orrs r1, r3
	strb r1, [r5, #4]
	movs r0, #2
	ldrb r1, [r2, #2]
	ands r1, r0
	cmp r1, #0
	beq _0800D3DC
	movs r1, #1
	strb r1, [r2, #3]
	movs r0, #0
	str r0, [r2, #4]
	strb r1, [r2, #1]
	adds r0, r2, #0
	adds r0, #0x50
	movs r1, #0x80
	bl FUN_08003014
	ldr r0, _0800D3D8 @ =0x00000143
	bl PlaySound_082406e0
	b _0800D3EA
	.align 2, 0
_0800D3D8: .4byte 0x00000143
_0800D3DC:
	strb r6, [r2, #3]
	str r1, [r2, #4]
	movs r0, #1
	strb r0, [r2, #1]
	ldr r0, _0800D3F0 @ =0x0000021B
	bl PlaySound_082406e0
_0800D3EA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800D3F0: .4byte 0x0000021B

	thumb_func_start FUN_0800d3f4
FUN_0800d3f4: @ 0x0800D3F4
	push {r4, lr}
	sub sp, #0xc
	adds r4, r1, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D42E
	movs r0, #0
	strb r0, [r4, #1]
	add r2, sp, #4
	ldr r0, [r4, #0x50]
	ldr r1, [r4, #0x54]
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r2, #0
	ldrh r0, [r0]
	adds r0, #0x40
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r2, #4]
	adds r0, #0x40
	strh r0, [r2, #4]
	movs r0, #7
	str r0, [sp]
	adds r0, r1, #0
	movs r1, #0x90
	movs r2, #0x28
	movs r3, #8
	bl FUN_08019814
_0800D42E:
	ldrh r1, [r4, #0x2a]
	movs r0, #0x10
	movs r3, #0
	orrs r1, r0
	strh r1, [r4, #0x2a]
	ldr r2, [r4, #4]
	cmp r2, #0xf
	bhi _0800D448
	movs r0, #7
	ands r0, r2
	cmp r0, #4
	bne _0800D456
	b _0800D450
_0800D448:
	movs r0, #3
	ands r0, r2
	cmp r0, #2
	bne _0800D456
_0800D450:
	movs r0, #0xc
	orrs r1, r0
	strh r1, [r4, #0x2a]
_0800D456:
	cmp r2, #0x1f
	bls _0800D462
	adds r1, r4, #0
	adds r1, #0x44
	movs r0, #1
	strb r0, [r1]
_0800D462:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800d46c
FUN_0800d46c: @ 0x0800D46C
	movs r0, #0
	strh r0, [r1, #0x2a]
	ldrb r0, [r1, #3]
	adds r2, r1, #0
	adds r2, #0x45
	strb r0, [r2]
	ldrb r0, [r1, #2]
	adds r1, #0x46
	strb r0, [r1]
	bx lr

	thumb_func_start FUN_0800d480
FUN_0800d480: @ 0x0800D480
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	mov r8, r0
	adds r5, r1, #0
	movs r0, #0x48
	adds r0, r0, r5
	mov sl, r0
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	adds r0, r5, #0
	adds r0, #0x50
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800D4C6
	cmp r1, #0
	blt _0800D4C6
	ldr r0, _0800D4CC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800D4C6
	ldr r0, _0800D4D0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800D4D4
_0800D4C6:
	movs r0, #0
	b _0800D4E2
	.align 2, 0
_0800D4CC: .4byte 0x030046A8
_0800D4D0: .4byte 0x030046AC
_0800D4D4:
	ldr r0, _0800D508 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0800D4E2:
	movs r1, #1
	bl FUN_08234224
	adds r0, r5, #0
	adds r0, #0x48
	bl FUN_0823b4b8
	ldrh r1, [r5, #0x28]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800D50C
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	bl FUN_08234660
	b _0800D53C
	.align 2, 0
_0800D508: .4byte 0x030046A4
_0800D50C:
	ldrb r0, [r5, #3]
	cmp r0, #1
	bne _0800D530
	adds r2, r5, #0
	adds r2, #0x4a
	ldrh r0, [r2]
	ldr r1, _0800D52C @ =0x0000FFFD
	ands r1, r0
	strh r1, [r2]
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r5, r3
	bl FUN_08234660
	b _0800D53C
	.align 2, 0
_0800D52C: .4byte 0x0000FFFD
_0800D530:
	adds r2, r5, #0
	adds r2, #0x4a
	ldrh r0, [r2]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
_0800D53C:
	movs r2, #1
	ldrb r0, [r5, #2]
	ands r0, r2
	cmp r0, #0
	beq _0800D5B0
	mov r4, r8
	movs r6, #0x24
	ldrsh r0, [r4, r6]
	cmp r0, #0xf
	ble _0800D558
	ldrh r1, [r5, #0x2a]
	movs r0, #0x20
	orrs r0, r1
	strh r0, [r5, #0x2a]
_0800D558:
	ldrh r1, [r5, #0x38]
	movs r3, #0x38
	ldrsh r0, [r5, r3]
	cmp r0, #0
	ble _0800D5B0
	adds r0, r5, #0
	adds r0, #0x42
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	blt _0800D5B0
	subs r0, r1, #1
	strh r0, [r5, #0x38]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800D5B0
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r5, #2]
	ands r0, r1
	strb r0, [r5, #2]
	cmp r0, #0
	bne _0800D58A
	movs r0, #0x78
	b _0800D5AE
_0800D58A:
	movs r0, #8
	ldrb r1, [r5, #2]
	ands r0, r1
	cmp r0, #0
	beq _0800D598
	movs r0, #0x7b
	b _0800D5AE
_0800D598:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D5A4
	movs r0, #0x7c
	b _0800D5AE
_0800D5A4:
	ands r1, r2
	movs r0, #0x7a
	cmp r1, #0
	beq _0800D5AE
	movs r0, #0x79
_0800D5AE:
	strh r0, [r5, #0x2e]
_0800D5B0:
	adds r4, r5, #0
	adds r4, #0xa8
	movs r1, #0xc
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D5C8
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	b _0800D5FC
_0800D5C8:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r2, r5, #0
	adds r2, #0xc4
	mov r6, sl
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r5, #0x34]
	ldrh r1, [r4, #0x1e]
	adds r0, r0, r1
	strh r0, [r4, #0x1e]
	movs r1, #1
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D5FC
	mov r2, r8
	ldrh r0, [r2, #0x20]
	ldrh r3, [r5, #0x36]
	adds r0, r0, r3
	strh r0, [r5, #0x34]
_0800D5FC:
	adds r4, r5, #0
	adds r4, #0xf0
	movs r1, #4
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D614
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	b _0800D658
_0800D614:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r6, #0x86
	lsls r6, r6, #1
	adds r2, r5, r6
	mov r3, sl
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	mov r0, sb
	ldrh r6, [r0, #2]
	adds r0, r6, #0
	movs r1, #3
	bl FUN_08234224
	cmp r0, #0
	beq _0800D642
	adds r0, #4
	b _0800D64E
_0800D642:
	ldr r0, _0800D6AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800D64E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r4, #0x1e]
_0800D658:
	ldrh r0, [r5, #0x3a]
	cmp r0, #0
	beq _0800D66C
	subs r0, #1
	strh r0, [r5, #0x3a]
	strh r0, [r5, #0x3c]
	ldrh r1, [r5, #0x2a]
	movs r0, #2
	orrs r0, r1
	strh r0, [r5, #0x2a]
_0800D66C:
	movs r1, #2
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D720
	ldr r2, _0800D6B0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800D6B4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0800D6B8 @ =0x0203B400
	adds r0, r0, r1
	add r4, sp, #0x20
	ldrh r3, [r0]
	ldrh r6, [r5, #0x3c]
	ldr r2, _0800D6BC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r7, r4, #0
	cmp r0, #0
	blt _0800D6C0
	asrs r1, r0, #0xc
	b _0800D6C6
	.align 2, 0
_0800D6AC: .4byte 0x030046A4
_0800D6B0: .4byte 0x030046B8
_0800D6B4: .4byte 0x000003FF
_0800D6B8: .4byte 0x0203B400
_0800D6BC: .4byte 0x085B0A08
_0800D6C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0800D6C6:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0800D6E2
	asrs r0, r0, #0xc
	b _0800D6E8
_0800D6E2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0800D6E8:
	strh r0, [r4, #4]
	adds r1, r5, #0
	adds r1, #0xc4
	add r0, sp, #0x20
	ldrh r4, [r0]
	ldrh r3, [r1]
	adds r0, r4, r3
	strh r0, [r1]
	ldrh r3, [r7, #2]
	ldrh r6, [r1, #2]
	adds r0, r3, r6
	strh r0, [r1, #2]
	ldrh r2, [r7, #4]
	ldrh r6, [r1, #4]
	adds r0, r2, r6
	strh r0, [r1, #4]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r6, [r0]
	adds r4, r4, r6
	strh r4, [r0]
	ldrh r1, [r0, #2]
	adds r3, r3, r1
	strh r3, [r0, #2]
	ldrh r3, [r0, #4]
	adds r2, r2, r3
	strh r2, [r0, #4]
_0800D720:
	movs r6, #0x96
	lsls r6, r6, #1
	adds r4, r5, r6
	movs r1, #0x10
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D738
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	b _0800D762
_0800D738:
	adds r1, r5, #0
	adds r1, #0x50
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r1, r5, #0
	adds r1, #0x40
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800D75A
	subs r0, #1
	strb r0, [r1]
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	b _0800D762
_0800D75A:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
_0800D762:
	strh r0, [r4, #6]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r1, #0x20
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D7E4
	ldr r0, [r5, #4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800D7A8
	ldr r3, _0800D7A0 @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r3
	movs r1, #0x90
	orrs r0, r1
	ldr r1, _0800D7A4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x40
	b _0800D7C6
	.align 2, 0
_0800D7A0: .4byte 0xFFFF0000
_0800D7A4: .4byte 0x0000FFFF
_0800D7A8:
	ldr r3, _0800D82C @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r3
	movs r1, #0x40
	orrs r0, r1
	ldr r1, _0800D830 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x90
_0800D7C6:
	orrs r0, r1
	str r0, [r2, #4]
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	adds r1, r5, #0
	adds r1, #0x50
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_0800D7E4:
	adds r0, r5, #0
	adds r0, #0x45
	ldrb r0, [r0]
	ldrb r1, [r5, #3]
	cmp r0, r1
	beq _0800D7FE
	cmp r1, #0
	beq _0800D7FE
	ldr r0, _0800D834 @ =0xFFFFFDFF
	mov r2, sb
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_0800D7FE:
	adds r1, r5, #0
	adds r1, #0x41
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800D838
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800D85A
	adds r4, r5, #0
	adds r4, #0x8c
	ldrh r1, [r5, #0x2e]
	adds r0, r4, #0
	bl FUN_0822b20c
	ldrh r0, [r5, #0x2e]
	cmp r0, #0x79
	bne _0800D850
	mov r0, r8
	adds r0, #0x34
	b _0800D858
	.align 2, 0
_0800D82C: .4byte 0xFFFF0000
_0800D830: .4byte 0x0000FFFF
_0800D834: .4byte 0xFFFFFDFF
_0800D838:
	adds r4, r5, #0
	adds r4, #0x8c
	ldrh r1, [r5, #0x2e]
	adds r0, r4, #0
	bl FUN_0822b20c
	ldrh r0, [r5, #0x2e]
	cmp r0, #0x79
	bne _0800D850
	mov r0, r8
	adds r0, #0x34
	b _0800D858
_0800D850:
	cmp r0, #0x7a
	bne _0800D85A
	mov r0, r8
	adds r0, #0x54
_0800D858:
	str r0, [r4, #0xc]
_0800D85A:
	adds r2, r5, #0
	adds r2, #0x46
	ldrb r3, [r5, #2]
	ldrb r1, [r2]
	cmp r3, r1
	beq _0800D8AC
	ldr r6, [r5, #8]
	cmp r6, #0
	beq _0800D8AC
	mov r4, sl
	ldrh r0, [r4]
	str r0, [sp]
	ldrb r0, [r5, #2]
	str r0, [sp, #4]
	bics r0, r1
	str r0, [sp, #8]
	ldrb r0, [r2]
	bics r0, r3
	str r0, [sp, #0xc]
	add r4, sp, #0x30
	adds r3, r5, #0
	adds r3, #0xc
	add r2, sp, #0x10
	movs r1, #3
_0800D88A:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _0800D88A
	ldr r0, _0800D8C4 @ =0xFFFF0000
	ldr r1, [sp, #0x30]
	ands r1, r0
	movs r0, #8
	orrs r1, r0
	str r1, [sp, #0x30]
	mov r0, sp
	str r0, [r4, #4]
	adds r0, r6, #0
	adds r1, r4, #0
	bl Script_ExecById
_0800D8AC:
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D8C4: .4byte 0xFFFF0000

	thumb_func_start FUN_0800d8c8
FUN_0800d8c8: @ 0x0800D8C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _0800D8F0 @ =0x085B0A08
	adds r1, r5, #0
	adds r1, #0x22
	ldrb r1, [r1]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800D8F4
	asrs r0, r0, #0xc
	b _0800D8FA
	.align 2, 0
_0800D8F0: .4byte 0x085B0A08
_0800D8F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0800D8FA:
	strh r0, [r5, #0x20]
	adds r1, r5, #0
	adds r1, #0x22
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	ldr r4, [r5, #0x74]
	movs r7, #0
	ldr r0, [r5, #0x1c]
	movs r1, #0x34
	adds r1, r1, r5
	mov r8, r1
	adds r2, r5, #0
	adds r2, #0x54
	str r2, [sp, #4]
	movs r1, #0x23
	adds r1, r1, r5
	mov sl, r1
	cmp r7, r0
	bhs _0800D976
	ldr r2, _0800D9B8 @ =0x085AA774
	mov sb, r2
_0800D926:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0800D968
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	bl FUN_0800d46c
	ldrb r0, [r4, #3]
	lsls r0, r0, #2
	add r0, sb
	ldr r3, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	bl _call_via_r3
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	bl FUN_0800d480
	adds r6, r4, #0
	adds r6, #0x44
	ldrb r0, [r6]
	cmp r0, #0
	beq _0800D968
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800cb7c
	movs r0, #0
	strb r0, [r6]
_0800D968:
	adds r7, #1
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r0, [r5, #0x1c]
	cmp r7, r0
	blo _0800D926
_0800D976:
	ldr r1, [r5, #0x28]
	ldr r2, [r5, #0x2c]
	movs r0, #0x24
	ldrsh r3, [r5, r0]
	movs r4, #5
	str r4, [sp]
	mov r0, r8
	bl rgb555_08237468
	ldr r1, [r5, #0x28]
	ldr r2, [r5, #0x30]
	movs r0, #0x24
	ldrsh r3, [r5, r0]
	str r4, [sp]
	ldr r0, [sp, #4]
	bl rgb555_08237468
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800D9BC
	ldrh r0, [r5, #0x24]
	adds r0, #1
	strh r0, [r5, #0x24]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	ble _0800D9D0
	movs r0, #0x20
	strh r0, [r5, #0x24]
	movs r0, #1
	b _0800D9CE
	.align 2, 0
_0800D9B8: .4byte 0x085AA774
_0800D9BC:
	ldrh r0, [r5, #0x24]
	subs r0, #1
	strh r0, [r5, #0x24]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0800D9D0
	movs r0, #0
	strh r0, [r5, #0x24]
	mov r1, sl
_0800D9CE:
	strb r0, [r1]
_0800D9D0:
	movs r0, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800d9e4
FUN_0800d9e4: @ 0x0800D9E4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x74]
	movs r6, #0
	b _0800D9FE
_0800D9EE:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0800cb7c
	adds r6, #1
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r5, r5, r0
_0800D9FE:
	ldr r0, [r4, #0x1c]
	cmp r6, r0
	blo _0800D9EE
	ldr r0, [r4, #0x74]
	cmp r0, #0
	beq _0800DA12
	bl Free
	movs r0, #0
	str r0, [r4, #0x74]
_0800DA12:
	ldr r1, _0800DA20 @ =0x03002B38
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0800DA20: .4byte 0x03002B38

	thumb_func_start FUN_0800da24
FUN_0800da24: @ 0x0800DA24
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0800DA4C @ =0x03002B38
	str r5, [r0]
	movs r4, #0
	str r4, [r5, #0x18]
	ldr r1, [r5, #0x1c]
	lsls r0, r1, #7
	subs r0, r0, r1
	lsls r0, r0, #2
	bl Malloc
	adds r2, r0, #0
	str r2, [r5, #0x74]
	cmp r2, #0
	bne _0800DA50
	movs r0, #1
	rsbs r0, r0, #0
	b _0800DAB8
	.align 2, 0
_0800DA4C: .4byte 0x03002B38
_0800DA50:
	ldr r0, [r5, #0x1c]
	lsls r1, r0, #7
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r0, r2, #0
	bl ClearMemory
	adds r0, r5, #0
	adds r0, #0x23
	strb r4, [r0]
	strh r4, [r5, #0x24]
	ldr r0, _0800DAC0 @ =0x03003584
	ldr r1, [r0]
	movs r2, #0xf0
	lsls r2, r2, #4
	adds r0, r1, r2
	str r0, [r5, #0x28]
	movs r3, #0xf2
	lsls r3, r3, #4
	adds r2, r1, r3
	str r2, [r5, #0x2c]
	movs r2, #0xf4
	lsls r2, r2, #4
	adds r1, r1, r2
	str r1, [r5, #0x30]
	adds r1, r5, #0
	adds r1, #0x34
	ldr r4, _0800DAC4 @ =0x04000008
	adds r2, r4, #0
	bl CpuSet
	ldr r0, [r5, #0x28]
	adds r1, r5, #0
	adds r1, #0x54
	adds r2, r4, #0
	bl CpuSet
	ldr r1, [r5, #0x74]
	movs r2, #0
	ldr r0, [r5, #0x1c]
	cmp r2, r0
	bhs _0800DAB6
	movs r4, #0
	movs r3, #0xfe
	lsls r3, r3, #1
_0800DAAA:
	strb r4, [r1]
	adds r2, #1
	adds r1, r1, r3
	ldr r0, [r5, #0x1c]
	cmp r2, r0
	blo _0800DAAA
_0800DAB6:
	movs r0, #0
_0800DAB8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800DAC0: .4byte 0x03003584
_0800DAC4: .4byte 0x04000008

	thumb_func_start FUN_0800dac8
FUN_0800dac8: @ 0x0800DAC8
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_0800cb70
	adds r4, r0, #0
	cmp r4, #0
	bne _0800DB16
	movs r0, #9
	movs r1, #0x78
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800DB14
	ldr r1, _0800DB0C @ =FUN_0800d8c8
	ldr r2, _0800DB10 @ =FUN_0800d9e4
	bl SetEntityRoutine
	movs r0, #0x6d
	movs r1, #4
	bl VM_GetKeywordValue
	str r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0800da24
	cmp r0, #0
	bge _0800DB14
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800DB16
	.align 2, 0
_0800DB0C: .4byte FUN_0800d8c8
_0800DB10: .4byte FUN_0800d9e4
_0800DB14:
	adds r0, r4, #0
_0800DB16:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800db1c
FUN_0800db1c: @ 0x0800DB1C
	push {r4, lr}
	ldr r1, [r0, #0x74]
	movs r2, #0
	ldr r0, [r0, #0x1c]
	cmp r2, r0
	bhs _0800DB40
	movs r4, #0xfe
	lsls r4, r4, #1
	adds r3, r0, #0
_0800DB2E:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800DB38
	adds r0, r1, #0
	b _0800DB42
_0800DB38:
	adds r2, #1
	adds r1, r1, r4
	cmp r2, r3
	blo _0800DB2E
_0800DB40:
	movs r0, #0
_0800DB42:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800db48
FUN_0800db48: @ 0x0800DB48
	push {r4, r5, lr}
	adds r4, r1, #0
	ldr r2, [r0, #0x74]
	movs r3, #0
	ldr r0, [r0, #0x1c]
	cmp r3, r0
	bhs _0800DB78
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r1, r0, #0
_0800DB5C:
	ldrb r0, [r2]
	cmp r0, #0
	beq _0800DB70
	adds r0, r2, #0
	adds r0, #0x48
	ldrh r0, [r0]
	cmp r0, r4
	bne _0800DB70
	adds r0, r2, #0
	b _0800DB7A
_0800DB70:
	adds r3, #1
	adds r2, r2, r5
	cmp r3, r1
	blo _0800DB5C
_0800DB78:
	movs r0, #0
_0800DB7A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800db80
FUN_0800db80: @ 0x0800DB80
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x54
	bl FUN_0800cb70
	str r0, [sp, #0x24]
	cmp r0, #0
	beq _0800DBB8
	ldr r0, [sp, #0x24]
	bl FUN_0800db1c
	adds r5, r0, #0
	cmp r5, #0
	beq _0800DBB8
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	mov r8, r0
	ldr r0, [sp, #0x24]
	mov r1, r8
	bl FUN_0800db48
	cmp r0, #0
	beq _0800DBBE
_0800DBB8:
	movs r0, #1
	rsbs r0, r0, #0
	b _0800E0C0
_0800DBBE:
	movs r0, #0x61
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r5, #2]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0800DBEE
	movs r0, #1
	ldrb r1, [r5, #2]
	ands r0, r1
	cmp r0, #0
	bne _0800DBEE
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800DBE4
	movs r2, #1
	b _0800DBF0
_0800DBE4:
	movs r0, #4
	ands r1, r0
	movs r2, #6
	cmp r1, #0
	beq _0800DBF0
_0800DBEE:
	movs r2, #0
_0800DBF0:
	movs r0, #0
	strb r2, [r5, #3]
	str r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #1]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800DC40
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800DC38 @ =0xFFFF0000
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800DC3C @ =0x0000FFFF
	ldr r1, [sp, #0xc]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0xc]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	b _0800DC4A
	.align 2, 0
_0800DC38: .4byte 0xFFFF0000
_0800DC3C: .4byte 0x0000FFFF
_0800DC40:
	ldr r1, _0800DCA0 @ =0xFFFF0000
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r1
	str r0, [sp, #0x10]
_0800DC4A:
	ldr r0, _0800DCA4 @ =0xFFFFFF00
	adds r3, r0, #0
	add r0, sp, #0xc
	ldrh r1, [r0]
	ands r1, r3
	movs r0, #0x80
	orrs r1, r0
	ldr r2, _0800DCA0 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	ldrh r1, [r0, #4]
	ands r1, r3
	movs r0, #0x80
	orrs r1, r0
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	add r6, sp, #0xc
	adds r0, r6, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800DC9C
	cmp r1, #0
	blt _0800DC9C
	ldr r0, _0800DCA8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800DC9C
	ldr r0, _0800DCAC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800DCB0
_0800DC9C:
	movs r4, #0
	b _0800DCBE
	.align 2, 0
_0800DCA0: .4byte 0xFFFF0000
_0800DCA4: .4byte 0xFFFFFF00
_0800DCA8: .4byte 0x030046A8
_0800DCAC: .4byte 0x030046AC
_0800DCB0:
	ldr r0, _0800DCD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0800DCBE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800DCD4
	adds r0, #4
	b _0800DCE0
	.align 2, 0
_0800DCD0: .4byte 0x030046A4
_0800DCD4:
	ldr r0, _0800DCF4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800DCE0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0800DCF8
	cmp r2, #2
	beq _0800DCFC
	b _0800DD00
	.align 2, 0
_0800DCF4: .4byte 0x030046A4
_0800DCF8:
	ldrb r0, [r6, #4]
	b _0800DCFE
_0800DCFC:
	ldrb r0, [r6]
_0800DCFE:
	subs r1, r1, r0
_0800DD00:
	add r0, sp, #0xc
	strh r1, [r0, #2]
	movs r0, #0x50
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r5, #8]
	movs r0, #0x52
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800DD8A
	adds r6, r5, #0
	adds r6, #0xc
	adds r1, r5, #0
	adds r1, #0x42
	str r1, [sp, #0x48]
	adds r2, r5, #0
	adds r2, #0x30
	str r2, [sp, #0x38]
	adds r3, r5, #0
	adds r3, #0x31
	str r3, [sp, #0x3c]
	adds r4, r5, #0
	adds r4, #0x40
	str r4, [sp, #0x40]
	adds r0, r5, #0
	adds r0, #0x41
	str r0, [sp, #0x44]
	adds r1, #0x66
	str r1, [sp, #0x50]
	adds r7, r5, #0
	adds r7, #0x8c
	adds r2, #0xc0
	str r2, [sp, #0x28]
	movs r3, #0xd4
	adds r3, r3, r5
	mov sb, r3
	movs r4, #0x86
	lsls r4, r4, #1
	adds r4, r5, r4
	str r4, [sp, #0x2c]
	movs r0, #0x48
	adds r0, r0, r5
	mov sl, r0
	mov r1, r8
	lsls r1, r1, #0x10
	str r1, [sp, #0x34]
	subs r2, #0xa0
	str r2, [sp, #0x4c]
	add r3, sp, #0x14
	mov r8, r3
	mov r4, sp
	adds r4, #0x1c
	str r4, [sp, #0x30]
	adds r4, r6, #0
_0800DD70:
	bl VM_GetPC
	cmp r0, #0
	beq _0800DD7C
	bl Script_GetValue
_0800DD7C:
	str r0, [r4]
	adds r4, #4
	adds r0, r6, #0
	adds r0, #0xc
	cmp r4, r0
	ble _0800DD70
	b _0800DDEC
_0800DD8A:
	adds r0, r5, #0
	adds r0, #0x42
	str r0, [sp, #0x48]
	adds r1, r5, #0
	adds r1, #0x30
	str r1, [sp, #0x38]
	adds r2, r5, #0
	adds r2, #0x31
	str r2, [sp, #0x3c]
	adds r3, r5, #0
	adds r3, #0x40
	str r3, [sp, #0x40]
	adds r4, r5, #0
	adds r4, #0x41
	str r4, [sp, #0x44]
	adds r0, #0x66
	str r0, [sp, #0x50]
	adds r7, r5, #0
	adds r7, #0x8c
	adds r1, #0xc0
	str r1, [sp, #0x28]
	movs r2, #0xd4
	adds r2, r2, r5
	mov sb, r2
	movs r3, #0x86
	lsls r3, r3, #1
	adds r3, r5, r3
	str r3, [sp, #0x2c]
	movs r4, #0x48
	adds r4, r4, r5
	mov sl, r4
	mov r0, r8
	lsls r0, r0, #0x10
	str r0, [sp, #0x34]
	subs r1, #0xa0
	str r1, [sp, #0x4c]
	add r2, sp, #0x14
	mov r8, r2
	mov r3, sp
	adds r3, #0x1c
	str r3, [sp, #0x30]
	subs r1, #0x44
	movs r2, #0
	adds r0, r5, #0
	adds r0, #0x18
_0800DDE4:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _0800DDE4
_0800DDEC:
	movs r4, #0
	str r4, [r5, #0x1c]
	str r4, [r5, #0x20]
	str r4, [r5, #0x24]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r5, #0x28]
	strh r4, [r5, #0x2a]
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _0800DE12
	add r0, sp, #0xc
	bl FUN_08241574
_0800DE12:
	strh r0, [r5, #0x2c]
	ldrb r0, [r5, #2]
	cmp r0, #0
	bne _0800DE1E
	movs r0, #0x78
	b _0800DE44
_0800DE1E:
	movs r0, #8
	ldrb r1, [r5, #2]
	ands r0, r1
	cmp r0, #0
	beq _0800DE2C
	movs r0, #0x7b
	b _0800DE44
_0800DE2C:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800DE38
	movs r0, #0x7c
	b _0800DE44
_0800DE38:
	movs r0, #1
	ands r1, r0
	movs r0, #0x7a
	cmp r1, #0
	beq _0800DE44
	movs r0, #0x79
_0800DE44:
	strh r0, [r5, #0x2e]
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x46
	bl VM_GetKeywordValue
	adds r2, r0, #0
	ldr r4, [sp, #0x48]
	strh r2, [r4]
	movs r0, #1
	ldrb r1, [r5, #2]
	ands r1, r0
	cmp r1, #0
	beq _0800DE64
	strh r2, [r5, #0x38]
	b _0800DE66
_0800DE64:
	strh r1, [r5, #0x38]
_0800DE66:
	movs r0, #0
	movs r2, #0
	strh r2, [r5, #0x3a]
	ldr r1, [sp, #0x38]
	strb r0, [r1]
	ldr r3, [sp, #0x3c]
	strb r0, [r3]
	add r0, sp, #0xc
	ldrh r0, [r0, #2]
	strh r0, [r5, #0x32]
	movs r1, #0x28
	strh r1, [r5, #0x36]
	ldrb r0, [r5, #3]
	cmp r0, #1
	beq _0800DE88
	cmp r0, #3
	bne _0800DE8C
_0800DE88:
	strh r2, [r5, #0x34]
	b _0800DE8E
_0800DE8C:
	strh r1, [r5, #0x34]
_0800DE8E:
	movs r0, #0x6c
	movs r1, #1
	bl VM_GetKeywordValue
	movs r1, #0
	strh r0, [r5, #0x3e]
	ldr r4, [sp, #0x40]
	strb r1, [r4]
	ldr r0, [sp, #0x44]
	strb r1, [r0]
	ldr r6, [sp, #0x50]
	ldr r1, _0800DEC0 @ =0x0000BCA8
	adds r0, r7, #0
	bl Video_GetActorSprite
	ldrh r1, [r5, #0x2e]
	adds r0, r7, #0
	bl FUN_0822b20c
	ldrh r0, [r5, #0x2e]
	cmp r0, #0x79
	bne _0800DEC4
	ldr r0, [sp, #0x24]
	adds r0, #0x34
	b _0800DECC
	.align 2, 0
_0800DEC0: .4byte 0x0000BCA8
_0800DEC4:
	cmp r0, #0x7a
	bne _0800DECE
	ldr r0, [sp, #0x24]
	adds r0, #0x54
_0800DECC:
	str r0, [r7, #0xc]
_0800DECE:
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #0
	strh r0, [r6, #0x10]
	add r4, sp, #0xc
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	ldrh r0, [r5, #0x34]
	ldrh r1, [r6, #0x1e]
	adds r0, r0, r1
	strh r0, [r6, #0x1e]
	ldr r6, [sp, #0x28]
	ldr r1, _0800DF3C @ =0x0000BCA8
	mov r0, sb
	bl Video_GetActorSprite
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r6, #0
	mov r1, sb
	bl FUN_0822a470
	movs r0, #1
	strh r0, [r6, #0x10]
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	add r0, sp, #0xc
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800DF38
	cmp r1, #0
	blt _0800DF38
	ldr r0, _0800DF40 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800DF38
	ldr r0, _0800DF44 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800DF48
_0800DF38:
	movs r6, #0
	b _0800DF56
	.align 2, 0
_0800DF3C: .4byte 0x0000BCA8
_0800DF40: .4byte 0x030046A8
_0800DF44: .4byte 0x030046AC
_0800DF48:
	ldr r0, _0800DF68 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_0800DF56:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800DF6C
	adds r0, #4
	b _0800DF78
	.align 2, 0
_0800DF68: .4byte 0x030046A4
_0800DF6C:
	ldr r0, _0800E0D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800DF78:
	ldrb r0, [r0]
	movs r3, #0xf
	ands r3, r0
	cmp r3, #0xe
	bgt _0800DF84
	adds r3, #1
_0800DF84:
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r0, #0xff
	str r0, [sp]
	movs r0, #9
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_08234270
	ldrh r0, [r4]
	movs r6, #2
	movs r7, #0
	orrs r0, r6
	strh r0, [r4]
	mov r4, sl
	ldr r2, [sp, #0x34]
	lsrs r1, r2, #0x10
	movs r0, #7
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #0xc
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	ldr r1, [sp, #0x50]
	bl FUN_0823b46c
	ldrb r0, [r5, #3]
	cmp r0, #1
	beq _0800DFD4
	adds r1, r5, #0
	adds r1, #0x4a
	ldrh r0, [r1]
	orrs r0, r6
	strh r0, [r1]
_0800DFD4:
	mov r3, sl
	ldrh r1, [r3]
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r1, [r0]
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [sp, #0x4c]
	str r2, [r0]
	ldr r2, _0800E0D4 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x82
	orrs r0, r3
	ldr r1, _0800E0D8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x14]
	mov r4, r8
	ldr r0, [r4, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r4, #4]
	str r1, [sp, #0x1c]
	ldr r1, [sp, #0x30]
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r2, #0x96
	lsls r2, r2, #1
	adds r6, r5, r2
	mov r3, sl
	ldrh r1, [r3]
	ldr r2, _0800E0DC @ =0x00004041
	movs r0, #0x10
	str r0, [sp]
	str r4, [sp, #4]
	ldr r4, [sp, #0x30]
	str r4, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r6, #0
	ldr r1, [sp, #0x4c]
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0800E0E0 @ =FUN_0800cbd0
	adds r0, r6, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r0, r6, #0
	bl FUN_08236400
	movs r1, #0x90
	add r0, sp, #0x14
	strh r1, [r0]
	movs r0, #0x80
	mov r2, r8
	strh r0, [r2, #2]
	strh r1, [r2, #4]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r6, r5, r3
	mov r4, sl
	ldrh r1, [r4]
	ldr r2, _0800E0E4 @ =0x00002801
	movs r4, #1
	str r4, [sp]
	mov r0, r8
	str r0, [sp, #4]
	ldr r3, [sp, #0x30]
	str r3, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r6, #0
	ldr r1, [sp, #0x4c]
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0800E0E8 @ =FUN_0800cc04
	adds r0, r6, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r0, r6, #0
	movs r1, #0x32
	movs r2, #0
	bl FUN_082364f0
	ldr r0, _0800E0EC @ =0x00010100
	str r0, [r6, #0x34]
	movs r0, #4
	str r0, [r6, #0x38]
	ldrh r0, [r5, #0x28]
	ands r4, r0
	cmp r4, #0
	bne _0800E0BA
	mov r0, sl
	bl FUN_08002a48
	cmp r0, #0
	bge _0800E0BA
	ldrh r0, [r5, #0x28]
	movs r1, #1
	orrs r0, r1
	strh r0, [r5, #0x28]
_0800E0BA:
	movs r0, #1
	strb r0, [r5]
	movs r0, #0
_0800E0C0:
	add sp, #0x54
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800E0D0: .4byte 0x030046A4
_0800E0D4: .4byte 0xFFFF0000
_0800E0D8: .4byte 0x0000FFFF
_0800E0DC: .4byte 0x00004041
_0800E0E0: .4byte FUN_0800cbd0
_0800E0E4: .4byte 0x00002801
_0800E0E8: .4byte FUN_0800cc04
_0800E0EC: .4byte 0x00010100

	thumb_func_start FUN_0800e0f0
FUN_0800e0f0: @ 0x0800E0F0
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r6, r1, #0
	movs r5, #0
	adds r0, r2, #0
	adds r0, #0x6e
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0800E122
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800E118
	ldr r1, [r2, #0x70]
	ldr r0, [r3, #0x34]
	cmp r1, r0
	bne _0800E124
	b _0800E122
_0800E118:
	ldr r0, [r2, #0x70]
	ldr r1, [r3, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0800E124
_0800E122:
	movs r5, #1
_0800E124:
	movs r4, #0
	adds r0, r2, #0
	adds r0, #0x6e
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0800E150
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800E146
	ldr r1, [r2, #0x74]
	ldr r0, [r3, #0x38]
	cmp r1, r0
	bne _0800E152
	b _0800E150
_0800E146:
	ldr r0, [r2, #0x74]
	ldr r1, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0800E152
_0800E150:
	movs r4, #1
_0800E152:
	cmp r5, #0
	beq _0800E16C
	cmp r4, #0
	beq _0800E16C
	ldrh r0, [r3, #0x3e]
	ldrh r1, [r6, #0x3e]
	adds r0, r0, r1
	strh r0, [r6, #0x3e]
	adds r2, #0x84
	ldr r0, [r3, #0xc]
	ldr r1, [r3, #0x10]
	str r0, [r2]
	str r1, [r2, #4]
_0800E16C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800e174
FUN_0800e174: @ 0x0800E174
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x18
	adds r1, r4, #0
	adds r1, #0x7c
	ldrh r0, [r1]
	cmp r0, #0
	beq _0800E194
	subs r0, #1
	strh r0, [r1]
	ldrh r1, [r4, #0x1e]
	movs r0, #4
	orrs r0, r1
	b _0800E19A
_0800E194:
	ldrh r1, [r4, #0x1e]
	ldr r0, _0800E204 @ =0x0000FFFB
	ands r0, r1
_0800E19A:
	strh r0, [r4, #0x1e]
	ldrh r0, [r6, #0x3e]
	cmp r0, #0
	beq _0800E246
	adds r0, r4, #0
	adds r0, #0x7e
	ldrh r1, [r0]
	subs r0, #2
	strh r1, [r0]
	adds r5, r4, #0
	adds r5, #0x6a
	ldrh r0, [r5]
	ldrh r1, [r6, #0x3e]
	subs r0, r0, r1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0800E212
	adds r1, r4, #0
	adds r1, #0x82
	ldrh r0, [r1]
	cmp r0, #0
	beq _0800E1EE
	adds r0, r4, #0
	adds r0, #0x84
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp]
	adds r0, r4, #0
	adds r0, #0x86
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r0, #0x88
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #8]
	ldrh r0, [r1]
	add r1, sp, #0xc
	bl Script_ExecById
_0800E1EE:
	adds r0, r4, #0
	adds r0, #0x6e
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800E208
	adds r0, r4, #0
	bl KillEntity
	b _0800E242
	.align 2, 0
_0800E204: .4byte 0x0000FFFB
_0800E208:
	adds r0, r4, #0
	adds r0, #0x6c
	ldrh r0, [r0]
	strh r0, [r5]
	b _0800E242
_0800E212:
	adds r1, r4, #0
	adds r1, #0x80
	ldrh r0, [r1]
	cmp r0, #0
	beq _0800E242
	adds r0, r4, #0
	adds r0, #0x84
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp]
	adds r0, r4, #0
	adds r0, #0x86
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r0, #0x88
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #8]
	ldrh r0, [r1]
	add r1, sp, #0x14
	bl Script_ExecById
_0800E242:
	movs r0, #0
	strh r0, [r6, #0x3e]
_0800E246:
	movs r0, #0
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800e250
FUN_0800e250: @ 0x0800E250
	push {lr}
	adds r0, #0x18
	bl FUN_08236424
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800e260
FUN_0800e260: @ 0x0800E260
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	adds r5, r0, #0
	adds r6, r1, #0
	adds r0, #0x68
	strh r6, [r0]
	movs r0, #0x6c
	movs r1, #0x64
	bl VM_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x6c
	strh r0, [r1]
	subs r1, #2
	strh r0, [r1]
	movs r0, #0x53
	movs r1, #0x10
	bl VM_GetKeywordValue
	str r0, [r5, #0x78]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800E2D0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800E2C8 @ =0xFFFF0000
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800E2CC @ =0x0000FFFF
	ldr r1, [sp, #0xc]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0xc]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	b _0800E2DA
	.align 2, 0
_0800E2C8: .4byte 0xFFFF0000
_0800E2CC: .4byte 0x0000FFFF
_0800E2D0:
	ldr r1, _0800E31C @ =0xFFFF0000
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r1
	str r0, [sp, #0x10]
_0800E2DA:
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800E324
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800E31C @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x14]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800E320 @ =0x0000FFFF
	ldr r1, [sp, #0x14]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x14]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #0x14
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	adds r7, r2, #0
	b _0800E332
	.align 2, 0
_0800E31C: .4byte 0xFFFF0000
_0800E320: .4byte 0x0000FFFF
_0800E324:
	ldr r2, _0800E374 @ =0xFFFF0000
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r7, r1, #0
_0800E332:
	movs r0, #0x6f
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800E37C
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800E374 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800E378 @ =0x0000FFFF
	ldr r1, [sp, #0x1c]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #0x1c
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	adds r3, r2, #0
	b _0800E38A
	.align 2, 0
_0800E374: .4byte 0xFFFF0000
_0800E378: .4byte 0x0000FFFF
_0800E37C:
	ldr r2, _0800E3EC @ =0xFFFF0000
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r3, r1, #0
_0800E38A:
	adds r4, r5, #0
	adds r4, #0x18
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0800E3F0 @ =0x00004001
	ldr r0, [r5, #0x78]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	str r7, [sp, #4]
	str r3, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r4, #0
	add r1, sp, #0xc
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0800E3F4 @ =FUN_0800e0f0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	adds r0, r4, #0
	bl FUN_08236400
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, #0x56
	strh r0, [r4]
	movs r0, #0x77
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800E3F8
	bl Script_GetValue
	str r0, [r5, #0x70]
	b _0800E402
	.align 2, 0
_0800E3EC: .4byte 0xFFFF0000
_0800E3F0: .4byte 0x00004001
_0800E3F4: .4byte FUN_0800e0f0
_0800E3F8:
	str r0, [r5, #0x70]
	ldrh r0, [r4]
	movs r1, #8
	orrs r0, r1
	strh r0, [r4]
_0800E402:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800E414
	bl Script_GetValue
	str r0, [r5, #0x74]
	b _0800E41E
_0800E414:
	str r0, [r5, #0x74]
	ldrh r1, [r4]
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r4]
_0800E41E:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x80
	movs r4, #0
	strh r0, [r1]
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x82
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x7c
	strh r4, [r0]
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x7e
	strh r0, [r1]
	movs r0, #0
	add sp, #0x24
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800e45c
FUN_0800e45c: @ 0x0800E45C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #8
	movs r1, #0x8c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800E494
	ldr r1, _0800E48C @ =FUN_0800e174
	ldr r2, _0800E490 @ =FUN_0800e250
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0800e260
	cmp r0, #0
	bge _0800E494
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800E496
	.align 2, 0
_0800E48C: .4byte FUN_0800e174
_0800E490: .4byte FUN_0800e250
_0800E494:
	adds r0, r4, #0
_0800E496:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800e49c
FUN_0800e49c: @ 0x0800E49C
	ldr r1, _0800E4A4 @ =0x03002B3C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0800E4A4: .4byte 0x03002B3C

	thumb_func_start FUN_0800e4a8
FUN_0800e4a8: @ 0x0800E4A8
	push {r4, r5, lr}
	adds r1, r0, #0
	adds r5, r2, #0
	ldrb r4, [r2, #2]
	cmp r4, #0
	bne _0800E4D2
	ldr r0, [r1, #0x38]
	ldrh r3, [r1, #0x3e]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0800E4C8
	lsls r3, r3, #1
	ldrh r0, [r2, #0x10]
	subs r0, r0, r3
	strh r0, [r2, #0x10]
_0800E4C8:
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bge _0800E4D2
	strh r4, [r5, #0x10]
_0800E4D2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800e4d8
FUN_0800e4d8: @ 0x0800E4D8
	bx lr
	.align 2, 0

	thumb_func_start FUN_0800e4dc
FUN_0800e4dc: @ 0x0800E4DC
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	adds r0, r2, #0
	adds r0, #0xec
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	ldr r1, [r3, #0x1c]
	str r1, [r0]
	cmp r1, #0
	beq _0800E4FA
	adds r0, r1, #0
	adds r0, #0xec
	str r2, [r0]
_0800E4FA:
	str r2, [r3, #0x1c]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800e504
FUN_0800e504: @ 0x0800E504
	push {lr}
	adds r3, r0, #0
	adds r0, r1, #0
	adds r0, #0xec
	ldr r2, [r0]
	adds r1, #0xf0
	ldr r1, [r1]
	cmp r2, #0
	beq _0800E51E
	adds r0, r2, #0
	adds r0, #0xf0
	str r1, [r0]
	b _0800E520
_0800E51E:
	str r1, [r3, #0x1c]
_0800E520:
	cmp r1, #0
	beq _0800E52A
	adds r0, r1, #0
	adds r0, #0xec
	str r2, [r0]
_0800E52A:
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_0800e530
FUN_0800e530: @ 0x0800E530
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xb]
	cmp r0, #0
	beq _0800E546
	adds r0, r4, #0
	adds r0, #0x80
	bl FUN_08013c70
	movs r0, #0
	strb r0, [r4, #0xb]
_0800E546:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800e54c
FUN_0800e54c: @ 0x0800E54C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x44
	bl FUN_0822a4e0
	ldr r0, _0800E590 @ =0x03002B3C
	ldr r0, [r0]
	cmp r0, #0
	beq _0800E564
	adds r1, r4, #0
	bl FUN_0800e504
_0800E564:
	adds r0, r4, #0
	bl FUN_0800e530
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0800E57A
	bl FUN_08236424
	ldr r0, [r4, #0x20]
	bl Free
_0800E57A:
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _0800E584
	bl Free
_0800E584:
	adds r0, r4, #0
	bl Free
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800E590: .4byte 0x03002B3C

	thumb_func_start FUN_0800e594
FUN_0800e594: @ 0x0800E594
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x2c
	mov r8, r1
	adds r5, r2, #0
	adds r7, r3, #0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _0800E5EC @ =0x03002B3C
	ldr r0, [r0]
	cmp r0, #0
	bne _0800E5BE
	ldr r0, _0800E5F0 @ =0x0000C0DB
	movs r1, #0
	bl FUN_0800f110
	cmp r0, #0
	bne _0800E5BE
	b _0800E832
_0800E5BE:
	movs r0, #0xf4
	bl Malloc
	adds r6, r0, #0
	cmp r6, #0
	bne _0800E5CC
	b _0800E832
_0800E5CC:
	adds r0, r6, #0
	movs r1, #0xf4
	bl ClearMemory
	strh r4, [r6]
	movs r0, #0
	mov sb, r0
	mov r3, r8
	cmp r3, #1
	ble _0800E5F4
	movs r0, #2
	strb r0, [r6, #2]
	subs r0, #4
	add r0, r8
	mov sb, r0
	b _0800E5F8
	.align 2, 0
_0800E5EC: .4byte 0x03002B3C
_0800E5F0: .4byte 0x0000C0DB
_0800E5F4:
	mov r3, r8
	strb r3, [r6, #2]
_0800E5F8:
	movs r0, #0
	strb r0, [r6, #4]
	strh r0, [r6, #6]
	movs r2, #1
	strb r2, [r6, #3]
	strb r5, [r6, #5]
	strh r7, [r6, #8]
	ldr r0, [sp, #0x58]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	ldrb r0, [r6, #2]
	cmp r0, #0
	bne _0800E61A
	strb r2, [r6, #0xc]
	b _0800E61E
_0800E61A:
	movs r0, #0
	strb r0, [r6, #0xc]
_0800E61E:
	ldr r0, [sp, #0x48]
	strh r0, [r6, #0x12]
	adds r5, r6, #0
	adds r5, #0x18
	ldrh r0, [r6, #0x18]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r7, r5, #0
	cmp r2, #0
	blt _0800E64C
	cmp r1, #0
	blt _0800E64C
	ldr r0, _0800E650 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800E64C
	ldr r0, _0800E654 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800E658
_0800E64C:
	movs r4, #0
	b _0800E666
	.align 2, 0
_0800E650: .4byte 0x030046A8
_0800E654: .4byte 0x030046AC
_0800E658:
	ldr r0, _0800E678 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0800E666:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800E67C
	adds r0, #4
	b _0800E688
	.align 2, 0
_0800E678: .4byte 0x030046A4
_0800E67C:
	ldr r0, _0800E69C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800E688:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0800E6A0
	cmp r2, #2
	beq _0800E6A4
	b _0800E6A8
	.align 2, 0
_0800E69C: .4byte 0x030046A4
_0800E6A0:
	ldrb r0, [r5, #4]
	b _0800E6A6
_0800E6A4:
	ldrb r0, [r5]
_0800E6A6:
	subs r1, r1, r0
_0800E6A8:
	strh r1, [r6, #0x14]
	ldr r0, [sp, #0x4c]
	strh r0, [r6, #0x10]
	ldrb r0, [r6, #5]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _0800E760
	movs r0, #0x50
	bl Malloc
	str r0, [r6, #0x20]
	cmp r0, #0
	bne _0800E6C6
	b _0800E832
_0800E6C6:
	movs r1, #0x50
	bl ClearMemory
	ldrb r1, [r6, #5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800E6F4
	ldr r2, _0800E6EC @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r3, #0xb4
	orrs r0, r3
	ldr r1, _0800E6F0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	b _0800E706
	.align 2, 0
_0800E6EC: .4byte 0xFFFF0000
_0800E6F0: .4byte 0x0000FFFF
_0800E6F4:
	ldr r2, _0800E750 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r3, #0x5a
	orrs r0, r3
	ldr r1, _0800E754 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
_0800E706:
	orrs r0, r1
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r1, sp, #0x24
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r5, r1, #0
	ldr r0, [r6, #0x20]
	ldrh r1, [r6]
	ldr r2, _0800E758 @ =0x00004001
	movs r3, #0x10
	str r3, [sp]
	add r3, sp, #0x1c
	str r3, [sp, #4]
	str r5, [sp, #8]
	movs r3, #0
	bl FUN_0823646c
	ldr r0, [r6, #0x20]
	ldr r1, _0800E75C @ =FUN_0800e4a8
	adds r2, r6, #0
	bl FUN_0823651c
	ldr r0, [r6, #0x20]
	bl FUN_08236400
	ldr r0, [r6, #0x20]
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	b _0800E762
	.align 2, 0
_0800E750: .4byte 0xFFFF0000
_0800E754: .4byte 0x0000FFFF
_0800E758: .4byte 0x00004001
_0800E75C: .4byte FUN_0800e4a8
_0800E760:
	str r1, [r6, #0x20]
_0800E762:
	ldrb r1, [r6, #5]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _0800E818
	movs r0, #0x50
	bl Malloc
	str r0, [r6, #0x24]
	cmp r0, #0
	beq _0800E832
	movs r1, #0x50
	bl ClearMemory
	ldrb r1, [r6, #5]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _0800E7A8
	movs r3, #0
	movs r2, #0x78
	add r0, sp, #0x1c
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0xa0
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r0, sp, #0x24
	strh r3, [r0]
	movs r1, #0x50
	b _0800E7BC
_0800E7A8:
	movs r2, #0x3c
	add r0, sp, #0x1c
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x50
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r0, sp, #0x24
	strh r3, [r0]
	movs r1, #0x28
_0800E7BC:
	strh r1, [r0, #2]
	strh r3, [r0, #4]
	adds r5, r0, #0
	movs r4, #0
	ldrb r0, [r6, #2]
	cmp r0, #0
	bne _0800E7CC
	ldr r4, _0800E80C @ =0x00200004
_0800E7CC:
	ldr r0, [r6, #0x24]
	ldrh r1, [r6]
	ldr r2, _0800E810 @ =0x00002001
	movs r3, #0x20
	str r3, [sp]
	add r3, sp, #0x1c
	str r3, [sp, #4]
	str r5, [sp, #8]
	movs r3, #0
	bl FUN_0823646c
	ldr r0, [r6, #0x24]
	movs r3, #0x80
	lsls r3, r3, #6
	str r4, [sp]
	movs r1, #0x3c
	str r1, [sp, #4]
	ldr r1, [sp, #0x50]
	ldr r2, [sp, #0x54]
	bl FUN_082364f8
	ldr r0, [r6, #0x24]
	ldr r1, _0800E814 @ =FUN_0800e4d8
	adds r2, r6, #0
	bl FUN_0823651c
	ldr r0, [r6, #0x24]
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	b _0800E81A
	.align 2, 0
_0800E80C: .4byte 0x00200004
_0800E810: .4byte 0x00002001
_0800E814: .4byte FUN_0800e4d8
_0800E818:
	str r0, [r6, #0x24]
_0800E81A:
	adds r4, r6, #0
	adds r4, #0x28
	ldr r1, _0800E838 @ =0x085AA790
	ldrb r0, [r6, #2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl Video_GetActorSprite
	cmp r0, #0
	bne _0800E83C
_0800E832:
	movs r0, #1
	rsbs r0, r0, #0
	b _0800E8F6
	.align 2, 0
_0800E838: .4byte 0x085AA790
_0800E83C:
	adds r0, r6, #0
	adds r0, #0x44
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r6, #0
	adds r0, #0x4b
	movs r5, #2
	strb r5, [r0]
	ldr r0, [r6, #0x18]
	ldr r1, [r6, #0x1c]
	str r0, [r6, #0x60]
	str r1, [r6, #0x64]
	mov r0, r8
	cmp r0, #1
	ble _0800E868
	ldr r1, _0800E880 @ =0x0000027B
	add r1, sb
	adds r0, r4, #0
	bl FUN_0822b20c
_0800E868:
	ldrb r1, [r6, #5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800E884
	ldr r0, [r6, #0x44]
	orrs r0, r5
	str r0, [r6, #0x44]
	adds r0, r6, #0
	adds r0, #0x4d
	movs r1, #0x78
	b _0800E894
	.align 2, 0
_0800E880: .4byte 0x0000027B
_0800E884:
	ldr r0, [r6, #0x44]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x44]
	adds r0, r6, #0
	adds r0, #0x4d
	movs r1, #0x40
_0800E894:
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	ldrb r0, [r6, #0xc]
	cmp r0, #0
	beq _0800E8B6
	adds r0, r6, #0
	adds r0, #0x70
	ldr r1, _0800E904 @ =0x03002B3C
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	movs r2, #0
	str r2, [sp]
	movs r2, #3
	movs r3, #0
	bl FUN_08236fac
_0800E8B6:
	adds r0, r6, #0
	adds r0, #0x80
	movs r1, #0x6b
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0xc8
	lsls r1, r1, #4
	str r1, [sp, #8]
	movs r5, #1
	str r5, [sp, #0xc]
	movs r1, #5
	str r1, [sp, #0x10]
	str r5, [sp, #0x14]
	movs r4, #0
	str r4, [sp, #0x18]
	adds r1, r7, #0
	movs r2, #0x50
	movs r3, #7
	bl FUN_08013ba8
	strb r5, [r6, #0xb]
	strb r4, [r6, #0xd]
	adds r0, r6, #0
	adds r0, #0xec
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	ldr r0, _0800E904 @ =0x03002B3C
	ldr r0, [r0]
	adds r1, r6, #0
	bl FUN_0800e4dc
_0800E8F6:
	add sp, #0x2c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800E904: .4byte 0x03002B3C

	thumb_func_start FUN_0800e908
FUN_0800e908: @ 0x0800E908
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x1c]
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp, #0x20]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	mov sl, r0
	movs r0, #0x54
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x73
	movs r1, #0
	bl VM_GetKeywordValue
	mov r8, r0
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x50
	movs r1, #0xc8
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x46
	movs r1, #0x32
	bl VM_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800E9B0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800E9A8 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x14]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800E9AC @ =0x0000FFFF
	ldr r1, [sp, #0x14]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x14]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x18]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x18]
	b _0800E9BA
	.align 2, 0
_0800E9A8: .4byte 0xFFFF0000
_0800E9AC: .4byte 0x0000FFFF
_0800E9B0:
	ldr r1, _0800E9E4 @ =0xFFFF0000
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x18]
	ands r0, r1
	str r0, [sp, #0x18]
_0800E9BA:
	mov r0, r8
	str r0, [sp]
	str r7, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	add r0, sp, #0x14
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x20]
	mov r2, sl
	mov r3, sb
	bl FUN_0800e594
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800E9E4: .4byte 0xFFFF0000

	thumb_func_start FUN_0800e9e8
FUN_0800e9e8: @ 0x0800E9E8
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _0800EA12
	movs r2, #0
	strb r2, [r4, #3]
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	beq _0800EA12
	adds r0, r4, #0
	adds r0, #0x70
	ldr r1, _0800EA40 @ =0x03002B3C
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	str r2, [sp]
	movs r2, #3
	movs r3, #0
	bl FUN_08236fac
_0800EA12:
	ldrh r0, [r4, #0x1a]
	ldrh r1, [r4, #0x12]
	subs r0, r0, r1
	strh r0, [r4, #0x1a]
	movs r1, #0x1a
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, #0x14]
	cmp r0, r1
	bgt _0800EA6C
	strh r1, [r4, #0x1a]
	ldrb r0, [r4, #2]
	cmp r0, #2
	bne _0800EA54
	ldrb r1, [r4, #5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800EA48
	ldr r0, _0800EA44 @ =0x0000029D
	bl PlaySound_082406e0
	b _0800EA5C
	.align 2, 0
_0800EA40: .4byte 0x03002B3C
_0800EA44: .4byte 0x0000029D
_0800EA48:
	ldr r0, _0800EA50 @ =0x000001FF
	bl PlaySound_082406e0
	b _0800EA5C
	.align 2, 0
_0800EA50: .4byte 0x000001FF
_0800EA54:
	movs r0, #0xa3
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0800EA5C:
	movs r2, #1
	movs r1, #0
	strb r2, [r4, #4]
	movs r0, #0
	strh r1, [r4, #6]
	strb r2, [r4, #3]
	strb r0, [r4, #0xf]
	strb r0, [r4, #0xe]
_0800EA6C:
	ldrb r0, [r4, #2]
	cmp r0, #1
	bls _0800EA9C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0xe]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bne _0800EA94
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0800EA92
	strb r1, [r4, #0xf]
_0800EA92:
	strb r1, [r4, #0xe]
_0800EA94:
	ldrb r1, [r4, #0xf]
	adds r0, r4, #0
	adds r0, #0x44
	strh r1, [r0, #0x10]
_0800EA9C:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0800EAAC
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
_0800EAAC:
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _0800EAC2
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [r4, #0x24]
	bl FUN_08236400
_0800EAC2:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800eacc
FUN_0800eacc: @ 0x0800EACC
	push {r4, r5, lr}
	sub sp, #0x18
	adds r5, r0, #0
	ldrb r0, [r5, #3]
	cmp r0, #0
	beq _0800EB30
	movs r4, #0
	strb r4, [r5, #3]
	adds r0, r5, #0
	adds r0, #0x70
	ldr r1, _0800EB78 @ =0x03002B3C
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	str r4, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	adds r0, r5, #0
	bl FUN_0800e530
	ldr r2, _0800EB7C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800EB80 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0800EB84 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #6
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #8
	str r2, [sp]
	str r2, [sp, #4]
	str r4, [sp, #8]
	adds r2, #0xf8
	str r2, [sp, #0xc]
	movs r2, #0x18
	str r2, [sp, #0x10]
	movs r2, #0x10
	str r2, [sp, #0x14]
	movs r2, #9
	movs r3, #0x14
	bl FUN_080166ac
_0800EB30:
	ldrb r0, [r5, #2]
	cmp r0, #1
	bls _0800EB60
	ldrb r0, [r5, #0xe]
	adds r0, #1
	movs r1, #0
	strb r0, [r5, #0xe]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bne _0800EB58
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0800EB56
	strb r1, [r5, #0xf]
_0800EB56:
	strb r1, [r5, #0xe]
_0800EB58:
	ldrb r1, [r5, #0xf]
	adds r0, r5, #0
	adds r0, #0x44
	strh r1, [r0, #0x10]
_0800EB60:
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bgt _0800EB88
	movs r0, #3
	movs r1, #0
	strb r0, [r5, #4]
	strh r1, [r5, #6]
	movs r0, #1
	strb r0, [r5, #3]
	b _0800EBFE
	.align 2, 0
_0800EB78: .4byte 0x03002B3C
_0800EB7C: .4byte 0x030046B8
_0800EB80: .4byte 0x000003FF
_0800EB84: .4byte 0x0203B400
_0800EB88:
	ldrh r0, [r5, #6]
	adds r1, r0, #1
	strh r1, [r5, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1e
	bls _0800EBA4
	movs r0, #2
	movs r1, #0
	strb r0, [r5, #4]
	strh r1, [r5, #6]
	movs r0, #1
	strb r0, [r5, #3]
	b _0800EBD8
_0800EBA4:
	ldrh r0, [r5, #6]
	movs r1, #0x1e
	subs r1, r1, r0
	asrs r2, r1, #1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800EBC6
	adds r1, r5, #0
	adds r1, #0x60
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r1, #4
	ldrh r0, [r1]
	subs r0, r0, r2
	b _0800EBD6
_0800EBC6:
	adds r1, r5, #0
	adds r1, #0x60
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
	adds r1, #4
	ldrh r0, [r1]
	adds r0, r0, r2
_0800EBD6:
	strh r0, [r1]
_0800EBD8:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0800EBE8
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
_0800EBE8:
	ldr r0, [r5, #0x24]
	cmp r0, #0
	beq _0800EBFE
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [r5, #0x24]
	bl FUN_08236400
_0800EBFE:
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800ec08
FUN_0800ec08: @ 0x0800EC08
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	ldrb r0, [r5, #3]
	cmp r0, #0
	beq _0800EC80
	movs r0, #0
	strb r0, [r5, #3]
	adds r0, r5, #0
	bl FUN_0800e530
	ldr r0, _0800EC94 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0800EC7C
	ldr r2, _0800EC98 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	ldr r3, _0800EC9C @ =0x0000FFF1
	orrs r0, r3
	ldr r4, _0800ECA0 @ =0x0000FFFF
	ands r0, r4
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x1e
	orrs r0, r3
	ands r0, r4
	movs r1, #0xb0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	adds r2, r5, #0
	adds r2, #0x18
	str r1, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #8
	movs r1, #3
	add r3, sp, #0xc
	bl FUN_08014730
_0800EC7C:
	movs r0, #0x1e
	strh r0, [r5, #8]
_0800EC80:
	ldrh r0, [r5, #6]
	cmp r0, #0xb
	bhi _0800ECA4
	ldrh r0, [r5, #0x1a]
	adds r0, #8
	strh r0, [r5, #0x1a]
	movs r0, #0x28
	bl FUN_0823b9cc
	b _0800ECB6
	.align 2, 0
_0800EC94: .4byte 0x030047A4
_0800EC98: .4byte 0xFFFF0000
_0800EC9C: .4byte 0x0000FFF1
_0800ECA0: .4byte 0x0000FFFF
_0800ECA4:
	ldrh r0, [r5, #0x1a]
	subs r0, #4
	strh r0, [r5, #0x1a]
	movs r1, #0x1a
	ldrsh r0, [r5, r1]
	ldrh r1, [r5, #0x14]
	cmp r0, r1
	bge _0800ECB6
	strh r1, [r5, #0x1a]
_0800ECB6:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0800ECC6
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
_0800ECC6:
	ldr r0, [r5, #0x24]
	cmp r0, #0
	beq _0800ECDC
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [r5, #0x24]
	bl FUN_08236400
_0800ECDC:
	ldrh r1, [r5, #6]
	movs r0, #7
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #1
	bhi _0800ECF0
	ldr r0, [r5, #0x44]
	movs r1, #1
	orrs r0, r1
	b _0800ECF8
_0800ECF0:
	ldr r0, [r5, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_0800ECF8:
	str r0, [r5, #0x44]
	adds r0, r2, #1
	strh r0, [r5, #6]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r5, #8]
	cmp r0, r1
	bls _0800ED0C
	movs r0, #1
	strb r0, [r5, #0xd]
_0800ED0C:
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800ed14
FUN_0800ed14: @ 0x0800ED14
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	ldrb r0, [r5, #3]
	cmp r0, #0
	beq _0800ED86
	movs r0, #0
	strb r0, [r5, #3]
	ldr r0, _0800EDA4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0800ED82
	ldr r2, _0800EDA8 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	ldr r3, _0800EDAC @ =0x0000FFF1
	orrs r0, r3
	ldr r4, _0800EDB0 @ =0x0000FFFF
	ands r0, r4
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x1e
	orrs r0, r3
	ands r0, r4
	movs r1, #0xb0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	adds r2, r5, #0
	adds r2, #0x18
	str r1, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #8
	movs r1, #3
	add r3, sp, #0xc
	bl FUN_08014730
_0800ED82:
	movs r0, #0x19
	strh r0, [r5, #8]
_0800ED86:
	ldrh r0, [r5, #6]
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0xe
	bhi _0800EDB4
	lsrs r1, r1, #0x12
	subs r1, #0x10
	ldrh r0, [r5, #0x1a]
	subs r0, r0, r1
	strh r0, [r5, #0x1a]
	movs r0, #0x28
	bl FUN_0823b9cc
	b _0800EDD6
	.align 2, 0
_0800EDA4: .4byte 0x030047A4
_0800EDA8: .4byte 0xFFFF0000
_0800EDAC: .4byte 0x0000FFF1
_0800EDB0: .4byte 0x0000FFFF
_0800EDB4:
	ldrh r0, [r5, #6]
	adds r1, r0, #0
	subs r1, #0xf
	cmp r1, #0xf
	bgt _0800EDC4
	ldrh r0, [r5, #0x1a]
	subs r0, r0, r1
	b _0800EDC8
_0800EDC4:
	ldrh r0, [r5, #0x1a]
	subs r0, #0x10
_0800EDC8:
	strh r0, [r5, #0x1a]
	movs r1, #0x1a
	ldrsh r0, [r5, r1]
	ldrh r1, [r5, #0x14]
	cmp r0, r1
	bge _0800EDD6
	strh r1, [r5, #0x1a]
_0800EDD6:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0800EDE6
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
_0800EDE6:
	ldr r0, [r5, #0x24]
	cmp r0, #0
	beq _0800EDFC
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [r5, #0x24]
	bl FUN_08236400
_0800EDFC:
	ldrh r1, [r5, #6]
	movs r0, #7
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #1
	bhi _0800EE10
	ldr r0, [r5, #0x44]
	movs r1, #1
	orrs r0, r1
	b _0800EE18
_0800EE10:
	ldr r0, [r5, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_0800EE18:
	str r0, [r5, #0x44]
	adds r0, r2, #1
	strh r0, [r5, #6]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r5, #8]
	cmp r0, r1
	bls _0800EE32
	adds r0, r5, #0
	bl FUN_0800e530
	movs r0, #1
	strb r0, [r5, #0xd]
_0800EE32:
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800ee3c
FUN_0800ee3c: @ 0x0800EE3C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _0800EE60
	movs r2, #0
	strb r2, [r4, #3]
	adds r0, r4, #0
	adds r0, #0x70
	ldr r1, _0800EE88 @ =0x03002B3C
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
_0800EE60:
	movs r1, #0x10
	ldrsh r0, [r4, r1]
	cmp r0, #0
	ble _0800EE78
	ldrh r0, [r4, #6]
	adds r1, r0, #1
	strh r1, [r4, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4, #8]
	cmp r0, r1
	bls _0800EE8C
_0800EE78:
	movs r0, #3
	movs r1, #0
	strb r0, [r4, #4]
	strh r1, [r4, #6]
	movs r0, #1
	strb r0, [r4, #3]
	b _0800EEB2
	.align 2, 0
_0800EE88: .4byte 0x03002B3C
_0800EE8C:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0800EE9C
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
_0800EE9C:
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _0800EEB2
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [r4, #0x24]
	bl FUN_08236400
_0800EEB2:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800eebc
FUN_0800eebc: @ 0x0800EEBC
	push {lr}
	sub sp, #0x18
	adds r3, r0, #0
	adds r0, #0x60
	ldr r2, _0800EF04 @ =0xFFFF0000
	adds r1, r3, #0
	adds r1, #0x62
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	ldrh r0, [r0]
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r0, r3, #0
	adds r0, #0x64
	ldrh r1, [r0]
	ldr r0, [sp, #0x14]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r0, #8
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #2
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015d3c
	add sp, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_0800EF04: .4byte 0xFFFF0000

	thumb_func_start FUN_0800ef08
FUN_0800ef08: @ 0x0800EF08
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _0800EF40
	movs r2, #0
	strb r2, [r4, #3]
	adds r0, r4, #0
	adds r0, #0x70
	ldr r1, _0800EF60 @ =0x03002B3C
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	str r2, [sp]
	movs r2, #4
	movs r3, #0
	bl FUN_08236fac
	ldr r2, [r4, #0x20]
	cmp r2, #0
	beq _0800EF3A
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0800EF3A:
	adds r0, r4, #0
	bl FUN_0800e530
_0800EF40:
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	beq _0800EF56
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	bne _0800EF52
	adds r0, r4, #0
	bl FUN_0800eebc
_0800EF52:
	movs r0, #1
	strb r0, [r4, #0xd]
_0800EF56:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800EF60: .4byte 0x03002B3C

	thumb_func_start FUN_0800ef64
FUN_0800ef64: @ 0x0800EF64
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, [r0, #0x1c]
	cmp r4, #0
	bne _0800EF74
	b _0800F0A8
_0800EF74:
	movs r0, #1
	mov r8, r0
	movs r1, #2
	mov sb, r1
_0800EF7C:
	adds r0, r4, #0
	adds r0, #0xf0
	ldr r7, [r0]
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _0800EF90
	adds r0, r4, #0
	bl FUN_0800e54c
	b _0800F0A0
_0800EF90:
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	beq _0800F082
	adds r6, r4, #0
	adds r6, #0x44
	adds r3, r4, #0
	adds r3, #0x70
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r4, #0x70]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r3, #4]
	mov r2, r8
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r1, r8
	ands r0, r1
	cmp r2, r0
	beq _0800EFCA
	ldr r0, [r4, #0x44]
	movs r1, #4
	orrs r0, r1
	b _0800EFD2
_0800EFCA:
	ldr r0, [r4, #0x44]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800EFD2:
	str r0, [r4, #0x44]
	ldrb r0, [r3, #4]
	mov r1, sb
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sb
	ands r0, r2
	cmp r1, r0
	beq _0800EFF6
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0800EFFE
_0800EFF6:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0800EFFE:
	str r0, [r6]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r5, _0800F038 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r3, #7]
	cmp r0, r5
	blo _0800F07E
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800F042
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _0800F03C
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	movs r2, #1
	b _0800F058
	.align 2, 0
_0800F038: .4byte 0x0000FFFF
_0800F03C:
	subs r0, #1
	strh r0, [r3, #8]
	b _0800F056
_0800F042:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _0800F056
	strh r1, [r3, #8]
	movs r2, #1
	b _0800F058
_0800F056:
	movs r2, #0
_0800F058:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800F080
	mov r5, r8
	strb r5, [r3, #7]
	b _0800F080
_0800F07E:
	movs r2, #0
_0800F080:
	strb r2, [r4, #0xa]
_0800F082:
	ldr r0, [r4, #0x18]
	ldr r1, [r4, #0x1c]
	str r0, [r4, #0x60]
	str r1, [r4, #0x64]
	ldr r2, _0800F0B8 @ =0x085AA7A0
	ldrb r1, [r4, #4]
	lsls r1, r1, #2
	ldrb r0, [r4, #2]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r1, r1, r2
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_0800F0A0:
	adds r4, r7, #0
	cmp r4, #0
	beq _0800F0A8
	b _0800EF7C
_0800F0A8:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800F0B8: .4byte 0x085AA7A0

	thumb_func_start FUN_0800f0bc
FUN_0800f0bc: @ 0x0800F0BC
	push {r4, lr}
	ldr r1, [r0, #0x1c]
	cmp r1, #0
	beq _0800F0D6
_0800F0C4:
	adds r0, r1, #0
	adds r0, #0xf0
	ldr r4, [r0]
	adds r0, r1, #0
	bl FUN_0800e54c
	adds r1, r4, #0
	cmp r1, #0
	bne _0800F0C4
_0800F0D6:
	ldr r1, _0800F0E4 @ =0x03002B3C
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800F0E4: .4byte 0x03002B3C

	thumb_func_start FUN_0800f0e8
FUN_0800f0e8: @ 0x0800F0E8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0800F104 @ =0x03002B3C
	str r4, [r0]
	ldr r0, _0800F108 @ =0x0000922E
	ldr r1, _0800F10C @ =0x0000931E
	bl GetFile
	str r0, [r4, #0x18]
	movs r0, #0
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800F104: .4byte 0x03002B3C
_0800F108: .4byte 0x0000922E
_0800F10C: .4byte 0x0000931E

	thumb_func_start FUN_0800f110
FUN_0800f110: @ 0x0800F110
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0800F148 @ =0x03002B3C
	ldr r0, [r0]
	cmp r0, #0
	bne _0800F156
	movs r0, #8
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800F154
	ldr r1, _0800F14C @ =FUN_0800ef64
	ldr r2, _0800F150 @ =FUN_0800f0bc
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0800f0e8
	cmp r0, #0
	bge _0800F154
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800F156
	.align 2, 0
_0800F148: .4byte 0x03002B3C
_0800F14C: .4byte FUN_0800ef64
_0800F150: .4byte FUN_0800f0bc
_0800F154:
	adds r0, r4, #0
_0800F156:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800f15c
FUN_0800f15c: @ 0x0800F15C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	movs r5, #0
	ldr r1, _0800F258 @ =0x000002DA
	adds r0, r4, r1
	ldrh r2, [r0]
	cmp r5, r2
	bge _0800F19E
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r7, r4, r3
	adds r6, r4, #0
	adds r6, #0x54
	mov ip, r5
	adds r3, r0, #0
_0800F184:
	lsls r2, r5, #1
	ldrh r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	adds r2, r6, r2
	mov r0, ip
	strh r0, [r2]
	adds r5, #1
	ldrh r1, [r3]
	cmp r5, r1
	blt _0800F184
_0800F19E:
	ldr r2, _0800F258 @ =0x000002DA
	adds r0, r4, r2
	ldrh r5, [r0]
	movs r3, #0xb7
	lsls r3, r3, #2
	mov ip, r3
	adds r0, r4, r3
	ldr r1, _0800F25C @ =0x000002D6
	adds r1, r1, r4
	mov sl, r1
	subs r2, #2
	adds r2, r4, r2
	str r2, [sp]
	ldrh r0, [r0]
	cmp r5, r0
	bge _0800F210
	ldr r3, _0800F260 @ =0x0203B400
	mov sb, r3
	ldr r6, _0800F264 @ =0x030046B8
	ldr r0, _0800F25C @ =0x000002D6
	adds r0, r0, r4
	mov r8, r0
	movs r1, #0xb5
	lsls r1, r1, #2
	adds r7, r4, r1
_0800F1D0:
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _0800F268 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r0]
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r2, r1, #0
	muls r2, r0, r2
	asrs r2, r2, #0x12
	lsls r3, r5, #1
	ldrh r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r3, r3, r0
	adds r1, r4, #0
	adds r1, #0x54
	adds r1, r1, r3
	lsls r0, r2, #8
	orrs r2, r0
	strh r2, [r1]
	adds r5, #1
	mov r1, ip
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r5, r0
	blt _0800F1D0
_0800F210:
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r5, [r0]
	cmp r5, #0x9f
	bgt _0800F23E
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r6, r4, r3
	adds r3, r4, #0
	adds r3, #0x54
	movs r4, #0
_0800F228:
	lsls r2, r5, #1
	ldrh r1, [r6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	adds r2, r3, r2
	strh r4, [r2]
	adds r5, #1
	cmp r5, #0x9f
	ble _0800F228
_0800F23E:
	mov r1, sl
	ldr r2, [sp]
	ldrh r0, [r2]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0800F26C
	movs r0, #0
	b _0800F274
	.align 2, 0
_0800F258: .4byte 0x000002DA
_0800F25C: .4byte 0x000002D6
_0800F260: .4byte 0x0203B400
_0800F264: .4byte 0x030046B8
_0800F268: .4byte 0x000003FF
_0800F26C:
	cmp r0, #0x80
	ble _0800F276
	movs r0, #0x80
	mov r1, sl
_0800F274:
	strh r0, [r1]
_0800F276:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800f288
FUN_0800f288: @ 0x0800F288
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x46
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0800F2B0
	adds r0, r4, #0
	adds r0, #0x48
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	adds r1, r4, #0
	adds r1, #0x4e
	movs r5, #0
	ldrsh r1, [r1, r5]
	bl Div
	ldr r1, _0800F2E0 @ =0x03004040
	str r0, [r1]
_0800F2B0:
	adds r2, r4, #0
	adds r2, #0x48
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	adds r1, r4, #0
	adds r1, #0x4e
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r3, [r1]
	movs r5, #0
	ldrsh r1, [r1, r5]
	cmp r0, r1
	ble _0800F2D8
	strh r3, [r2]
	movs r0, #0xb9
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
_0800F2D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800F2E0: .4byte 0x03004040

	thumb_func_start FUN_0800f2e4
FUN_0800f2e4: @ 0x0800F2E4
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x46
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0800F30C
	adds r0, r4, #0
	adds r0, #0x48
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	adds r1, r4, #0
	adds r1, #0x4e
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl Div
	ldr r1, _0800F340 @ =0x03004040
	str r0, [r1]
_0800F30C:
	adds r1, r4, #0
	adds r1, #0x48
	ldrh r0, [r1]
	subs r0, #1
	movs r2, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0800F33A
	strh r2, [r1]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	str r2, [r0]
	ldr r0, [r4, #0x40]
	cmp r0, #0
	beq _0800F334
	movs r1, #0
	bl Script_ExecById
_0800F334:
	adds r0, r4, #0
	bl KillEntity
_0800F33A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800F340: .4byte 0x03004040

	thumb_func_start FUN_0800f344
FUN_0800f344: @ 0x0800F344
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r3, r5, #0
	adds r3, #0x46
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	bne _0800F35C
	ldr r0, _0800F3DC @ =0x0300445C
	ldr r1, _0800F3E0 @ =0x03004040
	ldr r1, [r1]
	str r1, [r0]
_0800F35C:
	adds r0, r5, #0
	adds r0, #0x44
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _0800F3F4
	ldr r0, _0800F3E4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0800F3F4
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r1, #8]
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	movs r0, #0xeb
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, _0800F3E8 @ =0x0000040C
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, _0800F3EC @ =0x0000046C
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, _0800F3F0 @ =0x000004CC
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	movs r1, #0
	ldrsh r2, [r3, r1]
	cmp r2, #0
	bne _0800F3C8
	ldr r1, _0800F3DC @ =0x0300445C
	ldr r0, _0800F3E0 @ =0x03004040
	str r2, [r0]
	str r2, [r1]
_0800F3C8:
	ldr r0, [r5, #0x40]
	cmp r0, #0
	beq _0800F3D4
	movs r1, #0
	bl Script_ExecById
_0800F3D4:
	adds r0, r5, #0
	bl KillEntity
	b _0800F506
	.align 2, 0
_0800F3DC: .4byte 0x0300445C
_0800F3E0: .4byte 0x03004040
_0800F3E4: .4byte 0x030044E0
_0800F3E8: .4byte 0x0000040C
_0800F3EC: .4byte 0x0000046C
_0800F3F0: .4byte 0x000004CC
_0800F3F4:
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r6, r5, r2
	ldr r1, [r6]
	cmp r1, #0
	beq _0800F406
	adds r0, r5, #0
	bl _call_via_r1
_0800F406:
	movs r3, #0xba
	lsls r3, r3, #2
	adds r7, r5, r3
	ldr r1, [r7]
	cmp r1, #0
	beq _0800F43A
	adds r0, r5, #0
	bl _call_via_r1
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrh r0, [r4]
	lsls r2, r0, #2
	adds r2, r2, r0
	lsls r2, r2, #6
	adds r2, #0x54
	adds r2, r5, r2
	movs r0, #0
	movs r1, #2
	bl FUN_0822ee58
	ldrh r1, [r4]
	movs r0, #1
	subs r0, r0, r1
	strh r0, [r4]
_0800F43A:
	ldrh r2, [r5, #0x38]
	cmp r2, #1
	beq _0800F4A8
	cmp r2, #1
	bgt _0800F44A
	cmp r2, #0
	beq _0800F450
	b _0800F500
_0800F44A:
	cmp r2, #2
	beq _0800F4B4
	b _0800F500
_0800F450:
	ldrh r0, [r5, #0x3a]
	adds r0, #1
	strh r0, [r5, #0x3a]
	ldrh r1, [r5, #0x3a]
	adds r0, r5, #0
	adds r0, #0x4a
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	ble _0800F500
	movs r0, #1
	strh r0, [r5, #0x38]
	strh r2, [r5, #0x3a]
	ldr r0, _0800F498 @ =FUN_0800f288
	str r0, [r6]
	ldr r1, _0800F49C @ =0x000002DA
	adds r0, r5, r1
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _0800F486
	movs r0, #0xe1
	bl PlaySound_082406e0
_0800F486:
	ldr r3, _0800F4A0 @ =0x000002D6
	adds r1, r5, r3
	movs r0, #0x80
	strh r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, _0800F4A4 @ =0x0000FFFE
	b _0800F4FA
	.align 2, 0
_0800F498: .4byte FUN_0800f288
_0800F49C: .4byte 0x000002DA
_0800F4A0: .4byte 0x000002D6
_0800F4A4: .4byte 0x0000FFFE
_0800F4A8:
	ldr r0, [r6]
	cmp r0, #0
	bne _0800F500
	movs r0, #2
	strh r0, [r5, #0x38]
	b _0800F500
_0800F4B4:
	ldrh r0, [r5, #0x3a]
	adds r0, #1
	movs r4, #0
	strh r0, [r5, #0x3a]
	ldrh r1, [r5, #0x3a]
	adds r0, r5, #0
	adds r0, #0x4c
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	ble _0800F500
	movs r0, #3
	strh r0, [r5, #0x38]
	strh r4, [r5, #0x3a]
	ldr r0, _0800F510 @ =FUN_0800f2e4
	str r0, [r6]
	ldr r3, _0800F514 @ =0x000002DA
	adds r0, r5, r3
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _0800F4EC
	movs r0, #0xe3
	bl PlaySound_082406e0
_0800F4EC:
	ldr r3, _0800F518 @ =0x000002D6
	adds r0, r5, r3
	strh r4, [r0]
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #4
_0800F4FA:
	strh r0, [r1]
	ldr r0, _0800F51C @ =FUN_0800f15c
	str r0, [r7]
_0800F500:
	ldr r0, [r5, #0x3c]
	adds r0, #1
	str r0, [r5, #0x3c]
_0800F506:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800F510: .4byte FUN_0800f2e4
_0800F514: .4byte 0x000002DA
_0800F518: .4byte 0x000002D6
_0800F51C: .4byte FUN_0800f15c

	thumb_func_start FUN_0800f520
FUN_0800f520: @ 0x0800F520
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_0822f0d8
	bl FUN_0822ed10
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0xeb
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r1, _0800F570 @ =0x0000040C
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r0, _0800F574 @ =0x0000046C
	adds r4, r4, r0
	movs r5, #1
_0800F558:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0800F558
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800F570: .4byte 0x0000040C
_0800F574: .4byte 0x0000046C

	thumb_func_start FUN_0800f578
FUN_0800f578: @ 0x0800F578
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r5, r0, #0
	ldr r1, _0800F5D4 @ =0x03004250
	movs r4, #0
	ldr r0, _0800F5D8 @ =0x00001084
	strh r0, [r1]
	ldr r1, _0800F5DC @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	str r4, [sp, #0x10]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	str r4, [r0]
	adds r0, r5, #0
	adds r0, #0x48
	strh r4, [r0]
	strh r4, [r5, #0x38]
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x44
	strh r0, [r1]
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x46
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800F5E0
	adds r1, #4
	movs r0, #0x40
	strh r0, [r1]
	b _0800F5E6
	.align 2, 0
_0800F5D4: .4byte 0x03004250
_0800F5D8: .4byte 0x00001084
_0800F5DC: .4byte 0xFFFF0000
_0800F5E0:
	adds r0, r5, #0
	adds r0, #0x4a
	strh r4, [r0]
_0800F5E6:
	adds r1, r5, #0
	adds r1, #0x4e
	movs r0, #0x40
	strh r0, [r1]
	movs r0, #0x64
	movs r1, #0x80
	bl VM_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x4c
	strh r0, [r1]
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp, #0x20]
	movs r0, #0x63
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r4, #1
	rsbs r4, r4, #0
	movs r0, #0x73
	adds r1, r4, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r5, #0x40]
	movs r0, #0x6f
	adds r1, r4, #0
	bl VM_GetKeywordValue
	ldr r2, _0800F688 @ =0x000002DE
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #0x74
	adds r1, r4, #0
	bl VM_GetKeywordValue
	ldr r3, _0800F68C @ =0x000002DF
	adds r1, r5, r3
	strb r0, [r1]
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetKeywordValue
	movs r4, #0xb8
	lsls r4, r4, #2
	adds r1, r5, r4
	strb r0, [r1]
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800F662
	bl FUN_0823d340
_0800F662:
	str r0, [r5, #0x50]
	movs r0, #0x79
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _0800F694
	bl Script_GetValue
	ldr r7, _0800F690 @ =0x000002DA
	adds r1, r5, r7
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r5, r2
	strh r0, [r1]
	b _0800F6A2
	.align 2, 0
_0800F688: .4byte 0x000002DE
_0800F68C: .4byte 0x000002DF
_0800F690: .4byte 0x000002DA
_0800F694:
	ldr r3, _0800F6B8 @ =0x000002DA
	adds r0, r5, r3
	strh r1, [r0]
	movs r4, #0xb7
	lsls r4, r4, #2
	adds r0, r5, r4
	strh r1, [r0]
_0800F6A2:
	ldr r0, _0800F6BC @ =0x0000CB05
	ldr r1, _0800F6C0 @ =0x0000E89F
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _0800F6C4
	movs r0, #1
	rsbs r0, r0, #0
	b _0800F942
	.align 2, 0
_0800F6B8: .4byte 0x000002DA
_0800F6BC: .4byte 0x0000CB05
_0800F6C0: .4byte 0x0000E89F
_0800F6C4:
	adds r0, r5, #0
	adds r0, #0x18
	adds r1, r2, #0
	ldm r1!, {r3, r4, r7}
	stm r0!, {r3, r4, r7}
	ldm r1!, {r3, r4, r7}
	stm r0!, {r3, r4, r7}
	ldm r1!, {r3, r7}
	stm r0!, {r3, r7}
	adds r4, r5, #0
	adds r4, #0x18
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	mov sl, r4
	cmp r6, #0
	blt _0800F710
	movs r4, #0xbb
	lsls r4, r4, #2
	adds r0, r5, r4
	adds r2, r6, #0
	adds r2, #0x17
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #0x87
	lsls r3, r3, #4
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r7, sp, #0x10
	str r7, [sp, #0xc]
	mov r1, sl
	bl FUN_0822f3fc
	b _0800F72E
_0800F710:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r3, _0800F7D4 @ =0x00000871
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	mov r1, sl
	movs r2, #0x17
	bl FUN_0822f3fc
_0800F72E:
	movs r3, #0xd3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r4, _0800F7D4 @ =0x00000871
	mov r8, r4
	movs r6, #0
	str r6, [sp]
	str r6, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	add r7, sp, #0x10
	str r7, [sp, #0xc]
	mov r1, sl
	movs r2, #0x16
	mov r3, r8
	bl FUN_0822f3fc
	mov r0, sb
	cmp r0, #0
	beq _0800F766
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0800F766:
	ldr r2, _0800F7D8 @ =0x0000040C
	adds r1, r5, r2
	movs r3, #0xb8
	lsls r3, r3, #2
	adds r7, r5, r3
	movs r0, #0
	ldrsb r0, [r7, r0]
	movs r2, #1
	cmp r0, #0
	beq _0800F77C
	movs r2, #0x26
_0800F77C:
	str r6, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r0, r1, #0
	mov r1, sl
	mov r3, r8
	bl FUN_0822f3fc
	ldr r0, _0800F7DC @ =0x000002DE
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _0800F7E4
	ldr r1, _0800F7E0 @ =0x00000414
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #0xa
	bl Mod
	str r0, [sp, #0x18]
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #0xa
	bl Div
	add r1, sp, #0x18
	str r0, [r1, #4]
	ldr r0, [sp, #0x18]
	adds r0, #2
	str r0, [sp, #0x18]
	ldr r0, [r1, #4]
	adds r0, #0xc
	str r0, [r1, #4]
	adds r0, r1, #0
	b _0800F804
	.align 2, 0
_0800F7D4: .4byte 0x00000871
_0800F7D8: .4byte 0x0000040C
_0800F7DC: .4byte 0x000002DE
_0800F7E0: .4byte 0x00000414
_0800F7E4:
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #0
	beq _0800F7FA
	ldr r2, _0800F8EC @ =0x00000414
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0800F7FA:
	movs r0, #2
	str r0, [sp, #0x18]
	movs r1, #0xc
	add r0, sp, #0x18
	str r1, [r0, #4]
_0800F804:
	adds r3, r5, #0
	adds r3, #0x46
	str r3, [sp, #0x24]
	adds r6, r0, #0
	ldr r7, _0800F8F0 @ =0x0000046C
	adds r4, r5, r7
	movs r0, #0
	mov sb, r0
	movs r1, #1
	mov r8, r1
_0800F818:
	ldrh r2, [r6]
	movs r7, #0
	str r7, [sp]
	str r7, [sp, #4]
	movs r3, #0x3c
	str r3, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sl
	ldr r3, _0800F8F4 @ =0x00000871
	bl FUN_0822f3fc
	ldr r1, _0800F8F8 @ =0x000002DE
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0800F850
	ldr r2, _0800F8FC @ =0x00000474
	adds r0, r5, r2
	add r0, sb
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0800F850:
	adds r6, #4
	adds r4, #0x60
	movs r3, #0x60
	add sb, r3
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _0800F818
	ldr r2, _0800F900 @ =0x000002DF
	adds r6, r5, r2
	movs r0, #0
	ldrsb r0, [r6, r0]
	movs r2, #0
	cmp r0, #0
	blt _0800F874
	adds r2, r0, #0
_0800F874:
	movs r3, #0xeb
	lsls r3, r3, #2
	adds r0, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _0800F8F4 @ =0x00000871
	str r7, [sp]
	str r7, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	add r7, sp, #0x10
	str r7, [sp, #0xc]
	mov r1, sl
	bl FUN_0822f3fc
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #0
	blt _0800F8AA
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0800F8AA:
	ldr r0, [r5, #0x50]
	cmp r0, #0
	beq _0800F90C
	movs r0, #1
	bl FUN_080477e4
	ldr r0, _0800F904 @ =0x0000539C
	bl FUN_08047dc0
	ldr r0, [r5, #0x50]
	bl FUN_080478f0
	ldr r0, [sp, #0x20]
	bl FUN_08047a28
	movs r0, #0
	movs r1, #7
	movs r2, #0x1a
	movs r3, #2
	bl FUN_08047b8c
	bl FUN_080488dc
	ldr r1, _0800F908 @ =0x03003ED0
	lsls r0, r0, #2
	subs r0, #0x78
	strh r0, [r1, #0x20]
	movs r0, #0
	movs r1, #0
	movs r2, #0x11
	bl FUN_0822ece4
	b _0800F916
	.align 2, 0
_0800F8EC: .4byte 0x00000414
_0800F8F0: .4byte 0x0000046C
_0800F8F4: .4byte 0x00000871
_0800F8F8: .4byte 0x000002DE
_0800F8FC: .4byte 0x00000474
_0800F900: .4byte 0x000002DF
_0800F904: .4byte 0x0000539C
_0800F908: .4byte 0x03003ED0
_0800F90C:
	movs r0, #0
	movs r1, #0
	movs r2, #0x10
	bl FUN_0822ece4
_0800F916:
	ldr r2, [sp, #0x24]
	movs r4, #0
	ldrsh r3, [r2, r4]
	cmp r3, #0
	bne _0800F940
	ldr r0, _0800F954 @ =0x03004040
	str r3, [r0]
	ldr r0, _0800F958 @ =0x03004494
	ldr r7, _0800F95C @ =0x00001084
	adds r2, r7, #0
	strh r2, [r0]
	ldr r1, _0800F960 @ =0x03004454
	ldr r4, _0800F964 @ =0x0000FFFF
	adds r0, r4, #0
	strh r0, [r1]
	ldr r0, _0800F968 @ =0x0300445C
	str r3, [r0]
	ldr r0, _0800F96C @ =0x03004464
	strh r2, [r0]
	ldr r0, _0800F970 @ =0x03004490
	strh r3, [r0]
_0800F940:
	movs r0, #0
_0800F942:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800F954: .4byte 0x03004040
_0800F958: .4byte 0x03004494
_0800F95C: .4byte 0x00001084
_0800F960: .4byte 0x03004454
_0800F964: .4byte 0x0000FFFF
_0800F968: .4byte 0x0300445C
_0800F96C: .4byte 0x03004464
_0800F970: .4byte 0x03004490

	thumb_func_start FUN_0800f974
FUN_0800f974: @ 0x0800F974
	push {r4, lr}
	ldr r1, _0800F9A0 @ =0x0000052C
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800F9AC
	ldr r1, _0800F9A4 @ =FUN_0800f344
	ldr r2, _0800F9A8 @ =FUN_0800f520
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0800f578
	cmp r0, #0
	bge _0800F9AC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800F9AE
	.align 2, 0
_0800F9A0: .4byte 0x0000052C
_0800F9A4: .4byte FUN_0800f344
_0800F9A8: .4byte FUN_0800f520
_0800F9AC:
	adds r0, r4, #0
_0800F9AE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800f9b4
FUN_0800f9b4: @ 0x0800F9B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r2, r1, #4
	str r2, [sp, #4]
	ldrh r2, [r0, #0x1c]
	lsls r2, r2, #2
	adds r1, #0x24
	adds r2, r1, r2
	ldr r2, [r2]
	str r2, [sp, #8]
	ldrh r2, [r0, #0x1e]
	lsls r2, r2, #2
	adds r1, r1, r2
	ldr r1, [r1]
	mov sl, r1
	ldrh r7, [r0, #0x20]
	cmp r7, #0x40
	ble _0800F9E2
	movs r7, #0x40
_0800F9E2:
	movs r0, #0x1f
	mov sb, r0
	movs r1, #0x1f
	mov ip, r1
	movs r0, #0x40
	subs r0, r0, r7
	mov r8, r0
	movs r2, #0xf
	str r2, [sp]
_0800F9F4:
	ldr r0, [sp, #8]
	ldrh r3, [r0]
	mov r6, ip
	ands r6, r3
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x15
	mov r1, sb
	ands r5, r1
	lsrs r3, r3, #0x1a
	ands r3, r1
	mov r0, sl
	ldrh r2, [r0]
	mov r0, ip
	ands r0, r2
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x15
	ands r4, r1
	lsrs r2, r2, #0x1a
	ands r2, r1
	muls r0, r7, r0
	mov r1, r8
	muls r1, r6, r1
	adds r0, r0, r1
	asrs r6, r0, #6
	adds r0, r4, #0
	muls r0, r7, r0
	mov r1, r8
	muls r1, r5, r1
	adds r0, r0, r1
	asrs r4, r0, #6
	adds r0, r2, #0
	muls r0, r7, r0
	mov r1, r8
	muls r1, r3, r1
	adds r0, r0, r1
	asrs r1, r0, #6
	mov r2, ip
	ands r6, r2
	ands r4, r2
	ands r1, r2
	lsls r0, r4, #5
	orrs r6, r0
	lsls r0, r1, #0xa
	orrs r6, r0
	ldr r0, [sp, #4]
	strh r6, [r0]
	adds r0, #2
	str r0, [sp, #4]
	ldr r1, [sp, #8]
	adds r1, #2
	str r1, [sp, #8]
	movs r2, #2
	add sl, r2
	ldr r0, [sp]
	subs r0, #1
	str r0, [sp]
	cmp r0, #0
	bge _0800F9F4
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800fa78
FUN_0800fa78: @ 0x0800FA78
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _0800FB20 @ =gClock
	ldrh r0, [r5, #0x26]
	ldrb r1, [r1, #0xe]
	cmp r0, r1
	beq _0800FA98
	adds r0, r5, #0
	adds r0, #0x1c
	adds r1, r5, #0
	adds r1, #0x1e
	bl FUN_0823ce10
	movs r0, #0
	strh r0, [r5, #0x20]
_0800FA98:
	ldrh r0, [r5, #0x20]
	cmp r0, #0x3f
	bhi _0800FACE
	movs r6, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _0800FABC
	adds r4, r5, #0
	adds r4, #0x28
_0800FAAA:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800f9b4
	adds r4, #0x30
	adds r6, #1
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	blt _0800FAAA
_0800FABC:
	ldrh r0, [r5, #0x20]
	adds r0, #1
	strh r0, [r5, #0x20]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _0800FACE
	movs r0, #0x40
	strh r0, [r5, #0x20]
_0800FACE:
	ldr r1, _0800FB24 @ =0x03004044
	ldr r0, _0800FB28 @ =0x03004458
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _0800FB2C @ =0x03004450
	movs r0, #0
	str r0, [r1]
	movs r6, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _0800FB0C
	adds r2, r1, #0
	adds r7, r5, #0
	adds r7, #0x2c
	adds r4, r5, #0
	adds r4, #0x28
_0800FAEE:
	ldrh r0, [r4, #2]
	adds r1, r7, #0
	str r2, [sp]
	bl FUN_0822d190
	ldr r2, [sp]
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	adds r7, #0x30
	adds r4, #0x30
	adds r6, #1
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	blt _0800FAEE
_0800FB0C:
	ldr r0, _0800FB20 @ =gClock
	ldrb r1, [r0, #0xf]
	strh r1, [r5, #0x24]
	ldrb r0, [r0, #0xe]
	strh r0, [r5, #0x26]
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800FB20: .4byte gClock
_0800FB24: .4byte 0x03004044
_0800FB28: .4byte 0x03004458
_0800FB2C: .4byte 0x03004450

	thumb_func_start FUN_0800fb30
FUN_0800fb30: @ 0x0800FB30
	movs r0, #0
	bx lr

	thumb_func_start FUN_0800fb34
FUN_0800fb34: @ 0x0800FB34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	movs r0, #0
	strh r1, [r5, #0x18]
	strh r0, [r5, #0x1a]
	movs r0, #0x6f
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800FB8C
	movs r6, #0
	movs r0, #0x1c
	adds r0, r0, r5
	mov sb, r0
	movs r2, #0x1e
	adds r2, r2, r5
	mov r8, r2
	b _0800FB6E
_0800FB62:
	bl Script_GetValue
	lsls r1, r6, #1
	add r1, sp
	strh r0, [r1]
	adds r6, #1
_0800FB6E:
	cmp r6, #5
	bgt _0800FBA6
	bl VM_GetPC
	cmp r0, #0
	bne _0800FB62
	movs r1, #0
	lsls r0, r6, #1
	add r0, sp
_0800FB80:
	strh r1, [r0]
	adds r0, #2
	adds r6, #1
	cmp r6, #5
	ble _0800FB80
	b _0800FBA6
_0800FB8C:
	movs r0, #0x1c
	adds r0, r0, r5
	mov sb, r0
	movs r2, #0x1e
	adds r2, r2, r5
	mov r8, r2
	movs r1, #0
	mov r0, sp
	adds r0, #0xa
_0800FB9E:
	strh r1, [r0]
	subs r0, #2
	cmp r0, sp
	bge _0800FB9E
_0800FBA6:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800FC02
	movs r6, #0
	ldr r0, _0800FBC0 @ =0x03003584
	mov sl, r0
	mov r7, sp
	adds r4, r5, #0
	adds r4, #0x28
	b _0800FBF6
	.align 2, 0
_0800FBC0: .4byte 0x03003584
_0800FBC4:
	bl Script_GetValue
	strh r0, [r4]
	ldrh r0, [r4]
	bl FUN_0823cdf8
	ldrh r1, [r7]
	adds r1, r1, r0
	strh r1, [r4, #2]
	ldrh r1, [r4, #2]
	lsls r1, r1, #5
	mov r2, sl
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r4, #0x24]
	adds r0, #0x20
	str r0, [r4, #0x28]
	adds r0, #0x20
	str r0, [r4, #0x2c]
	ldrh r0, [r5, #0x1a]
	adds r0, #1
	strh r0, [r5, #0x1a]
	adds r7, #2
	adds r4, #0x30
	adds r6, #1
_0800FBF6:
	cmp r6, #5
	bgt _0800FC02
	bl VM_GetPC
	cmp r0, #0
	bne _0800FBC4
_0800FC02:
	mov r0, sb
	mov r1, r8
	bl FUN_0823ce10
	movs r0, #0x40
	strh r0, [r5, #0x20]
	ldr r1, _0800FC48 @ =gClock
	ldrb r0, [r1, #0xf]
	strh r0, [r5, #0x24]
	ldrb r0, [r1, #0xe]
	strh r0, [r5, #0x26]
	movs r6, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _0800FC36
	adds r4, r5, #0
	adds r4, #0x28
_0800FC24:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800f9b4
	adds r4, #0x30
	adds r6, #1
	ldrh r2, [r5, #0x1a]
	cmp r6, r2
	blt _0800FC24
_0800FC36:
	movs r0, #0
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800FC48: .4byte gClock

	thumb_func_start FUN_0800fc4c
FUN_0800fc4c: @ 0x0800FC4C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xa4
	lsls r1, r1, #1
	movs r0, #0xc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800FC88
	ldr r1, _0800FC80 @ =FUN_0800fa78
	ldr r2, _0800FC84 @ =FUN_0800fb30
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0800fb34
	cmp r0, #0
	bge _0800FC88
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800FC8A
	.align 2, 0
_0800FC80: .4byte FUN_0800fa78
_0800FC84: .4byte FUN_0800fb30
_0800FC88:
	adds r0, r4, #0
_0800FC8A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800fc90
FUN_0800fc90: @ 0x0800FC90
	ldr r1, _0800FC98 @ =0x03000048
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0800FC98: .4byte 0x03000048

	thumb_func_start FUN_0800fc9c
FUN_0800fc9c: @ 0x0800FC9C
	push {r4, lr}
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _0800FCC0 @ =0x03003ED0
	adds r3, r3, r0
	ldr r0, [r3, #0x2c]
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0x18
	ldrsh r1, [r3, r4]
	lsls r1, r1, #1
	muls r1, r2, r1
	lsls r1, r1, #1
	adds r0, r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800FCC0: .4byte 0x03003ED0

	thumb_func_start FUN_0800fcc4
FUN_0800fcc4: @ 0x0800FCC4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov sb, r2
	movs r2, #0
	cmp r1, #9
	ble _0800FCD8
	movs r2, #1
_0800FCD8:
	str r2, [sp]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #1
	subs r0, r1, r0
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #6
	movs r2, #0xb
	bl FUN_0800fc9c
	adds r4, r0, #0
	movs r3, #0
	mov ip, sp
	ldr r0, _0800FD90 @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _0800FD94 @ =0x03003ED0
	mov r8, r1
_0800FCFC:
	lsls r5, r3, #4
	mov r6, ip
	adds r1, r4, #0
	movs r2, #1
_0800FD04:
	ldm r6!, {r0}
	adds r0, #0x20
	adds r0, r5, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FD04
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r4, r4, r0
	adds r3, #1
	cmp r3, #1
	ble _0800FCFC
	mov r0, sb
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r2, sb
	subs r1, r2, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0xa
	movs r2, #0xb
	bl FUN_0800fc9c
	adds r4, r0, #0
	movs r3, #0
	mov ip, sp
	ldr r0, _0800FD90 @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _0800FD94 @ =0x03003ED0
	mov r8, r1
_0800FD54:
	adds r6, r3, #1
	lsls r3, r3, #4
	mov r5, ip
	adds r1, r4, #0
	movs r2, #1
_0800FD5E:
	ldm r5!, {r0}
	adds r0, #0x20
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FD5E
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r4, r4, r0
	adds r3, r6, #0
	cmp r3, #1
	ble _0800FD54
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FD90: .4byte 0xFFFFD000
_0800FD94: .4byte 0x03003ED0

	thumb_func_start FUN_0800fd98
FUN_0800fd98: @ 0x0800FD98
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	bl GetHour
	adds r4, r0, #0
	bl GetMinute
	mov sb, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [sp, #4]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0xb
	bl FUN_0800fc9c
	adds r4, r0, #0
	movs r3, #0
	mov ip, sp
	ldr r0, _0800FE6C @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _0800FE70 @ =0x03003ED0
	mov r8, r1
_0800FDDA:
	lsls r5, r3, #4
	mov r6, ip
	adds r1, r4, #0
	movs r2, #1
_0800FDE2:
	ldm r6!, {r0}
	adds r0, #0x20
	adds r0, r5, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FDE2
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r4, r4, r0
	adds r3, #1
	cmp r3, #1
	ble _0800FDDA
	mov r0, sb
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r2, sb
	subs r1, r2, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0x14
	movs r2, #0xb
	bl FUN_0800fc9c
	adds r4, r0, #0
	movs r3, #0
	mov ip, sp
	ldr r0, _0800FE6C @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _0800FE70 @ =0x03003ED0
	mov r8, r1
_0800FE32:
	adds r6, r3, #1
	lsls r3, r3, #4
	mov r5, ip
	adds r1, r4, #0
	movs r2, #1
_0800FE3C:
	ldm r5!, {r0}
	adds r0, #0x20
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FE3C
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r4, r4, r0
	adds r3, r6, #0
	cmp r3, #1
	ble _0800FE32
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FE6C: .4byte 0xFFFFD000
_0800FE70: .4byte 0x03003ED0

	thumb_func_start FUN_0800fe74
FUN_0800fe74: @ 0x0800FE74
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _0800FEB0 @ =gClock
	cmp r0, #0
	bne _0800FE88
	b _0801001E
_0800FE88:
	ldrb r0, [r0, #0xe]
	cmp r0, #0
	beq _0800FE96
	cmp r0, #4
	beq _0800FE96
	cmp r0, #5
	bne _0800FEB4
_0800FE96:
	movs r0, #0
	movs r1, #4
	movs r2, #0xf
	bl FUN_0800fc9c
	adds r5, r0, #0
	ldr r1, _0800FEB0 @ =gClock
	ldrb r1, [r1, #0x12]
	mov r8, r1
	ldr r2, _0800FEB0 @ =gClock
	ldrb r2, [r2, #0x13]
	mov sl, r2
	b _0800FECC
	.align 2, 0
_0800FEB0: .4byte gClock
_0800FEB4:
	movs r0, #0
	movs r1, #4
	movs r2, #0xf
	bl FUN_0800fc9c
	adds r5, r0, #0
	ldr r7, _0800FF24 @ =gClock
	ldrb r7, [r7, #0x10]
	mov r8, r7
	ldr r0, _0800FF24 @ =gClock
	ldrb r0, [r0, #0x11]
	mov sl, r0
_0800FECC:
	movs r4, #0
	ldr r1, _0800FF28 @ =0xFFFFD000
	mov ip, r1
	movs r6, #0x6a
	ldr r2, _0800FF2C @ =0x03003ED0
	mov sb, r2
_0800FED8:
	movs r2, #0
	adds r3, r6, #0
	adds r1, r5, #0
_0800FEDE:
	adds r0, r3, r2
	mov r7, ip
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _0800FEDE
	mov r1, sb
	movs r2, #0x18
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r6, #0x10
	adds r4, #1
	cmp r4, #1
	ble _0800FED8
	movs r0, #0
	movs r1, #8
	movs r2, #0xf
	bl FUN_0800fc9c
	adds r5, r0, #0
	ldr r7, _0800FF24 @ =gClock
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _0800FF1C
	cmp r0, #4
	beq _0800FF1C
	cmp r0, #5
	bne _0800FF30
_0800FF1C:
	movs r0, #2
	mov ip, r0
	movs r0, #0x6e
	b _0800FF36
	.align 2, 0
_0800FF24: .4byte gClock
_0800FF28: .4byte 0xFFFFD000
_0800FF2C: .4byte 0x03003ED0
_0800FF30:
	movs r1, #2
	mov ip, r1
	movs r0, #0x4e
_0800FF36:
	movs r4, #0
	ldr r2, _08010030 @ =0x03003ED0
	mov sb, r2
	adds r6, r0, #0
_0800FF3E:
	movs r2, #0
	cmp r2, ip
	bge _0800FF5A
	adds r3, r6, #0
	ldr r0, _08010034 @ =0xFFFFD000
	adds r7, r0, #0
	adds r1, r5, #0
_0800FF4C:
	adds r0, r3, r2
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, ip
	blt _0800FF4C
_0800FF5A:
	mov r1, sb
	movs r2, #0x18
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r6, #0x10
	adds r4, #1
	cmp r4, #1
	ble _0800FF3E
	mov r0, r8
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r7, r8
	subs r1, r7, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0xf
	bl FUN_0800fc9c
	adds r5, r0, #0
	movs r4, #0
	mov ip, sp
	ldr r0, _08010034 @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _08010030 @ =0x03003ED0
	mov r8, r1
_0800FF9A:
	lsls r3, r4, #4
	mov r6, ip
	adds r1, r5, #0
	movs r2, #1
_0800FFA2:
	ldm r6!, {r0}
	adds r0, #0x60
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FFA2
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #1
	ble _0800FF9A
	mov r0, sl
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r2, sl
	subs r1, r2, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0x16
	movs r2, #0xf
	bl FUN_0800fc9c
	adds r5, r0, #0
	movs r4, #0
	mov ip, sp
	ldr r0, _08010034 @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _08010030 @ =0x03003ED0
	mov r8, r1
_0800FFF2:
	adds r6, r4, #1
	lsls r3, r4, #4
	mov r4, ip
	adds r1, r5, #0
	movs r2, #1
_0800FFFC:
	ldm r4!, {r0}
	adds r0, #0x60
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FFFC
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r4, r6, #0
	cmp r4, #1
	ble _0800FFF2
_0801001E:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010030: .4byte 0x03003ED0
_08010034: .4byte 0xFFFFD000

	thumb_func_start FUN_08010038
FUN_08010038: @ 0x08010038
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	add r4, sp, #4
	add r5, sp, #8
	bl GetDate
	adds r3, r0, #0
	mov r0, sp
	adds r1, r4, #0
	adds r2, r5, #0
	bl ParseBCDDate
	ldrh r1, [r6, #0x28]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08010066
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	adds r0, r6, #0
	bl FUN_0800fcc4
_08010066:
	ldrh r1, [r6, #0x28]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08010076
	adds r0, r6, #0
	bl FUN_0800fd98
_08010076:
	ldrh r1, [r6, #0x28]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08010086
	adds r0, r6, #0
	bl FUN_0800fe74
_08010086:
	movs r0, #0
	strh r0, [r6, #0x28]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08010094
FUN_08010094: @ 0x08010094
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _080100DC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080100AE
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080100E8
_080100AE:
	movs r0, #4
	str r0, [sp]
	ldr r0, _080100E0 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080100E4 @ =FUN_080104c8
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r5, r1
	strh r4, [r0]
	movs r0, #1
	b _080100EA
	.align 2, 0
_080100DC: .4byte 0x030044E0
_080100E0: .4byte 0x0000FFFF
_080100E4: .4byte FUN_080104c8
_080100E8:
	movs r0, #0
_080100EA:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080100f4
FUN_080100f4: @ 0x080100F4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrh r2, [r5]
	cmp r2, #0
	bne _08010138
	subs r0, #0x16
	adds r1, r4, r0
	movs r0, #0xc
	strh r0, [r1]
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0x10
	strh r0, [r1]
	ldr r0, _08010180 @ =0x000002C6
	adds r1, r4, r0
	ldr r0, _08010184 @ =0x00001084
	strh r0, [r1]
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r2, [r0]
	ldr r2, _08010188 @ =0x000002CA
	adds r1, r4, r2
	movs r0, #2
	strh r0, [r1]
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _0801018C @ =FUN_08010718
	str r0, [r1]
_08010138:
	movs r2, #0xb0
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r0, [r5]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08010166
	movs r1, #0xc1
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	adds r2, #0x1c
	adds r1, r4, r2
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
	ldr r2, _08010190 @ =0x03003E78
	ldr r0, _08010194 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08010166:
	ldrh r1, [r4, #0x28]
	movs r0, #4
	orrs r0, r1
	ldr r1, _08010198 @ =0x0000FFFC
	ands r0, r1
	strh r0, [r4, #0x28]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010180: .4byte 0x000002C6
_08010184: .4byte 0x00001084
_08010188: .4byte 0x000002CA
_0801018C: .4byte FUN_08010718
_08010190: .4byte 0x03003E78
_08010194: .4byte 0xFFFFFEFF
_08010198: .4byte 0x0000FFFC

	thumb_func_start FUN_0801019c
FUN_0801019c: @ 0x0801019C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrh r6, [r5]
	cmp r6, #0
	bne _080101DA
	movs r0, #0xe3
	bl PlaySound_082406e0
	ldr r2, _08010218 @ =0x000002B2
	adds r1, r4, r2
	movs r0, #0x74
	strh r0, [r1]
	movs r3, #0xad
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r0, #0xa0
	strh r0, [r1]
	ldr r1, _0801021C @ =0x000002AE
	adds r0, r4, r1
	strh r6, [r0]
	subs r2, #2
	adds r1, r4, r2
	movs r0, #4
	strh r0, [r1]
	adds r3, #0x20
	adds r1, r4, r3
	ldr r0, _08010220 @ =FUN_0801084c
	str r0, [r1]
_080101DA:
	ldrh r0, [r5]
	adds r1, r0, #1
	strh r1, [r5]
	ldr r2, _08010224 @ =0x000002BE
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _0801020A
	ldrh r1, [r4, #0x28]
	ldr r0, _08010228 @ =0x0000FFFC
	ands r0, r1
	movs r2, #0
	strh r0, [r4, #0x28]
	ldr r1, _0801022C @ =FUN_080100f4
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r2, [r0]
_0801020A:
	ldrh r1, [r4, #0x28]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #0x28]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08010218: .4byte 0x000002B2
_0801021C: .4byte 0x000002AE
_08010220: .4byte FUN_0801084c
_08010224: .4byte 0x000002BE
_08010228: .4byte 0x0000FFFC
_0801022C: .4byte FUN_080100f4

	thumb_func_start FUN_08010230
FUN_08010230: @ 0x08010230
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r6, r4, r0
	ldrh r5, [r6]
	cmp r5, #0
	bne _080102A0
	movs r0, #0xe1
	bl PlaySound_082406e0
	ldr r2, _0801032C @ =0x000002C2
	adds r1, r4, r2
	movs r0, #1
	strh r0, [r1]
	movs r7, #0xb1
	lsls r7, r7, #2
	adds r1, r4, r7
	movs r0, #5
	strh r0, [r1]
	ldr r0, _08010330 @ =0x000002C6
	adds r1, r4, r0
	ldr r0, _08010334 @ =0x00001084
	strh r0, [r1]
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r5, [r0]
	adds r2, #8
	adds r0, r4, r2
	movs r2, #4
	strh r2, [r0]
	adds r7, #0xc
	adds r1, r4, r7
	ldr r0, _08010338 @ =FUN_08010718
	str r0, [r1]
	ldr r1, _0801033C @ =0x000002B2
	adds r0, r4, r1
	strh r5, [r0]
	subs r7, #0x1c
	adds r1, r4, r7
	movs r0, #0x74
	strh r0, [r1]
	ldr r1, _08010340 @ =0x000002AE
	adds r0, r4, r1
	strh r5, [r0]
	movs r5, #0xac
	lsls r5, r5, #2
	adds r0, r4, r5
	strh r2, [r0]
	adds r7, #0x20
	adds r1, r4, r7
	ldr r0, _08010344 @ =FUN_0801084c
	str r0, [r1]
_080102A0:
	ldrh r0, [r6]
	cmp r0, #0x30
	bne _080102E8
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0800fc9c
	adds r1, r0, #0
	movs r3, #0
	ldr r0, _08010348 @ =0x03003ED0
	mov r8, r0
	mov ip, r8
_080102BA:
	movs r2, #0
	mov r5, ip
	movs r6, #0x18
	ldrsh r0, [r5, r6]
	lsls r0, r0, #1
	adds r5, r3, #1
	cmp r2, r0
	bge _080102E2
	movs r7, #0xd0
	lsls r7, r7, #8
	adds r6, r7, #0
	mov r3, r8
_080102D2:
	strh r6, [r1]
	adds r1, #2
	adds r2, #1
	movs r7, #0x18
	ldrsh r0, [r3, r7]
	lsls r0, r0, #1
	cmp r2, r0
	blt _080102D2
_080102E2:
	adds r3, r5, #0
	cmp r3, #0xe
	ble _080102BA
_080102E8:
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _08010318
	ldr r1, _0801034C @ =FUN_0801019c
	movs r5, #0xb3
	lsls r5, r5, #2
	adds r0, r4, r5
	str r1, [r0]
	movs r6, #0xb6
	lsls r6, r6, #2
	adds r1, r4, r6
	movs r0, #0
	strh r0, [r1]
_08010318:
	ldrh r1, [r4, #0x28]
	movs r0, #0xf
	orrs r0, r1
	strh r0, [r4, #0x28]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801032C: .4byte 0x000002C2
_08010330: .4byte 0x000002C6
_08010334: .4byte 0x00001084
_08010338: .4byte FUN_08010718
_0801033C: .4byte 0x000002B2
_08010340: .4byte 0x000002AE
_08010344: .4byte FUN_0801084c
_08010348: .4byte 0x03003ED0
_0801034C: .4byte FUN_0801019c

	thumb_func_start FUN_08010350
FUN_08010350: @ 0x08010350
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08010094
	adds r3, r0, #0
	cmp r3, #0
	bne _08010398
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	ldr r2, _080103A0 @ =0x000002BA
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _08010390
	ldr r1, _080103A4 @ =FUN_08010230
	adds r2, #0x12
	adds r0, r4, r2
	str r1, [r0]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r3, [r0]
	adds r2, #8
	adds r1, r4, r2
	ldr r0, _080103A8 @ =FUN_080109b0
	str r0, [r1]
_08010390:
	ldrh r1, [r4, #0x28]
	movs r0, #0xf
	orrs r0, r1
	strh r0, [r4, #0x28]
_08010398:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080103A0: .4byte 0x000002BA
_080103A4: .4byte FUN_08010230
_080103A8: .4byte FUN_080109b0

	thumb_func_start FUN_080103ac
FUN_080103ac: @ 0x080103AC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_08010094
	adds r6, r0, #0
	cmp r6, #0
	bne _08010448
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _0801041A
	movs r0, #0xe1
	bl PlaySound_082406e0
	ldr r1, _08010450 @ =0x000002B2
	adds r0, r4, r1
	strh r6, [r0]
	movs r2, #0xad
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #0xa0
	strh r0, [r1]
	ldr r0, _08010454 @ =0x000002AE
	adds r1, r4, r0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	subs r2, #4
	adds r1, r4, r2
	ldr r0, _08010458 @ =0x0000FFFE
	strh r0, [r1]
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _0801045C @ =FUN_0801084c
	str r0, [r1]
	adds r2, #0x16
	adds r1, r4, r2
	ldr r0, _08010460 @ =0x00001084
	strh r0, [r1]
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r6, [r0]
	adds r2, #4
	adds r1, r4, r2
	movs r0, #4
	strh r0, [r1]
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _08010464 @ =FUN_080105ec
	str r0, [r1]
_0801041A:
	ldrh r0, [r5]
	adds r1, r0, #1
	strh r1, [r5]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _08010440
	ldr r0, _08010468 @ =FUN_0801046c
	adds r2, #0x14
	adds r1, r4, r2
	str r0, [r1]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r6, [r0]
_08010440:
	ldrh r1, [r4, #0x28]
	movs r0, #0xf
	orrs r0, r1
	strh r0, [r4, #0x28]
_08010448:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08010450: .4byte 0x000002B2
_08010454: .4byte 0x000002AE
_08010458: .4byte 0x0000FFFE
_0801045C: .4byte FUN_0801084c
_08010460: .4byte 0x00001084
_08010464: .4byte FUN_080105ec
_08010468: .4byte FUN_0801046c

	thumb_func_start FUN_0801046c
FUN_0801046c: @ 0x0801046C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08010094
	adds r3, r0, #0
	cmp r3, #0
	bne _080104B6
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	ldr r2, _080104BC @ =0x000002B6
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080104AE
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _080104C0 @ =FUN_080109b0
	str r0, [r1]
	ldr r1, _080104C4 @ =FUN_08010350
	adds r2, #0x16
	adds r0, r4, r2
	str r1, [r0]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r3, [r0]
_080104AE:
	ldrh r1, [r4, #0x28]
	movs r0, #0xf
	orrs r0, r1
	strh r0, [r4, #0x28]
_080104B6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080104BC: .4byte 0x000002B6
_080104C0: .4byte FUN_080109b0
_080104C4: .4byte FUN_08010350

	thumb_func_start FUN_080104c8
FUN_080104c8: @ 0x080104C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r0, #0x20
	subs r5, r0, r1
	movs r0, #0
	ldr r2, [r7, #0x20]
	mov sb, r2
	movs r1, #0xf8
	lsls r1, r1, #7
	mov sl, r1
_080104EC:
	movs r6, #0
	lsls r2, r0, #4
	mov ip, r2
	adds r0, #1
	mov r8, r0
_080104F6:
	mov r0, ip
	adds r4, r0, r6
	lsls r4, r4, #1
	add r4, sb
	ldrh r1, [r4]
	movs r0, #0x1f
	ands r0, r1
	adds r2, r0, #0
	muls r2, r5, r2
	movs r0, #0xf8
	lsls r0, r0, #3
	ands r2, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	adds r3, r0, #0
	muls r3, r5, r3
	movs r0, #0xf8
	lsls r0, r0, #8
	ands r3, r0
	mov r0, sl
	ands r0, r1
	adds r1, r0, #0
	muls r1, r5, r1
	movs r0, #0xf8
	lsls r0, r0, #0xd
	ands r1, r0
	orrs r2, r3
	orrs r2, r1
	asrs r2, r2, #6
	strh r2, [r4]
	adds r6, #1
	cmp r6, #0xf
	ble _080104F6
	mov r0, r8
	cmp r0, #1
	ble _080104EC
	movs r2, #0xb6
	lsls r2, r2, #2
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _08010574
	movs r0, #0
	bl FUN_0822b644
	movs r1, #0xc1
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r7, r2
	bl Script_ExecById
	adds r0, r7, #0
	bl KillEntity
	b _0801057C
_08010574:
	ldrh r0, [r7, #0x28]
	movs r1, #0xf
	orrs r0, r1
	strh r0, [r7, #0x28]
_0801057C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801058c
FUN_0801058c: @ 0x0801058C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r6, #0x80
	lsls r6, r6, #1
	ldr r5, _080105DC @ =0x03003E78
	ldrh r0, [r5]
	bics r0, r6
	strh r0, [r5]
	adds r0, r4, #0
	bl FUN_08010094
	cmp r0, #0
	bne _080105D4
	ldrh r0, [r4, #0x2a]
	ldr r2, _080105E0 @ =0x0000FFFF
	adds r1, r0, r2
	strh r1, [r4, #0x2a]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _080105D4
	ldrh r1, [r5]
	adds r0, r6, #0
	orrs r0, r1
	strh r0, [r5]
	ldr r0, _080105E4 @ =0x03000048
	ldr r2, [r0]
	ldr r1, _080105E8 @ =FUN_080103ac
	movs r4, #0xb3
	lsls r4, r4, #2
	adds r0, r2, r4
	str r1, [r0]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r2, r1
	strh r3, [r0]
_080105D4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080105DC: .4byte 0x03003E78
_080105E0: .4byte 0x0000FFFF
_080105E4: .4byte 0x03000048
_080105E8: .4byte FUN_080103ac

	thumb_func_start FUN_080105ec
FUN_080105ec: @ 0x080105EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov r8, r0
	movs r0, #0xb2
	lsls r0, r0, #2
	add r0, r8
	ldrh r7, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r7, r0
	ble _0801060C
	adds r7, r0, #0
_0801060C:
	subs r0, r0, r7
	mov ip, r0
	ldr r0, _0801070C @ =0x000002C6
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r1, r0
	str r1, [sp]
	movs r2, #0xf8
	lsls r2, r2, #2
	ands r2, r0
	str r2, [sp, #4]
	movs r3, #0xf8
	lsls r3, r3, #7
	ands r3, r0
	str r3, [sp, #8]
	movs r1, #0
	movs r0, #0
	ldr r4, _08010710 @ =0x000002C2
	add r4, r8
	str r4, [sp, #0xc]
	movs r2, #0xb1
	lsls r2, r2, #2
	add r2, r8
	str r2, [sp, #0x10]
_0801063E:
	ldr r3, [sp, #0xc]
	ldrh r6, [r3]
	adds r4, r1, #0
	adds r4, #0x10
	str r4, [sp, #0x14]
	adds r0, #1
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x10]
	ldrh r0, [r0]
	cmp r6, r0
	bge _080106CA
	mov r2, r8
	ldr r2, [r2, #0x24]
	mov sl, r2
	mov r3, r8
	ldr r3, [r3, #0x20]
	mov sb, r3
	adds r0, r6, r1
	lsls r5, r0, #1
_08010664:
	mov r4, sl
	adds r0, r4, r5
	mov r1, sb
	adds r1, r1, r5
	str r1, [sp, #0x1c]
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	adds r2, r0, #0
	muls r2, r7, r2
	ldr r3, [sp]
	mov r0, ip
	muls r0, r3, r0
	adds r2, r2, r0
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r2, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	adds r3, r0, #0
	muls r3, r7, r3
	ldr r4, [sp, #4]
	mov r0, ip
	muls r0, r4, r0
	adds r3, r3, r0
	movs r0, #0xf8
	lsls r0, r0, #0xa
	ands r3, r0
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r0, r1
	muls r0, r7, r0
	ldr r4, [sp, #8]
	mov r1, ip
	muls r1, r4, r1
	adds r0, r0, r1
	movs r1, #0xf8
	lsls r1, r1, #0xf
	ands r0, r1
	orrs r2, r3
	orrs r2, r0
	asrs r2, r2, #8
	ldr r0, [sp, #0x1c]
	strh r2, [r0]
	adds r5, #2
	adds r6, #1
	ldr r1, [sp, #0x10]
	ldrh r1, [r1]
	cmp r6, r1
	blt _08010664
_080106CA:
	ldr r1, [sp, #0x14]
	ldr r0, [sp, #0x18]
	cmp r0, #1
	ble _0801063E
	movs r2, #0xb2
	lsls r2, r2, #2
	add r2, r8
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bls _080106EE
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, r8
	movs r0, #0
	str r0, [r1]
	strh r0, [r2]
_080106EE:
	ldr r0, _08010714 @ =0x000002CA
	add r0, r8
	ldrh r0, [r0]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801070C: .4byte 0x000002C6
_08010710: .4byte 0x000002C2
_08010714: .4byte 0x000002CA

	thumb_func_start FUN_08010718
FUN_08010718: @ 0x08010718
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	mov r8, r0
	movs r0, #0xb2
	lsls r0, r0, #2
	add r0, r8
	ldrh r0, [r0]
	mov ip, r0
	movs r0, #0x80
	lsls r0, r0, #1
	cmp ip, r0
	ble _0801073A
	mov ip, r0
_0801073A:
	mov r1, ip
	subs r7, r0, r1
	ldr r0, _08010840 @ =0x000002C6
	add r0, r8
	ldrh r0, [r0]
	movs r2, #0x1f
	ands r2, r0
	str r2, [sp]
	movs r1, #0xf8
	lsls r1, r1, #2
	ands r1, r0
	str r1, [sp, #4]
	movs r2, #0xf8
	lsls r2, r2, #7
	ands r2, r0
	str r2, [sp, #8]
	movs r1, #0
	movs r0, #0
	ldr r2, _08010844 @ =0x000002C2
	add r2, r8
	str r2, [sp, #0xc]
	movs r2, #0xb1
	lsls r2, r2, #2
	add r2, r8
	str r2, [sp, #0x1c]
_0801076C:
	ldr r2, [sp, #0xc]
	ldrh r6, [r2]
	adds r2, r1, #0
	adds r2, #0x10
	str r2, [sp, #0x24]
	adds r0, #1
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x1c]
	ldrh r0, [r0]
	cmp r6, r0
	bge _08010800
	ldr r0, [sp]
	mov r2, ip
	muls r2, r0, r2
	str r2, [sp, #0x10]
	ldr r0, [sp, #4]
	mov r2, ip
	muls r2, r0, r2
	str r2, [sp, #0x14]
	ldr r0, [sp, #8]
	mov r2, ip
	muls r2, r0, r2
	str r2, [sp, #0x18]
	mov r2, r8
	ldr r2, [r2, #0x24]
	mov sl, r2
	mov r0, r8
	ldr r0, [r0, #0x20]
	mov sb, r0
	adds r0, r6, r1
	lsls r5, r0, #1
_080107AA:
	mov r1, sl
	adds r0, r1, r5
	mov r2, sb
	adds r4, r2, r5
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	adds r2, r0, #0
	muls r2, r7, r2
	ldr r0, [sp, #0x10]
	adds r2, r0, r2
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r2, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	adds r3, r0, #0
	muls r3, r7, r3
	ldr r0, [sp, #0x14]
	adds r3, r0, r3
	movs r0, #0xf8
	lsls r0, r0, #0xa
	ands r3, r0
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r0, r1
	muls r0, r7, r0
	ldr r1, [sp, #0x18]
	adds r0, r1, r0
	movs r1, #0xf8
	lsls r1, r1, #0xf
	ands r0, r1
	orrs r2, r3
	orrs r2, r0
	asrs r2, r2, #8
	strh r2, [r4]
	adds r5, #2
	adds r6, #1
	ldr r2, [sp, #0x1c]
	ldrh r2, [r2]
	cmp r6, r2
	blt _080107AA
_08010800:
	ldr r1, [sp, #0x24]
	ldr r0, [sp, #0x20]
	cmp r0, #1
	ble _0801076C
	movs r2, #0xb2
	lsls r2, r2, #2
	add r2, r8
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bls _08010824
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, r8
	movs r0, #0
	str r0, [r1]
	strh r0, [r2]
_08010824:
	ldr r0, _08010848 @ =0x000002CA
	add r0, r8
	ldrh r0, [r0]
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010840: .4byte 0x000002C6
_08010844: .4byte 0x000002C2
_08010848: .4byte 0x000002CA

	thumb_func_start FUN_0801084c
FUN_0801084c: @ 0x0801084C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov ip, r0
	movs r4, #0
	ldr r0, _0801096C @ =0x000002B2
	add r0, ip
	ldrh r1, [r0]
	cmp r4, r1
	bge _0801088C
	movs r6, #0xab
	lsls r6, r6, #2
	add r6, ip
	mov r5, ip
	adds r5, #0x2c
	movs r7, #0
	adds r3, r0, #0
_08010874:
	lsls r2, r4, #1
	ldrh r1, [r6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	adds r2, r5, r2
	strh r7, [r2]
	adds r4, #1
	ldrh r2, [r3]
	cmp r4, r2
	blt _08010874
_0801088C:
	ldr r0, _0801096C @ =0x000002B2
	add r0, ip
	ldrh r4, [r0]
	movs r0, #0xad
	lsls r0, r0, #2
	mov r8, r0
	mov r0, ip
	add r0, r8
	ldr r1, _08010970 @ =0x000002AE
	add r1, ip
	str r1, [sp]
	movs r2, #0xac
	lsls r2, r2, #2
	add r2, ip
	str r2, [sp, #4]
	ldrh r0, [r0]
	cmp r4, r0
	bge _080108FC
	ldr r0, _08010974 @ =0x0203B400
	mov sl, r0
	ldr r5, _08010978 @ =0x030046B8
	movs r7, #0xab
	lsls r7, r7, #2
	add r7, ip
	ldr r6, _08010970 @ =0x000002AE
	add r6, ip
	ldr r1, _0801097C @ =0x000003FF
	mov sb, r1
_080108C4:
	ldr r0, [r5]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sl
	ldrh r3, [r0]
	lsls r2, r4, #1
	ldrh r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	mov r1, ip
	adds r1, #0x2c
	adds r1, r1, r2
	movs r2, #0
	ldrsh r0, [r6, r2]
	muls r0, r3, r0
	asrs r0, r0, #0x12
	strh r0, [r1]
	adds r4, #1
	mov r0, ip
	add r0, r8
	ldrh r0, [r0]
	cmp r4, r0
	blt _080108C4
_080108FC:
	movs r0, #0xad
	lsls r0, r0, #2
	add r0, ip
	ldrh r4, [r0]
	cmp r4, #0x9f
	bgt _0801092A
	movs r5, #0xab
	lsls r5, r5, #2
	add r5, ip
	mov r3, ip
	adds r3, #0x2c
	movs r6, #0
_08010914:
	lsls r2, r4, #1
	ldrh r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	adds r2, r3, r2
	strh r6, [r2]
	adds r4, #1
	cmp r4, #0x9f
	ble _08010914
_0801092A:
	movs r0, #0xab
	lsls r0, r0, #2
	add r0, ip
	ldrh r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r0, #0x2c
	add r0, ip
	ldr r1, _08010980 @ =0x03003518
	str r0, [r1]
	ldr r0, _08010984 @ =0x0400004C
	ldr r2, _08010988 @ =0x03002CA0
	str r0, [r2]
	movs r0, #1
	ldr r1, _0801098C @ =0x03003510
	strh r0, [r1]
	ldr r2, _08010990 @ =0x03003514
	strh r0, [r2]
	ldr r1, [sp]
	ldr r2, [sp, #4]
	ldrh r0, [r2]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08010994
	movs r0, #0
	strh r0, [r1]
	b _080109A0
	.align 2, 0
_0801096C: .4byte 0x000002B2
_08010970: .4byte 0x000002AE
_08010974: .4byte 0x0203B400
_08010978: .4byte 0x030046B8
_0801097C: .4byte 0x000003FF
_08010980: .4byte 0x03003518
_08010984: .4byte 0x0400004C
_08010988: .4byte 0x03002CA0
_0801098C: .4byte 0x03003510
_08010990: .4byte 0x03003514
_08010994:
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	ble _080109A0
	ldr r0, [sp]
	strh r1, [r0]
_080109A0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080109b0
FUN_080109b0: @ 0x080109B0
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r4, #0
	str r4, [sp]
	adds r1, r5, #0
	adds r1, #0x2c
	ldr r2, _080109FC @ =0x05000091
	mov r0, sp
	bl CpuSet
	ldr r2, _08010A00 @ =0x03003518
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r0, #0x2c
	adds r0, r5, r0
	str r0, [r2]
	ldr r1, _08010A04 @ =0x03002CA0
	ldr r0, _08010A08 @ =0x0400004C
	str r0, [r1]
	ldr r1, _08010A0C @ =0x03003510
	movs r0, #1
	strh r0, [r1]
	ldr r0, _08010A10 @ =0x03003514
	strh r4, [r0]
	movs r1, #0xb5
	lsls r1, r1, #2
	adds r0, r5, r1
	str r4, [r0]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080109FC: .4byte 0x05000091
_08010A00: .4byte 0x03003518
_08010A04: .4byte 0x03002CA0
_08010A08: .4byte 0x0400004C
_08010A0C: .4byte 0x03003510
_08010A10: .4byte 0x03003514

	thumb_func_start FUN_08010a14
FUN_08010a14: @ 0x08010A14
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08010A2C
	adds r0, r5, #0
	bl _call_via_r1
_08010A2C:
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08010A3E
	adds r0, r5, #0
	bl _call_via_r1
_08010A3E:
	movs r1, #0xb5
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08010A50
	adds r0, r5, #0
	bl _call_via_r1
_08010A50:
	movs r0, #0xab
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	movs r4, #0
	strh r0, [r2]
	adds r0, r5, #0
	bl FUN_08010038
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08010a7c
FUN_08010a7c: @ 0x08010A7C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r5, #0
	str r5, [sp]
	adds r1, r4, #0
	adds r1, #0x2c
	ldr r2, _08010AC4 @ =0x05000091
	mov r0, sp
	bl CpuSet
	ldr r3, _08010AC8 @ =0x03003518
	movs r2, #0xab
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r2, [r1]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #6
	adds r1, #0x2c
	adds r4, r4, r1
	str r4, [r3]
	ldr r2, _08010ACC @ =0x03002CA0
	ldr r1, _08010AD0 @ =0x0400004C
	str r1, [r2]
	ldr r2, _08010AD4 @ =0x03003510
	movs r1, #1
	strh r1, [r2]
	ldr r1, _08010AD8 @ =0x03003514
	strh r5, [r1]
	ldr r1, _08010ADC @ =0x03000048
	str r5, [r1]
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08010AC4: .4byte 0x05000091
_08010AC8: .4byte 0x03003518
_08010ACC: .4byte 0x03002CA0
_08010AD0: .4byte 0x0400004C
_08010AD4: .4byte 0x03003510
_08010AD8: .4byte 0x03003514
_08010ADC: .4byte 0x03000048

	thumb_func_start FUN_08010ae0
FUN_08010ae0: @ 0x08010AE0
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r0, _08010B40 @ =0x03000048
	str r6, [r0]
	ldr r3, _08010B44 @ =0x03003E78
	ldr r0, _08010B48 @ =0xFFFFFEFF
	ldrh r2, [r3]
	ands r0, r2
	strh r0, [r3]
	strh r1, [r6, #0x18]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r6, #0x1a]
	ldr r0, _08010B4C @ =0x0000596F
	strh r0, [r6, #0x1c]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r6, #0x1e]
	ldr r0, _08010B50 @ =0x030043F0
	str r0, [r6, #0x20]
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xc1
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0x61
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _08010B7E
	movs r3, #0xb8
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r6, r2
	str r0, [r1]
	movs r4, #0
	b _08010B68
	.align 2, 0
_08010B40: .4byte 0x03000048
_08010B44: .4byte 0x03003E78
_08010B48: .4byte 0xFFFFFEFF
_08010B4C: .4byte 0x0000596F
_08010B50: .4byte 0x030043F0
_08010B54:
	bl Script_GetValue
	movs r3, #0xb8
	lsls r3, r3, #2
	adds r1, r6, r3
	ldr r2, [r1]
	lsls r1, r4, #2
	adds r1, r1, r2
	str r0, [r1]
	adds r4, #1
_08010B68:
	cmp r4, #7
	bgt _08010B74
	bl VM_GetPC
	cmp r0, #0
	bne _08010B54
_08010B74:
	movs r1, #0xb7
	lsls r1, r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	b _08010B86
_08010B7E:
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
_08010B86:
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08010BE4
	movs r4, #0
	b _08010BB4
_08010B94:
	bl Script_GetValue
	lsls r2, r4, #1
	ldr r3, _08010BDC @ =0x000002B6
	adds r1, r6, r3
	adds r3, r1, r2
	strh r0, [r3]
	ldr r1, _08010BE0 @ =0x085AA810
	adds r2, r2, r1
	ldrh r2, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r2
	bhs _08010BB2
	strh r2, [r3]
_08010BB2:
	adds r4, #1
_08010BB4:
	cmp r4, #5
	bgt _08010BFA
	bl VM_GetPC
	cmp r0, #0
	bne _08010B94
	ldr r1, _08010BE0 @ =0x085AA810
	lsls r0, r4, #1
	adds r2, r0, r1
	ldr r1, _08010BDC @ =0x000002B6
	adds r0, r0, r1
	adds r1, r0, r6
_08010BCC:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	adds r4, #1
	cmp r4, #5
	ble _08010BCC
	b _08010BFA
	.align 2, 0
_08010BDC: .4byte 0x000002B6
_08010BE0: .4byte 0x085AA810
_08010BE4:
	ldr r2, _08010C20 @ =0x085AA810
	ldr r3, _08010C24 @ =0x000002B6
	adds r1, r6, r3
	movs r4, #5
_08010BEC:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _08010BEC
_08010BFA:
	movs r0, #0
	strb r0, [r6, #0x1b]
	ldr r0, _08010C28 @ =0x0000C091
	ldrh r1, [r6, #0x1c]
	bl GetFile
	adds r4, r0, #0
	cmp r4, #0
	beq _08010C1A
	ldr r0, _08010C2C @ =0x000092B3
	ldrh r1, [r6, #0x1e]
	bl GetFile
	adds r5, r0, #0
	cmp r5, #0
	bne _08010C30
_08010C1A:
	movs r0, #1
	rsbs r0, r0, #0
	b _08010D0C
	.align 2, 0
_08010C20: .4byte 0x085AA810
_08010C24: .4byte 0x000002B6
_08010C28: .4byte 0x0000C091
_08010C2C: .4byte 0x000092B3
_08010C30:
	ldrb r0, [r4]
	cmp r0, #0x4d
	bne _08010C46
	ldrb r0, [r4, #1]
	cmp r0, #0x50
	bne _08010C46
	ldrb r0, [r6, #0x1b]
	movs r1, #0
	bl SetBGPrioDirect
	b _08010C62
_08010C46:
	movs r0, #0
	bl GetTilemapBuffer
	ldrb r2, [r6, #0x1b]
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r2, #0
	adds r2, r4, #0
	movs r3, #0
	bl FUN_0822bfbc
_08010C62:
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r5, r1
	str r0, [r6, #0x24]
	movs r4, #0
	str r4, [sp, #0x10]
	ldr r1, [r6, #0x20]
	ldr r2, _08010D14 @ =0x05000018
	add r0, sp, #0x10
	bl CpuSet
	ldr r2, _08010D18 @ =0x04000008
	ldrh r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x77
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r6, #0x2a]
	ldr r1, _08010D1C @ =FUN_0801058c
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r6, r2
	str r1, [r0]
	movs r3, #0xb6
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r4, [r0]
	ldr r1, _08010D20 @ =0x000002C2
	adds r0, r6, r1
	strh r4, [r0]
	subs r2, #8
	adds r1, r6, r2
	movs r0, #0x10
	strh r0, [r1]
	subs r3, #0x12
	adds r1, r6, r3
	ldr r0, _08010D24 @ =0x00001084
	strh r0, [r1]
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	adds r2, #6
	adds r0, r6, r2
	movs r5, #1
	strh r5, [r0]
	adds r3, #0xa
	adds r0, r6, r3
	str r4, [r0]
	str r4, [sp, #0x14]
	add r0, sp, #0x14
	adds r1, r6, #0
	adds r1, #0x2c
	ldr r2, _08010D28 @ =0x05000091
	bl CpuSet
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	ldr r2, _08010D2C @ =0x000002AE
	adds r1, r6, r2
	movs r0, #0x80
	lsls r0, r0, #3
	strh r0, [r1]
	movs r3, #0xac
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r5, [r0]
	ldr r1, _08010D30 @ =0x000002B2
	adds r0, r6, r1
	strh r4, [r0]
	adds r2, #6
	adds r1, r6, r2
	movs r0, #0xa0
	strh r0, [r1]
	adds r3, #0x24
	adds r0, r6, r3
	str r4, [r0]
	movs r0, #0xf
	strh r0, [r6, #0x28]
	movs r0, #0
_08010D0C:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08010D14: .4byte 0x05000018
_08010D18: .4byte 0x04000008
_08010D1C: .4byte FUN_0801058c
_08010D20: .4byte 0x000002C2
_08010D24: .4byte 0x00001084
_08010D28: .4byte 0x05000091
_08010D2C: .4byte 0x000002AE
_08010D30: .4byte 0x000002B2

	thumb_func_start FUN_08010d34
FUN_08010d34: @ 0x08010D34
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xc2
	lsls r1, r1, #2
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08010D70
	ldr r1, _08010D68 @ =FUN_08010a14
	ldr r2, _08010D6C @ =FUN_08010a7c
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08010ae0
	cmp r0, #0
	bge _08010D70
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08010D72
	.align 2, 0
_08010D68: .4byte FUN_08010a14
_08010D6C: .4byte FUN_08010a7c
_08010D70:
	adds r0, r4, #0
_08010D72:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08010d78
FUN_08010d78: @ 0x08010D78
	ldr r1, _08010D80 @ =0x0300004C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08010D80: .4byte 0x0300004C

	thumb_func_start FUN_08010d84
FUN_08010d84: @ 0x08010D84
	push {r4, lr}
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _08010DA8 @ =0x03003ED0
	adds r3, r3, r0
	ldr r0, [r3, #0x2c]
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0x18
	ldrsh r1, [r3, r4]
	lsls r1, r1, #1
	muls r1, r2, r1
	lsls r1, r1, #1
	adds r0, r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08010DA8: .4byte 0x03003ED0

	thumb_func_start FUN_08010dac
FUN_08010dac: @ 0x08010DAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _08010DE8 @ =gClock
	cmp r0, #0
	bne _08010DC0
	b _08010F56
_08010DC0:
	ldrb r0, [r0, #0xe]
	cmp r0, #0
	beq _08010DCE
	cmp r0, #4
	beq _08010DCE
	cmp r0, #5
	bne _08010DEC
_08010DCE:
	movs r0, #0
	movs r1, #4
	movs r2, #0xf
	bl FUN_08010d84
	adds r5, r0, #0
	ldr r1, _08010DE8 @ =gClock
	ldrb r1, [r1, #0x12]
	mov r8, r1
	ldr r2, _08010DE8 @ =gClock
	ldrb r2, [r2, #0x13]
	mov sl, r2
	b _08010E04
	.align 2, 0
_08010DE8: .4byte gClock
_08010DEC:
	movs r0, #0
	movs r1, #4
	movs r2, #0xf
	bl FUN_08010d84
	adds r5, r0, #0
	ldr r7, _08010E5C @ =gClock
	ldrb r7, [r7, #0x10]
	mov r8, r7
	ldr r0, _08010E5C @ =gClock
	ldrb r0, [r0, #0x11]
	mov sl, r0
_08010E04:
	movs r4, #0
	ldr r1, _08010E60 @ =0xFFFFD000
	mov ip, r1
	movs r6, #0x6a
	ldr r2, _08010E64 @ =0x03003ED0
	mov sb, r2
_08010E10:
	movs r2, #0
	adds r3, r6, #0
	adds r1, r5, #0
_08010E16:
	adds r0, r3, r2
	mov r7, ip
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _08010E16
	mov r1, sb
	movs r2, #0x18
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r6, #0x10
	adds r4, #1
	cmp r4, #1
	ble _08010E10
	movs r0, #0
	movs r1, #8
	movs r2, #0xf
	bl FUN_08010d84
	adds r5, r0, #0
	ldr r7, _08010E5C @ =gClock
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _08010E54
	cmp r0, #4
	beq _08010E54
	cmp r0, #5
	bne _08010E68
_08010E54:
	movs r0, #2
	mov ip, r0
	movs r0, #0x6e
	b _08010E6E
	.align 2, 0
_08010E5C: .4byte gClock
_08010E60: .4byte 0xFFFFD000
_08010E64: .4byte 0x03003ED0
_08010E68:
	movs r1, #2
	mov ip, r1
	movs r0, #0x4e
_08010E6E:
	movs r4, #0
	ldr r2, _08010F68 @ =0x03003ED0
	mov sb, r2
	adds r6, r0, #0
_08010E76:
	movs r2, #0
	cmp r2, ip
	bge _08010E92
	adds r3, r6, #0
	ldr r0, _08010F6C @ =0xFFFFD000
	adds r7, r0, #0
	adds r1, r5, #0
_08010E84:
	adds r0, r3, r2
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, ip
	blt _08010E84
_08010E92:
	mov r1, sb
	movs r2, #0x18
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r6, #0x10
	adds r4, #1
	cmp r4, #1
	ble _08010E76
	mov r0, r8
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r7, r8
	subs r1, r7, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0xf
	bl FUN_08010d84
	adds r5, r0, #0
	movs r4, #0
	mov ip, sp
	ldr r0, _08010F6C @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _08010F68 @ =0x03003ED0
	mov r8, r1
_08010ED2:
	lsls r3, r4, #4
	mov r6, ip
	adds r1, r5, #0
	movs r2, #1
_08010EDA:
	ldm r6!, {r0}
	adds r0, #0x60
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _08010EDA
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #1
	ble _08010ED2
	mov r0, sl
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r2, sl
	subs r1, r2, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0x16
	movs r2, #0xf
	bl FUN_08010d84
	adds r5, r0, #0
	movs r4, #0
	mov ip, sp
	ldr r0, _08010F6C @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _08010F68 @ =0x03003ED0
	mov r8, r1
_08010F2A:
	adds r6, r4, #1
	lsls r3, r4, #4
	mov r4, ip
	adds r1, r5, #0
	movs r2, #1
_08010F34:
	ldm r4!, {r0}
	adds r0, #0x60
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _08010F34
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r4, r6, #0
	cmp r4, #1
	ble _08010F2A
_08010F56:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010F68: .4byte 0x03003ED0
_08010F6C: .4byte 0xFFFFD000

	thumb_func_start FUN_08010f70
FUN_08010f70: @ 0x08010F70
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	add r5, sp, #4
	add r6, sp, #8
	bl GetDate
	adds r3, r0, #0
	mov r0, sp
	adds r1, r5, #0
	adds r2, r6, #0
	bl ParseBCDDate
	movs r5, #0
	movs r0, #0xf
	strh r0, [r4, #0x28]
	adds r0, r4, #0
	bl FUN_08010dac
	strh r5, [r4, #0x28]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08010fa0
FUN_08010fa0: @ 0x08010FA0
	push {lr}
	bl FUN_08010f70
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08010fac
FUN_08010fac: @ 0x08010FAC
	ldr r2, _08010FB4 @ =0x0300004C
	movs r1, #0
	str r1, [r2]
	bx lr
	.align 2, 0
_08010FB4: .4byte 0x0300004C

	thumb_func_start FUN_08010fb8
FUN_08010fb8: @ 0x08010FB8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _0801100C @ =0x0300004C
	str r6, [r0]
	movs r4, #0
	strh r1, [r6, #0x18]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r6, #0x1a]
	ldr r0, _08011010 @ =0x0000596F
	strh r0, [r6, #0x1c]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r6, #0x1e]
	ldr r0, _08011014 @ =0x030043F0
	str r0, [r6, #0x20]
	strb r4, [r6, #0x1b]
	ldr r0, _08011018 @ =0x0000C091
	ldrh r1, [r6, #0x1c]
	bl GetFile
	adds r4, r0, #0
	cmp r4, #0
	beq _08011006
	ldr r0, _0801101C @ =0x000092B3
	ldrh r1, [r6, #0x1e]
	bl GetFile
	mov r8, r0
	cmp r0, #0
	bne _08011020
_08011006:
	movs r0, #1
	rsbs r0, r0, #0
	b _080110B6
	.align 2, 0
_0801100C: .4byte 0x0300004C
_08011010: .4byte 0x0000596F
_08011014: .4byte 0x030043F0
_08011018: .4byte 0x0000C091
_0801101C: .4byte 0x000092B3
_08011020:
	ldrb r0, [r4]
	cmp r0, #0x4d
	bne _08011036
	ldrb r0, [r4, #1]
	cmp r0, #0x50
	bne _08011036
	ldrb r0, [r6, #0x1b]
	movs r1, #0
	bl SetBGPrioDirect
	b _08011052
_08011036:
	movs r0, #0
	bl GetTilemapBuffer
	ldrb r2, [r6, #0x1b]
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r2, #0
	adds r2, r4, #0
	movs r3, #0
	bl FUN_0822bfbc
_08011052:
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08010d84
	adds r2, r0, #0
	movs r4, #0
	ldr r0, _080110C4 @ =0x03003ED0
	mov ip, r0
	ldr r1, [r6, #0x20]
	mov sb, r1
_08011076:
	movs r3, #0
	mov r5, ip
	movs r7, #0x18
	ldrsh r0, [r5, r7]
	lsls r0, r0, #1
	adds r1, r4, #1
	cmp r3, r0
	bge _0801109E
	movs r0, #0xd0
	lsls r0, r0, #8
	adds r5, r0, #0
	ldr r4, _080110C4 @ =0x03003ED0
_0801108E:
	strh r5, [r2]
	adds r2, #2
	adds r3, #1
	movs r7, #0x18
	ldrsh r0, [r4, r7]
	lsls r0, r0, #1
	cmp r3, r0
	blt _0801108E
_0801109E:
	adds r4, r1, #0
	cmp r4, #0xe
	ble _08011076
	movs r0, #0xda
	lsls r0, r0, #1
	add r0, r8
	str r0, [r6, #0x24]
	ldr r2, _080110C8 @ =0x04000018
	mov r1, sb
	bl CpuSet
	movs r0, #0
_080110B6:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080110C4: .4byte 0x03003ED0
_080110C8: .4byte 0x04000018

	thumb_func_start FUN_080110cc
FUN_080110cc: @ 0x080110CC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #9
	movs r1, #0x2c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08011108
	ldr r1, _08011100 @ =FUN_08010fa0
	ldr r2, _08011104 @ =FUN_08010fac
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08010fb8
	cmp r0, #0
	bge _08011108
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801110A
	.align 2, 0
_08011100: .4byte FUN_08010fa0
_08011104: .4byte FUN_08010fac
_08011108:
	adds r0, r4, #0
_0801110A:
	pop {r4, r5}
	pop {r1}
	bx r1

