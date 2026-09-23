	push {r4, r5, lr}
	sub sp, #4
	str r1, [sp]
	movs r5, #0
	adds r4, r0, #0
	movs r2, #0
	adds r1, r4, #0
	adds r1, #0xb
_08048B38:
	strb r2, [r1]
	subs r1, #1
	cmp r1, r0
	bge _08048B38
	ldr r0, [sp]
	cmp r0, #0
	bge _08048B52
	movs r0, #0x2d
	strb r0, [r4]
	adds r4, #1
	ldr r0, [sp]
	rsbs r0, r0, #0
	str r0, [sp]
_08048B52:
	ldr r1, _08048BEC @ =0x000186A0
	mov r0, sp
	bl FUN_08048a78
	cmp r0, #0
	beq _08048B66
	adds r0, #0x30
	strb r0, [r4]
	movs r5, #1
	adds r4, #1
_08048B66:
	ldr r1, _08048BF0 @ =0x00002710
	mov r0, sp
	bl FUN_08048a78
	cmp r0, #0
	bne _08048B76
	cmp r5, #0
	beq _08048B7E
_08048B76:
	adds r0, #0x30
	strb r0, [r4]
	movs r5, #1
	adds r4, #1
_08048B7E:
	movs r1, #0xfa
	lsls r1, r1, #2
	mov r0, sp
	bl FUN_08048a78
	cmp r0, #0
	bne _08048B90
	cmp r5, #0
	beq _08048B98
_08048B90:
	adds r0, #0x30
	strb r0, [r4]
	movs r5, #1
	adds r4, #1
_08048B98:
	mov r0, sp
	movs r1, #0x64
	bl FUN_08048a78
	cmp r0, #0
	bne _08048BA8
	cmp r5, #0
	beq _08048BB0
_08048BA8:
	adds r0, #0x30
	strb r0, [r4]
	movs r5, #1
	adds r4, #1
_08048BB0:
	mov r0, sp
	movs r1, #0xa
	bl FUN_08048a78
	cmp r0, #0
	bne _08048BC0
	cmp r5, #0
	beq _08048BC6
_08048BC0:
	adds r0, #0x30
	strb r0, [r4]
	adds r4, #1
_08048BC6:
	movs r0, #0
	ldr r2, [sp]
	adds r3, r4, #1
	cmp r2, #0
	ble _08048BDC
_08048BD0:
	adds r0, #1
	subs r1, r2, #1
	adds r2, r1, #0
	cmp r1, #0
	bgt _08048BD0
	str r1, [sp]
_08048BDC:
	adds r0, #0x30
	strb r0, [r4]
	movs r0, #0
	strb r0, [r3]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08048BEC: .4byte 0x000186A0
_08048BF0: .4byte 0x00002710
