	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x24
	strb r2, [r0]
	str r1, [r4, #0x18]
	cmp r3, #0
	bne _080AC33A
	strh r3, [r4, #0x1c]
	strh r3, [r4, #0x1e]
	strh r3, [r4, #0x20]
	b _080AC342
_080AC33A:
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
_080AC342:
	ldr r0, [r4, #0x18]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x25
	strb r0, [r1]
	ldr r0, [sp, #8]
	strh r0, [r4, #0x28]
	ldr r0, [sp, #0xc]
	strh r0, [r4, #0x2a]
	ldr r1, [r4, #0x18]
	adds r1, #0x2c
	adds r0, r4, #0
	bl FUN_080ac228
	adds r0, r4, #0
	bl FUN_080ac008
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
