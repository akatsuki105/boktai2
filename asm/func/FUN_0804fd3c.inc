	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, [r4, #0x6c]
	cmp r1, #0
	beq _0804FE02
	ldr r0, _0804FDAC @ =0x03002CF0
	ldr r0, [r0]
	bl Mod
	adds r5, r0, #0
	ldr r6, [r4, #0x74]
	movs r2, #0
	movs r0, #0xf
	mov sl, r0
	adds r4, #0x98
	mov sb, r4
_0804FD66:
	ldr r1, _0804FDB0 @ =0x030046A0
	ldr r0, [r1]
	lsls r1, r2, #1
	adds r0, r1, r0
	adds r0, #0x68
	mov ip, r0
	movs r3, #1
	rsbs r3, r3, #0
	adds r0, r3, #0
	mov r3, ip
	strh r0, [r3]
	adds r4, r5, #0
	mov r8, r1
	adds r7, r5, #0
	adds r7, #0x10
	adds r2, #1
	str r2, [sp]
	cmp r5, r7
	bge _0804FDE0
	adds r2, r5, #0
	mov r0, sl
	ands r2, r0
	movs r3, #1
	lsls r3, r2
	adds r0, r6, #0
	ands r0, r3
	cmp r0, #0
	beq _0804FDB4
	lsls r0, r2, #1
	add r0, sb
	ldrh r0, [r0]
	mov r1, ip
	strh r0, [r1]
	bics r6, r3
	b _0804FDE0
	.align 2, 0
_0804FDAC: .4byte 0x03002CF0
_0804FDB0: .4byte 0x030046A0
_0804FDB4:
	adds r4, #1
	cmp r4, r7
	bge _0804FDE0
	adds r1, r4, #0
	mov r3, sl
	ands r1, r3
	movs r2, #1
	lsls r2, r1
	adds r0, r6, #0
	ands r0, r2
	cmp r0, #0
	beq _0804FDB4
	ldr r3, _0804FE14 @ =0x030046A0
	ldr r0, [r3]
	add r0, r8
	adds r0, #0x68
	lsls r1, r1, #1
	add r1, sb
	ldrh r1, [r1]
	strh r1, [r0]
	bics r6, r2
	adds r5, r4, #0
_0804FDE0:
	ldr r1, _0804FE18 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0804FE1C @ =0x000003FF
	ands r0, r1
	ldr r3, _0804FE18 @ =0x030046B8
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _0804FE20 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r3, sl
	ands r0, r3
	adds r5, r5, r0
	ldr r2, [sp]
	cmp r2, #3
	ble _0804FD66
_0804FE02:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804FE14: .4byte 0x030046A0
_0804FE18: .4byte 0x030046B8
_0804FE1C: .4byte 0x000003FF
_0804FE20: .4byte 0x0203B400
