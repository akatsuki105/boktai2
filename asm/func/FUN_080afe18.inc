	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r1, _080AFE38 @ =0x00000692
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080AFE3C
	movs r4, #0xf0
	lsls r4, r4, #3
	movs r6, #0xf0
	lsls r6, r6, #1
	b _080AFE5C
	.align 2, 0
_080AFE38: .4byte 0x00000692
_080AFE3C:
	cmp r0, #1
	bne _080AFE46
	movs r4, #0xf8
	lsls r4, r4, #4
	b _080AFE58
_080AFE46:
	cmp r0, #2
	bne _080AFE54
	movs r4, #0xc8
	lsls r4, r4, #4
	movs r6, #0xf0
	lsls r6, r6, #1
	b _080AFE5C
_080AFE54:
	movs r4, #0x90
	lsls r4, r4, #3
_080AFE58:
	movs r6, #0xc8
	lsls r6, r6, #1
_080AFE5C:
	ldr r2, _080AFE7C @ =0x0000067C
	adds r1, r5, r2
	ldrh r2, [r1]
	ldr r3, _080AFE80 @ =0xFFFFF000
	adds r0, r2, r3
	subs r7, r4, r0
	ldr r3, _080AFE84 @ =0x00000FFF
	ands r7, r3
	ldr r0, _080AFE88 @ =0x000007FF
	cmp r7, r0
	bgt _080AFE8C
	cmp r7, #0x2f
	ble _080AFE94
	adds r0, r2, #0
	adds r0, #0x30
	b _080AFE9E
	.align 2, 0
_080AFE7C: .4byte 0x0000067C
_080AFE80: .4byte 0xFFFFF000
_080AFE84: .4byte 0x00000FFF
_080AFE88: .4byte 0x000007FF
_080AFE8C:
	movs r0, #0xfd
	lsls r0, r0, #4
	cmp r7, r0
	ble _080AFE98
_080AFE94:
	strh r4, [r1]
	b _080AFEA2
_080AFE98:
	movs r4, #0xfd
	lsls r4, r4, #4
	adds r0, r2, r4
_080AFE9E:
	ands r0, r3
	strh r0, [r1]
_080AFEA2:
	ldr r1, _080AFEE0 @ =0x0000067C
	adds r0, r5, r1
	ldrh r0, [r0]
	lsrs r4, r0, #4
	ldr r3, _080AFEE4 @ =0x00000684
	adds r2, r5, r3
	ldrh r1, [r2]
	subs r0, r6, r1
	mov ip, r0
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r6
	asrs r0, r0, #3
	strh r0, [r2]
	ldrh r3, [r2]
	ldr r2, _080AFEE8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r6, r2, #0
	cmp r0, #0
	blt _080AFEEC
	asrs r0, r0, #0xc
	b _080AFEF2
	.align 2, 0
_080AFEE0: .4byte 0x0000067C
_080AFEE4: .4byte 0x00000684
_080AFEE8: .4byte 0x085B0A08
_080AFEEC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AFEF2:
	mov r8, r0
	ldr r2, _080AFF24 @ =0x0000068C
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	muls r0, r2, r0
	cmp r0, #0
	blt _080AFF28
	asrs r2, r0, #0x18
	b _080AFF2E
	.align 2, 0
_080AFF24: .4byte 0x0000068C
_080AFF28:
	rsbs r0, r0, #0
	asrs r0, r0, #0x18
	rsbs r2, r0, #0
_080AFF2E:
	movs r3, #0xce
	lsls r3, r3, #3
	adds r0, r5, r3
	ldrh r0, [r0]
	add r0, r8
	adds r0, r0, r2
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r1, r5, r2
	strh r0, [r1]
	adds r3, #0x14
	adds r0, r5, r3
	ldrh r1, [r0]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080AFF5E
	asrs r0, r0, #0xc
	b _080AFF64
_080AFF5E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AFF64:
	mov r8, r0
	ldr r3, _080AFF90 @ =0x0000068C
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r2, [r0, r3]
	ands r4, r1
	lsls r0, r4, #1
	adds r0, r0, r6
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #5
	muls r0, r2, r0
	cmp r0, #0
	blt _080AFF94
	asrs r1, r0, #0x18
	b _080AFF9A
	.align 2, 0
_080AFF90: .4byte 0x0000068C
_080AFF94:
	rsbs r0, r0, #0
	asrs r0, r0, #0x18
	rsbs r1, r0, #0
_080AFF9A:
	ldr r2, _080AFFD4 @ =0x00000674
	adds r0, r5, r2
	ldrh r0, [r0]
	add r0, r8
	adds r0, r0, r1
	ldr r3, _080AFFD8 @ =0x0000061C
	adds r1, r5, r3
	strh r0, [r1]
	cmp r7, #0
	bne _080AFFC8
	mov r0, ip
	cmp r0, #0
	bge _080AFFB6
	rsbs r0, r0, #0
_080AFFB6:
	cmp r0, #0x1f
	bgt _080AFFC8
	movs r0, #0xf4
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #5
	bl FUN_080af374
_080AFFC8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AFFD4: .4byte 0x00000674
_080AFFD8: .4byte 0x0000061C
