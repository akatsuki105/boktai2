	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r1
	mov r8, r2
	mov ip, r3
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r5, #0
	ldr r1, _081932E0 @ =0xFFFFFEFF
	mov sl, r1
	ldr r1, _081932E4 @ =0x0000077A
	adds r3, r0, r1
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r7, _081932E8 @ =0xFFFFFDFF
	movs r6, #0x92
	lsls r6, r6, #1
	adds r1, #7
	adds r4, r0, r1
_081932BE:
	cmp r5, sb
	blt _08193306
	cmp r5, r8
	bgt _08193306
	mov r0, ip
	cmp r0, #0
	bne _081932EC
	ldrh r1, [r3]
	mov r0, sl
	ands r0, r1
	strh r0, [r3]
	ldr r0, [r2]
	ands r0, r7
	str r0, [r2]
	movs r0, #2
	strb r0, [r4]
	b _0819330C
	.align 2, 0
_081932E0: .4byte 0xFFFFFEFF
_081932E4: .4byte 0x0000077A
_081932E8: .4byte 0xFFFFFDFF
_081932EC:
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #1
	orrs r0, r1
	strh r0, [r3]
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r2]
	movs r0, #3
	strb r0, [r4]
	b _0819330C
_08193306:
	ldr r0, [r2]
	ands r0, r7
	str r0, [r2]
_0819330C:
	adds r4, r4, r6
	adds r3, r3, r6
	adds r2, r2, r6
	adds r5, #1
	cmp r5, #5
	ble _081932BE
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
