	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _08060F44
	ldr r0, _08060F40 @ =0x030046A0
	ldr r0, [r0]
	adds r1, #4
	adds r2, r5, r1
	adds r1, r0, #0
	adds r1, #0x18
	movs r4, #0x63
	movs r3, #3
_08060F20:
	ldrh r0, [r1, #8]
	ldrh r5, [r1]
	adds r0, r0, r5
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x63
	bls _08060F32
	strh r4, [r2]
_08060F32:
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _08060F20
	b _08060F9A
	.align 2, 0
_08060F40: .4byte 0x030046A0
_08060F44:
	ldr r7, _08060FA0 @ =0x030046A0
	ldr r0, [r7]
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r0, #0xa
	cmp r0, #0x63
	ble _08060F56
	movs r0, #0x63
_08060F56:
	subs r0, #1
	lsls r4, r0, #1
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #4
	bl Div
	lsls r1, r0, #2
	subs r4, r4, r1
	adds r6, r0, #0
	adds r6, #0xa
	movs r0, #0xd7
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r2, [r7]
	movs r5, #0x63
	movs r3, #3
_08060F78:
	ldrh r0, [r2, #0x20]
	adds r0, r0, r6
	strh r0, [r1]
	cmp r4, #0
	ble _08060F88
	adds r0, #1
	strh r0, [r1]
	subs r4, #1
_08060F88:
	ldrh r0, [r1]
	cmp r0, #0x63
	bls _08060F90
	strh r5, [r1]
_08060F90:
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _08060F78
_08060F9A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08060FA0: .4byte 0x030046A0
