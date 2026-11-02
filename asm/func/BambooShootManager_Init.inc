	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0800A20C @ =0x03000040
	str r5, [r0]
	ldr r0, _0800A210 @ =gClock
	ldrb r1, [r0, #0xe]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0800A25C
	cmp r1, #0
	beq _0800A25C
	ldr r0, _0800A214 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800A228
	ldr r0, _0800A218 @ =0x03002BE0
	ldr r1, [r0]
	cmp r1, #0
	beq _0800A224
	ldr r2, _0800A21C @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _0800A208
	ldr r3, _0800A220 @ =0x00000442
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #4
	bne _0800A208
	movs r2, #1
_0800A208:
	adds r0, r2, #0
	b _0800A258
	.align 2, 0
_0800A20C: .4byte 0x03000040
_0800A210: .4byte gClock
_0800A214: .4byte 0x030047A4
_0800A218: .4byte 0x03002BE0
_0800A21C: .4byte 0x00000446
_0800A220: .4byte 0x00000442
_0800A224:
	movs r0, #0
	b _0800A258
_0800A228:
	ldr r0, _0800A290 @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	bgt _0800A25C
	ldr r0, _0800A294 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	beq _0800A25C
	ldr r0, _0800A298 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _0800A256
	ldr r0, _0800A29C @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _0800A256
	movs r1, #1
_0800A256:
	adds r0, r1, #0
_0800A258:
	cmp r0, #0
	beq _0800A25E
_0800A25C:
	movs r0, #1
_0800A25E:
	strb r0, [r5, #0x18]
	ldr r0, _0800A2A0 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r5, #0x1c]
	ldr r0, _0800A2A4 @ =0x00001C1C
	bl GetParticleGroup
	str r0, [r5, #0x20]
	ldr r4, _0800A2A8 @ =0x0000922E
	ldr r1, _0800A2AC @ =0x0000D1B8
	adds r0, r4, #0
	bl GetFile
	str r0, [r5, #0x24]
	ldr r1, _0800A2B0 @ =0x0000D41F
	adds r0, r4, #0
	bl GetFile
	str r0, [r5, #0x28]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800A290: .4byte 0x03002B48
_0800A294: .4byte 0x030046A0
_0800A298: .4byte 0x03002B8C
_0800A29C: .4byte 0x03002B60
_0800A2A0: .4byte 0x00001C1A
_0800A2A4: .4byte 0x00001C1C
_0800A2A8: .4byte 0x0000922E
_0800A2AC: .4byte 0x0000D1B8
_0800A2B0: .4byte 0x0000D41F
