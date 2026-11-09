	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x54
	movs r5, #0
	ldr r7, _0805EDF4 @ =0x085ABA70
_0805EDCC:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805EDE4
	ldrb r0, [r4, #1]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
_0805EDE4:
	adds r5, #1
	adds r4, #0x4c
	cmp r5, #7
	ble _0805EDCC
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805EDF4: .4byte 0x085ABA70
