	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	mov r8, r0
	mov sb, r8
	ldr r5, _0821DA50 @ =0x00000B54
	add r5, r8
	ldr r1, _0821DA54 @ =0x08252864
	mov r0, sp
	movs r2, #0x20
	bl memcpy
	add r4, sp, #0x20
	ldr r1, _0821DA58 @ =0x08252884
	adds r0, r4, #0
	movs r2, #0x10
	bl memcpy
	ldr r6, _0821DA5C @ =0x00000B74
	add r6, r8
	movs r2, #0xb7
	lsls r2, r2, #2
	add r2, r8
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r7, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r7, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	mov sl, r4
	cmp r0, #0
	blt _0821DA60
	asrs r0, r0, #8
	b _0821DA66
	.align 2, 0
_0821DA50: .4byte 0x00000B54
_0821DA54: .4byte 0x08252864
_0821DA58: .4byte 0x08252884
_0821DA5C: .4byte 0x00000B74
_0821DA60:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0821DA66:
	strh r0, [r6]
	adds r1, r7, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0821DA78
	asrs r0, r0, #8
	b _0821DA7E
_0821DA78:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0821DA7E:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0821DA92
	asrs r0, r0, #8
	b _0821DA98
_0821DA92:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0821DA98:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0821DB1C @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r0, #0xb4
	lsls r0, r0, #2
	add r0, sb
	ldrh r4, [r0]
	ldr r0, _0821DB20 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	ldr r1, _0821DB24 @ =0x00000B34
	add r1, sb
	lsls r0, r0, #1
	lsls r2, r4, #2
	adds r0, r0, r2
	add r0, sp
	ldrh r2, [r0]
	adds r0, r5, #0
	movs r3, #1
	bl FUN_0822f3cc
	mov r0, r8
	adds r0, #0xaf
	ldrb r0, [r0]
	cmp r0, #0
	bne _0821DB28
	ldr r0, [r5, #8]
	movs r1, #4
	orrs r0, r1
	str r0, [r5, #8]
	lsls r2, r4, #1
	mov r0, sl
	adds r1, r0, r2
	ldrh r0, [r5, #0x20]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
	mov r0, sp
	adds r0, #0x21
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r5, #0x22]
	adds r0, r0, r1
	b _0821DB50
	.align 2, 0
_0821DB1C: .4byte 0x030047C8
_0821DB20: .4byte 0x030046A0
_0821DB24: .4byte 0x00000B34
_0821DB28:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #8]
	lsls r2, r4, #1
	mov r1, sl
	adds r0, r1, r2
	ldrb r1, [r0]
	ldrh r0, [r5, #0x20]
	subs r0, r0, r1
	strh r0, [r5, #0x20]
	mov r0, sp
	adds r0, #0x21
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r2, [r5, #0x22]
	adds r0, r0, r2
_0821DB50:
	strh r0, [r5, #0x22]
	ldr r0, _0821DB68 @ =0x03002BE0
	ldr r1, [r0]
	ldr r2, _0821DB6C @ =0x00000359
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0821DB70
	adds r0, r1, #0
	adds r0, #0xd0
	ldr r0, [r0]
	b _0821DB7A
	.align 2, 0
_0821DB68: .4byte 0x03002BE0
_0821DB6C: .4byte 0x00000359
_0821DB70:
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
_0821DB7A:
	str r0, [r5, #0x48]
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
