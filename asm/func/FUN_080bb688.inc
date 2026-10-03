	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	adds r6, r0, #0
	movs r5, #0
	mov r0, sp
	adds r0, #0x2c
	str r0, [sp, #0x44]
	add r1, sp, #0x34
	mov r8, r1
	add r4, sp, #0x3c
	mov sb, r4
	add r0, sp, #0x1c
	mov sl, r0
	mov r1, sb
	str r1, [sp, #0x48]
	mov r4, r8
	str r4, [sp, #0x4c]
	ldr r7, [sp, #0x44]
_080BB6B4:
	cmp r5, #0
	bne _080BB6C4
	ldr r1, _080BB6C0 @ =0x0000140E
	adds r0, r6, r1
	b _080BB6C8
	.align 2, 0
_080BB6C0: .4byte 0x0000140E
_080BB6C4:
	ldr r4, _080BB714 @ =0x0000140B
	adds r0, r6, r4
_080BB6C8:
	ldrb r2, [r0]
	adds r1, r2, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r1, r6, #0
	adds r1, #0x80
	adds r1, r1, r0
	ldr r0, [r1]
	movs r3, #1
	orrs r0, r3
	str r0, [r1]
	ldr r4, _080BB718 @ =0x030046A0
	ldr r0, [r4]
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bne _080BB6FA
	movs r0, #0xd4
	lsls r0, r0, #4
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
_080BB6FA:
	ldr r1, [r4]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	cmp r1, #0
	blt _080BB71C
	str r3, [r7]
	b _080BB720
	.align 2, 0
_080BB714: .4byte 0x0000140B
_080BB718: .4byte 0x030046A0
_080BB71C:
	movs r0, #0
	str r0, [r7]
_080BB720:
	adds r0, r1, #0
	adds r0, #0x43
	ldr r1, [sp, #0x4c]
	stm r1!, {r0}
	str r1, [sp, #0x4c]
	ldr r0, _080BB78C @ =0x000002DF
	ldr r4, [sp, #0x48]
	stm r4!, {r0}
	str r4, [sp, #0x48]
	lsls r0, r5, #3
	add r0, sp
	adds r0, #0xc
	adds r1, r2, #0
	bl FUN_080b9938
	adds r7, #4
	adds r5, #1
	cmp r5, #1
	ble _080BB6B4
	add r2, sp, #0x14
	mov r3, sl
	movs r5, #1
_080BB74C:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	stm r3!, {r0, r1}
	subs r2, #8
	subs r5, #1
	cmp r5, #0
	bge _080BB74C
	ldr r1, _080BB790 @ =0x00001314
	adds r0, r6, r1
	mov r4, r8
	str r4, [sp]
	mov r1, sb
	str r1, [sp, #4]
	movs r1, #0xc
	str r1, [sp, #8]
	ldr r1, [sp, #0x44]
	add r2, sp, #0xc
	mov r3, sl
	bl FUN_080b9a28
	ldr r0, _080BB794 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BB78C: .4byte 0x000002DF
_080BB790: .4byte 0x00001314
_080BB794: .4byte 0x0000038A
