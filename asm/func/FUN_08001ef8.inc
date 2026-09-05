	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _08001F40 @ =0x03004040
	ldr r0, _08001F44 @ =0x0000063C
	adds r2, r4, r0
	ldrh r0, [r2]
	lsls r0, r0, #6
	ldr r1, _08001F48 @ =0x0000063E
	adds r3, r4, r1
	ldrh r1, [r3]
	asrs r0, r1
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
	blt _08001F3A
	bl FUN_0822d00c
	movs r1, #0x40
	str r1, [r5]
	ldr r2, _08001F4C @ =0x03004494
	ldr r3, _08001F50 @ =0x00001084
	adds r1, r3, #0
	strh r1, [r2]
	strh r1, [r0]
	movs r0, #0
	strb r0, [r4, #0x1b]
_08001F3A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08001F40: .4byte 0x03004040
_08001F44: .4byte 0x0000063C
_08001F48: .4byte 0x0000063E
_08001F4C: .4byte 0x03004494
_08001F50: .4byte 0x00001084
