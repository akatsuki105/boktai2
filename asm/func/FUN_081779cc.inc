	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r3, r2, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #2
	ldr r2, _081779F8 @ =0x00000755
	adds r0, r0, r2
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081779FC
	movs r0, #1
	b _081779FE
	.align 2, 0
_081779F8: .4byte 0x00000755
_081779FC:
	movs r0, #0
_081779FE:
	cmp r0, #0
	beq _08177A40
	lsls r2, r3, #3
	adds r0, r2, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #1
	ldr r6, _08177A20 @ =0x00000755
	adds r0, r0, r6
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08177A24
	movs r0, #1
	b _08177A26
	.align 2, 0
_08177A20: .4byte 0x00000755
_08177A24:
	movs r0, #0
_08177A26:
	cmp r0, #0
	bne _08177A40
	adds r0, r2, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r4, r0
	ldr r1, _08177A48 @ =0x0000076C
	adds r0, r0, r1
	ldr r1, [r5]
	ldr r2, [r5, #4]
	str r1, [r0]
	str r2, [r0, #4]
_08177A40:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08177A48: .4byte 0x0000076C
