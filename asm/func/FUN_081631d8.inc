	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r2, _081631F8 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081631FC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081631FE
	.align 2, 0
_081631F8: .4byte 0x0000046D
_081631FC:
	movs r0, #0
_081631FE:
	cmp r0, #0
	beq _08163222
	ldr r2, _08163234 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08163238 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0816323C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x40
	ldr r2, _08163240 @ =0x0000068C
	adds r1, r3, r2
	strh r0, [r1]
_08163222:
	ldr r0, _08163240 @ =0x0000068C
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r5, r0, #0
	cmp r5, #0
	beq _08163244
	subs r0, #1
	strh r0, [r1]
	b _08163276
	.align 2, 0
_08163234: .4byte 0x030046B8
_08163238: .4byte 0x000003FF
_0816323C: .4byte 0x0203B400
_08163240: .4byte 0x0000068C
_08163244:
	ldr r1, _0816327C @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08163276
	ldr r3, _08163280 @ =FUN_08162fa8
	movs r2, #0x21
	ldr r0, _08163284 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08163288 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
_08163276:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0816327C: .4byte 0x0000046E
_08163280: .4byte FUN_08162fa8
_08163284: .4byte 0x0000046D
_08163288: .4byte 0x0000046B
