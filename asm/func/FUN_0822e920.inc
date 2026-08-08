	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov sb, r0
	mov r8, r1
	adds r7, r2, #0
	adds r6, r3, #0
	bl FUN_0822e8c8
	adds r4, r0, #0
	mov r0, r8
	adds r1, r7, #0
	adds r2, r6, #0
	ldr r3, [sp, #0x40]
	bl FUN_0822e8d0
	adds r5, r0, #0
	cmp r5, #0
	blt _0822E96C
	lsls r3, r5, #2
	adds r3, r3, r4
	ldr r1, [r3]
	movs r0, #0xff
	lsls r0, r0, #0x16
	ands r0, r1
	ldr r2, _0822E968 @ =0xC03FFFFF
	ands r1, r2
	movs r2, #0x80
	lsls r2, r2, #0xf
	adds r0, r0, r2
	orrs r1, r0
	str r1, [r3]
	b _0822E9F6
	.align 2, 0
_0822E968: .4byte 0xC03FFFFF
_0822E96C:
	movs r2, #0
	ldr r0, [r4]
	movs r1, #0xff
	lsls r1, r1, #0x16
	b _0822E980
_0822E976:
	adds r4, #4
	adds r2, #1
	cmp r2, #0xff
	bgt _0822E986
	ldr r0, [r4]
_0822E980:
	ands r0, r1
	cmp r0, #0
	bne _0822E976
_0822E986:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r2, r0
	bne _0822E994
	movs r0, #1
	rsbs r0, r0, #0
	b _0822E9F8
_0822E994:
	adds r5, r2, #0
	lsls r0, r7, #0x10
	mov r7, r8
	orrs r0, r7
	lsls r1, r6, #0x12
	orrs r1, r0
	ldr r0, [sp, #0x40]
	lsls r2, r0, #0x14
	orrs r2, r1
	movs r0, #0x80
	lsls r0, r0, #0xf
	orrs r0, r2
	str r0, [r4]
	lsls r0, r6, #8
	adds r0, r0, r6
	lsls r1, r0, #0x10
	adds r0, r0, r1
	lsls r1, r0, #6
	mov r8, r1
	lsls r0, r0, #2
	mov sl, r0
	mov ip, sb
	ldr r3, _0822EA08 @ =0xF0F0F0F0
	ldr r4, _0822EA0C @ =0x0F0F0F0F
	mov r6, sp
	movs r2, #7
_0822E9C8:
	mov r7, ip
	adds r7, #4
	mov ip, r7
	subs r7, #4
	ldm r7!, {r1}
	adds r0, r1, #0
	ands r0, r3
	mov r7, r8
	orrs r0, r7
	ands r0, r3
	ands r1, r4
	mov r7, sl
	orrs r1, r7
	ands r1, r4
	orrs r0, r1
	stm r6!, {r0}
	subs r2, #1
	cmp r2, #0
	bge _0822E9C8
	adds r0, r5, #0
	mov r1, sp
	bl FUN_0822e794
_0822E9F6:
	adds r0, r5, #0
_0822E9F8:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0822EA08: .4byte 0xF0F0F0F0
_0822EA0C: .4byte 0x0F0F0F0F
