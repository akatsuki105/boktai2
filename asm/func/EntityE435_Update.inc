	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	cmp r0, #0
	beq _08017A10
	ldrh r0, [r6, #0x1a]
	ldrh r1, [r6, #0x1c]
	ldrh r3, [r6, #0x2c]
	lsls r2, r3, #3
	adds r2, r2, r3
	lsls r2, r2, #6
	adds r2, #0x2e
	adds r2, r6, r2
	ldr r5, _08017A18 @ =0x03003ED0
	ldr r3, _08017A1C @ =0x030044A0
	ldr r4, [r3]
	lsls r3, r4, #1
	adds r3, r3, r4
	lsls r3, r3, #4
	adds r3, r3, r5
	movs r4, #0x22
	ldrsh r3, [r3, r4]
	ldrh r4, [r6, #0x22]
	adds r3, r3, r4
	movs r4, #0x7f
	ands r3, r4
	lsls r3, r3, #1
	adds r2, r2, r3
	bl Video_SetHBlankEffect
	ldrh r0, [r6, #0x26]
	adds r0, #1
	strh r0, [r6, #0x26]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r6, #0x24]
	cmp r0, r1
	blo _08017A10
	movs r0, #0
	strh r0, [r6, #0x26]
	ldrh r0, [r6, #0x20]
	ldrh r4, [r6, #0x22]
	adds r0, r0, r4
	strh r0, [r6, #0x22]
_08017A10:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08017A18: .4byte 0x03003ED0
_08017A1C: .4byte 0x030044A0
