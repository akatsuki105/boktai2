	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081DA908
	movs r0, #4
	str r0, [sp]
	ldr r0, _081DA928 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _081DA92C @ =0x0000029E
	adds r0, r5, r1
	movs r1, #0
	strh r4, [r0]
	strb r1, [r6]
_081DA908:
	ldr r0, _081DA92C @ =0x0000029E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x14
	bne _081DA918
	adds r0, r5, #0
	bl FUN_081d9f3c
_081DA918:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DA928: .4byte 0x0000FFFF
_081DA92C: .4byte 0x0000029E
