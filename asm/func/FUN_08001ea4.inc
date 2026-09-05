	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _08001EE4 @ =0x03004040
	ldr r0, _08001EE8 @ =0x0000063C
	adds r2, r4, r0
	ldrh r1, [r2]
	lsls r1, r1, #6
	adds r0, #2
	adds r3, r4, r0
	ldrh r0, [r3]
	asrs r1, r0
	movs r0, #0x40
	subs r0, r0, r1
	str r0, [r5]
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #1
	ldrh r3, [r3]
	lsls r0, r3
	cmp r1, r0
	blt _08001EF0
	movs r0, #0
	str r0, [r5]
	ldrb r0, [r4, #0x1b]
	cmp r0, #3
	bne _08001EEC
	movs r0, #0
	b _08001EEE
	.align 2, 0
_08001EE4: .4byte 0x03004040
_08001EE8: .4byte 0x0000063C
_08001EEC:
	movs r0, #6
_08001EEE:
	strb r0, [r4, #0x1b]
_08001EF0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
