	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080097AC @ =0x0300003C
	str r4, [r0]
	movs r0, #0x6e
	movs r1, #1
	bl VM_GetKeywordValue
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #0xff
	strb r0, [r4, #0x19]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r4, #0x1a]
	str r1, [r4, #0x1c]
	ldrb r0, [r4, #0x18]
	movs r5, #0x6c
	muls r0, r5, r0
	bl Malloc
	adds r2, r0, #0
	str r2, [r4, #0x20]
	cmp r2, #0
	bne _080097B0
_080097A6:
	movs r0, #1
	rsbs r0, r0, #0
	b _080097FC
	.align 2, 0
_080097AC: .4byte 0x0300003C
_080097B0:
	ldrb r0, [r4, #0x18]
	adds r1, r0, #0
	muls r1, r5, r1
	adds r0, r2, #0
	bl ClearMemory
	ldr r6, [r4, #0x20]
	movs r5, #0
	b _080097D4
_080097C2:
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl FUN_080091e8
	cmp r0, #0
	blt _080097A6
	adds r5, #1
	adds r6, #0x6c
_080097D4:
	ldrb r0, [r4, #0x18]
	cmp r5, r0
	blt _080097C2
	ldr r0, _080097F0 @ =0x03002BE0
	ldr r0, [r0]
	str r0, [r4, #0x24]
	cmp r0, #0
	beq _080097F4
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	b _080097FA
	.align 2, 0
_080097F0: .4byte 0x03002BE0
_080097F4:
	strh r0, [r4, #0x28]
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x2c]
_080097FA:
	movs r0, #0
_080097FC:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
