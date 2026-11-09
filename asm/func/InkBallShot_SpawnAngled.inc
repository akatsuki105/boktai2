	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x30
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r4, _08203548 @ =0x03000218
	ldr r0, [r4]
	cmp r0, #0
	bne _0820352A
	bl InkBallShotManager_Create
	str r0, [r4]
_0820352A:
	add r3, sp, #0x28
	ldr r2, _0820354C @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08203550
	asrs r1, r0, #0xc
	b _08203556
	.align 2, 0
_08203548: .4byte 0x03000218
_0820354C: .4byte gSineTable
_08203550:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08203556:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08203572
	asrs r0, r0, #0xc
	b _08203578
_08203572:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08203578:
	strh r0, [r3, #4]
	ldr r0, [sp, #0x48]
	str r0, [sp]
	ldr r0, [sp, #0x4c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x50]
	str r0, [sp, #8]
	ldr r0, [sp, #0x54]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x5c]
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x60]
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x64]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x68]
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x6c]
	str r0, [sp, #0x24]
	adds r0, r7, #0
	add r1, sp, #0x28
	movs r2, #0
	mov r3, r8
	bl InkBallShotManager_Add
	add sp, #0x30
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
