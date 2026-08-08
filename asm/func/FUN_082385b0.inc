	push {r4, r5, r6, lr}
	ldr r0, _082385B8 @ =0x03000820
	ldr r4, [r0]
	b _082385C4
	.align 2, 0
_082385B8: .4byte 0x03000820
_082385BC:
	adds r0, r4, #0
	adds r0, #0xc0
	bl FUN_08238178
_082385C4:
	adds r0, r4, #0
	bl FUN_082381b4
	adds r1, r0, #0
	cmp r1, #0
	bne _082385BC
	adds r5, r4, #0
	adds r5, #0x40
	adds r6, r4, #0
	adds r6, #0x80
	b _082385E2
_082385DA:
	adds r0, r4, #0
	adds r0, #0xc0
	bl FUN_08238178
_082385E2:
	adds r0, r5, #0
	bl FUN_082381b4
	adds r1, r0, #0
	cmp r1, #0
	bne _082385DA
	b _082385F8
_082385F0:
	adds r0, r4, #0
	adds r0, #0xc0
	bl FUN_08238178
_082385F8:
	adds r0, r6, #0
	bl FUN_082381b4
	adds r1, r0, #0
	cmp r1, #0
	bne _082385F0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
