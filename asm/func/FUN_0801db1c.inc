	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl EntityDA0B_TakeFnChanged
	cmp r0, #0
	beq _0801DB74
	ldr r1, _0801DB9C @ =FUN_0801d81c
	adds r0, r5, #0
	bl FUN_0801d7f8
	adds r0, r5, #0
	adds r0, #0x84
	movs r1, #0
	str r1, [r0]
	str r1, [r5, #0x7c]
	adds r2, r5, #0
	adds r2, #0x80
	movs r0, #0x20
	str r0, [r2]
	ldr r0, [r5, #0x68]
	asrs r0, r0, #5
	str r0, [r5, #0x6c]
	adds r0, r5, #0
	adds r0, #0x66
	strb r1, [r0]
	adds r0, #0x3e
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0x88
	movs r0, #2
	str r0, [r1]
	ldr r0, [r5, #0x6c]
	cmp r0, #0xa
	bls _0801DB70
	movs r0, #0xa
	str r0, [r5, #0x6c]
_0801DB70:
	ldr r0, [r5, #0x6c]
	str r0, [r5, #0x70]
_0801DB74:
	adds r4, r5, #0
	adds r4, #0x91
	movs r6, #0
	strb r6, [r4]
	ldr r1, _0801DBA0 @ =0x00001318
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	adds r0, #0x84
	ldr r1, [r0]
	movs r2, #0xb0
	lsls r2, r2, #5
	cmp r1, r2
	ble _0801DBA4
	str r2, [r0]
	b _0801DBAA
	.align 2, 0
_0801DB9C: .4byte FUN_0801d81c
_0801DBA0: .4byte 0x00001318
_0801DBA4:
	cmp r1, #0
	bge _0801DBAA
	str r6, [r0]
_0801DBAA:
	ldr r0, [r0]
	asrs r0, r0, #5
	adds r6, r5, #0
	adds r6, #0x62
	movs r7, #0
	adds r2, r0, #0
	strh r0, [r6]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801DC62
	adds r0, r5, #0
	adds r0, #0x60
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #0
	ldrsh r0, [r6, r3]
	subs r4, r1, r0
	cmp r4, #0
	bge _0801DBD2
	rsbs r4, r4, #0
_0801DBD2:
	adds r0, r5, #0
	adds r0, #0x93
	strb r2, [r0]
	adds r0, r5, #0
	bl FUN_0801d4a8
	adds r1, r5, #0
	adds r1, #0xa0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r0, r5, #0
	adds r0, #0x5c
	movs r2, #0
	ldrsh r1, [r6, r2]
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	blt _0801DC50
	adds r0, r5, #0
	adds r0, #0x5e
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bgt _0801DC50
	cmp r4, #1
	bgt _0801DC28
	adds r1, r5, #0
	adds r1, #0x65
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x43
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	subs r1, #4
	ldr r0, [r1]
	adds r0, #0x64
	str r0, [r1]
	adds r0, r5, #0
	adds r0, #0x92
	strb r7, [r0]
	b _0801DC62
_0801DC28:
	adds r0, r5, #0
	adds r0, #0x65
	strb r7, [r0]
	cmp r4, #0x63
	bgt _0801DC3E
	adds r1, r5, #0
	adds r1, #0xa4
	ldr r0, [r1]
	adds r0, #0x64
	subs r0, r0, r4
	str r0, [r1]
_0801DC3E:
	adds r0, r5, #0
	adds r0, #0xac
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0x92
	movs r0, #1
	b _0801DC60
_0801DC50:
	adds r0, r5, #0
	adds r0, #0xb0
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0x92
	movs r0, #2
_0801DC60:
	strb r0, [r1]
_0801DC62:
	adds r0, r5, #0
	bl FUN_0801d540
	adds r1, r5, #0
	adds r1, #0xb4
	ldr r0, [r1]
	cmp r0, #0
	bne _0801DC80
	ldr r1, _0801DC7C @ =FUN_0801dc90
	adds r0, r5, #0
	bl EntityDA0B_SetFn
	b _0801DC8A
	.align 2, 0
_0801DC7C: .4byte FUN_0801dc90
_0801DC80:
	subs r0, #1
	str r0, [r1]
	ldr r0, [r5, #0x44]
	adds r0, #1
	str r0, [r5, #0x44]
_0801DC8A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
