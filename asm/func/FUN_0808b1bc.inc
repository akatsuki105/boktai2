	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r1, _0808B1FC @ =0x00000A97
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808B1CC
	b _0808B2F2
_0808B1CC:
	subs r1, #0xb7
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0808B1E2
	movs r1, #4
	ldr r0, _0808B200 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0808B208
_0808B1E2:
	movs r3, #1
	ldr r0, _0808B204 @ =0x00000AA8
	adds r1, r5, r0
	movs r2, #1
_0808B1EA:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0808B1EA
	ldr r0, _0808B1FC @ =0x00000A97
	b _0808B22E
	.align 2, 0
_0808B1FC: .4byte 0x00000A97
_0808B200: .4byte 0x03002BC0
_0808B204: .4byte 0x00000AA8
_0808B208:
	ldr r1, _0808B238 @ =0x00000A9C
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r4, [r0]
	ldr r0, _0808B23C @ =0x00001734
	cmp r4, r0
	ble _0808B248
	movs r3, #1
	ldr r0, _0808B240 @ =0x00000AA8
	adds r1, r5, r0
	movs r2, #1
_0808B21E:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0808B21E
	ldr r0, _0808B244 @ =0x00000A98
_0808B22E:
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	b _0808B2F2
	.align 2, 0
_0808B238: .4byte 0x00000A9C
_0808B23C: .4byte 0x00001734
_0808B240: .4byte 0x00000AA8
_0808B244: .4byte 0x00000A98
_0808B248:
	adds r7, r5, #0
	adds r7, #0x60
	movs r3, #2
	rsbs r3, r3, #0
	ldr r0, _0808B288 @ =0x00000AA8
	adds r1, r5, r0
	movs r2, #1
_0808B256:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0808B256
	cmp r4, #0
	ble _0808B28C
	subs r0, r4, #1
	movs r1, #0x3c
	bl Div
	adds r4, r0, #1
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	adds r6, r0, #0
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #1
	subs r4, r4, r0
	b _0808B290
	.align 2, 0
_0808B288: .4byte 0x00000AA8
_0808B28C:
	movs r6, #0
	movs r4, #0
_0808B290:
	cmp r6, #0
	bne _0808B2BC
	movs r1, #0xaa
	lsls r1, r1, #4
	adds r0, r5, r1
	adds r1, r7, #0
	movs r2, #0x7d
	movs r3, #1
	bl MainSprite_SetPose
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r5, r1
	adds r2, r4, #0
	adds r2, #0x7d
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r7, #0
	movs r3, #1
	bl MainSprite_SetPose
	b _0808B2E8
_0808B2BC:
	movs r1, #0xaa
	lsls r1, r1, #4
	adds r0, r5, r1
	adds r2, r6, #0
	adds r2, #0x73
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r7, #0
	movs r3, #1
	bl MainSprite_SetPose
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r5, r1
	adds r2, r4, #0
	adds r2, #0x73
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r7, #0
	movs r3, #1
	bl MainSprite_SetPose
_0808B2E8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0808b11c
_0808B2F2:
	ldr r0, _0808B308 @ =0x00000A99
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808B300
	subs r0, #1
	strb r0, [r1]
_0808B300:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808B308: .4byte 0x00000A99
