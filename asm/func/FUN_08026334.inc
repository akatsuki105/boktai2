	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	adds r5, r0, #0
	str r1, [sp, #0x24]
	adds r7, r5, #0
	movs r0, #0x48
	adds r0, r0, r5
	mov sl, r0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080263D0
	movs r3, #0
	strb r3, [r1]
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r6, #0x8e
	lsls r6, r6, #2
	adds r2, r5, r6
	movs r0, #2
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r5, #0
	movs r3, #9
	bl Boss_PlayAnim
	bl Entity5DA5_AreAllLit
	cmp r0, #0
	beq _080263BA
	movs r4, #0
	ldr r0, _080264E8 @ =0x0203B400
	mov sb, r0
	ldr r3, _080264EC @ =0x030046B8
	movs r1, #0xad
	lsls r1, r1, #3
	adds r1, r5, r1
	str r1, [sp, #0x28]
	movs r2, #0x18
	ldr r6, _080264F0 @ =0x000003FF
	mov r8, r6
	movs r0, #3
	mov ip, r0
_08026396:
	ldr r0, [r3]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	ldr r6, [sp, #0x28]
	adds r1, r6, r4
	mov r6, ip
	ands r0, r6
	adds r0, r2, r0
	strb r0, [r1]
	adds r2, #3
	adds r4, #1
	cmp r4, #3
	ble _08026396
_080263BA:
	ldr r0, _080264F4 @ =0x0000054C
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xef
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	bl Duneyrr_SetHurtboxPower
_080263D0:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080264D8
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080264D8
	adds r0, r5, #0
	adds r0, #0xb2
	ldrh r0, [r0]
	cmp r0, #9
	bne _08026488
	movs r6, #0xac
	lsls r6, r6, #1
	adds r2, r7, r6
	ldrh r1, [r2]
	ldr r0, _080264F8 @ =0x000002FF
	cmp r1, r0
	bhi _08026414
	adds r0, r1, #0
	adds r0, #0x10
	strh r0, [r2]
_08026414:
	ldr r0, _080264FC @ =0x0000FFFC
	mov r1, sl
	strh r0, [r1, #0x14]
	movs r3, #7
	ldr r2, [sp, #0x24]
	ands r3, r2
	cmp r3, #0
	bne _08026488
	ldr r0, [r1, #8]
	ldr r1, [r1, #0xc]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	ldr r2, _080264EC @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _080264F0 @ =0x000003FF
	ands r1, r0
	str r1, [r2]
	lsls r1, r1, #1
	ldr r6, _080264E8 @ =0x0203B400
	adds r1, r1, r6
	add r0, sp, #0x1c
	ldrh r0, [r0]
	subs r0, #0x80
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08026500 @ =0xFFFF0000
	ldr r2, [sp, #0x1c]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	subs r1, #0x40
	lsls r1, r1, #0x10
	ldr r0, _08026504 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	ldr r2, _08026508 @ =0x00003001
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
	add r0, sp, #0x1c
	str r0, [sp, #0x18]
	movs r0, #1
	movs r1, #5
	movs r3, #0x40
	bl FUN_08015ce0
_08026488:
	movs r4, #0
_0802648A:
	movs r1, #0xad
	lsls r1, r1, #3
	adds r0, r7, r1
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq _080264AC
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080264AC
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl Entity5DA5_SetState
_080264AC:
	adds r4, #1
	cmp r4, #3
	ble _0802648A
	ldr r2, _0802650C @ =0x00000275
	adds r0, r7, r2
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080264D8
	ldr r2, _08026510 @ =FUN_08025654
	movs r3, #1
	adds r0, r5, #0
	adds r0, #0xa3
	movs r1, #0
	strb r3, [r0]
	adds r0, #0x55
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r0, #0x1d
	strb r3, [r0]
_080264D8:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080264E8: .4byte 0x0203B400
_080264EC: .4byte 0x030046B8
_080264F0: .4byte 0x000003FF
_080264F4: .4byte 0x0000054C
_080264F8: .4byte 0x000002FF
_080264FC: .4byte 0x0000FFFC
_08026500: .4byte 0xFFFF0000
_08026504: .4byte 0x0000FFFF
_08026508: .4byte 0x00003001
_0802650C: .4byte 0x00000275
_08026510: .4byte FUN_08025654
