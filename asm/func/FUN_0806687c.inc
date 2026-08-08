	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _08066918 @ =0x0000038E
	adds r3, r4, r0
	ldrb r0, [r3]
	ldr r1, _0806691C @ =0x030046A0
	ldr r2, [r1]
	lsls r0, r0, #2
	adds r1, r0, r2
	movs r6, #0xb2
	lsls r6, r6, #2
	adds r0, r1, r6
	ldr r5, [r0]
	cmp r5, #0
	bne _080668CC
	movs r7, #0xb0
	lsls r7, r7, #2
	adds r0, r1, r7
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	ldr r0, _08066920 @ =0x00008C9F
	cmp r1, r0
	ble _080668CC
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r1, r7, #0
	adds r0, r0, r1
	str r5, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, r0, r6
	ldr r1, _08066924 @ =0x0002BF20
	str r1, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08060e90
_080668CC:
	movs r1, #0x80
	lsls r1, r1, #0x10
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08066910
	ldr r5, _08066928 @ =0x0000038F
	adds r3, r4, r5
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xe
	bls _08066910
	movs r7, #0xda
	lsls r7, r7, #2
	adds r2, r4, r7
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	subs r5, #0x25
	adds r1, r4, r5
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	blo _0806690C
	strh r1, [r2]
_0806690C:
	movs r0, #0
	strb r0, [r3]
_08066910:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08066918: .4byte 0x0000038E
_0806691C: .4byte 0x030046A0
_08066920: .4byte 0x00008C9F
_08066924: .4byte 0x0002BF20
_08066928: .4byte 0x0000038F
