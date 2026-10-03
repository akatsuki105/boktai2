	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r4, r7, r0
	ldr r0, [r4]
	ldr r1, _0808B038 @ =0x00000446
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0808B04C
	ldr r3, _0808B03C @ =0x00000A3C
	adds r2, r7, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808B040 @ =0x00000A34
	adds r0, r7, r1
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r2, [r4]
	ldr r3, _0808B044 @ =0x00000444
	adds r2, r2, r3
	ldrh r2, [r2]
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl MainSprite_SetPose
	movs r0, #0
	movs r1, #1
	movs r2, #5
	bl FUN_0808a420
	adds r6, r0, #0
	ldr r0, [r4]
	ldr r1, _0808B038 @ =0x00000446
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, #0x3b
	movs r1, #0x3c
	bl Div
	adds r4, r0, #0
	movs r1, #0xa
	bl Div
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	movs r1, #0
	bl FUN_0808a440
	ldr r2, _0808B048 @ =0xFFFFD000
	adds r5, r2, #0
	orrs r0, r5
	strh r0, [r6]
	adds r6, #2
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808a440
	orrs r0, r5
	strh r0, [r6]
	b _0808B0C4
	.align 2, 0
_0808B038: .4byte 0x00000446
_0808B03C: .4byte 0x00000A3C
_0808B040: .4byte 0x00000A34
_0808B044: .4byte 0x00000444
_0808B048: .4byte 0xFFFFD000
_0808B04C:
	ldr r0, _0808B078 @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0xac
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	beq _0808B084
	ldr r0, _0808B07C @ =0x00000A3C
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808B080 @ =0x00000A34
	adds r0, r7, r1
	adds r1, r7, #0
	adds r1, #0xa0
	movs r2, #0x83
	b _0808B0A8
	.align 2, 0
_0808B078: .4byte 0x030046A0
_0808B07C: .4byte 0x00000A3C
_0808B080: .4byte 0x00000A34
_0808B084:
	ldr r2, _0808B0D0 @ =0x000002B2
	adds r0, r1, r2
	movs r3, #0
	ldrsh r5, [r0, r3]
	cmp r5, #0
	beq _0808B0E0
	ldr r0, _0808B0D4 @ =0x00000A3C
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808B0D8 @ =0x00000A34
	adds r0, r7, r1
	adds r1, r7, #0
	adds r1, #0xa0
	movs r2, #0x84
_0808B0A8:
	movs r3, #1
	bl MainSprite_SetPose
	movs r0, #0
	movs r1, #1
	movs r2, #5
	bl FUN_0808a420
	adds r6, r0, #0
	movs r2, #0xd0
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r6]
	strh r0, [r6, #2]
_0808B0C4:
	ldr r3, _0808B0DC @ =0x00000A94
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
	b _0808B10C
	.align 2, 0
_0808B0D0: .4byte 0x000002B2
_0808B0D4: .4byte 0x00000A3C
_0808B0D8: .4byte 0x00000A34
_0808B0DC: .4byte 0x00000A94
_0808B0E0:
	ldr r0, _0808B114 @ =0x00000A94
	adds r4, r7, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0808B10C
	ldr r1, _0808B118 @ =0x00000A3C
	adds r2, r7, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	movs r2, #5
	bl FUN_0808a420
	adds r6, r0, #0
	movs r2, #0xd0
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r6]
	strh r0, [r6, #2]
	strb r5, [r4]
_0808B10C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808B114: .4byte 0x00000A94
_0808B118: .4byte 0x00000A3C
