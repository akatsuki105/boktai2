	.include "asm/macros.inc"

	.syntax unified
	
	.text

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

	thumb_func_start Entity4D4D_Update
Entity4D4D_Update: @ 0x0800FA78
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

	thumb_func_start Entity4D4D_Destroy
Entity4D4D_Destroy: @ 0x0800FB30
	movs r0, #0
	bx lr

	thumb_func_start Entity4D4D_Init
Entity4D4D_Init: @ 0x0800FB34
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

	thumb_func_start Entity4D4D_Create
Entity4D4D_Create: @ 0x0800FC4C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xa4
	lsls r1, r1, #1
	movs r0, #0xc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800FC88
	ldr r1, _0800FC80 @ =Entity4D4D_Update
	ldr r2, _0800FC84 @ =Entity4D4D_Destroy
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl Entity4D4D_Init
	cmp r0, #0
	bge _0800FC88
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800FC8A
	.align 2, 0
_0800FC80: .4byte Entity4D4D_Update
_0800FC84: .4byte Entity4D4D_Destroy
_0800FC88:
	adds r0, r4, #0
_0800FC8A:
	pop {r4, r5}
	pop {r1}
	bx r1
