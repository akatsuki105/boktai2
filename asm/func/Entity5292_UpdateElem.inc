	push {r4, r5, lr}
	mov ip, r0
	mov r1, ip
	adds r1, #0x48
	adds r0, #0x50
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	ldr r3, _080ACE88 @ =0x00000FFF
	adds r2, r3, #0
	ands r0, r2
	strh r0, [r1]
	mov r3, ip
	adds r3, #0x4a
	mov r0, ip
	adds r0, #0x52
	ldrh r0, [r0]
	ldrh r4, [r3]
	adds r0, r0, r4
	ands r0, r2
	strh r0, [r3]
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	mov r1, ip
	strh r0, [r1, #0x1c]
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r1, #0x1e]
	adds r1, #0x5c
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x12
	movs r1, #3
	ands r0, r1
	mov r2, ip
	strh r0, [r2, #0x10]
	mov r1, ip
	adds r1, #0x5e
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080ACF44
	ldr r2, _080ACE8C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080ACE90 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080ACE94 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x1f
	ands r0, r1
	adds r3, r0, #0
	subs r3, #0xf
	adds r5, r2, #0
	cmp r3, #0
	ble _080ACE98
	mov r4, ip
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	str r0, [r4]
	b _080ACEA6
	.align 2, 0
_080ACE88: .4byte 0x00000FFF
_080ACE8C: .4byte 0x030046B8
_080ACE90: .4byte 0x000003FF
_080ACE94: .4byte 0x0203B400
_080ACE98:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
_080ACEA6:
	mov r0, ip
	adds r0, #0x60
	ldrh r0, [r0]
	adds r3, r3, r0
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _080ACEEC @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r4, _080ACEF0 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	mov r2, ip
	adds r2, #0x62
	asrs r0, r0, #3
	movs r1, #0xf
	ands r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	subs r4, r0, #7
	ldr r2, _080ACEF4 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080ACEF8
	asrs r1, r0, #0xc
	b _080ACEFE
	.align 2, 0
_080ACEEC: .4byte 0x000003FF
_080ACEF0: .4byte 0x0203B400
_080ACEF4: .4byte gSineTable
_080ACEF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080ACEFE:
	mov r0, ip
	adds r0, #0x50
	strh r1, [r0]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _080ACF1A
	asrs r0, r0, #0xc
	b _080ACF20
_080ACF1A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080ACF20:
	mov r1, ip
	adds r1, #0x52
	strh r0, [r1]
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _080ACF4C @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r3, _080ACF50 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0xf
	mov r1, ip
	adds r1, #0x5e
	strh r0, [r1]
_080ACF44:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ACF4C: .4byte 0x000003FF
_080ACF50: .4byte 0x0203B400
