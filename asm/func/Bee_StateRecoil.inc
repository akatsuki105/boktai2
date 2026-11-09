	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08169068 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816906C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816906E
	.align 2, 0
_08169068: .4byte 0x0000046C
_0816906C:
	movs r0, #0
_0816906E:
	cmp r0, #0
	beq _08169128
	ldr r4, _081690E4 @ =Bee_AnimRecoil
	movs r3, #0x26
	ldr r2, _081690E8 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081690EC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	ldr r2, _081690F0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081690F4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081690F8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r2, r5, r1
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x71
	ldrb r2, [r2]
	adds r3, r0, r2
	movs r1, #0xff
	ands r3, r1
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r4, r5, r2
	ldr r2, _081690FC @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08169100
	asrs r1, r0, #0xc
	b _08169106
	.align 2, 0
_081690E4: .4byte Bee_AnimRecoil
_081690E8: .4byte 0x0000046D
_081690EC: .4byte 0x0000046B
_081690F0: .4byte 0x030046B8
_081690F4: .4byte 0x000003FF
_081690F8: .4byte 0x0203B400
_081690FC: .4byte gSineTable
_08169100:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08169106:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _08169120
	asrs r0, r0, #0xc
	b _08169126
_08169120:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08169126:
	strh r0, [r4, #4]
_08169128:
	ldr r0, _0816916C @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	cmp r0, #0x1e
	ble _0816917C
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _08169170 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r4, #0
	strh r1, [r2]
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _08169174 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r2, #0x1b
	adds r0, r5, r2
	str r4, [r0]
	ldr r0, _08169178 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _08169180
	.align 2, 0
_0816916C: .4byte 0x00000484
_08169170: .4byte 0xFFFFFEFF
_08169174: .4byte 0x0000046A
_08169178: .4byte 0x0000046C
_0816917C:
	adds r0, #1
	str r0, [r1]
_08169180:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
