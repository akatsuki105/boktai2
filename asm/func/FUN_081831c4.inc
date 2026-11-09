	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081831DC @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081831E0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081831E2
	.align 2, 0
_081831DC: .4byte 0x0000046C
_081831E0:
	movs r0, #0
_081831E2:
	cmp r0, #0
	beq _08183216
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _0818325C @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08183260 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08183216:
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _08183272
	ldr r1, _08183260 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08183268
	movs r1, #0xf
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _08183264 @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _08183272
	.align 2, 0
_0818325C: .4byte 0x0000046D
_08183260: .4byte 0x0000046B
_08183264: .4byte 0x00000484
_08183268:
	ldr r0, _08183278 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08183272:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08183278: .4byte 0x00000484
