	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r0, _0809ED6C @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	bne _0809ED70
	movs r1, #1
	rsbs r1, r1, #0
	b _0809ED74
	.align 2, 0
_0809ED6C: .4byte 0x03002C68
_0809ED70:
	movs r2, #0x18
	ldrsh r1, [r1, r2]
_0809ED74:
	ldr r0, [r0]
	cmp r0, #0
	bne _0809ED7E
	movs r0, #0
	b _0809ED84
_0809ED7E:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_0809ED84:
	adds r2, r0, #0
	cmp r2, #0
	beq _0809EDD6
	mov r1, ip
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #0
	bne _0809EE12
	movs r0, #1
	strb r0, [r1]
	movs r4, #0
	mov r0, ip
	adds r0, #0x26
	adds r5, r0, #0
	ldrb r0, [r5]
	cmp r4, r0
	bge _0809EE12
	mov r3, ip
	adds r3, #0xc6
	movs r6, #0
	mov r7, ip
	adds r7, #0x34
_0809EDB0:
	ldrb r0, [r3, #3]
	cmp r0, #0
	beq _0809EDC8
	ldrb r0, [r3]
	cmp r0, #0
	beq _0809EDC8
	adds r0, r7, r6
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0809EDC8:
	adds r3, #0xa8
	adds r6, #0xa8
	adds r4, #1
	ldrb r2, [r5]
	cmp r4, r2
	blt _0809EDB0
	b _0809EE12
_0809EDD6:
	mov r1, ip
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #1
	bne _0809EE12
	strb r2, [r1]
	movs r4, #0
	mov r0, ip
	adds r0, #0x26
	adds r5, r0, #0
	ldrb r0, [r5]
	cmp r4, r0
	bge _0809EE12
	movs r6, #1
	mov r2, ip
	adds r2, #0xc9
	mov r1, ip
	adds r3, r5, #0
_0809EDFA:
	ldrb r0, [r2]
	cmp r0, #0
	beq _0809EE06
	ldr r0, [r1, #0x34]
	orrs r0, r6
	str r0, [r1, #0x34]
_0809EE06:
	adds r2, #0xa8
	adds r1, #0xa8
	adds r4, #1
	ldrb r0, [r3]
	cmp r4, r0
	blt _0809EDFA
_0809EE12:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
