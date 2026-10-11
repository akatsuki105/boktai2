	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _0809F668 @ =0x03000144
	ldr r0, [r0]
	cmp r0, #0
	bne _0809F676
	b _0809F6E4
	.align 2, 0
_0809F668: .4byte 0x03000144
_0809F66C:
	adds r1, r3, #0
	adds r1, #0xdf
	movs r0, #1
	strb r0, [r1]
	b _0809F6E6
_0809F676:
	movs r4, #0
	ldrh r1, [r0, #0x18]
	cmp r4, r1
	bge _0809F6E4
	mov ip, r0
	adds r6, r1, #0
_0809F682:
	movs r0, #0xf4
	muls r0, r4, r0
	adds r0, #0x1c
	mov r1, ip
	adds r3, r1, r0
	adds r0, r3, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F6DE
	movs r2, #0x1e
	ldrsh r1, [r3, r2]
	movs r7, #2
	ldrsh r0, [r5, r7]
	cmp r1, r0
	blt _0809F6DE
	movs r0, #0
	ldrsh r1, [r5, r0]
	movs r2, #0x1c
	ldrsh r0, [r3, r2]
	subs r2, r1, r0
	cmp r2, #0
	bge _0809F6B2
	rsbs r2, r2, #0
_0809F6B2:
	cmp r2, #0x80
	bgt _0809F6DE
	movs r7, #4
	ldrsh r1, [r5, r7]
	movs r7, #0x20
	ldrsh r0, [r3, r7]
	subs r1, r1, r0
	cmp r1, #0
	bge _0809F6C6
	rsbs r1, r1, #0
_0809F6C6:
	cmp r1, #0x80
	bgt _0809F6DE
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	ble _0809F66C
_0809F6DE:
	adds r4, #1
	cmp r4, r6
	blt _0809F682
_0809F6E4:
	movs r0, #0
_0809F6E6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
