	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x58
	adds r7, r0, #0
	movs r6, #0
	mov r0, sp
	adds r0, #0x2c
	str r0, [sp, #0x48]
	mov r1, sp
	adds r1, #0x34
	str r1, [sp, #0x4c]
	add r2, sp, #0x3c
	mov sl, r2
	subs r0, #0x10
	str r0, [sp, #0x44]
	mov r1, sl
	str r1, [sp, #0x50]
	ldr r2, [sp, #0x4c]
	str r2, [sp, #0x54]
	ldr r0, [sp, #0x48]
	mov sb, r0
_080B6CD8:
	cmp r6, #0
	bne _080B6CE8
	ldr r1, _080B6CE4 @ =0x0000142E
	adds r0, r7, r1
	b _080B6CEC
	.align 2, 0
_080B6CE4: .4byte 0x0000142E
_080B6CE8:
	ldr r2, _080B6D40 @ =0x0000142B
	adds r0, r7, r2
_080B6CEC:
	ldrb r4, [r0]
	adds r0, r4, #3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r5, r7, #0
	adds r5, #0x80
	adds r1, r5, r1
	ldr r0, [r1]
	movs r2, #1
	mov r8, r2
	orrs r0, r2
	str r0, [r1]
	adds r0, r7, #0
	adds r1, r4, #0
	bl Warehouse_FindRegisteredSlot
	cmp r0, #0
	blt _080B6D24
	adds r0, #0x28
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r1, r5, r1
	ldr r0, [r1]
	mov r2, r8
	orrs r0, r2
	str r0, [r1]
_080B6D24:
	ldr r1, _080B6D44 @ =0x00001458
	adds r0, r7, r1
	adds r0, r0, r4
	ldrb r0, [r0]
	bl GetWeaponID
	adds r1, r0, #0
	cmp r1, #0
	ble _080B6D48
	mov r2, r8
	mov r0, sb
	str r2, [r0]
	b _080B6D4E
	.align 2, 0
_080B6D40: .4byte 0x0000142B
_080B6D44: .4byte 0x00001458
_080B6D48:
	movs r0, #0
	mov r2, sb
	str r0, [r2]
_080B6D4E:
	ldr r0, [sp, #0x54]
	stm r0!, {r1}
	str r0, [sp, #0x54]
	ldr r0, _080B6DB8 @ =0x000002DF
	ldr r1, [sp, #0x50]
	stm r1!, {r0}
	str r1, [sp, #0x50]
	lsls r0, r6, #3
	add r0, sp
	adds r0, #0xc
	adds r1, r4, #0
	bl FUN_080b9938
	movs r2, #4
	add sb, r2
	adds r6, #1
	cmp r6, #1
	ble _080B6CD8
	add r2, sp, #0x14
	ldr r3, [sp, #0x44]
	movs r6, #1
_080B6D78:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	stm r3!, {r0, r1}
	subs r2, #8
	subs r6, #1
	cmp r6, #0
	bge _080B6D78
	ldr r1, _080B6DBC @ =0x00001218
	adds r0, r7, r1
	ldr r2, [sp, #0x4c]
	str r2, [sp]
	mov r1, sl
	str r1, [sp, #4]
	movs r1, #0xc
	str r1, [sp, #8]
	ldr r1, [sp, #0x48]
	add r2, sp, #0xc
	ldr r3, [sp, #0x44]
	bl FUN_080b9a28
	ldr r0, _080B6DC0 @ =0x0000038A
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
_080B6DB8: .4byte 0x000002DF
_080B6DBC: .4byte 0x00001218
_080B6DC0: .4byte 0x0000038A
