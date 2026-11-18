	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r2, _0819BE3C @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819BE40
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819BE42
	.align 2, 0
_0819BE3C: .4byte 0x0000046D
_0819BE40:
	movs r0, #0
_0819BE42:
	cmp r0, #0
	beq _0819BE6A
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r5, #0x94
	lsls r5, r5, #1
	adds r2, r4, r5
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r2, r4, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	orrs r1, r0
	strh r1, [r2, #6]
_0819BE6A:
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	movs r5, #1
	orrs r0, r5
	str r0, [r1]
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl ParticleShadow_Hide
	movs r2, #0xe4
	lsls r2, r2, #4
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r7, r0
	ble _0819BEC6
	adds r1, r4, #0
	adds r1, #8
	ldr r0, _0819BECC @ =0x03002BE0
	ldr r2, [r0]
	adds r2, #0x2c
	movs r3, #0x80
	lsls r3, r3, #0xb
	adds r0, r4, #0
	bl Ax_PickFarPathNode
	ldr r3, _0819BED0 @ =FUN_0819bedc
	movs r2, #0x24
	ldr r1, _0819BED4 @ =0x0000046D
	adds r0, r4, r1
	movs r1, #0
	strb r5, [r0]
	ldr r5, _0819BED8 @ =0x0000046B
	adds r0, r4, r5
	strb r1, [r0]
	adds r5, #0xe8
	adds r0, r4, r5
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	str r3, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r4, r5
	strh r1, [r0]
_0819BEC6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819BECC: .4byte 0x03002BE0
_0819BED0: .4byte FUN_0819bedc
_0819BED4: .4byte 0x0000046D
_0819BED8: .4byte 0x0000046B
