	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r1, [r7, #0x64]
	adds r0, r1, #0
	subs r0, #0xa
	cmp r0, #0x13
	bls _08089F6C
	subs r0, #0x32
	cmp r0, #0x13
	bhi _08089FB0
_08089F6C:
	ldr r6, _08089FA4 @ =0x0203B400
	ldr r5, _08089FA8 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _08089FAC @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r4, #0x1f
	ands r0, r4
	subs r0, #0x10
	adds r2, r7, #0
	adds r2, #0x60
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #0x10
	adds r1, r7, #0
	adds r1, #0x62
	strh r0, [r1]
	b _08089FBC
	.align 2, 0
_08089FA4: .4byte 0x0203B400
_08089FA8: .4byte 0x030046B8
_08089FAC: .4byte 0x000003FF
_08089FB0:
	adds r0, r7, #0
	adds r0, #0x60
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_08089FBC:
	ldr r0, [r7, #0x64]
	cmp r0, #0xa
	beq _08089FCE
	cmp r0, #0x14
	beq _08089FCE
	cmp r0, #0x3c
	beq _08089FCE
	cmp r0, #0x46
	bne _08089FD4
_08089FCE:
	movs r0, #0xd3
	bl PlaySound_082406e0
_08089FD4:
	ldr r0, [r7, #0x64]
	cmp r0, #0x59
	bls _08089FE6
	movs r1, #7
	adds r2, r7, #0
	adds r2, #0x4e
	movs r0, #0
	strh r1, [r2]
	b _08089FE8
_08089FE6:
	adds r0, #1
_08089FE8:
	str r0, [r7, #0x64]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
