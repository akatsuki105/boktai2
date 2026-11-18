	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08195B9C @ =0x00000C6C
	adds r5, r4, r0
	ldr r0, [r5]
	lsls r0, r0, #3
	ldr r1, _08195BA0 @ =0x00000CC2
	adds r6, r4, r1
	movs r1, #0
	ldrsb r1, [r6, r1]
	bl Div
	adds r0, #0x10
	ldr r3, _08195BA4 @ =0x00000C34
	adds r2, r4, r3
	strb r0, [r2]
	ldr r0, [r5]
	subs r0, #1
	str r0, [r5]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne _08195B6E
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, _08195BA8 @ =FUN_08195bb4
	str r1, [r0]
	movs r0, #0
	ldrsb r0, [r6, r0]
	str r0, [r5]
_08195B6E:
	ldr r3, _08195BAC @ =0x00000C36
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0xa
	subs r3, #1
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	orrs r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	orrs r0, r1
	ldr r2, _08195BB0 @ =0x00000CA2
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08195B9C: .4byte 0x00000C6C
_08195BA0: .4byte 0x00000CC2
_08195BA4: .4byte 0x00000C34
_08195BA8: .4byte FUN_08195bb4
_08195BAC: .4byte 0x00000C36
_08195BB0: .4byte 0x00000CA2
