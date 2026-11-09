	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x30
	adds r6, r0, #0
	mov r8, r1
	adds r5, r2, #0
	adds r7, r3, #0
	ldr r4, _08203688 @ =0x03000218
	ldr r0, [r4]
	cmp r0, #0
	bne _0820363A
	bl InkBallShotManager_Create
	str r0, [r4]
_0820363A:
	add r2, sp, #0x28
	movs r1, #0
	adds r0, r2, #0
	strh r5, [r0]
	strh r1, [r2, #2]
	strh r1, [r2, #4]
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
	adds r0, r6, #0
	adds r1, r2, #0
	mov r2, r8
	adds r3, r7, #0
	bl InkBallShotManager_Add
	add sp, #0x30
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08203688: .4byte 0x03000218
