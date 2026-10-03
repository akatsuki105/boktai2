	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	mov sl, r0
	str r1, [sp, #0x30]
	ldrb r0, [r1, #1]
	cmp r0, #1
	beq _080BCF34
	cmp r0, #1
	bgt _080BCF24
	cmp r0, #0
	beq _080BCF2E
	b _080BCF44
_080BCF24:
	cmp r0, #2
	beq _080BCF38
	cmp r0, #4
	beq _080BCF3E
	b _080BCF44
_080BCF2E:
	movs r0, #0
	str r0, [sp, #0x34]
	b _080BCF4A
_080BCF34:
	movs r1, #1
	b _080BCF48
_080BCF38:
	movs r2, #2
	str r2, [sp, #0x34]
	b _080BCF4A
_080BCF3E:
	movs r0, #3
	str r0, [sp, #0x34]
	b _080BCF4A
_080BCF44:
	movs r1, #1
	rsbs r1, r1, #0
_080BCF48:
	str r1, [sp, #0x34]
_080BCF4A:
	movs r6, #0
	mov r2, sp
	adds r2, #0xc
	str r2, [sp, #0x3c]
	mov r0, sl
	adds r0, #0x18
	str r0, [sp, #0x38]
_080BCF58:
	adds r0, r6, #0
	ldr r1, [sp, #0x3c]
	bl FUN_08242b28
	ldr r0, [sp, #0x3c]
	bl FUN_0807a6cc
	adds r4, r0, #0
	ldr r1, [sp, #0x34]
	cmp r6, r1
	beq _080BCFAC
	mov r1, sp
	bl SplitDecimal3
	movs r7, #0
	lsls r1, r6, #1
	adds r2, r6, #1
	mov sb, r2
	movs r0, #0
	mov r8, r0
	mov r5, sp
	adds r0, r6, #0
	adds r0, #0x28
	adds r4, r1, r0
_080BCF88:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #5
	adds r0, #0x78
	add r0, sl
	ldm r5!, {r2}
	add r2, r8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r1, [sp, #0x38]
	movs r3, #1
	bl MainSprite_SetPose
	adds r4, #1
	adds r7, #1
	cmp r7, #2
	ble _080BCF88
	b _080BD006
_080BCFAC:
	ldr r0, [sp, #0x30]
	bl FUN_0807a6cc
	movs r5, #0
	cmp r0, r4
	beq _080BCFC0
	movs r5, #2
	cmp r0, r4
	ble _080BCFC0
	movs r5, #1
_080BCFC0:
	mov r1, sp
	bl SplitDecimal3
	movs r7, #0
	lsls r1, r6, #1
	lsls r0, r5, #2
	adds r2, r6, #1
	mov sb, r2
	adds r0, r0, r5
	lsls r5, r0, #1
	mov r8, sp
	adds r0, r6, #0
	adds r0, #0x28
	adds r4, r1, r0
_080BCFDC:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #5
	adds r0, #0x78
	add r0, sl
	mov r1, r8
	adds r1, #4
	mov r8, r1
	subs r1, #4
	ldm r1!, {r2}
	adds r2, r2, r5
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r1, [sp, #0x38]
	movs r3, #1
	bl MainSprite_SetPose
	adds r4, #1
	adds r7, #1
	cmp r7, #2
	ble _080BCFDC
_080BD006:
	mov r6, sb
	cmp r6, #3
	ble _080BCF58
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
