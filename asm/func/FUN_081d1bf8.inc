	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0x5a
	strh r1, [r0]
	adds r5, r4, #0
	adds r5, #0x80
	ldrh r1, [r5]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _081D1C5A
	movs r0, #2
	orrs r0, r1
	movs r1, #0
	orrs r0, r1
	ldr r1, _081D1C4C @ =0x0000FFFE
	ands r0, r1
	strh r0, [r5]
	adds r1, r4, #0
	adds r1, #0x84
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_081d1b34
	strh r6, [r4, #0x10]
	ldr r0, [r4, #0xc]
	movs r1, #0x90
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	ldrh r1, [r5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081D1C54
	ldr r0, _081D1C50 @ =0x00000389
	bl PlaySound_082406e0
	b _081D1C5A
	.align 2, 0
_081D1C4C: .4byte 0x0000FFFE
_081D1C50: .4byte 0x00000389
_081D1C54:
	ldr r0, _081D1C60 @ =0x00000155
	bl PlaySound_082406e0
_081D1C5A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D1C60: .4byte 0x00000155
