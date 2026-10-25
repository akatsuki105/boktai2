	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x24
	adds r5, r0, #0
	mov r8, r1
	adds r6, r5, #0
	adds r7, r5, #0
	adds r7, #0x48
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080267B4
	movs r4, #0
	strb r4, [r1]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	str r4, [sp, #4]
	adds r0, r5, #0
	movs r3, #8
	bl Boss_PlayAnim
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	ldr r2, _08026904 @ =0x00000542
	adds r0, r5, r2
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	movs r1, #0
	movs r4, #3
	adds r2, #0x27
	adds r0, r5, r2
_0802678E:
	strb r1, [r0]
	subs r0, #1
	subs r4, #1
	cmp r4, #0
	bge _0802678E
	ldr r0, _08026908 @ =0x0000054C
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xef
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r0, r6, #0
	bl Duneyrr_SetHurtboxPower
	ldr r0, _0802690C @ =0x000003BE
	bl PlaySound_0824078c
_080267B4:
	ldr r2, _08026910 @ =0x00000564
	adds r0, r6, r2
	movs r1, #0
	str r1, [r0]
	subs r2, #0x24
	adds r0, r6, r2
	strh r1, [r0]
	movs r2, #0xd
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r5, #0
	adds r0, #0xb2
	ldrh r1, [r0]
	mov sb, r0
	cmp r1, #9
	bne _08026860
	movs r0, #0xac
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r1, [r2]
	ldr r0, _08026914 @ =0x000002FF
	cmp r1, r0
	bhi _080267EE
	adds r0, r1, #0
	adds r0, #0x10
	strh r0, [r2]
_080267EE:
	ldr r0, _08026918 @ =0x0000FFFC
	strh r0, [r7, #0x14]
	movs r3, #7
	mov r1, r8
	ands r3, r1
	cmp r3, #0
	bne _08026860
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	ldr r2, _0802691C @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _08026920 @ =0x000003FF
	ands r1, r0
	str r1, [r2]
	lsls r1, r1, #1
	ldr r2, _08026924 @ =0x0203B400
	adds r1, r1, r2
	add r0, sp, #0x1c
	ldrh r0, [r0]
	subs r0, #0x80
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08026928 @ =0xFFFF0000
	ldr r2, [sp, #0x1c]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	subs r1, #0x40
	lsls r1, r1, #0x10
	ldr r0, _0802692C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	ldr r2, _08026930 @ =0x00003001
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
_08026860:
	movs r4, #0
_08026862:
	movs r1, #0xad
	lsls r1, r1, #3
	adds r0, r6, r1
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq _08026884
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08026884
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl Entity5DA5_SetState
_08026884:
	adds r4, #1
	cmp r4, #3
	ble _08026862
	ldr r2, _08026934 @ =0x00000275
	adds r0, r6, r2
	ldrb r1, [r0]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08026956
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #8
	bne _0802693E
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #3
	bls _08026938
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0x20
	adds r2, r6, r0
	str r3, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r3, #9
	bl Boss_PlayAnim
	bl Entity5DA5_AreAllLit
	cmp r0, #0
	beq _08026956
	movs r4, #0
	ldr r1, _08026924 @ =0x0203B400
	mov ip, r1
	ldr r5, _0802691C @ =0x030046B8
	movs r0, #0xad
	lsls r0, r0, #3
	adds r2, r6, r0
	movs r3, #0x18
	ldr r7, _08026920 @ =0x000003FF
	movs r6, #3
_080268E2:
	ldr r0, [r5]
	adds r0, #1
	ands r0, r7
	str r0, [r5]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	adds r1, r2, r4
	ands r0, r6
	adds r0, r3, r0
	strb r0, [r1]
	adds r3, #3
	adds r4, #1
	cmp r4, #3
	ble _080268E2
	b _08026956
	.align 2, 0
_08026904: .4byte 0x00000542
_08026908: .4byte 0x0000054C
_0802690C: .4byte 0x000003BE
_08026910: .4byte 0x00000564
_08026914: .4byte 0x000002FF
_08026918: .4byte 0x0000FFFC
_0802691C: .4byte 0x030046B8
_08026920: .4byte 0x000003FF
_08026924: .4byte 0x0203B400
_08026928: .4byte 0xFFFF0000
_0802692C: .4byte 0x0000FFFF
_08026930: .4byte 0x00003001
_08026934: .4byte 0x00000275
_08026938:
	adds r0, #1
	strh r0, [r1]
	b _08026956
_0802693E:
	ldr r2, _08026964 @ =FUN_08025654
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
_08026956:
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08026964: .4byte FUN_08025654
