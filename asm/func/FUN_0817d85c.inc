	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov r8, r0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817D876
	b _0817DA12
_0817D876:
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r5, [r0]
	movs r1, #0x80
	ldr r2, _0817D890 @ =0x00000898
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817D894
	movs r0, #1
	b _0817D896
	.align 2, 0
_0817D890: .4byte 0x00000898
_0817D894:
	movs r0, #0
_0817D896:
	cmp r0, #0
	bne _0817D89C
	b _0817DA12
_0817D89C:
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r3, r3, r5
	mov sb, r3
	movs r0, #0xdb
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	bne _0817D928
	ldr r1, _0817D8E8 @ =0x02008000
	movs r0, #0xbc
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817D8C2
	b _0817DA20
_0817D8C2:
	ldr r0, _0817D8EC @ =0x0000047A
	add r0, r8
	ldrh r1, [r0]
	movs r0, #0x90
	lsls r0, r0, #3
	add r0, r8
	ldrh r0, [r0]
	adds r1, r1, r0
	ldr r0, _0817D8F0 @ =0x0000025D
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	bne _0817D8F4
	mov r2, r8
	ldr r0, [r2, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _0817D902
	.align 2, 0
_0817D8E8: .4byte 0x02008000
_0817D8EC: .4byte 0x0000047A
_0817D8F0: .4byte 0x0000025D
_0817D8F4:
	mov r3, r8
	ldr r2, [r3, #0x44]
	ldr r0, _0817D91C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_0817D902:
	mov r1, r8
	ldr r0, [r1, #0x44]
	adds r0, #0x20
	ldr r1, _0817D920 @ =0x00000272
	strh r1, [r0, #0x3a]
	ldr r3, _0817D924 @ =0x00000898
	adds r2, r5, r3
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0817DA20
	.align 2, 0
_0817D91C: .4byte 0x03003584
_0817D920: .4byte 0x00000272
_0817D924: .4byte 0x00000898
_0817D928:
	movs r0, #0xbc
	lsls r0, r0, #1
	add r0, r8
	str r0, [sp, #0xc]
	ldr r2, _0817D988 @ =0x000006DC
	adds r2, r5, r2
	str r2, [sp, #4]
	ldr r3, _0817D98C @ =0x0000073C
	adds r3, r5, r3
	str r3, [sp, #8]
	mov sl, r1
	mov r6, sb
	movs r7, #0
	ldr r0, _0817D990 @ =0x000006FC
	adds r4, r5, r0
	ldr r1, _0817D994 @ =0x0000075C
	adds r1, r1, r5
	mov ip, r1
	ldr r2, _0817D998 @ =0x0000077C
	adds r2, r5, r2
	str r2, [sp]
	ldr r3, _0817D99C @ =0x0000071C
	adds r2, r5, r3
_0817D956:
	ldr r0, [sp, #4]
	adds r1, r0, r7
	ldr r3, [sp, #8]
	adds r0, r3, r7
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	mov r3, ip
	ldrh r0, [r3]
	ldrh r3, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldr r3, [sp]
	adds r0, r3, r7
	ldrh r0, [r0]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	blt _0817D9A0
	asrs r0, r0, #8
	b _0817D9A6
	.align 2, 0
_0817D988: .4byte 0x000006DC
_0817D98C: .4byte 0x0000073C
_0817D990: .4byte 0x000006FC
_0817D994: .4byte 0x0000075C
_0817D998: .4byte 0x0000077C
_0817D99C: .4byte 0x0000071C
_0817D9A0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0817D9A6:
	adds r5, r0, #0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	blt _0817D9B4
	asrs r0, r0, #8
	b _0817D9BA
_0817D9B4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0817D9BA:
	adds r3, r0, #0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	blt _0817D9C8
	asrs r1, r0, #8
	b _0817D9CE
_0817D9C8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0817D9CE:
	lsls r0, r3, #5
	orrs r0, r5
	lsls r1, r1, #0xa
	orrs r1, r0
	strh r1, [r6]
	adds r6, #2
	adds r2, #2
	adds r7, #2
	adds r4, #2
	movs r3, #2
	add ip, r3
	mov r0, sb
	adds r0, #0x1e
	cmp r6, r0
	ble _0817D956
	mov r1, sl
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	ldr r1, _0817DA18 @ =0x02008000
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0817DA0A
	ldr r2, _0817DA1C @ =0x00000273
	mov r0, r8
	mov r1, sb
	bl FUN_0817dbf0
_0817DA0A:
	mov r3, sl
	ldrh r0, [r3]
	cmp r0, #0
	beq _0817DA20
_0817DA12:
	movs r0, #0
	b _0817DA22
	.align 2, 0
_0817DA18: .4byte 0x02008000
_0817DA1C: .4byte 0x00000273
_0817DA20:
	movs r0, #1
_0817DA22:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
