	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081DF6AC @ =0x03002C68
	ldr r3, [r0]
	cmp r3, #0
	bne _081DF6B0
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF6D6
	.align 2, 0
_081DF6AC: .4byte 0x03002C68
_081DF6B0:
	movs r2, #0
	b _081DF6B6
_081DF6B4:
	adds r2, #1
_081DF6B6:
	cmp r2, #4
	bgt _081DF6D4
	movs r4, #0x8c
	lsls r4, r4, #1
	adds r0, r3, r4
	adds r4, r0, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, r1
	bne _081DF6B4
	adds r0, r5, #0
	bl FUN_081e1984
	movs r0, #0xff
	strb r0, [r4]
_081DF6D4:
	movs r0, #0
_081DF6D6:
	pop {r4, r5}
	pop {r1}
	bx r1
