	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081488E4
	movs r3, #0x93
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrh r1, [r0]
	ldr r7, _081488E0 @ =0x0000024E
	adds r0, r4, r7
	strh r1, [r0]
	b _08148988
	.align 2, 0
_081488E0: .4byte 0x0000024E
_081488E4:
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	bne _08148988
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r3, #0
	ldrsh r0, [r1, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	movs r7, #2
	ldrsh r0, [r1, r7]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r2, r2, r0
	movs r7, #4
	ldrsh r0, [r1, r7]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	cmn r2, r0
	bne _0814892E
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r3, #0
	ldrsh r5, [r0, r3]
	cmp r5, #0
	beq _08148936
_0814892E:
	adds r0, r4, #0
	bl FUN_081486d8
	b _0814897E
_08148936:
	ldr r3, _08148990 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r7, _08148994 @ =0x0000046D
	adds r0, r4, r7
	movs r2, #1
	strb r2, [r0]
	subs r7, #2
	adds r0, r4, r7
	strb r5, [r0]
	adds r7, #0xe8
	adds r0, r4, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r1, #0
	strh r5, [r0]
	subs r7, #0xeb
	adds r0, r4, r7
	strb r1, [r0]
	ldr r3, _08148998 @ =0x00000469
	adds r0, r4, r3
	strb r2, [r0]
	adds r7, #2
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, _0814899C @ =0x00000484
	adds r0, r4, r1
	str r5, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r2, [r0]
_0814897E:
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
_08148988:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08148990: .4byte Enemy_ClearStateBegun
_08148994: .4byte 0x0000046D
_08148998: .4byte 0x00000469
_0814899C: .4byte 0x00000484
