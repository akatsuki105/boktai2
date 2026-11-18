	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r3, [r0]
	ldr r2, [r5, #0x44]
	ldr r0, _0819C764 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819C768
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819C76A
	.align 2, 0
_0819C764: .4byte 0x0000046D
_0819C768:
	movs r0, #0
_0819C76A:
	cmp r0, #0
	beq _0819C784
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r0, _0819C7D0 @ =0x00000EAD
	adds r1, r3, r0
	movs r0, #0x28
	strb r0, [r1]
	ldr r0, _0819C7D4 @ =0x000001E3
	bl PlaySound_082406e0
_0819C784:
	adds r0, r4, #0
	movs r1, #6
	bl Mod
	cmp r0, #0
	bne _0819C79E
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0819C79E:
	cmp r4, #0x50
	ble _0819C7CA
	ldr r4, _0819C7D8 @ =FUN_0819cc04
	movs r3, #0x33
	ldr r0, _0819C7DC @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819C7E0 @ =0x0000046B
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
_0819C7CA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819C7D0: .4byte 0x00000EAD
_0819C7D4: .4byte 0x000001E3
_0819C7D8: .4byte FUN_0819cc04
_0819C7DC: .4byte 0x0000046D
_0819C7E0: .4byte 0x0000046B
