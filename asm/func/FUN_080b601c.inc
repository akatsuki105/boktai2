	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x54
	adds r7, r0, #0
	movs r5, #0
	mov r0, sp
	adds r0, #0x2c
	str r0, [sp, #0x44]
	add r1, sp, #0x34
	mov r8, r1
	add r0, sp, #0x3c
	mov sb, r0
	add r1, sp, #0x1c
	mov sl, r1
	str r0, [sp, #0x48]
	mov r1, r8
	str r1, [sp, #0x4c]
	ldr r2, [sp, #0x44]
_080B6046:
	cmp r5, #0
	bne _080B6054
	ldr r1, _080B6050 @ =0x0000142E
	b _080B6056
	.align 2, 0
_080B6050: .4byte 0x0000142E
_080B6054:
	ldr r1, _080B608C @ =0x0000142B
_080B6056:
	adds r0, r7, r1
	ldrb r4, [r0]
	adds r1, r4, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r1, r7, #0
	adds r1, #0x80
	adds r1, r1, r0
	ldr r0, [r1]
	movs r6, #1
	orrs r0, r6
	str r0, [r1]
	ldr r1, _080B6090 @ =0x00001458
	adds r0, r7, r1
	adds r0, r0, r4
	ldrb r0, [r0]
	str r2, [sp, #0x50]
	bl GetNormalItemID
	adds r1, r0, #0
	ldr r2, [sp, #0x50]
	cmp r1, #0
	blt _080B6094
	str r6, [r2]
	b _080B6098
	.align 2, 0
_080B608C: .4byte 0x0000142B
_080B6090: .4byte 0x00001458
_080B6094:
	movs r0, #0
	str r0, [r2]
_080B6098:
	adds r0, r1, #0
	adds r0, #0x68
	ldr r1, [sp, #0x4c]
	stm r1!, {r0}
	str r1, [sp, #0x4c]
	ldr r0, _080B6108 @ =0x000002DF
	ldr r1, [sp, #0x48]
	stm r1!, {r0}
	str r1, [sp, #0x48]
	lsls r0, r5, #3
	add r0, sp
	adds r0, #0xc
	adds r1, r4, #0
	str r2, [sp, #0x50]
	bl FUN_080b9938
	ldr r2, [sp, #0x50]
	adds r2, #4
	adds r5, #1
	cmp r5, #1
	ble _080B6046
	add r2, sp, #0x14
	mov r3, sl
	movs r5, #1
_080B60C8:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	stm r3!, {r0, r1}
	subs r2, #8
	subs r5, #1
	cmp r5, #0
	bge _080B60C8
	ldr r1, _080B610C @ =0x00001218
	adds r0, r7, r1
	mov r1, r8
	str r1, [sp]
	mov r1, sb
	str r1, [sp, #4]
	movs r1, #0xc
	str r1, [sp, #8]
	ldr r1, [sp, #0x44]
	add r2, sp, #0xc
	mov r3, sl
	bl FUN_080b9a28
	ldr r0, _080B6110 @ =0x0000038A
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
_080B6108: .4byte 0x000002DF
_080B610C: .4byte 0x00001218
_080B6110: .4byte 0x0000038A
