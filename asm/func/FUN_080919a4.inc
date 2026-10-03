	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _08091A08
	ldr r2, _08091A10 @ =0x00003F9C
	adds r0, r5, r2
	ldrb r0, [r0]
	ldr r3, _08091A14 @ =0x00003AEE
	adds r1, r5, r3
	ldrb r1, [r1]
	bl GetItemID
	ldr r2, _08091A18 @ =0x00000444
	adds r1, r4, r2
	movs r2, #0
	strh r0, [r1]
	ldr r3, _08091A1C @ =0x00000442
	adds r0, r4, r3
	strh r7, [r0]
	lsls r0, r6, #4
	subs r0, r0, r6
	lsls r0, r0, #2
	adds r3, #4
	adds r1, r4, r3
	strh r0, [r1]
	ldr r0, _08091A20 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _08091A24 @ =0x00000121
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	movs r0, #0x30
	strh r0, [r1]
	ldr r1, _08091A28 @ =0x00003FA2
	adds r0, r5, r1
	strh r2, [r0]
	ldr r2, _08091A2C @ =0x00000A95
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _08091A30 @ =0x00003AE4
	adds r0, r5, r3
	strb r1, [r0]
_08091A08:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091A10: .4byte 0x00003F9C
_08091A14: .4byte 0x00003AEE
_08091A18: .4byte 0x00000444
_08091A1C: .4byte 0x00000442
_08091A20: .4byte 0x0000095E
_08091A24: .4byte 0x00000121
_08091A28: .4byte 0x00003FA2
_08091A2C: .4byte 0x00000A95
_08091A30: .4byte 0x00003AE4
