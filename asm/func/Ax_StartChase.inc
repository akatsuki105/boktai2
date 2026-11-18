	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081A15A4 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A15A8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A15AA
	.align 2, 0
_081A15A4: .4byte 0x0000046C
_081A15A8:
	movs r0, #0
_081A15AA:
	cmp r0, #0
	beq _081A15F2
	ldr r4, _081A160C @ =FUN_0819cfcc
	movs r3, #0xa
	ldr r2, _081A1610 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A1614 @ =0x0000046B
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
	movs r0, #0x80
	lsls r0, r0, #1
	subs r1, #0x48
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
_081A15F2:
	ldr r1, _081A1614 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A161C
	ldr r0, _081A1618 @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	adds r0, r5, #0
	bl Ax_BeginCurveTo
	b _081A1626
	.align 2, 0
_081A160C: .4byte FUN_0819cfcc
_081A1610: .4byte 0x0000046D
_081A1614: .4byte 0x0000046B
_081A1618: .4byte 0x03002BE0
_081A161C:
	ldr r2, _081A162C @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A1626:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081A162C: .4byte 0x00000484
