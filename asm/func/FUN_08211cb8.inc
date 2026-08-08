	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r0, _08211D00 @ =0x00000322
	adds r2, r4, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bne _08211CD2
	ldr r1, _08211D04 @ =0x03004464
	ldr r5, _08211D08 @ =0x00001084
	adds r0, r5, #0
	strh r0, [r1]
_08211CD2:
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r3, #4]
	cmp r0, r1
	blt _08211D10
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08211bac
	movs r0, #0xc8
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, _08211D0C @ =0x0300445C
	movs r0, #0
	str r0, [r1]
	b _08211D22
	.align 2, 0
_08211D00: .4byte 0x00000322
_08211D04: .4byte 0x03004464
_08211D08: .4byte 0x00001084
_08211D0C: .4byte 0x0300445C
_08211D10:
	ldr r4, _08211D28 @ =0x0300445C
	movs r3, #0
	ldrsh r0, [r2, r3]
	lsls r0, r0, #6
	bl Div
	movs r1, #0x40
	subs r1, r1, r0
	str r1, [r4]
_08211D22:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08211D28: .4byte 0x0300445C
