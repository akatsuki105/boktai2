	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08143F10 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08143F14
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08143F16
	.align 2, 0
_08143F10: .4byte 0x0000046C
_08143F14:
	movs r0, #0
_08143F16:
	cmp r0, #0
	beq _08143F42
	ldr r4, _08143F84 @ =FUN_08143094
	movs r3, #0x22
	ldr r2, _08143F88 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08143F8C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_08143F42:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	ldr r2, _08143F8C @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08143F98
	movs r2, #2
	movs r3, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r1, #0
	strb r1, [r0]
	adds r4, #1
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08143F90 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r1, _08143F94 @ =0x0000046C
	adds r0, r5, r1
	strb r3, [r0]
	b _08143FA2
	.align 2, 0
_08143F84: .4byte FUN_08143094
_08143F88: .4byte 0x0000046D
_08143F8C: .4byte 0x0000046B
_08143F90: .4byte 0x0000046A
_08143F94: .4byte 0x0000046C
_08143F98:
	ldr r2, _08143FA8 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08143FA2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08143FA8: .4byte 0x00000484
