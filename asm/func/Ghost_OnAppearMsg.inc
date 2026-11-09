	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0816CD2A
	movs r1, #0x80
	lsls r1, r1, #7
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816CD2A
	movs r2, #0x20
	ldr r3, _0816CCD4 @ =0x000007DC
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _0816CCD8
	movs r0, #1
	b _0816CCDA
	.align 2, 0
_0816CCD4: .4byte 0x000007DC
_0816CCD8:
	movs r0, #0
_0816CCDA:
	cmp r0, #0
	bne _0816CD2A
	movs r1, #1
	ldr r3, _0816CCF8 @ =0x0000025D
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816CCFC
	ldr r0, [r4, #0x44]
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0816CD06
	b _0816CD0A
	.align 2, 0
_0816CCF8: .4byte 0x0000025D
_0816CCFC:
	ldr r0, [r4, #0x44]
	ldr r0, [r0, #0x28]
	ands r0, r1
	cmp r0, #0
	beq _0816CD0A
_0816CD06:
	movs r0, #1
	b _0816CD0C
_0816CD0A:
	movs r0, #0
_0816CD0C:
	cmp r0, #0
	beq _0816CD2A
	ldr r0, _0816CD30 @ =0x00000836
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0816CD34 @ =0xFFFFFDBF
	ldr r0, [r2]
	ands r0, r1
	movs r1, #0x20
	orrs r0, r1
	str r0, [r2]
	ldr r0, _0816CD38 @ =0x0000021E
	bl PlaySound_082406e0
_0816CD2A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0816CD30: .4byte 0x00000836
_0816CD34: .4byte 0xFFFFFDBF
_0816CD38: .4byte 0x0000021E
