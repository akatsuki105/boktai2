	push {r4, r5, lr}
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0800CBC8
	adds r0, r4, #0
	adds r0, #0xa8
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0xf0
	bl FUN_0822a4e0
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_082342a8
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08236424
	ldrh r1, [r4, #0x28]
	movs r0, #1
	ands r0, r1
	adds r5, r4, #0
	adds r5, #0x48
	cmp r0, #0
	bne _0800CBBE
	adds r0, r5, #0
	bl FUN_08002a58
_0800CBBE:
	adds r0, r5, #0
	bl FUN_0823b284
	movs r0, #0
	strb r0, [r4]
_0800CBC8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
