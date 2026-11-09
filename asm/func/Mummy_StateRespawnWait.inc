	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	adds r3, r1, #0
	movs r2, #1
	ldr r1, _081231F8 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081231FC
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08123206
	.align 2, 0
_081231F8: .4byte 0x0000025D
_081231FC:
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_08123206:
	ldr r2, _0812321C @ =0x0000046D
	adds r0, r5, r2
	ldrb r1, [r0]
	mov sb, r0
	cmp r1, #0
	beq _08123220
	movs r0, #0
	mov r4, sb
	strb r0, [r4]
	movs r0, #1
	b _08123222
	.align 2, 0
_0812321C: .4byte 0x0000046D
_08123220:
	movs r0, #0
_08123222:
	adds r1, r0, #0
	cmp r1, #0
	beq _08123234
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r5, r1
	bl ParticleShadow_Hide
	b _08123342
_08123234:
	cmp r3, #0x1a
	bgt _0812323A
	b _0812333C
_0812323A:
	mov r4, sp
	adds r4, #5
	adds r0, r5, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl Enemy_SetAnimFacing
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r1, [r4]
	movs r0, #4
	movs r2, #8
	adds r4, r1, #0
	orrs r4, r0
	ldr r1, _0812327C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08123288
	ldr r1, _08123280 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r4, [sp]
	bl AuxAnim_SetAnim
	ldr r2, _08123284 @ =0x0000046E
	adds r7, r5, r2
	b _08123306
	.align 2, 0
_0812327C: .4byte 0x0000025D
_08123280: .4byte 0x000004B7
_08123284: .4byte 0x0000046E
_08123288:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r3, #0
	adds r2, #8
	ldr r1, _081232F4 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081232F8 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081232C4
	ldrb r0, [r7]
	cmp r0, #0
	bne _081232C4
	cmp r4, #1
	bne _081232B6
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0812330A
_081232B6:
	cmp r4, #0
	bne _081232C4
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0812330A
_081232C4:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081232D6
	movs r3, #6
_081232D6:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081232FC
	ldr r0, [r6, #8]
	mov r2, r8
	orrs r0, r2
	b _08123304
	.align 2, 0
_081232F4: .4byte 0x000004B7
_081232F8: .4byte 0x0000046E
_081232FC:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08123304:
	str r0, [r6, #8]
_08123306:
	movs r0, #0
	strb r0, [r7]
_0812330A:
	ldr r3, _08123334 @ =Mummy_StateRespawn
	movs r2, #0xd
	movs r1, #0
	movs r0, #1
	mov r4, sb
	strb r0, [r4]
	ldr r4, _08123338 @ =0x0000046B
	adds r0, r5, r4
	strb r1, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r1, [r0]
	b _08123342
	.align 2, 0
_08123334: .4byte Mummy_StateRespawn
_08123338: .4byte 0x0000046B
_0812333C:
	ldr r2, _08123350 @ =0x0000046E
	adds r0, r5, r2
	strb r1, [r0]
_08123342:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08123350: .4byte 0x0000046E
