	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0816B1B8 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816B1BC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816B1BE
	.align 2, 0
_0816B1B8: .4byte 0x0000046D
_0816B1BC:
	movs r0, #0
_0816B1BE:
	cmp r0, #0
	beq _0816B1E4
	ldr r0, _0816B224 @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r1, [r0]
	ldr r0, _0816B228 @ =0x00000842
	add r0, r8
	movs r2, #0
	strb r1, [r0]
	ldr r0, _0816B22C @ =0x000007E6
	add r0, r8
	strh r2, [r0]
	ldr r0, _0816B230 @ =0x00000482
	adds r1, r5, r0
	movs r0, #4
	strh r0, [r1]
_0816B1E4:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Ghost_GetAnimVariant
	ldr r1, _0816B234 @ =0x000004C4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0816B238 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816B244
	ldr r1, _0816B23C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl AuxAnim_SetAnim
	ldr r2, _0816B240 @ =0x0000046E
	adds r7, r5, r2
	b _0816B2C6
	.align 2, 0
_0816B224: .4byte 0x03002BE0
_0816B228: .4byte 0x00000842
_0816B22C: .4byte 0x000007E6
_0816B230: .4byte 0x00000482
_0816B234: .4byte 0x000004C4
_0816B238: .4byte 0x0000025D
_0816B23C: .4byte 0x000004B7
_0816B240: .4byte 0x0000046E
_0816B244:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r3, _0816B2B4 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0816B2B8 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0816B27E
	ldrb r0, [r7]
	cmp r0, #0
	bne _0816B27E
	cmp r4, #1
	bne _0816B270
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0816B2CA
_0816B270:
	cmp r4, #0
	bne _0816B27E
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0816B2CA
_0816B27E:
	strb r2, [r3]
	movs r1, #4
	mov sb, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0816B290
	movs r3, #6
_0816B290:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0816B2BC
	ldr r0, [r6, #8]
	mov r2, sb
	orrs r0, r2
	b _0816B2C4
	.align 2, 0
_0816B2B4: .4byte 0x000004B7
_0816B2B8: .4byte 0x0000046E
_0816B2BC:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0816B2C4:
	str r0, [r6, #8]
_0816B2C6:
	movs r0, #0
	strb r0, [r7]
_0816B2CA:
	movs r3, #0x90
	lsls r3, r3, #3
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _0816B308
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	ldr r1, _0816B300 @ =0x000007E4
	add r1, r8
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _0816B344
	ldr r0, _0816B304 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r1, [r1]
	bl Player_ReduceENE
	b _0816B344
	.align 2, 0
_0816B300: .4byte 0x000007E4
_0816B304: .4byte 0x03002BE0
_0816B308:
	cmp r0, #1
	bne _0816B344
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ldr r1, _0816B364 @ =0x000007E4
	add r1, r8
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _0816B332
	ldr r0, _0816B368 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r1, [r1]
	bl Player_ReduceENE
_0816B332:
	ldr r0, _0816B368 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0816B344
	movs r2, #0xe1
	lsls r2, r2, #2
	movs r1, #2
	bl Player_ApplyBadCondition
_0816B344:
	ldr r0, _0816B36C @ =0x00000842
	add r0, r8
	ldrb r2, [r0]
	ldr r0, _0816B368 @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r1, [r0]
	cmp r1, r2
	bge _0816B374
	ldr r3, _0816B370 @ =0xFFFFFF00
	adds r0, r2, r3
	subs r4, r1, r0
	b _0816B376
	.align 2, 0
_0816B364: .4byte 0x000007E4
_0816B368: .4byte 0x03002BE0
_0816B36C: .4byte 0x00000842
_0816B370: .4byte 0xFFFFFF00
_0816B374:
	subs r4, r1, r2
_0816B376:
	ldr r6, _0816B3C0 @ =0x00000841
	add r6, r8
	ldrb r0, [r6]
	cmp r0, r4
	beq _0816B39A
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0816B398
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0816B398:
	strb r4, [r6]
_0816B39A:
	ldr r0, _0816B3C0 @ =0x00000841
	add r0, r8
	ldr r1, _0816B3C4 @ =0x000007E5
	add r1, r8
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _0816B3B2
	ldr r2, _0816B3C8 @ =0x0000046B
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_0816B3B2:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816B3C0: .4byte 0x00000841
_0816B3C4: .4byte 0x000007E5
_0816B3C8: .4byte 0x0000046B
