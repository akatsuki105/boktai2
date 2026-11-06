	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x38
	adds r5, r0, #0
	adds r6, r1, #0
	movs r4, #0
	cmp r4, r6
	bge _081F62FE
	movs r0, #1
	mov r8, r0
	movs r7, #0
_081F6264:
	adds r1, r4, #0
	mov r0, r8
	ands r1, r0
	cmp r1, #0
	beq _081F62B8
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0x12
	str r0, [sp, #4]
	lsls r0, r4, #6
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x30
	str r0, [sp, #0x10]
	mov r0, r8
	str r0, [sp, #0x14]
	movs r0, #2
	str r0, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x1c]
	str r7, [sp, #0x20]
	ldr r0, _081F62B0 @ =0x0000F422
	str r0, [sp, #0x24]
	ldr r0, _081F62B4 @ =0x0000121B
	str r0, [sp, #0x28]
	str r7, [sp, #0x2c]
	str r7, [sp, #0x30]
	movs r0, #0xd8
	str r0, [sp, #0x34]
	adds r0, r5, #0
	movs r1, #8
	movs r2, #0x10
	movs r3, #4
	bl Entity081ee7a8_SpawnEx
	b _081F62F8
	.align 2, 0
_081F62B0: .4byte 0x0000F422
_081F62B4: .4byte 0x0000121B
_081F62B8:
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0x12
	str r0, [sp, #4]
	lsls r0, r4, #6
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x30
	str r0, [sp, #0x10]
	mov r0, r8
	str r0, [sp, #0x14]
	movs r0, #2
	str r0, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	ldr r0, _081F630C @ =0x0000F422
	str r0, [sp, #0x24]
	ldr r0, _081F6310 @ =0x0000121B
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r1, [sp, #0x30]
	movs r0, #0xd8
	str r0, [sp, #0x34]
	adds r0, r5, #0
	movs r1, #8
	movs r2, #0x10
	movs r3, #4
	bl Entity081ee7a8_SpawnEx
_081F62F8:
	adds r4, #1
	cmp r4, r6
	blt _081F6264
_081F62FE:
	add sp, #0x38
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F630C: .4byte 0x0000F422
_081F6310: .4byte 0x0000121B
