	push {r4, lr}
	adds r1, r0, #0
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r1, r0
	ldrb r2, [r4]
	cmp r2, #0
	bne _08049C6C
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r1, r3
	str r2, [r0]
	adds r0, r1, #0
	movs r1, #1
	bl FUN_0804990c
	ldr r1, _08049C68 @ =0x03003520
	movs r0, #1
	str r0, [r1]
	strb r0, [r4]
	movs r0, #0
	b _08049C70
	.align 2, 0
_08049C68: .4byte 0x03003520
_08049C6C:
	movs r0, #1
	rsbs r0, r0, #0
_08049C70:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
