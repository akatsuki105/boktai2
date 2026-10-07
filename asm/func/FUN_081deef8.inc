	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DEF54
	bl Sound_StopAll
	movs r0, #1
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl FUN_080a6180
	movs r2, #4
	ldr r1, _081DEF6C @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	bl MosaicFader_Stop
	ldr r1, _081DEF70 @ =0x030044D0
	movs r0, #0
	str r0, [r1]
	ldr r4, _081DEF74 @ =0x030046A0
	ldr r0, [r4]
	ldr r3, _081DEF78 @ =0x00000914
	adds r1, r0, r3
	ldrh r2, [r1]
	movs r6, #0
	ldrsh r0, [r1, r6]
	cmp r0, #0
	bge _081DEF3E
	movs r2, #0
_081DEF3E:
	strh r2, [r1]
	ldr r0, [r4]
	adds r1, r0, r3
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r0, #1
	ldr r2, _081DEF7C @ =0x0000270F
	cmp r0, r2
	ble _081DEF52
	adds r0, r2, #0
_081DEF52:
	strh r0, [r1]
_081DEF54:
	adds r0, r5, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DEF80
	adds r0, r5, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF00C
	.align 2, 0
_081DEF6C: .4byte 0x030044BC
_081DEF70: .4byte 0x030044D0
_081DEF74: .4byte 0x030046A0
_081DEF78: .4byte 0x00000914
_081DEF7C: .4byte 0x0000270F
_081DEF80:
	movs r7, #0
	movs r4, #0
	ldrh r6, [r5, #0x1a]
	cmp r7, r6
	bge _081DEFD0
	movs r1, #0xf0
	lsls r1, r1, #6
	mov ip, r1
_081DEF90:
	cmp r4, #0
	bge _081DEF9C
	ldr r1, _081DEF98 @ =0x0000FFFF
	b _081DEFA4
	.align 2, 0
_081DEF98: .4byte 0x0000FFFF
_081DEF9C:
	ldr r2, [r5, #0x44]
	lsls r1, r4, #1
	adds r1, r1, r2
	ldrh r1, [r1]
_081DEFA4:
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	adds r1, r3, #0
	mov r2, ip
	ands r1, r2
	movs r2, #0x80
	lsls r2, r2, #5
	cmp r1, r2
	bne _081DEFBA
	movs r1, #1
	b _081DEFBC
_081DEFBA:
	movs r1, #0
_081DEFBC:
	cmp r1, #0
	beq _081DEFCA
	movs r1, #0x3f
	ands r1, r3
	cmp r1, #0
	bne _081DEFCA
	adds r7, #1
_081DEFCA:
	adds r4, #1
	cmp r4, r6
	blt _081DEF90
_081DEFD0:
	cmp r7, r6
	bne _081DEFFC
	ldr r2, _081DEFF8 @ =FUN_081df014
	adds r0, r5, #0
	movs r1, #0xe
	bl Entity9A9F_SetState
	adds r1, r5, #0
	adds r1, #0x21
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_081ddc3c
	adds r0, r5, #0
	bl FUN_081ddcfc
	movs r0, #0
	b _081DF00C
	.align 2, 0
_081DEFF8: .4byte FUN_081df014
_081DEFFC:
	ldr r1, [r5, #0x34]
	cmp r1, #0x59
	bls _081DF00C
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r5, #0
	adds r1, #0x42
	strh r2, [r1]
_081DF00C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
