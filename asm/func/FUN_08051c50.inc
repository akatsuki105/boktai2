	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r3, r0, #0
	mov ip, r1
	adds r7, r2, #0
	ldr r0, _08051C70 @ =0x03000118
	ldr r4, [r0]
	cmp r4, #0
	bne _08051C74
	movs r0, #1
	rsbs r0, r0, #0
	b _08051D08
	.align 2, 0
_08051C70: .4byte 0x03000118
_08051C74:
	str r3, [r4, #0x30]
	movs r0, #0
	strh r0, [r4, #0x1e]
	mov r1, ip
	ldrb r0, [r1, #6]
	cmp r0, #0
	beq _08051C86
	movs r0, #1
	strh r0, [r4, #0x1e]
_08051C86:
	ldrb r0, [r7, #6]
	cmp r0, #0
	beq _08051C94
	ldrh r0, [r4, #0x1e]
	movs r1, #2
	orrs r0, r1
	strh r0, [r4, #0x1e]
_08051C94:
	movs r3, #0
	movs r6, #0x20
	adds r6, r6, r4
	mov r8, r6
	mov sl, r8
	mov sb, r3
	adds r5, r4, #0
	adds r5, #0x24
	adds r2, r4, #0
	adds r2, #0x28
_08051CA8:
	mov r0, sl
	adds r1, r0, r3
	mov r6, ip
	adds r0, r6, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r5, r3
	adds r0, r7, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, r3
	mov r1, sb
	strb r1, [r0]
	adds r3, #1
	cmp r3, #3
	ble _08051CA8
	movs r3, #4
	movs r6, #3
	mov r5, r8
	ldr r0, _08051CE8 @ =0x000002DE
	adds r2, r4, r0
_08051CD2:
	adds r1, r3, #0
	ands r1, r6
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strb r1, [r2]
	cmp r0, #0xa
	ble _08051CEC
	movs r0, #0xa
	b _08051CF2
	.align 2, 0
_08051CE8: .4byte 0x000002DE
_08051CEC:
	cmp r0, #0
	bge _08051CF2
	movs r0, #0
_08051CF2:
	strb r0, [r2, #1]
	adds r2, #0x7c
	adds r3, #1
	cmp r3, #7
	ble _08051CD2
	movs r0, #0
	movs r1, #2
	strb r1, [r4, #0x1c]
	movs r1, #1
	strb r1, [r4, #0x1d]
	str r0, [r4, #0x18]
_08051D08:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
