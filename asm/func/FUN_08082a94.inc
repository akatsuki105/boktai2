	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x13
	beq _08082AF4
	ldr r0, _08082B50 @ =0x00000366
	bl sound_08240740
	ldr r0, _08082B54 @ =0x00000369
	bl PlaySound_082406e0
	movs r3, #0x99
	lsls r3, r3, #4
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	ldr r6, _08082B58 @ =0x0000098C
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldr r3, _08082B5C @ =0x00000474
	adds r2, r5, r3
	str r2, [sp]
	ldr r6, _08082B60 @ =0x00000472
	adds r2, r5, r6
	movs r3, #0
	ldrsh r2, [r2, r3]
	str r2, [sp, #4]
	movs r2, #0x96
	lsls r2, r2, #1
	str r2, [sp, #8]
	adds r2, #0x50
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #3
	bl FUN_080da9c4
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_08080e0c
_08082AF4:
	ldr r6, _08082B64 @ =0x0000037E
	adds r0, r5, r6
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08082B86
	ldr r0, _08082B68 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0x2c
	ldrsh r1, [r5, r3]
	subs r0, r0, r1
	movs r6, #0x30
	ldrsh r1, [r2, r6]
	movs r3, #0x30
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	movs r6, #0xba
	lsls r6, r6, #2
	adds r3, r5, r6
	ldrb r2, [r3]
	cmp r1, r2
	beq _08082B74
	adds r0, r2, #0
	subs r0, #8
	subs r0, r1, r0
	movs r1, #7
	ands r0, r1
	cmp r0, #4
	ble _08082B6C
	adds r0, r2, #7
	b _08082B70
	.align 2, 0
_08082B50: .4byte 0x00000366
_08082B54: .4byte 0x00000369
_08082B58: .4byte 0x0000098C
_08082B5C: .4byte 0x00000474
_08082B60: .4byte 0x00000472
_08082B64: .4byte 0x0000037E
_08082B68: .4byte 0x03002BE0
_08082B6C:
	adds r0, r2, #1
	movs r1, #7
_08082B70:
	ands r0, r1
	strb r0, [r3]
_08082B74:
	adds r0, r5, #0
	bl LinkPlayer_SetAnimFacing
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
_08082B86:
	ldr r0, _08082BD4 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r3, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _08082BCC
	ldr r1, _08082BD8 @ =0x0000098C
	adds r4, r5, r1
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	movs r6, #0x99
	lsls r6, r6, #4
	adds r2, r5, r6
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	movs r3, #0x96
	lsls r3, r3, #1
	str r3, [sp, #8]
	adds r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08080e0c
_08082BCC:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08082BD4: .4byte 0x0000037E
_08082BD8: .4byte 0x0000098C
