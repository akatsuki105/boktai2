	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r5, r0, #0
	mov r8, r1
	adds r7, r5, #0
	adds r6, r5, #0
	adds r6, #0x48
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080259CC
	movs r4, #0
	strb r4, [r1]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r0, #1
	str r0, [sp]
	str r4, [sp, #4]
	adds r0, r5, #0
	movs r3, #2
	bl Boss_PlayAnim
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r4, [r0]
	ldr r2, _08025A7C @ =0x00000171
	adds r0, r5, r2
	strb r1, [r0]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r5, r3
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _08025A80 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08025A84 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08025A88 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x38
	movs r2, #0xb9
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, _08025A8C @ =0x000003B6
	bl PlaySound_0824078c
_080259CC:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080259E0
	b _08025C5E
_080259E0:
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080259F6
	b _08025C5E
_080259F6:
	movs r3, #7
	mov r0, r8
	ands r3, r0
	cmp r3, #0
	bne _08025A58
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	ldr r2, _08025A80 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08025A84 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08025A88 @ =0x0203B400
	adds r0, r0, r1
	add r1, sp, #0x1c
	ldrh r1, [r1]
	subs r1, #0x80
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08025A90 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	ldr r2, _08025A94 @ =0x00003001
	movs r0, #0x40
	str r0, [sp]
	movs r0, #0x10
	str r0, [sp, #4]
	movs r0, #8
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	subs r0, #6
	str r0, [sp, #0x10]
	str r3, [sp, #0x14]
	add r3, sp, #0x1c
	str r3, [sp, #0x18]
	movs r0, #1
	movs r1, #5
	movs r3, #0x40
	bl FUN_08015ce0
_08025A58:
	mov r0, r8
	cmp r0, #0x40
	ble _08025A60
	b _08025C2C
_08025A60:
	ldr r2, _08025A98 @ =gSineTable
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	mov ip, r2
	cmp r0, #0
	blt _08025A9C
	asrs r0, r0, #0xc
	b _08025AA2
	.align 2, 0
_08025A7C: .4byte 0x00000171
_08025A80: .4byte 0x030046B8
_08025A84: .4byte 0x000003FF
_08025A88: .4byte 0x0203B400
_08025A8C: .4byte 0x000003B6
_08025A90: .4byte 0xFFFF0000
_08025A94: .4byte 0x00003001
_08025A98: .4byte gSineTable
_08025A9C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08025AA2:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x24]
	mov r2, r8
	lsls r0, r2, #3
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08025AC2
	asrs r0, r0, #0xc
	b _08025AC8
_08025AC2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08025AC8:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08025B50 @ =0xFFFF0000
	add r3, sp, #0x24
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	adds r4, r6, #0
	adds r4, #8
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	ldrh r0, [r2]
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r6, #8]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r4, #4]
	mov r2, r8
	subs r2, #0x10
	cmp r2, #0x20
	bls _08025B04
	b _08025C2C
_08025B04:
	ldr r3, _08025B54 @ =0x00000171
	adds r1, r7, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _08025B18
	b _08025C2C
_08025B18:
	ldr r3, _08025B58 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _08025B5C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _08025B60 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r1, r2, #5
	movs r2, #0x3f
	ands r0, r2
	adds r1, r1, r0
	subs r1, #0xc8
	add r4, sp, #0x2c
	movs r0, #0x80
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	adds r6, r3, #0
	mov sb, r4
	cmp r0, #0
	blt _08025B64
	asrs r2, r0, #0xc
	b _08025B6A
	.align 2, 0
_08025B50: .4byte 0xFFFF0000
_08025B54: .4byte 0x00000171
_08025B58: .4byte 0x030046B8
_08025B5C: .4byte 0x000003FF
_08025B60: .4byte 0x0203B400
_08025B64:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08025B6A:
	movs r0, #0
	strh r2, [r4]
	strh r0, [r4, #2]
	movs r0, #0x40
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _08025B84
	asrs r0, r0, #0xc
	b _08025B8A
_08025B84:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08025B8A:
	strh r0, [r4, #4]
	ldr r0, [r6]
	adds r0, #1
	ldr r4, _08025BE4 @ =0x000003FF
	ands r0, r4
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _08025BE8 @ =0x0203B400
	adds r0, r0, r1
	mov r2, sb
	ldrh r1, [r2]
	subs r1, #0x80
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrb r0, [r0]
	ldrh r2, [r2]
	mov ip, r2
	add r0, ip
	adds r1, r1, r0
	add r2, sp, #0x2c
	strh r1, [r2]
	movs r0, #0xbe
	lsls r0, r0, #1
	ldrh r0, [r0, r7]
	ldrh r3, [r2, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r2, #2]
	mov r0, ip
	lsls r3, r0, #0x10
	lsls r1, r1, #0x10
	cmp r3, r1
	blt _08025BEC
	ldr r0, [r6]
	adds r0, #1
	ands r0, r4
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _08025BE8 @ =0x0203B400
	adds r0, r0, r1
	b _08025BFA
	.align 2, 0
_08025BE4: .4byte 0x000003FF
_08025BE8: .4byte 0x0203B400
_08025BEC:
	ldr r0, [r6]
	adds r0, #1
	ands r0, r4
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08025C70 @ =0x0203B400
	adds r0, r0, r2
_08025BFA:
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r1, r0, #0
	adds r1, #0x40
	movs r4, #0
	str r4, [sp]
	movs r0, #0x20
	str r0, [sp, #4]
	ldr r3, _08025C74 @ =0x0000078A
	adds r0, r7, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	mov r3, sb
	str r3, [sp, #0x10]
	movs r0, #1
	movs r2, #0
	movs r3, #2
	bl DustManager_Emit
	ldr r1, _08025C78 @ =0x00000171
	adds r0, r7, r1
	strb r4, [r0]
_08025C2C:
	mov r2, r8
	cmp r2, #0x3f
	ble _08025C5E
	ldr r3, _08025C7C @ =0x00000275
	adds r0, r7, r3
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08025C5E
	ldr r2, _08025C80 @ =FUN_08025c84
	movs r0, #5
	adds r3, r5, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_08025C5E:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08025C70: .4byte 0x0203B400
_08025C74: .4byte 0x0000078A
_08025C78: .4byte 0x00000171
_08025C7C: .4byte 0x00000275
_08025C80: .4byte FUN_08025c84
