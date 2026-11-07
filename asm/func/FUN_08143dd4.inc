	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _08143DF4 @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08143DF8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08143DFA
	.align 2, 0
_08143DF4: .4byte 0x0000046C
_08143DF8:
	movs r0, #0
_08143DFA:
	cmp r0, #0
	beq _08143E48
	ldr r3, _08143E5C @ =0x000005A4
	adds r0, r4, r3
	ldr r3, [r0]
	movs r2, #0
	ldr r0, _08143E60 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08143E64 @ =0x0000046B
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r2, [r0]
	ldr r2, _08143E68 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08143E6C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08143E70 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0x14
	ldr r2, _08143E74 @ =0x00000671
	adds r1, r5, r2
	strb r0, [r1]
_08143E48:
	movs r1, #4
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08143E78
	movs r0, #1
	b _08143E7A
	.align 2, 0
_08143E5C: .4byte 0x000005A4
_08143E60: .4byte 0x0000046D
_08143E64: .4byte 0x0000046B
_08143E68: .4byte 0x030046B8
_08143E6C: .4byte 0x000003FF
_08143E70: .4byte 0x0203B400
_08143E74: .4byte 0x00000671
_08143E78:
	movs r0, #0
_08143E7A:
	cmp r0, #0
	bne _08143EEE
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _08143EEE
	ldr r3, _08143ED4 @ =0x00000484
	adds r0, r4, r3
	ldr r3, _08143ED8 @ =0x00000671
	adds r1, r5, r3
	ldr r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	ble _08143EE4
	ldr r1, _08143EDC @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08143EE4
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _08143ED4 @ =0x00000484
	adds r0, r4, r1
	str r2, [r0]
	ldr r2, _08143EE0 @ =0x0000046C
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	b _08143EEE
	.align 2, 0
_08143ED4: .4byte 0x00000484
_08143ED8: .4byte 0x00000671
_08143EDC: .4byte 0x0000046E
_08143EE0: .4byte 0x0000046C
_08143EE4:
	ldr r3, _08143EF4 @ =0x00000484
	adds r1, r4, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08143EEE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08143EF4: .4byte 0x00000484
