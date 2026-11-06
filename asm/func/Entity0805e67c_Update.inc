	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, [r7, #0x18]
	cmp r0, #0
	bne _0805E42A
	b _0805E602
_0805E42A:
	ldr r0, _0805E48C @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0805E43E
	ldr r1, _0805E490 @ =0x00001508
	adds r2, r7, r1
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
_0805E43E:
	ldr r2, _0805E494 @ =0x000014E4
	adds r6, r7, r2
	ldrb r0, [r6]
	cmp r0, #0
	beq _0805E4C4
	ldr r0, _0805E498 @ =0x03003584
	ldr r2, [r0]
	ldr r3, _0805E49C @ =0x00004C60
	adds r1, r2, r3
	ldr r4, _0805E4A0 @ =0x00004CE0
	adds r2, r2, r4
	ldr r3, _0805E4A4 @ =0x000014E8
	adds r0, r7, r3
	ldr r4, _0805E4A8 @ =0x000014E5
	adds r5, r7, r4
	movs r3, #0
	ldrsb r3, [r5, r3]
	movs r4, #5
	str r4, [sp]
	bl BlendPltt
	ldr r0, _0805E4AC @ =0x000014E6
	adds r2, r7, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _0805E4B0
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1e
	ble _0805E4C4
	movs r0, #0x1f
	strb r0, [r5]
	movs r0, #1
	strb r0, [r2]
	b _0805E4C4
	.align 2, 0
_0805E48C: .4byte 0x03002BE0
_0805E490: .4byte 0x00001508
_0805E494: .4byte 0x000014E4
_0805E498: .4byte 0x03003584
_0805E49C: .4byte 0x00004C60
_0805E4A0: .4byte 0x00004CE0
_0805E4A4: .4byte 0x000014E8
_0805E4A8: .4byte 0x000014E5
_0805E4AC: .4byte 0x000014E6
_0805E4B0:
	ldrb r0, [r5]
	subs r0, #1
	movs r1, #0
	strb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _0805E4C4
	strb r1, [r5]
	strb r1, [r2]
	strb r1, [r6]
_0805E4C4:
	ldr r0, [r7, #0x1c]
	movs r1, #1
	ands r0, r1
	ldr r2, _0805E53C @ =0x000014E7
	adds r1, r7, r2
	strb r0, [r1]
	movs r3, #0x24
	adds r3, r3, r7
	mov r8, r3
	movs r4, #0
	mov sb, r4
	movs r0, #1
	mov sl, r0
	adds r6, r7, #0
	adds r6, #0xd8
_0805E4E2:
	mov r1, sl
	mov r2, sb
	lsls r1, r2
	ldr r0, [r7, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805E5E8
	ldr r1, _0805E540 @ =0x085ABA5C
	mov r3, r8
	movs r0, #2
	ldrsb r0, [r3, r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r7, #0
	mov r1, r8
	bl _call_via_r3
	mov r5, r8
	adds r5, #0xc4
	adds r3, r6, #0
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r6, #0x20]
	ldrb r0, [r6, #4]
	mov r2, sl
	ands r2, r0
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r1, sl
	ands r0, r1
	cmp r2, r0
	beq _0805E544
	ldr r0, [r6, #0x10]
	movs r1, #4
	orrs r0, r1
	str r0, [r6, #0x10]
	b _0805E54E
	.align 2, 0
_0805E53C: .4byte 0x000014E7
_0805E540: .4byte 0x085ABA5C
_0805E544:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
_0805E54E:
	ldrb r0, [r3, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r2, #2
	ands r0, r2
	cmp r1, r0
	beq _0805E570
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0805E578
_0805E570:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0805E578:
	str r0, [r5]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r4, _0805E5B0 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r4, [r3, #7]
	cmp r0, r4
	blo _0805E5E8
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805E5B4
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _0805E5A8
	ldrb r0, [r3, #5]
_0805E5A8:
	subs r0, #1
	strh r0, [r3, #8]
	b _0805E5C4
	.align 2, 0
_0805E5B0: .4byte 0x0000FFFF
_0805E5B4:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _0805E5C4
	strh r1, [r3, #8]
_0805E5C4:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805E5E8
	mov r4, sl
	strb r4, [r3, #7]
_0805E5E8:
	movs r0, #1
	add sb, r0
	movs r1, #0xa6
	lsls r1, r1, #1
	adds r6, r6, r1
	add r8, r1
	mov r2, sb
	cmp r2, #0xf
	bgt _0805E5FC
	b _0805E4E2
_0805E5FC:
	ldr r0, [r7, #0x1c]
	adds r0, #1
	str r0, [r7, #0x1c]
_0805E602:
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
