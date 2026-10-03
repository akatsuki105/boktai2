	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrh r1, [r0]
	cmp r1, #1
	bne _080BFDE0
	movs r2, #0x30
	movs r1, #5
	ldr r4, _080BFDDC @ =0x0000034A
	adds r0, r3, r4
_080BFDC4:
	strh r2, [r0]
	subs r0, #0x2c
	subs r1, #1
	cmp r1, #0
	bge _080BFDC4
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #4
	strh r0, [r1]
	b _080BFE40
	.align 2, 0
_080BFDDC: .4byte 0x0000034A
_080BFDE0:
	cmp r1, #2
	bne _080BFDEE
	movs r2, #0x9f
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r0, #4
	b _080BFE08
_080BFDEE:
	cmp r1, #5
	bne _080BFDFC
	movs r4, #0x9f
	lsls r4, r4, #2
	adds r0, r3, r4
	strh r1, [r0, #0x10]
	b _080BFE0A
_080BFDFC:
	cmp r1, #0xa
	bne _080BFE0A
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #6
_080BFE08:
	strh r0, [r1, #0x10]
_080BFE0A:
	movs r7, #2
	rsbs r7, r7, #0
	adds r2, r3, #0
	movs r4, #0x94
	lsls r4, r4, #2
	adds r1, r3, r4
	adds r4, r3, #0
	adds r4, #0xdc
	ldr r6, _080BFE48 @ =0x0000026E
	movs r5, #0x38
_080BFE1E:
	ldr r0, [r1]
	ands r0, r7
	str r0, [r1]
	adds r0, r2, r6
	strh r5, [r0]
	adds r2, #0x2c
	adds r1, #0x2c
	cmp r2, r4
	ble _080BFE1E
	movs r1, #0xdd
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r1, #0xa
	strh r1, [r0]
	ldr r0, _080BFE4C @ =0x0000028B
	bl PlaySound_082406e0
_080BFE40:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BFE48: .4byte 0x0000026E
_080BFE4C: .4byte 0x0000028B
