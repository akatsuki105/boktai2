	push {r4, lr}
	adds r2, r0, #0
	ldr r3, _08096D64 @ =0x00003FE0
	adds r0, r2, r3
	adds r3, r0, r1
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	blt _08096D60
	ldr r4, _08096D68 @ =0x00003FDC
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _08096D6C
_08096D60:
	movs r0, #0
	b _08096D8A
	.align 2, 0
_08096D64: .4byte 0x00003FE0
_08096D68: .4byte 0x00003FDC
_08096D6C:
	ldr r0, _08096D84 @ =0x08DAA7B0
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r2, #6
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _08096D88
	movs r0, #0x11
	b _08096D8A
	.align 2, 0
_08096D84: .4byte 0x08DAA7B0
_08096D88:
	movs r0, #1
_08096D8A:
	pop {r4}
	pop {r1}
	bx r1
