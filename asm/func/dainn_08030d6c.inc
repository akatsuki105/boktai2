	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	mov r8, r5
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08030E4E
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08030DAC
	ldr r1, _08030DA8 @ =0x00000824
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0x16
	movs r2, #0x82
	lsls r2, r2, #4
	adds r4, r5, r2
	cmp r0, #0
	bne _08030DBE
	movs r3, #0x12
	b _08030DBE
	.align 2, 0
_08030DA8: .4byte 0x00000824
_08030DAC:
	movs r3, #0x82
	lsls r3, r3, #4
	adds r0, r5, r3
	ldr r1, [r0]
	movs r3, #0x12
	adds r4, r0, #0
	cmp r1, #0
	beq _08030DBE
	movs r3, #0x16
_08030DBE:
	movs r7, #0xbd
	lsls r7, r7, #2
	adds r1, r5, r7
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	mov r0, r8
	bl Boss_PlayAnim
	movs r2, #0x87
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r3, #0xb4
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r0, [r4]
	cmp r0, #0
	beq _08030E00
	ldr r0, _08030DFC @ =0x00000313
	bl PlaySound_082406e0
	b _08030E06
	.align 2, 0
_08030DFC: .4byte 0x00000313
_08030E00:
	ldr r0, _08030E7C @ =0x0000033D
	bl PlaySound_082406e0
_08030E06:
	bl FUN_080846c8
	ldr r2, _08030E80 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08030E84 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r7, _08030E88 @ =0x0203B400
	adds r0, r0, r7
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x3c
	ldr r1, _08030E8C @ =0x0000016F
	adds r2, r5, r1
	movs r1, #0
	strb r0, [r2]
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _08030E90 @ =0x000008A2
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r0, r5, #0
	bl Ringo_SetHurtboxPower
	movs r7, #0xf2
	lsls r7, r7, #1
	adds r2, r5, r7
	ldr r0, _08030E94 @ =0xFFFFFEFF
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_08030E4E:
	mov r0, r8
	adds r0, #0xfc
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08030E98
	movs r1, #0x8a
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl Ringo_SetHurtboxPower
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r2, #6]
	b _08030EC6
	.align 2, 0
_08030E7C: .4byte 0x0000033D
_08030E80: .4byte 0x030046B8
_08030E84: .4byte 0x000003FF
_08030E88: .4byte 0x0203B400
_08030E8C: .4byte 0x0000016F
_08030E90: .4byte 0x000008A2
_08030E94: .4byte 0xFFFFFEFF
_08030E98:
	movs r4, #0x80
	lsls r4, r4, #1
	mov r7, r8
	adds r0, r7, r4
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08030ECC
	movs r1, #0x8a
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl Ringo_SetHurtboxPower
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2, #6]
	adds r0, r4, #0
_08030EC6:
	orrs r0, r1
	strh r0, [r2, #6]
	b _080310F6
_08030ECC:
	movs r1, #0x80
	lsls r1, r1, #0xa
	mov r6, r8
	adds r6, #0x98
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08030F32
	ldr r4, _08030FAC @ =0x0203B400
	ldr r3, _08030FB0 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _08030FB4 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	ldrh r1, [r1]
	movs r7, #0xb7
	lsls r7, r7, #1
	strb r1, [r7, r5]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x1e
	ldr r2, _08030FB8 @ =0x0000016F
	adds r1, r5, r2
	strb r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0xc
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08030F28
	adds r0, r5, #0
	bl FUN_08028b00
_08030F28:
	movs r7, #0xb4
	lsls r7, r7, #1
	adds r1, r5, r7
	movs r0, #0x3c
	strb r0, [r1]
_08030F32:
	ldr r0, _08030FB8 @ =0x0000016F
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	bne _08030F3E
	b _08031080
_08030F3E:
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803103C
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r3, r5, r1
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r3]
	ldr r2, _08030FAC @ =0x0203B400
	mov ip, r2
	ldr r7, _08030FB0 @ =0x030046B8
	ldr r0, [r7]
	adds r2, r0, #1
	ldr r6, _08030FB4 @ =0x000003FF
	ands r2, r6
	str r2, [r7]
	lsls r0, r2, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0xb7
	lsls r1, r1, #1
	strb r0, [r1, r5]
	movs r1, #0x87
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r1, r0
	bhi _08030FD2
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #8
	strb r1, [r0]
	ldrb r0, [r3]
	cmp r0, #3
	bne _08030FBC
	adds r0, r2, #1
	ands r0, r6
	str r0, [r7]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x3c
	strb r0, [r4]
	b _08031080
	.align 2, 0
_08030FAC: .4byte 0x0203B400
_08030FB0: .4byte 0x030046B8
_08030FB4: .4byte 0x000003FF
_08030FB8: .4byte 0x0000016F
_08030FBC:
	adds r0, r2, #1
	ands r0, r6
	str r0, [r7]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0xa
	strb r0, [r4]
	b _08031080
_08030FD2:
	movs r0, #0xe1
	lsls r0, r0, #1
	cmp r1, r0
	bhi _08031000
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #8
	strb r1, [r0]
	ldrb r0, [r3]
	cmp r0, #3
	bne _08031026
	adds r0, r2, #1
	ands r0, r6
	str r0, [r7]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x1e
	strb r0, [r4]
	b _08031080
_08031000:
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #6
	strb r1, [r0]
	ldrb r0, [r3]
	cmp r0, #3
	bne _08031026
	adds r0, r2, #1
	ands r0, r6
	str r0, [r7]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0xf
	strb r0, [r4]
	b _08031080
_08031026:
	adds r0, r2, #1
	ands r0, r6
	str r0, [r7]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #8
	strb r0, [r4]
	b _08031080
_0803103C:
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _0803107C
	ldr r2, _08031070 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08031074 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08031078 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r7, #0xb7
	lsls r7, r7, #1
	adds r1, r5, r7
	strb r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #4
	b _0803107E
	.align 2, 0
_08031070: .4byte 0x030046B8
_08031074: .4byte 0x000003FF
_08031078: .4byte 0x0203B400
_0803107C:
	subs r0, #1
_0803107E:
	strb r0, [r1]
_08031080:
	movs r2, #0xb1
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08031094
	subs r0, r2, #4
	b _08031096
_08031094:
	movs r0, #0
_08031096:
	strh r0, [r1]
	movs r7, #0xb0
	lsls r7, r7, #1
	adds r1, r5, r7
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _080310AC
	subs r0, r2, #4
	b _080310AE
_080310AC:
	movs r0, #0
_080310AE:
	strh r0, [r1]
	ldr r7, _08031104 @ =0x00000311
	adds r0, r5, r7
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080310EA
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _080310D4
	mov r0, r8
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #7
	ble _080310EA
_080310D4:
	movs r2, #0x87
	lsls r2, r2, #4
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r0, _08031108 @ =0x00000257
	cmp r1, r0
	bls _080310EA
	mov r1, r8
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_080310EA:
	movs r3, #0x87
	lsls r3, r3, #4
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080310F6:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08031104: .4byte 0x00000311
_08031108: .4byte 0x00000257
