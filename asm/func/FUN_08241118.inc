	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r2, _08241198 @ =0x030046A0
	ldr r1, [r2]
	ldr r0, _0824119C @ =0x03004594
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, [r2]
	movs r1, #4
	bl FUN_08231d5c
	movs r0, #0x80
	lsls r0, r0, #3
	bl FUN_08243648
	adds r5, r0, #0
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0824100c
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl FUN_08232260
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08243988
	adds r1, r0, #0
	adds r0, r5, #0
	adds r0, #8
	cmp r1, r0
	bne _082411A4
	bl FUN_08241078
	bl FUN_08243648
	adds r5, r0, #0
	adds r0, r6, #0
	movs r1, #1
	bl FUN_0824100c
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl FUN_08232254
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08243988
	adds r1, r0, #0
	adds r0, r5, #0
	adds r0, #8
	cmp r1, r0
	bne _082411A4
	ldr r1, _082411A0 @ =0x030047B4
	movs r0, #1
	str r0, [r1]
	b _082411A6
	.align 2, 0
_08241198: .4byte 0x030046A0
_0824119C: .4byte 0x03004594
_082411A0: .4byte 0x030047B4
_082411A4:
	movs r0, #0
_082411A6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
