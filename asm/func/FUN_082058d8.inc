	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x20
	adds r0, r4, #0
	bl FUN_082056a0
	movs r0, #2
	ldrh r1, [r4, #0xe]
	ands r0, r1
	cmp r0, #0
	beq _0820590C
	ldr r2, _08205950 @ =0x00000434
	adds r0, r6, r2
	ldr r2, [r0]
	cmp r2, #0
	beq _0820590C
	movs r0, #0x80
	lsls r0, r0, #3
	orrs r1, r0
	strh r1, [r4, #0xe]
	ldrh r0, [r2, #2]
	adds r1, r4, #0
	adds r1, #0x66
	strh r0, [r1]
_0820590C:
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_080411d8
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	ldrh r0, [r1, #2]
	adds r0, #0xa0
	strh r0, [r1, #2]
	movs r1, #1
	ldrh r0, [r4, #0xe]
	ands r0, r1
	cmp r0, #0
	bne _08205986
	ldrb r1, [r5, #5]
	movs r2, #3
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _08205972
	subs r3, #0x30
	adds r0, r4, r3
	ldrh r0, [r0]
	ands r2, r0
	cmp r2, #0
	beq _08205948
	cmp r2, #3
	bne _08205954
_08205948:
	ldrh r0, [r5, #6]
	subs r0, #8
	b _08205958
	.align 2, 0
_08205950: .4byte 0x00000434
_08205954:
	ldrh r0, [r5, #6]
	adds r0, #8
_08205958:
	strh r0, [r5, #6]
	movs r2, #6
	ldrsh r0, [r5, r2]
	cmp r0, #0x40
	ble _08205968
	movs r0, #0x40
	strh r0, [r5, #6]
	b _08205972
_08205968:
	movs r2, #0x40
	rsbs r2, r2, #0
	cmp r0, r2
	bge _08205972
	strh r2, [r5, #6]
_08205972:
	adds r0, r1, #1
	strb r0, [r5, #5]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	ldrh r0, [r5, #6]
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
_08205986:
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
