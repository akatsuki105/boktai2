	push {r4, r5, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq _08094CAE
	cmp r0, #0
	ble _08094C82
	movs r0, #0x2b
	b _08094C84
_08094C82:
	movs r0, #0x2d
_08094C84:
	strb r0, [r5]
	movs r0, #8
	ldrsh r4, [r2, r0]
	cmp r4, #0
	bge _08094C90
	rsbs r4, r4, #0
_08094C90:
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r4, r1
	adds r0, #0x30
	strb r0, [r5, #1]
	adds r1, #0x30
	strb r1, [r5, #2]
	movs r0, #0
	strb r0, [r5, #3]
	b _08094CD4
_08094CAE:
	ldrb r0, [r2, #0x18]
	cmp r0, #0
	bne _08094CC4
	ldrb r0, [r2, #0x1c]
	cmp r0, #0
	bne _08094CC4
	adds r0, r2, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	beq _08094CD2
_08094CC4:
	movs r0, #0x53
	strb r0, [r5]
	movs r0, #0x50
	strb r0, [r5, #1]
	movs r0, #0
	strb r0, [r5, #2]
	b _08094CD4
_08094CD2:
	strb r0, [r5]
_08094CD4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
