	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x18]
	ldrh r4, [r7, #0x1e]
	adds r1, r4, #0
	subs r1, #0xdc
	ldrh r0, [r0, #0x2e]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	ldr r6, _08195FD0 @ =0x0000FFFF
	adds r1, r6, #0
	ldr r2, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	asrs r2, r1, #0x10
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r3, r2, #0
	muls r3, r0, r3
	lsls r3, r3, #6
	lsrs r3, r3, #0x10
	ldr r5, _08195FD4 @ =0xFFFF0000
	adds r0, r5, #0
	ldr r2, [sp, #0xc]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0xc]
	adds r2, r5, #0
	ands r2, r1
	orrs r2, r3
	str r2, [sp, #8]
	mov r1, sp
	ldrh r0, [r1, #8]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp]
	ands r1, r5
	orrs r1, r0
	asrs r2, r2, #0x10
	adds r4, r4, r2
	lsls r4, r4, #0x10
	ands r1, r6
	orrs r1, r4
	str r1, [sp]
	mov r2, sp
	ldrh r0, [r2, #0xc]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r5
	orrs r1, r0
	str r1, [sp, #4]
	adds r0, r7, #0
	adds r0, #0x98
	mov r1, sp
	movs r2, #0
	bl Hitbox_SetPos
	adds r4, r7, #0
	adds r4, #0x48
	adds r0, r4, #0
	mov r1, sp
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	adds r0, #0x4e
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08195FC6
	adds r0, r4, #0
	bl Hitbox_Register
_08195FC6:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08195FD0: .4byte 0x0000FFFF
_08195FD4: .4byte 0xFFFF0000
