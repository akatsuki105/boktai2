	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r5, #0
	ldr r0, _0822CFF0 @ =0x03003FC0
	mov sl, r0
	ldr r1, _0822CFF4 @ =0x03003FE0
	mov sb, r1
	ldr r2, _0822CFF8 @ =0x03003FB0
	mov r8, r2
	ldr r7, _0822CFFC @ =0x03003FD0
	mov ip, r7
	ldr r0, _0822D000 @ =0x03003FF0
	str r0, [sp]
	ldr r6, _0822D004 @ =0x085B0130
_0822CF98:
	ldrh r1, [r6]
	ldrb r2, [r6]
	lsrs r1, r1, #8
	asrs r4, r2, #3
	asrs r3, r1, #3
	ldr r7, _0822D008 @ =0x03004030
	adds r0, r5, r7
	strb r2, [r0]
	mov r2, sl
	adds r0, r5, r2
	strb r1, [r0]
	mov r7, sb
	adds r0, r5, r7
	strb r4, [r0]
	mov r1, r8
	adds r0, r5, r1
	strb r3, [r0]
	mov r2, ip
	adds r1, r5, r2
	adds r0, r4, #0
	muls r0, r3, r0
	strb r0, [r1]
	movs r1, #3
	ands r1, r5
	lsls r1, r1, #0xe
	movs r0, #0xc
	ands r0, r5
	lsls r0, r0, #0x1c
	orrs r1, r0
	ldr r7, [sp]
	stm r7!, {r1}
	str r7, [sp]
	adds r6, #2
	adds r5, #1
	cmp r5, #0xf
	ble _0822CF98
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822CFF0: .4byte 0x03003FC0
_0822CFF4: .4byte 0x03003FE0
_0822CFF8: .4byte 0x03003FB0
_0822CFFC: .4byte 0x03003FD0
_0822D000: .4byte 0x03003FF0
_0822D004: .4byte 0x085B0130
_0822D008: .4byte 0x03004030
