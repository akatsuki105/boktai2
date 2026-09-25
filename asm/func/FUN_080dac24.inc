	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r1, #0
	adds r6, r7, #0
	adds r6, #0x44
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bgt _080DAC4A
	movs r0, #0x14
	strh r0, [r6]
	adds r2, r7, #0
	adds r2, #0x40
	ldrh r1, [r2]
	subs r0, #0x19
	ands r0, r1
	strh r0, [r2]
	b _080DAC94
_080DAC4A:
	cmp r0, #0xa
	ble _080DAC8E
	ldr r0, _080DACA0 @ =0x0203B400
	mov r8, r0
	ldr r4, _080DACA4 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080DACA8 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x28
	bl Mod
	ldrh r1, [r7, #0x1c]
	subs r1, #0x14
	adds r1, r1, r0
	strh r1, [r7, #0x1c]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x28
	bl Mod
	ldrh r1, [r7, #0x20]
	subs r1, #0x14
	adds r1, r1, r0
	strh r1, [r7, #0x20]
_080DAC8E:
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
_080DAC94:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DACA0: .4byte 0x0203B400
_080DACA4: .4byte 0x030046B8
_080DACA8: .4byte 0x000003FF
