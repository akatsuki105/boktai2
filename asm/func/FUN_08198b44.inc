	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _08198C18 @ =0x00000185
	adds r0, r6, r1
	ldrb r0, [r0]
	ldrb r2, [r6, #6]
	adds r0, r0, r2
	strb r0, [r6, #6]
	ldr r2, _08198C1C @ =gSineTable
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r6, r0
	ldr r3, [r4]
	subs r0, #0x7c
	subs r0, r0, r3
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x13
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r5, r0, #0
	muls r5, r1, r5
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	movs r1, #0x80
	bl Div
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	adds r1, r1, r5
	strh r1, [r6, #0x1c]
	movs r1, #0x9f
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x80
	bl Div
	movs r2, #0x9b
	lsls r2, r2, #1
	adds r1, r6, r2
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
	movs r2, #0x9c
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r6, #0x20]
	ldr r0, [r4]
	subs r0, #1
	str r0, [r4]
	cmp r0, #0
	bne _08198C10
	movs r0, #0x80
	strb r0, [r6, #6]
	movs r0, #1
	subs r2, #0x22
	adds r1, r6, r2
	strb r0, [r1]
	adds r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	ldr r1, _08198C20 @ =0x00000111
	adds r2, r6, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r0, _08198C24 @ =FUN_08199c38
	str r0, [r1]
_08198C10:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08198C18: .4byte 0x00000185
_08198C1C: .4byte gSineTable
_08198C20: .4byte 0x00000111
_08198C24: .4byte FUN_08199c38
