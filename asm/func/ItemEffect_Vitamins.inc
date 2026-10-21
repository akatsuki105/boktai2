	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r2, #0
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r6, [r0]
	cmp r6, #0
	beq _08091ABC
	cmp r1, #3
	bgt _08091A58
	ldr r2, _08091A54 @ =0x00003F9E
	adds r0, r5, r2
	strb r1, [r0]
	b _08091A7A
	.align 2, 0
_08091A54: .4byte 0x00003F9E
_08091A58:
	ldr r2, _08091AC4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08091AC8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08091ACC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #4
	bl Mod
	ldr r2, _08091AD0 @ =0x00003F9E
	adds r1, r5, r2
	strb r0, [r1]
_08091A7A:
	ldr r1, _08091AD4 @ =0x00003F9F
	adds r0, r5, r1
	strb r4, [r0]
	ldrb r2, [r0]
	subs r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r1, _08091AD8 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r1, r0, r1
	movs r0, #0x18
	ldrsh r4, [r1, r0]
	movs r0, #0x20
	ldrsh r3, [r1, r0]
	adds r0, r4, r3
	adds r0, r0, r2
	cmp r0, #0x63
	ble _08091AA6
	movs r0, #0x63
	subs r0, r0, r3
	subs r2, r0, r4
_08091AA6:
	ldrh r0, [r1, #0x20]
	adds r0, r0, r2
	strh r0, [r1, #0x20]
	adds r0, r6, #0
	bl FUN_080612bc
	adds r0, r5, #0
	movs r1, #5
	movs r2, #3
	bl FUN_0808b604
_08091ABC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08091AC4: .4byte 0x030046B8
_08091AC8: .4byte 0x000003FF
_08091ACC: .4byte 0x0203B400
_08091AD0: .4byte 0x00003F9E
_08091AD4: .4byte 0x00003F9F
_08091AD8: .4byte 0x030046A0
