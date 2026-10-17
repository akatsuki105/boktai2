	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08086AAC @ =0x03002C00
	ldr r3, [r0]
	cmp r3, #0
	beq _08086AA4
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x48]
	str r1, [r3, #0x4c]
	adds r2, r3, #0
	adds r2, #0xa0
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _08086AB0 @ =0x0000031E
	adds r0, r3, r1
	ldrh r0, [r0]
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r1, r3, #0
	adds r1, #0xa4
	ldr r2, _08086AB4 @ =0x00000322
	adds r0, r3, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
_08086AA4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086AAC: .4byte 0x03002C00
_08086AB0: .4byte 0x0000031E
_08086AB4: .4byte 0x00000322
