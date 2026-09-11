	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	bl FUN_0801200c
	ldr r0, [r6, #0x18]
	cmp r0, #0
	beq _08012B4C
	ldr r0, _08012AA4 @ =0x00000CA6
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08012A80
	bl FUN_0823b2d0
	ldr r2, _08012AA8 @ =0x00000CC8
	adds r1, r6, r2
	str r0, [r1]
_08012A80:
	ldr r3, _08012AAC @ =0x00000CA4
	adds r2, r6, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bne _08012AB4
	ldr r4, _08012AB0 @ =0x00000CA5
	adds r1, r6, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x3e
	ble _08012AEE
	movs r0, #0x3f
	b _08012AE8
	.align 2, 0
_08012AA4: .4byte 0x00000CA6
_08012AA8: .4byte 0x00000CC8
_08012AAC: .4byte 0x00000CA4
_08012AB0: .4byte 0x00000CA5
_08012AB4:
	cmp r0, #1
	bne _08012AD0
	ldr r0, _08012ACC @ =0x00000CA5
	adds r1, r6, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _08012AEE
	movs r0, #0
	b _08012AE8
	.align 2, 0
_08012ACC: .4byte 0x00000CA5
_08012AD0:
	cmp r0, #2
	bne _08012AEE
	ldr r3, _08012B58 @ =0x00000CA5
	adds r1, r6, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1f
	ble _08012AEE
	movs r0, #0x20
_08012AE8:
	strb r0, [r1]
	movs r0, #0xff
	strb r0, [r2]
_08012AEE:
	ldr r4, _08012B5C @ =0x00000CA4
	adds r0, r6, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08012B1E
	ldr r0, _08012B60 @ =0x03003584
	ldr r2, [r0]
	ldr r0, _08012B64 @ =0x00004C60
	adds r1, r2, r0
	ldr r3, _08012B68 @ =0x00004CA0
	adds r2, r2, r3
	adds r4, #4
	adds r0, r6, r4
	subs r4, #3
	adds r3, r6, r4
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	movs r4, #6
	str r4, [sp]
	bl rgb555_08237468
_08012B1E:
	adds r4, r6, #0
	adds r4, #0x24
	movs r5, #0
	ldr r7, _08012B6C @ =0x085AA81C
_08012B26:
	ldrb r0, [r4, #1]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
	adds r0, r4, #0
	bl FUN_080118d4
	adds r5, #1
	adds r4, #0xc8
	cmp r5, #0xf
	ble _08012B26
	ldr r0, [r6, #0x1c]
	adds r0, #1
	str r0, [r6, #0x1c]
_08012B4C:
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08012B58: .4byte 0x00000CA5
_08012B5C: .4byte 0x00000CA4
_08012B60: .4byte 0x03003584
_08012B64: .4byte 0x00004C60
_08012B68: .4byte 0x00004CA0
_08012B6C: .4byte 0x085AA81C
