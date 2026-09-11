	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x20]
	ldr r0, _0800C150 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, r1
	bne _0800C154
	movs r0, #1
	b _0800C156
	.align 2, 0
_0800C150: .4byte 0x030046A0
_0800C154:
	movs r0, #0
_0800C156:
	cmp r0, #0
	bne _0800C178
	ldr r0, [r4, #0x58]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x58]
	adds r2, r4, #0
	adds r2, #0xca
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0x84
	bl FUN_080136b4
	b _0800C240
_0800C178:
	ldr r0, [r4, #0x58]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x58]
	adds r2, r4, #0
	adds r2, #0xca
	ldrh r1, [r2]
	ldr r0, _0800C210 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0x84
	bl FUN_08013698
	ldrh r0, [r4, #0x28]
	cmp r0, #0
	beq _0800C1A0
	subs r0, #1
	strh r0, [r4, #0x28]
_0800C1A0:
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq _0800C1BA
	subs r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800C1BA
	adds r0, r4, #0
	adds r0, #0x3c
	ldr r1, _0800C214 @ =0x00000169
	bl Video_SetActorSpritePltt
_0800C1BA:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r3, #0
	strh r0, [r4, #0x2c]
	ldr r2, _0800C218 @ =0x085AA76C
	ldrh r1, [r4, #0x2a]
	lsls r1, r1, #1
	adds r1, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _0800C1EE
	strh r3, [r4, #0x2c]
	ldrh r0, [r4, #0x2a]
	adds r0, #1
	strh r0, [r4, #0x2a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _0800C1E6
	strh r3, [r4, #0x2a]
_0800C1E6:
	ldrh r1, [r4, #0x2a]
	adds r0, r4, #0
	adds r0, #0x58
	strh r1, [r0, #0x10]
_0800C1EE:
	adds r2, r4, #0
	adds r2, #0x30
	ldrb r0, [r2]
	cmp r0, #0
	beq _0800C21C
	ldrh r0, [r4, #0x34]
	adds r0, #2
	strh r0, [r4, #0x34]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x32
	ble _0800C234
	movs r0, #0x32
	strh r0, [r4, #0x34]
	movs r0, #0
	b _0800C232
	.align 2, 0
_0800C210: .4byte 0x0000FFFB
_0800C214: .4byte 0x00000169
_0800C218: .4byte 0x085AA76C
_0800C21C:
	ldrh r0, [r4, #0x34]
	subs r0, #2
	strh r0, [r4, #0x34]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x32
	rsbs r1, r1, #0
	cmp r0, r1
	bge _0800C234
	strh r1, [r4, #0x34]
	movs r0, #1
_0800C232:
	strb r0, [r2]
_0800C234:
	ldrh r0, [r4, #0x34]
	ldrh r1, [r4, #0x32]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x76
	strh r0, [r1]
_0800C240:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
