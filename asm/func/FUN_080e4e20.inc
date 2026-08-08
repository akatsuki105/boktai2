	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080E4E48 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x16
	bne _080E4E9C
	ldr r2, _080E4E4C @ =0x00000256
	adds r0, r4, r2
	ldrh r5, [r0]
	adds r6, r4, #0
	adds r6, #8
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E4E50
	adds r0, #4
	b _080E4E5C
	.align 2, 0
_080E4E48: .4byte 0x000001DF
_080E4E4C: .4byte 0x00000256
_080E4E50:
	ldr r0, _080E4E70 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E4E5C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _080E4E74
	cmp r3, #2
	beq _080E4E78
	b _080E4E7C
	.align 2, 0
_080E4E70: .4byte 0x030046A4
_080E4E74:
	ldrb r0, [r6, #4]
	b _080E4E7A
_080E4E78:
	ldrb r0, [r6]
_080E4E7A:
	subs r2, r2, r0
_080E4E7C:
	ldr r0, _080E4E98 @ =0x00000472
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, r2
	beq _080E4E94
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r3, r4, r1
	subs r1, r2, r0
	ldrh r0, [r3]
	subs r0, r0, r1
	strh r0, [r3]
_080E4E94:
	strh r2, [r5]
	b _080E4F2E
	.align 2, 0
_080E4E98: .4byte 0x00000472
_080E4E9C:
	movs r1, #0x80
	lsls r1, r1, #7
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080E4EDC
	ldr r1, _080E4EC4 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #0x11
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _080E4EC8
	movs r0, #1
	b _080E4ECA
	.align 2, 0
_080E4EC4: .4byte 0x000001DF
_080E4EC8:
	movs r0, #0
_080E4ECA:
	cmp r0, #0
	beq _080E4EDC
	ldr r0, _080E4ED8 @ =0x03002BE0
	ldr r0, [r0]
	ldrh r1, [r0, #0x2e]
	b _080E4F28
	.align 2, 0
_080E4ED8: .4byte 0x03002BE0
_080E4EDC:
	ldr r1, _080E4EF8 @ =0x00000256
	adds r0, r4, r1
	ldrh r5, [r0]
	adds r6, r4, #0
	adds r6, #8
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E4EFC
	adds r0, #4
	b _080E4F08
	.align 2, 0
_080E4EF8: .4byte 0x00000256
_080E4EFC:
	ldr r0, _080E4F1C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E4F08:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080E4F20
	cmp r2, #2
	beq _080E4F24
	b _080E4F28
	.align 2, 0
_080E4F1C: .4byte 0x030046A4
_080E4F20:
	ldrb r0, [r6, #4]
	b _080E4F26
_080E4F24:
	ldrb r0, [r6]
_080E4F26:
	subs r1, r1, r0
_080E4F28:
	ldr r2, _080E4F40 @ =0x00000472
	adds r0, r4, r2
	strh r1, [r0]
_080E4F2E:
	movs r1, #0x20
	ldr r2, _080E4F44 @ =0x00000474
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E4F48
	movs r0, #1
	b _080E4F4A
	.align 2, 0
_080E4F40: .4byte 0x00000472
_080E4F44: .4byte 0x00000474
_080E4F48:
	movs r0, #0
_080E4F4A:
	cmp r0, #0
	bne _080E4F62
	ldr r1, _080E4F78 @ =0x00000472
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r4, #0xa]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0xa]
_080E4F62:
	ldr r1, _080E4F7C @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080E4F80
	ldr r2, [r4, #0x44]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _080E4F8A
	.align 2, 0
_080E4F78: .4byte 0x00000472
_080E4F7C: .4byte 0x0000025D
_080E4F80:
	ldr r2, [r4, #0x44]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_080E4F8A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
