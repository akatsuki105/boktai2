	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x58
	mov r8, r0
	movs r7, #0
	mov r0, sp
	adds r0, #0x2c
	str r0, [sp, #0x4c]
	add r1, sp, #0x34
	mov sl, r1
	mov r2, sp
	adds r2, #0x3c
	str r2, [sp, #0x44]
	subs r0, #0x10
	str r0, [sp, #0x48]
	str r2, [sp, #0x50]
	str r1, [sp, #0x54]
	ldr r2, [sp, #0x4c]
	mov sb, r2
_080BD4A8:
	cmp r7, #0
	bne _080BD4B4
	ldr r0, _080BD4B0 @ =0x0000178A
	b _080BD4B6
	.align 2, 0
_080BD4B0: .4byte 0x0000178A
_080BD4B4:
	ldr r0, _080BD4FC @ =0x00001787
_080BD4B6:
	add r0, r8
	ldrb r4, [r0]
	adds r0, r4, #3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	mov r5, r8
	adds r5, #0x80
	adds r1, r5, r1
	ldr r0, [r1]
	movs r6, #1
	orrs r0, r6
	str r0, [r1]
	adds r0, r4, #0
	bl FindRegisteredWeaponSlot
	cmp r0, #0
	blt _080BD4EA
	adds r0, #0x22
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r1, r5, r1
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
_080BD4EA:
	adds r0, r4, #0
	bl GetWeaponID
	adds r1, r0, #0
	cmp r1, #0
	ble _080BD500
	mov r0, sb
	str r6, [r0]
	b _080BD506
	.align 2, 0
_080BD4FC: .4byte 0x00001787
_080BD500:
	movs r0, #0
	mov r2, sb
	str r0, [r2]
_080BD506:
	ldr r0, [sp, #0x54]
	stm r0!, {r1}
	str r0, [sp, #0x54]
	ldr r0, _080BD570 @ =0x000002DF
	ldr r1, [sp, #0x50]
	stm r1!, {r0}
	str r1, [sp, #0x50]
	lsls r0, r7, #3
	add r0, sp
	adds r0, #0xc
	adds r1, r4, #0
	bl FUN_080b9938
	movs r2, #4
	add sb, r2
	adds r7, #1
	cmp r7, #1
	ble _080BD4A8
	add r2, sp, #0x14
	ldr r3, [sp, #0x48]
	movs r7, #1
_080BD530:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	stm r3!, {r0, r1}
	subs r2, #8
	subs r7, #1
	cmp r7, #0
	bge _080BD530
	ldr r0, _080BD574 @ =0x00001690
	add r0, r8
	mov r1, sl
	str r1, [sp]
	ldr r2, [sp, #0x44]
	str r2, [sp, #4]
	movs r1, #0xc
	str r1, [sp, #8]
	ldr r1, [sp, #0x4c]
	add r2, sp, #0xc
	ldr r3, [sp, #0x48]
	bl FUN_080b9a28
	ldr r0, _080BD578 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x58
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BD570: .4byte 0x000002DF
_080BD574: .4byte 0x00001690
_080BD578: .4byte 0x0000038A
