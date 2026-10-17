	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x54
	adds r6, r0, #0
	movs r4, #0
	mov r0, sp
	adds r0, #0x2c
	str r0, [sp, #0x48]
	add r1, sp, #0x34
	mov sl, r1
	add r2, sp, #0x3c
	mov sb, r2
	subs r0, #0x10
	str r0, [sp, #0x44]
	mov r1, sb
	str r1, [sp, #0x4c]
	mov r2, sl
	str r2, [sp, #0x50]
	ldr r0, [sp, #0x48]
	mov r8, r0
_080B7F4E:
	cmp r4, #0
	bne _080B7F5C
	ldr r1, _080B7F58 @ =0x0000142E
	adds r0, r6, r1
	b _080B7F60
	.align 2, 0
_080B7F58: .4byte 0x0000142E
_080B7F5C:
	ldr r2, _080B7FB8 @ =0x0000142B
	adds r0, r6, r2
_080B7F60:
	ldrb r3, [r0]
	adds r1, r3, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r1, r6, #0
	adds r1, #0x80
	adds r1, r1, r0
	ldr r0, [r1]
	movs r5, #1
	orrs r0, r5
	str r0, [r1]
	ldr r7, _080B7FBC @ =0x030046A0
	ldr r0, [r7]
	adds r0, #0x5c
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _080B7FC0 @ =0x00001458
	adds r0, r6, r2
	adds r2, r0, r3
	ldrb r0, [r2]
	cmp r1, r0
	bne _080B7F9A
	movs r0, #0xf8
	lsls r0, r0, #4
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
_080B7F9A:
	ldrb r0, [r2]
	ldr r1, [r7]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #0
	blt _080B7FC4
	mov r0, r8
	str r5, [r0]
	b _080B7FCA
	.align 2, 0
_080B7FB8: .4byte 0x0000142B
_080B7FBC: .4byte 0x030046A0
_080B7FC0: .4byte 0x00001458
_080B7FC4:
	movs r0, #0
	mov r2, r8
	str r0, [r2]
_080B7FCA:
	adds r0, r1, #0
	adds r0, #0x43
	ldr r1, [sp, #0x50]
	stm r1!, {r0}
	str r1, [sp, #0x50]
	ldr r0, _080B8038 @ =0x000002DF
	ldr r2, [sp, #0x4c]
	stm r2!, {r0}
	str r2, [sp, #0x4c]
	lsls r0, r4, #3
	add r0, sp
	adds r0, #0xc
	adds r1, r3, #0
	bl FUN_080b9938
	movs r0, #4
	add r8, r0
	adds r4, #1
	cmp r4, #1
	ble _080B7F4E
	add r2, sp, #0x14
	ldr r3, [sp, #0x44]
	movs r4, #1
_080B7FF8:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	stm r3!, {r0, r1}
	subs r2, #8
	subs r4, #1
	cmp r4, #0
	bge _080B7FF8
	ldr r1, _080B803C @ =0x00001218
	adds r0, r6, r1
	mov r2, sl
	str r2, [sp]
	mov r1, sb
	str r1, [sp, #4]
	movs r1, #0xc
	str r1, [sp, #8]
	ldr r1, [sp, #0x48]
	add r2, sp, #0xc
	ldr r3, [sp, #0x44]
	bl FUN_080b9a28
	ldr r0, _080B8040 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x54
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B8038: .4byte 0x000002DF
_080B803C: .4byte 0x00001218
_080B8040: .4byte 0x0000038A
