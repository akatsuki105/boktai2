	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0813FCB4 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813FCB8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813FCBA
	.align 2, 0
_0813FCB4: .4byte 0x0000046C
_0813FCB8:
	movs r0, #0
_0813FCBA:
	cmp r0, #0
	beq _0813FCEE
	ldr r4, _0813FD14 @ =FUN_0813f268
	movs r3, #0x21
	ldr r0, _0813FD18 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0813FD1C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	adds r1, #0xa0
	adds r0, r5, r1
	bl ParticleShadow_Hide
_0813FCEE:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0813FD0C
	ldr r0, _0813FD20 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0813FD0C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0813FD14: .4byte FUN_0813f268
_0813FD18: .4byte 0x0000046D
_0813FD1C: .4byte 0x0000046B
_0813FD20: .4byte 0x00000484
