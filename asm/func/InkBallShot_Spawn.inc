	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	ldr r4, _08203618 @ =0x03000218
	ldr r0, [r4]
	cmp r0, #0
	bne _082035DA
	bl InkBallShotManager_Create
	str r0, [r4]
_082035DA:
	str r5, [sp]
	ldr r0, [sp, #0x40]
	str r0, [sp, #4]
	ldr r0, [sp, #0x44]
	str r0, [sp, #8]
	ldr r0, [sp, #0x48]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x4c]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x50]
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x54]
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x5c]
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x60]
	str r0, [sp, #0x24]
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	mov r3, r8
	bl InkBallShotManager_Add
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08203618: .4byte 0x03000218
