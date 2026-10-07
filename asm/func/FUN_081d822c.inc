	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081D828C @ =0x030001A0
	ldr r2, [r0]
	cmp r2, #0
	beq _081D8286
	adds r1, r5, #0
	adds r1, #0xd8
	ldr r0, _081D8290 @ =nop_081d8368
	str r0, [r1]
	adds r3, r5, #0
	adds r3, #0xd0
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r1, #0xea
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	movs r0, #1
	rsbs r0, r0, #0
	adds r6, r0, #0
	ldr r0, _081D8294 @ =0x0000FFFF
	strh r0, [r3]
	adds r0, r5, #0
	bl AuxSprite_Remove
	adds r4, r5, #0
	adds r4, #0xd2
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _081D8286
	adds r0, r5, #0
	adds r0, #0x8c
	bl ParticleShadow_Remove
	ldrh r0, [r4]
	orrs r0, r6
	strh r0, [r4]
_081D8286:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D828C: .4byte 0x030001A0
_081D8290: .4byte nop_081d8368
_081D8294: .4byte 0x0000FFFF
