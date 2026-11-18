	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _08198B38 @ =0x00000185
	adds r0, r6, r1
	ldrb r0, [r0]
	ldrb r2, [r6, #6]
	adds r0, r0, r2
	strb r0, [r6, #6]
	ldr r1, _08198B3C @ =gSineTable
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r4, r6, r3
	ldr r2, [r4]
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x13
	adds r3, #6
	adds r1, r6, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r5, r0, #0
	muls r5, r1, r5
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	movs r1, #0x80
	bl Div
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r6, #0x1c]
	movs r3, #0x9f
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x80
	bl Div
	movs r3, #0x9b
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r6, #0x1e]
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x80
	bl Div
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r1, [r1]
	adds r1, r1, r0
	adds r1, r1, r5
	strh r1, [r6, #0x20]
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	cmp r0, #0x80
	ble _08198B30
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08198B40 @ =FUN_08198c28
	str r0, [r1]
_08198B30:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08198B38: .4byte 0x00000185
_08198B3C: .4byte gSineTable
_08198B40: .4byte FUN_08198c28
