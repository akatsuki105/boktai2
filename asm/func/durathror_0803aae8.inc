	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	mov sl, r1
	mov sb, r7
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803AB4C
	movs r4, #0
	strb r4, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r3, #0x98
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r0, #1
	str r0, [sp]
	movs r0, #5
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #0x21
	bl Boss_PlayAnimFacing
	adds r0, r7, #0
	movs r1, #0xa
	movs r2, #0xa
	bl FUN_08022c24
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	adds r0, r7, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	ldr r2, _0803ABF8 @ =0x00000163
	adds r1, r7, r2
	strb r0, [r1]
	ldr r0, _0803ABFC @ =0x000002CE
	bl PlaySound_0824078c
_0803AB4C:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803AB60
	b _0803ACA2
_0803AB60:
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803AB76
	b _0803ACA2
_0803AB76:
	movs r2, #0x80
	lsls r2, r2, #0xb
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #0x1f
	mov r8, r4
	mov r0, sl
	ands r0, r4
	cmp r0, #0
	bne _0803AC7E
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	bhi _0803AC7E
	ldr r1, _0803AC00 @ =0x0203B400
	mov ip, r1
	ldr r2, _0803AC04 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r3, _0803AC08 @ =0x000003FF
	ands r1, r3
	str r1, [r2]
	lsls r0, r1, #1
	add r0, ip
	movs r6, #0xff
	ldrb r5, [r0]
	adds r4, #0xe5
	adds r0, r7, r4
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r4, [r0]
	adds r1, #1
	ands r1, r3
	str r1, [r2]
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	mov r1, r8
	ands r0, r1
	add r3, sp, #0xc
	adds r4, r4, r0
	subs r4, #0x10
	ldr r1, _0803AC0C @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0803AC10
	asrs r2, r0, #0xc
	b _0803AC16
	.align 2, 0
_0803ABF8: .4byte 0x00000163
_0803ABFC: .4byte 0x000002CE
_0803AC00: .4byte 0x0203B400
_0803AC04: .4byte 0x030046B8
_0803AC08: .4byte 0x000003FF
_0803AC0C: .4byte gSineTable
_0803AC10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0803AC16:
	movs r0, #0
	strh r2, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r5, r0
	cmp r0, #0
	blt _0803AC32
	asrs r0, r0, #0xc
	b _0803AC38
_0803AC32:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803AC38:
	strh r0, [r3, #4]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	add r4, sp, #0x14
	add r2, sp, #0xc
	adds r0, r2, #0
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	adds r0, r4, #0
	bl FUN_08036908
	ldr r0, _0803ACB4 @ =0x00000DEC
	add r0, sb
	ldr r0, [r0]
	movs r1, #0xd1
	lsls r1, r1, #1
	add r1, sb
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #0x20
	adds r3, r4, #0
	bl FUN_0805dd44
_0803AC7E:
	mov r3, sl
	cmp r3, #0xff
	ble _0803ACA2
	ldr r2, _0803ACB8 @ =FUN_0803ad74
	movs r0, #0xc
	adds r3, r7, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r7, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_0803ACA2:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803ACB4: .4byte 0x00000DEC
_0803ACB8: .4byte FUN_0803ad74
