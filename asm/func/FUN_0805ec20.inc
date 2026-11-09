	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	adds r6, r7, #0
	adds r6, #0x20
	ldrb r0, [r7, #2]
	cmp r0, #0
	beq _0805EC32
	movs r0, #0
	strb r0, [r7, #2]
_0805EC32:
	ldr r0, [r7, #0x14]
	cmp r0, #9
	bhi _0805EC88
	ldr r0, [r7, #0x18]
	ldr r1, [r7, #0x1c]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	ldr r0, _0805EC7C @ =0x0203B400
	mov ip, r0
	ldr r3, _0805EC80 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r5, _0805EC84 @ =0x000003FF
	ands r1, r5
	str r1, [r3]
	lsls r0, r1, #1
	add r0, ip
	ldrh r2, [r0]
	ldrh r0, [r6, #0x1c]
	subs r0, #4
	movs r4, #7
	ands r2, r4
	adds r0, r0, r2
	strh r0, [r6, #0x1c]
	adds r1, #1
	ands r1, r5
	str r1, [r3]
	lsls r1, r1, #1
	add r1, ip
	ldrh r1, [r1]
	ldrh r0, [r6, #0x20]
	subs r0, #4
	ands r1, r4
	adds r0, r0, r1
	strh r0, [r6, #0x20]
	b _0805EC94
	.align 2, 0
_0805EC7C: .4byte 0x0203B400
_0805EC80: .4byte 0x030046B8
_0805EC84: .4byte 0x000003FF
_0805EC88:
	cmp r0, #0xa
	bne _0805EC94
	ldr r0, [r7, #0x18]
	ldr r1, [r7, #0x1c]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
_0805EC94:
	ldr r0, [r7, #0x14]
	cmp r0, #0x28
	bne _0805ECA8
	movs r0, #4
	movs r1, #0
	strb r0, [r7, #1]
	movs r0, #1
	strb r0, [r7, #2]
	str r1, [r7, #0x14]
	b _0805ECAC
_0805ECA8:
	adds r0, #1
	str r0, [r7, #0x14]
_0805ECAC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
