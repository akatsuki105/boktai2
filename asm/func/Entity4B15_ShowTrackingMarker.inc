	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	ldr r0, _0801A0C0 @ =0x03000090
	ldr r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _0801A100
	ldr r0, _0801A0C4 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0801A0C8
	movs r0, #1
	rsbs r0, r0, #0
	b _0801A0CC
	.align 2, 0
_0801A0C0: .4byte 0x03000090
_0801A0C4: .4byte 0x03002C68
_0801A0C8:
	movs r1, #0x18
	ldrsh r0, [r0, r1]
_0801A0CC:
	cmp r0, r3
	beq _0801A100
	lsls r4, r3, #3
	subs r4, r4, r3
	lsls r4, r4, #3
	adds r4, #0x20
	ldr r2, [r2]
	adds r4, r2, r4
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x30]
	str r1, [r4, #0x34]
	adds r0, r4, #0
	adds r0, #8
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r2, r1
	ldr r1, [r2]
	movs r2, #0x33
	bl Particle_SetFrame
	movs r1, #1
	movs r0, #0
	strb r1, [r4]
	str r0, [r4, #4]
	strb r1, [r4, #2]
_0801A100:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
