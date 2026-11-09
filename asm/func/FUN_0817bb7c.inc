	push {lr}
	adds r3, r0, #0
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhi _0817BBD8
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrb r1, [r0]
	ldrb r0, [r3, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0817BBB0
	ldr r2, _0817BBAC @ =0xFFFFFF00
	adds r1, r1, r2
	b _0817BBBE
	.align 2, 0
_0817BBAC: .4byte 0xFFFFFF00
_0817BBB0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0817BBBE
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_0817BBBE:
	cmp r1, #0
	bge _0817BBC4
	rsbs r1, r1, #0
_0817BBC4:
	ldr r2, _0817BBD4 @ =0x000001FD
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r1, r0
	bgt _0817BBD8
	movs r0, #1
	b _0817BBDA
	.align 2, 0
_0817BBD4: .4byte 0x000001FD
_0817BBD8:
	movs r0, #0
_0817BBDA:
	pop {r1}
	bx r1
	.align 2, 0
