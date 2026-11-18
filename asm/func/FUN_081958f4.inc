	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0819595C @ =0x00000C6C
	adds r6, r5, r0
	ldr r0, [r6]
	lsls r0, r0, #4
	ldr r1, _08195960 @ =0x00000CC2
	adds r4, r5, r1
	movs r1, #0
	ldrsb r1, [r4, r1]
	bl Div
	ldr r2, _08195964 @ =0x00000C34
	adds r3, r5, r2
	strb r0, [r3]
	ldr r0, [r6]
	movs r2, #0
	ldrsb r2, [r4, r2]
	adds r1, r0, #0
	adds r0, #1
	str r0, [r6]
	cmp r1, r2
	bne _08195930
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, _08195968 @ =FUN_08195970
	str r1, [r0]
	movs r0, #0
	str r0, [r6]
_08195930:
	ldr r2, _0819596C @ =0x00000C36
	adds r0, r5, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0xa
	subs r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	orrs r1, r0
	movs r0, #0
	ldrsb r0, [r3, r0]
	orrs r0, r1
	adds r2, #0x6d
	adds r1, r5, r2
	strh r0, [r1]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0819595C: .4byte 0x00000C6C
_08195960: .4byte 0x00000CC2
_08195964: .4byte 0x00000C34
_08195968: .4byte FUN_08195970
_0819596C: .4byte 0x00000C36
