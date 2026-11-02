	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080045F8 @ =0x03000020
	str r5, [r0]
	ldrh r0, [r5, #0x18]
	cmp r0, #0
	bne _0800459A
	movs r0, #8
	strh r0, [r5, #0x18]
_0800459A:
	ldrh r0, [r5, #0x18]
	movs r4, #0xce
	lsls r4, r4, #1
	muls r0, r4, r0
	bl Malloc
	adds r2, r0, #0
	str r2, [r5, #0x70]
	cmp r2, #0
	beq _08004604
	ldrh r0, [r5, #0x18]
	adds r1, r0, #0
	muls r1, r4, r1
	adds r0, r2, #0
	bl ClearMemory
	movs r0, #0
	strb r0, [r5, #0x1a]
	strb r0, [r5, #0x1e]
	strb r0, [r5, #0x1b]
	strh r0, [r5, #0x1c]
	ldr r0, _080045FC @ =0x03003584
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x40
	str r0, [r5, #0x20]
	adds r0, #0x20
	str r0, [r5, #0x24]
	adds r0, #0x20
	str r0, [r5, #0x28]
	adds r1, #0xa0
	str r1, [r5, #0x2c]
	adds r1, r5, #0
	adds r1, #0x30
	ldr r4, _08004600 @ =0x04000008
	adds r2, r4, #0
	bl CpuSet
	ldr r0, [r5, #0x2c]
	adds r1, r5, #0
	adds r1, #0x50
	adds r2, r4, #0
	bl CpuSet
	movs r0, #0
	b _08004608
	.align 2, 0
_080045F8: .4byte 0x03000020
_080045FC: .4byte 0x03003584
_08004600: .4byte 0x04000008
_08004604:
	movs r0, #1
	rsbs r0, r0, #0
_08004608:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
