	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0805049C
	movs r0, #0
	strb r0, [r1]
	bl FUN_08016f84
	adds r0, r4, #0
	bl FUN_0804fb3c
	adds r0, r4, #0
	adds r0, #0x3c
	ldrh r1, [r0, #8]
	ldrb r2, [r0, #7]
	movs r0, #3
	ands r0, r2
	lsls r0, r0, #0x10
	orrs r1, r0
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #4
	mov r2, sp
	movs r3, #1
	bl FUN_0804fa44
	adds r0, r4, #0
	movs r1, #5
	bl FUN_0804fbd0
	movs r0, #4
	bl sound_fadeout_08240440
	movs r1, #4
	ldr r0, _080504CC @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0805049C
	ldr r0, _080504D0 @ =0x03002BE0
	ldr r0, [r0]
	subs r1, #5
	bl FUN_0807b910
_0805049C:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _080504D4
	movs r0, #0xc0
	ldr r1, [r4, #0x20]
	ands r0, r1
	cmp r0, #0xc0
	bne _080504D4
	movs r0, #0xc1
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r4, #0x20]
	movs r1, #7
	adds r0, r4, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r2, [r4, #0x24]
	b _080504D8
	.align 2, 0
_080504CC: .4byte 0x03002BC0
_080504D0: .4byte 0x03002BE0
_080504D4:
	adds r0, r2, #1
	str r0, [r4, #0x24]
_080504D8:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
