	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08163DAC @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08163DB0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08163DB2
	.align 2, 0
_08163DAC: .4byte 0x0000046C
_08163DB0:
	movs r0, #0
_08163DB2:
	cmp r0, #0
	beq _08163DE0
	ldr r1, _08163E00 @ =0x000005A4
	adds r0, r4, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r0, _08163E04 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08163E08 @ =0x0000046B
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
	strh r2, [r0]
_08163DE0:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r0, _08163E0C @ =0x00000484
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08163E00: .4byte 0x000005A4
_08163E04: .4byte 0x0000046D
_08163E08: .4byte 0x0000046B
_08163E0C: .4byte 0x00000484
