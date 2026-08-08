	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	movs r2, #0
	ldr r0, _0822D1DC @ =0x03004044
	ldr r1, [r0]
	adds r5, r0, #0
	cmp r2, r1
	bge _0822D1B4
	adds r3, r1, #0
	ldr r1, _0822D1E0 @ =0x03004470
_0822D1A6:
	ldrh r0, [r1]
	cmp r0, r4
	beq _0822D1E8
	adds r1, #2
	adds r2, #1
	cmp r2, r3
	blt _0822D1A6
_0822D1B4:
	ldr r2, [r5]
	cmp r2, #0xf
	bgt _0822D1EC
	ldr r1, _0822D1E0 @ =0x03004470
	lsls r0, r2, #1
	adds r0, r0, r1
	strh r4, [r0]
	lsls r1, r2, #5
	ldr r0, _0822D1E4 @ =gObjectPlttBuffer
	adds r1, r1, r0
	adds r0, r6, #0
	movs r2, #8
	bl CpuFastSet
	ldr r1, [r5]
	adds r0, r1, #0
	adds r1, #1
	str r1, [r5]
	b _0822D1EE
	.align 2, 0
_0822D1DC: .4byte 0x03004044
_0822D1E0: .4byte 0x03004470
_0822D1E4: .4byte gObjectPlttBuffer
_0822D1E8:
	adds r0, r2, #0
	b _0822D1EE
_0822D1EC:
	movs r0, #0
_0822D1EE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
