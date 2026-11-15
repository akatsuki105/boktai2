	push {r4, r5, r6, lr}
	adds r5, r0, #0
	strh r1, [r5, #0x18]
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A14B6
	bl VM_GetValue
	b _080A14B8
_080A14B6:
	movs r0, #1
_080A14B8:
	strh r0, [r5, #0x1a]
	movs r0, #0x48
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A14D8
	ldr r4, _080A14D4 @ =0x03002B84
	bl VM_GetValue
	adds r1, r0, #0
	strh r1, [r4]
	b _080A14DC
	.align 2, 0
_080A14D4: .4byte 0x03002B84
_080A14D8:
	ldr r1, _080A14EC @ =0x03002B84
	strh r2, [r1]
_080A14DC:
	ldrh r1, [r5, #0x1a]
	cmp r1, #1
	beq _080A14FC
	cmp r1, #1
	bgt _080A14F0
	cmp r1, #0
	beq _080A14F6
	b _080A164A
	.align 2, 0
_080A14EC: .4byte 0x03002B84
_080A14F0:
	cmp r1, #2
	beq _080A1598
	b _080A164A
_080A14F6:
	strh r1, [r5, #0x2a]
	strh r1, [r5, #0x26]
	b _080A164A
_080A14FC:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1512
	bl VM_GetValue
	strh r0, [r5, #0x1c]
	bl VM_GetValue
	b _080A1516
_080A1512:
	movs r0, #3
	strh r0, [r5, #0x1c]
_080A1516:
	strh r0, [r5, #0x1e]
	movs r0, #0x74
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A1532
	bl VM_GetValue
	strh r0, [r5, #0x20]
	bl VM_GetValue
	adds r1, r0, #0
	b _080A1536
_080A1532:
	movs r1, #0x78
	strh r1, [r5, #0x20]
_080A1536:
	strh r1, [r5, #0x22]
	ldr r3, _080A1558 @ =0x030046B8
	ldr r1, [r3]
	adds r2, r1, #1
	ldr r4, _080A155C @ =0x000003FF
	ands r2, r4
	str r2, [r3]
	lsls r1, r2, #1
	ldr r6, _080A1560 @ =0x0203B400
	adds r1, r1, r6
	ldrb r1, [r1]
	strh r1, [r5, #0x2a]
	ldrh r1, [r5, #0x1e]
	cmp r1, #0
	bne _080A1564
	ldrh r1, [r5, #0x1c]
	b _080A157E
	.align 2, 0
_080A1558: .4byte 0x030046B8
_080A155C: .4byte 0x000003FF
_080A1560: .4byte 0x0203B400
_080A1564:
	adds r0, r2, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _080A1594 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r5, #0x1e]
	bl Mod
	adds r2, r0, #0
	ldrh r1, [r5, #0x1c]
	adds r1, r1, r2
_080A157E:
	lsls r1, r1, #4
	strh r1, [r5, #0x26]
	ldrh r1, [r5, #0x1c]
	lsls r1, r1, #4
	strh r1, [r5, #0x24]
	ldrh r1, [r5, #0x22]
	cmp r1, #0
	bne _080A1628
	ldrh r1, [r5, #0x20]
	b _080A1648
	.align 2, 0
_080A1594: .4byte 0x0203B400
_080A1598:
	movs r0, #0x64
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A15A6
	bl VM_GetValue
_080A15A6:
	strh r0, [r5, #0x2a]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A15BE
	bl VM_GetValue
	strh r0, [r5, #0x1c]
	bl VM_GetValue
	b _080A15C2
_080A15BE:
	movs r0, #3
	strh r0, [r5, #0x1c]
_080A15C2:
	strh r0, [r5, #0x1e]
	movs r0, #0x74
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A15DE
	bl VM_GetValue
	strh r0, [r5, #0x20]
	bl VM_GetValue
	adds r1, r0, #0
	b _080A15E2
_080A15DE:
	movs r1, #0x78
	strh r1, [r5, #0x20]
_080A15E2:
	strh r1, [r5, #0x22]
	ldrh r1, [r5, #0x1e]
	cmp r1, #0
	bne _080A15EE
	ldrh r1, [r5, #0x1c]
	b _080A160E
_080A15EE:
	ldr r2, _080A161C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A1620 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080A1624 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r5, #0x1e]
	bl Mod
	adds r2, r0, #0
	ldrh r1, [r5, #0x1c]
	adds r1, r1, r2
_080A160E:
	lsls r1, r1, #4
	strh r1, [r5, #0x26]
	ldrh r1, [r5, #0x22]
	cmp r1, #0
	bne _080A1628
	ldrh r1, [r5, #0x20]
	b _080A1648
	.align 2, 0
_080A161C: .4byte 0x030046B8
_080A1620: .4byte 0x000003FF
_080A1624: .4byte 0x0203B400
_080A1628:
	ldr r2, _080A1654 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A1658 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r6, _080A165C @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	ldrh r1, [r5, #0x22]
	bl Mod
	adds r2, r0, #0
	ldrh r1, [r5, #0x20]
	adds r1, r1, r2
_080A1648:
	strh r1, [r5, #0x2c]
_080A164A:
	ldr r1, _080A1660 @ =0x03000148
	str r5, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A1654: .4byte 0x030046B8
_080A1658: .4byte 0x000003FF
_080A165C: .4byte 0x0203B400
_080A1660: .4byte 0x03000148
