	push {r4, lr}
	ldr r4, _08237E48 @ =0x0400012A
	movs r0, #0
	strh r0, [r4]
	ldr r0, _08237E4C @ =0x04000128
	ldrh r0, [r0]
	adds r1, r0, #0
	adds r3, r1, #0
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08237E54
	ldr r1, _08237E50 @ =0x030046D4
	movs r0, #9
	rsbs r0, r0, #0
	str r0, [r1]
	b _08237E8E
	.align 2, 0
_08237E48: .4byte 0x0400012A
_08237E4C: .4byte 0x04000128
_08237E50: .4byte 0x030046D4
_08237E54:
	movs r0, #0x80
	ands r1, r0
	lsls r0, r1, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _08237E70
	ldr r1, _08237E6C @ =0x030046D4
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r1]
	b _08237E8E
	.align 2, 0
_08237E6C: .4byte 0x030046D4
_08237E70:
	movs r0, #4
	ands r3, r0
	cmp r3, #0
	bne _08237E84
	ldr r0, _08237E80 @ =0x030046CC
	str r2, [r0]
	b _08237E8C
	.align 2, 0
_08237E80: .4byte 0x030046CC
_08237E84:
	ldr r1, _08237E94 @ =0x030046CC
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
_08237E8C:
	strh r2, [r4]
_08237E8E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08237E94: .4byte 0x030046CC
