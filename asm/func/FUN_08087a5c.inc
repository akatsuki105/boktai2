	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldr r0, _08087A84 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08087A76
	b _08087B96
_08087A76:
	ldr r0, _08087A88 @ =0x00000396
	adds r2, r6, r0
	ldrh r0, [r2]
	cmp r0, #0x3f
	bhi _08087A8C
	movs r7, #0x10
	b _08087A9C
	.align 2, 0
_08087A84: .4byte 0x030047A4
_08087A88: .4byte 0x00000396
_08087A8C:
	ldr r0, _08087B4C @ =0x0000032A
	adds r1, r6, r0
	movs r0, #2
	strh r0, [r1]
	ldrh r0, [r2]
	lsrs r0, r0, #2
	adds r7, r0, #0
	adds r7, #0x10
_08087A9C:
	ldr r1, _08087B50 @ =0x0203B400
	mov sb, r1
	ldr r5, _08087B54 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r2, _08087B58 @ =0x000003FF
	mov r8, r2
	ands r0, r2
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	adds r1, r7, #0
	bl Mod
	asrs r4, r7, #1
	subs r0, r0, r4
	ldr r2, _08087B5C @ =0x0000031E
	adds r1, r6, r2
	strh r0, [r1]
	ldr r0, [r5]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	adds r1, r7, #0
	bl Mod
	subs r0, r0, r4
	ldr r2, _08087B60 @ =0x00000322
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0xe7
	lsls r0, r0, #2
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _08087B64 @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _08087B1C
	ldr r0, [r5]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08087B50 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08087B1C
	ldr r0, _08087B68 @ =0x000002B9
	bl PlaySound_082406e0
_08087B1C:
	ldr r0, _08087B6C @ =0x00000396
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bls _08087B96
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08087B70 @ =0x000001F5
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _08087B78
	ldr r0, _08087B74 @ =0x0000039E
	adds r1, r6, r0
	movs r0, #2
	b _08087B7E
	.align 2, 0
_08087B4C: .4byte 0x0000032A
_08087B50: .4byte 0x0203B400
_08087B54: .4byte 0x030046B8
_08087B58: .4byte 0x000003FF
_08087B5C: .4byte 0x0000031E
_08087B60: .4byte 0x00000322
_08087B64: .4byte 0x0000FFFF
_08087B68: .4byte 0x000002B9
_08087B6C: .4byte 0x00000396
_08087B70: .4byte 0x000001F5
_08087B74: .4byte 0x0000039E
_08087B78:
	ldr r2, _08087BA4 @ =0x0000039E
	adds r1, r6, r2
	movs r0, #1
_08087B7E:
	strh r0, [r1]
	adds r0, r6, #0
	movs r1, #2
	bl Coffin_SetState
	ldr r1, _08087BA8 @ =0x0000039A
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
_08087B96:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08087BA4: .4byte 0x0000039E
_08087BA8: .4byte 0x0000039A
