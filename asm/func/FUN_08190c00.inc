	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r4, [r0]
	movs r1, #2
	ldr r2, _08190C20 @ =0x00000F2C
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08190C24
	movs r0, #1
	b _08190C26
	.align 2, 0
_08190C20: .4byte 0x00000F2C
_08190C24:
	movs r0, #0
_08190C26:
	cmp r0, #0
	beq _08190C70
	movs r2, #4
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r3, r5
	movs r1, #0
	strb r1, [r0]
	adds r5, #1
	adds r0, r3, r5
	strb r1, [r0]
	adds r5, #1
	adds r0, r3, r5
	strb r2, [r0]
	ldr r2, _08190C84 @ =0x00000484
	adds r0, r3, r2
	str r1, [r0]
	adds r5, #2
	adds r1, r3, r5
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r1, _08190C88 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _08190C8C @ =0x00000544
	adds r1, r3, r2
	movs r0, #0xb4
	strh r0, [r1]
	movs r5, #0xde
	lsls r5, r5, #1
	adds r1, r3, r5
	movs r0, #2
	strh r0, [r1]
_08190C70:
	ldr r1, _08190C90 @ =0x00000F2C
	adds r0, r4, r1
	movs r1, #3
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08190C84: .4byte 0x00000484
_08190C88: .4byte 0xFFEFFFFF
_08190C8C: .4byte 0x00000544
_08190C90: .4byte 0x00000F2C
