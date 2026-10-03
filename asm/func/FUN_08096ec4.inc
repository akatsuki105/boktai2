	push {lr}
	adds r1, r0, #0
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r1, r2
	ldr r0, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #5
	bne _08096EE0
_08096EDC:
	movs r0, #0
	b _08096F8A
_08096EE0:
	ldr r2, _08096F14 @ =0x00003AEE
	adds r0, r1, r2
	ldrb r2, [r0]
	ldr r3, _08096F18 @ =0x00003FE0
	adds r0, r1, r3
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _08096F44
	ldr r2, _08096F1C @ =0x00003AEB
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0x10
	bne _08096F24
	ldr r0, _08096F20 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5c
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _08096F24
	movs r0, #4
	b _08096F8A
	.align 2, 0
_08096F14: .4byte 0x00003AEE
_08096F18: .4byte 0x00003FE0
_08096F1C: .4byte 0x00003AEB
_08096F20: .4byte 0x030046A0
_08096F24:
	ldr r2, _08096F3C @ =0x00003AEB
	adds r0, r1, r2
	ldr r3, _08096F40 @ =0x00003FE0
	adds r1, r1, r3
	ldrb r0, [r0]
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _08096F88
	b _08096EDC
	.align 2, 0
_08096F3C: .4byte 0x00003AEB
_08096F40: .4byte 0x00003FE0
_08096F44:
	ldr r0, _08096F54 @ =0x00003AEB
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0x14
	bne _08096F58
	movs r0, #2
	b _08096F8A
	.align 2, 0
_08096F54: .4byte 0x00003AEB
_08096F58:
	cmp r0, #0x10
	bne _08096F60
	movs r0, #1
	b _08096F8A
_08096F60:
	cmp r0, r2
	bne _08096F88
	ldr r0, _08096F7C @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5c
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r2, r0
	bne _08096F80
	movs r0, #0x10
	strb r0, [r1]
	movs r0, #4
	b _08096F8A
	.align 2, 0
_08096F7C: .4byte 0x030046A0
_08096F80:
	movs r0, #0x10
	strb r0, [r1]
	movs r0, #1
	b _08096F8A
_08096F88:
	movs r0, #3
_08096F8A:
	pop {r1}
	bx r1
	.align 2, 0
