	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r0, _080F570C @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F5710
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F5712
	.align 2, 0
_080F570C: .4byte 0x0000046D
_080F5710:
	movs r0, #0
_080F5712:
	cmp r0, #0
	bne _080F5718
	b _080F58EA
_080F5718:
	ldrb r0, [r7, #5]
	adds r0, #0x20
	asrs r0, r0, #6
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	strb r0, [r7, #5]
	adds r0, r7, #0
	movs r1, #6
	bl FUN_080ef86c
	movs r0, #2
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r2, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	bne _080F582A
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080F5768
	ldr r3, _080F5764 @ =0x000001DF
	adds r0, r7, r3
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #3
	movs r2, #2
	bl FUN_080e5718
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	b _080F5778
	.align 2, 0
_080F5764: .4byte 0x000001DF
_080F5768:
	ldr r5, _080F5798 @ =0x000001DF
	adds r0, r7, r5
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #3
	movs r2, #0
	bl FUN_080e5718
_080F5778:
	movs r0, #2
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	ldr r1, _080F5798 @ =0x000001DF
	adds r0, r7, r1
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #0x14
	bhi _080F582A
	lsls r0, r0, #2
	ldr r1, _080F579C @ =_080F57A0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F5798: .4byte 0x000001DF
_080F579C: .4byte _080F57A0
_080F57A0: @ jump table
	.4byte _080F57FC @ case 0
	.4byte _080F582A @ case 1
	.4byte _080F5804 @ case 2
	.4byte _080F57F4 @ case 3
	.4byte _080F5818 @ case 4
	.4byte _080F5818 @ case 5
	.4byte _080F5818 @ case 6
	.4byte _080F582A @ case 7
	.4byte _080F582A @ case 8
	.4byte _080F580E @ case 9
	.4byte _080F582A @ case 10
	.4byte _080F582A @ case 11
	.4byte _080F582A @ case 12
	.4byte _080F582A @ case 13
	.4byte _080F582A @ case 14
	.4byte _080F582A @ case 15
	.4byte _080F582A @ case 16
	.4byte _080F582A @ case 17
	.4byte _080F582A @ case 18
	.4byte _080F582A @ case 19
	.4byte _080F5822 @ case 20
_080F57F4:
	movs r0, #0xed
	bl PlaySound_082406e0
	b _080F582A
_080F57FC:
	movs r0, #0xfe
	bl PlaySound_082406e0
	b _080F582A
_080F5804:
	adds r0, r7, #0
	movs r1, #2
	bl FUN_080e81dc
	b _080F582A
_080F580E:
	movs r0, #0xe7
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080F582A
_080F5818:
	movs r0, #0x9e
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080F582A
_080F5822:
	movs r0, #0x9e
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080F582A:
	movs r1, #2
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r3, r7, r2
	ldrh r0, [r3]
	movs r5, #0
	mov sl, r5
	movs r5, #0
	orrs r1, r0
	ldr r0, _080F5918 @ =0xFFFFE856
	ands r1, r0
	strh r1, [r3]
	ldr r0, _080F591C @ =0x00000482
	adds r0, r0, r7
	mov sb, r0
	movs r1, #1
	strh r1, [r0]
	adds r2, #0xa2
	adds r0, r7, r2
	strh r5, [r0]
	ldr r1, _080F5920 @ =0x0000024E
	adds r0, r7, r1
	strh r5, [r0]
	ldr r0, _080F5924 @ =0xFFFFFC7F
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _080F5928 @ =0xF3FFFFFF
	mov ip, r1
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	ldr r1, _080F592C @ =0x0000021E
	adds r6, r7, r1
	subs r1, #0x1c
	adds r1, r1, r7
	mov r8, r1
	cmp r0, #0
	beq _080F58A4
	ldr r1, _080F5930 @ =0xFEFFFFFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r0, _080F5934 @ =0xFFFFFDFF
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r1, sl
	strb r1, [r0]
	strh r5, [r6]
	mov r0, r8
	strh r5, [r0]
_080F58A4:
	ldr r0, _080F5938 @ =0xFFFFFBFF
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r3, _080F593C @ =0x00000542
	adds r1, r7, r3
	movs r0, #0xff
	strb r0, [r1]
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #1
	mov r0, sb
	strh r1, [r0]
	ldr r0, [r2]
	mov r3, ip
	ands r0, r3
	str r0, [r2]
	ldr r1, _080F5930 @ =0xFEFFFFFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r1, _080F5940 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	strh r5, [r6]
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r5, [r0]
	mov r2, r8
	strh r5, [r2]
_080F58EA:
	ldr r3, _080F5944 @ =0x0000025D
	adds r0, r7, r3
	ldrb r4, [r0]
	cmp r4, #0
	bne _080F5948
	ldr r0, [r7, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	ldrh r0, [r3, #8]
	cmp r0, #2
	bne _080F596A
	ldrh r1, [r3, #0xe]
	ldrb r2, [r3, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _080F596A
	cmp r2, #1
	beq _080F596A
	strh r4, [r3, #0xe]
	b _080F596A
	.align 2, 0
_080F5918: .4byte 0xFFFFE856
_080F591C: .4byte 0x00000482
_080F5920: .4byte 0x0000024E
_080F5924: .4byte 0xFFFFFC7F
_080F5928: .4byte 0xF3FFFFFF
_080F592C: .4byte 0x0000021E
_080F5930: .4byte 0xFEFFFFFF
_080F5934: .4byte 0xFFFFFDFF
_080F5938: .4byte 0xFFFFFBFF
_080F593C: .4byte 0x00000542
_080F5940: .4byte 0xFFFEBE3F
_080F5944: .4byte 0x0000025D
_080F5948:
	ldr r0, [r7, #0x44]
	adds r3, r0, #0
	adds r3, #0x20
	ldrh r0, [r3, #0x14]
	cmp r0, #2
	bne _080F596A
	ldrh r1, [r3, #0xc]
	ldrh r2, [r3, #0x16]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _080F596A
	cmp r2, #1
	beq _080F596A
	movs r0, #0
	strh r0, [r3, #0xc]
_080F596A:
	movs r0, #0xc9
	lsls r0, r0, #1
	adds r5, r7, r0
	ldrh r0, [r5]
	subs r0, #0x1e
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bhi _080F59A8
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #0x1e
	bl Mod
	adds r4, r0, #0
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r1, #0xa
	bl Div
	movs r1, #0xf
	subs r1, r1, r0
	cmp r4, r1
	bge _080F59A8
	movs r0, #0x20
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_080F59A8:
	movs r5, #0x83
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r3, #0x85
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _080F59C8
	asrs r0, r0, #2
	b _080F59CE
_080F59C8:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080F59CE:
	adds r3, r0, #0
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r5, #0
	ldrsh r2, [r0, r5]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _080F59EE
	asrs r0, r0, #2
	b _080F59F4
_080F59EE:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080F59F4:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _080F59FE
	movs r3, #0xc8
	b _080F5A08
_080F59FE:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _080F5A08
	adds r3, r0, #0
_080F5A08:
	cmp r2, #0xc8
	ble _080F5A10
	movs r2, #0xc8
	b _080F5A1A
_080F5A10:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _080F5A1A
	adds r2, r0, #0
_080F5A1A:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _080F5A3E
	cmp r2, #0
	bne _080F5A3E
	movs r0, #1
	b _080F5A40
_080F5A3E:
	movs r0, #0
_080F5A40:
	cmp r0, #0
	beq _080F5B0C
	movs r0, #0xc9
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bgt _080F5B0C
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r7, #5]
	cmp r0, #0
	blt _080F5A60
	asrs r0, r0, #5
	b _080F5A66
_080F5A60:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_080F5A66:
	adds r1, r0, #7
	movs r0, #7
	ands r1, r0
	ldr r3, _080F5B1C @ =0x000001DD
	adds r0, r7, r3
	movs r4, #0
	strb r1, [r0]
	movs r3, #1
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r5, r7
	mov ip, r5
	movs r0, #3
	strb r0, [r5]
	ldr r1, _080F5B20 @ =0x00000469
	adds r1, r1, r7
	mov sl, r1
	strb r3, [r1]
	ldr r2, _080F5B24 @ =0x0000046A
	adds r2, r2, r7
	mov sb, r2
	strb r4, [r2]
	ldr r5, _080F5B28 @ =0x00000484
	adds r5, r5, r7
	mov r8, r5
	str r4, [r5]
	ldr r0, _080F5B2C @ =0x0000046C
	adds r6, r7, r0
	strb r3, [r6]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r2, [r0]
	movs r1, #8
	ldr r5, _080F5B30 @ =0x0000046D
	adds r0, r7, r5
	strb r3, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	adds r5, #0xe8
	adds r0, r7, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r5, #0
	strh r4, [r0]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	movs r0, #0x3b
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #3
	mov r2, ip
	strb r0, [r2]
	mov r1, sl
	strb r3, [r1]
	mov r2, sb
	strb r5, [r2]
	mov r5, r8
	str r4, [r5]
	strb r3, [r6]
	ldrb r0, [r7, #5]
	adds r0, #0x20
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r7, #5]
_080F5B0C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F5B1C: .4byte 0x000001DD
_080F5B20: .4byte 0x00000469
_080F5B24: .4byte 0x0000046A
_080F5B28: .4byte 0x00000484
_080F5B2C: .4byte 0x0000046C
_080F5B30: .4byte 0x0000046D
