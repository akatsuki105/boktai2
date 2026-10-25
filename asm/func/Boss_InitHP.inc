	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0x92
	adds r0, r0, r4
	mov ip, r0
	strh r2, [r0]
	adds r2, r4, #0
	adds r2, #0x90
	strh r1, [r2]
	adds r0, r4, #0
	adds r0, #0x94
	strh r3, [r0]
	movs r3, #0
	ldrsh r1, [r2, r3]
	mov r5, ip
	ldrh r3, [r5]
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _08022B56
	strh r3, [r2]
_08022B56:
	mov r1, ip
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	beq _08022B74
	movs r5, #0
	ldrsh r0, [r2, r5]
	lsls r0, r0, #7
	movs r6, #0
	ldrsh r1, [r1, r6]
	bl Div
	adds r1, r4, #0
	adds r1, #0xdd
	b _08022B7A
_08022B74:
	adds r1, r4, #0
	adds r1, #0xdd
	movs r0, #0
_08022B7A:
	strb r0, [r1]
	ldr r2, _08022BAC @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x92
	movs r3, #0
	ldrsh r1, [r1, r3]
	str r1, [r0]
	ldr r0, [r2]
	movs r5, #0xae
	lsls r5, r5, #2
	adds r0, r0, r5
	adds r1, r4, #0
	adds r1, #0x90
	movs r6, #0
	ldrsh r1, [r1, r6]
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08022BAC: .4byte 0x030046A0
