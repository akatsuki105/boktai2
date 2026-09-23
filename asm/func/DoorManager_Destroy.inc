	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r6, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _08021B64
	ldr r1, _08021BD0 @ =0x0000042C
	adds r7, r5, r1
_08021B3C:
	movs r0, #0x8c
	adds r1, r6, #0
	muls r1, r0, r1
	ldr r0, [r7]
	adds r4, r0, r1
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _08021B56
	bl FUN_082342a8
	ldr r0, [r4, #0x2c]
	bl Free
_08021B56:
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r6, #1
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	blt _08021B3C
_08021B64:
	ldr r0, [r5, #0x34]
	cmp r0, #0
	beq _08021BB8
	movs r1, #0x82
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	ldr r1, _08021BD4 @ =0x00000414
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	movs r1, #0x83
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	ldr r1, _08021BD8 @ =0x0000041C
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	movs r1, #0x84
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	ldr r1, _08021BDC @ =0x00000424
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	movs r1, #0x85
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
_08021BB8:
	ldr r1, _08021BD0 @ =0x0000042C
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	ldr r0, _08021BE0 @ =0x000085E6
	bl FUN_08230e58
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08021BD0: .4byte 0x0000042C
_08021BD4: .4byte 0x00000414
_08021BD8: .4byte 0x0000041C
_08021BDC: .4byte 0x00000424
_08021BE0: .4byte 0x000085E6
