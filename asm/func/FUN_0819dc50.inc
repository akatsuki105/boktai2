	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _0819DC70 @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819DC74
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819DC76
	.align 2, 0
_0819DC70: .4byte 0x0000046C
_0819DC74:
	movs r0, #0
_0819DC76:
	cmp r0, #0
	beq _0819DCAC
	ldr r1, _0819DCE8 @ =0x000005A4
	adds r0, r4, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r0, _0819DCEC @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819DCF0 @ =0x0000046B
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	strh r2, [r0]
	ldr r2, _0819DCF4 @ =0x00000EA6
	adds r0, r5, r2
	strb r1, [r0]
_0819DCAC:
	ldr r5, _0819DCF8 @ =0x00000484
	adds r3, r4, r5
	ldr r0, [r3]
	cmp r0, #0x3c
	ble _0819DCDC
	movs r2, #3
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	subs r5, #0x1b
	adds r0, r4, r5
	strb r1, [r0]
	adds r5, #1
	adds r0, r4, r5
	strb r2, [r0]
	ldr r2, _0819DCF8 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r5, #2
	adds r1, r4, r5
	movs r0, #1
	strb r0, [r1]
_0819DCDC:
	ldr r0, [r3]
	adds r0, #1
	str r0, [r3]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819DCE8: .4byte 0x000005A4
_0819DCEC: .4byte 0x0000046D
_0819DCF0: .4byte 0x0000046B
_0819DCF4: .4byte 0x00000EA6
_0819DCF8: .4byte 0x00000484
