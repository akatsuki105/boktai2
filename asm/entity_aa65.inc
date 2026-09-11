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
	bl Video_SetActorSpritePltt
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

	thumb_func_start EntityAA65_Update
EntityAA65_Update: @ 0x0800C50C
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
	bl Video_SetActorSpritePltt
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

	thumb_func_start EntityAA65_Destroy
EntityAA65_Destroy: @ 0x0800C680
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

	thumb_func_start EntityAA65_Init
EntityAA65_Init: @ 0x0800C6CC
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

	thumb_func_start EntityAA65_Create
EntityAA65_Create: @ 0x0800C7AC
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
	ldr r1, _0800C7E4 @ =EntityAA65_Update
	ldr r2, _0800C7E8 @ =EntityAA65_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityAA65_Init
	cmp r0, #0
	bge _0800C7EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800C7EE
	.align 2, 0
_0800C7E0: .4byte 0x03002B34
_0800C7E4: .4byte EntityAA65_Update
_0800C7E8: .4byte EntityAA65_Destroy
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
