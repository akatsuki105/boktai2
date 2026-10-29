	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x60
	strh r0, [r4, #0x26]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080AD170
	bl VM_GetValue
	b _080AD172
_080AD170:
	movs r0, #6
_080AD172:
	strh r0, [r4, #0x2a]
	adds r0, r4, #0
	bl Entity5292_InitElems
	ldr r2, _080AD19C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AD1A0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AD1A4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	strh r0, [r4, #0x24]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080AD19C: .4byte 0x030046B8
_080AD1A0: .4byte 0x000003FF
_080AD1A4: .4byte 0x0203B400
