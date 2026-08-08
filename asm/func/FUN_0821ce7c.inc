	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0821CE98
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0821CE9A
_0821CE98:
	movs r0, #0
_0821CE9A:
	cmp r0, #0
	bne _0821CEA0
	b _0821D048
_0821CEA0:
	ldr r0, _0821CEB4 @ =0x00000809
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #7
	bhi _0821CEDC
	lsls r0, r0, #2
	ldr r1, _0821CEB8 @ =_0821CEBC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0821CEB4: .4byte 0x00000809
_0821CEB8: .4byte _0821CEBC
_0821CEBC: @ jump table
	.4byte _0821CEE0 @ case 0
	.4byte _0821CEE0 @ case 1
	.4byte _0821CFDC @ case 2
	.4byte _0821CF8C @ case 3
	.4byte _0821CFDC @ case 4
	.4byte _0821CEE0 @ case 5
	.4byte _0821CF1C @ case 6
	.4byte _0821CFDC @ case 7
_0821CEDC:
	movs r0, #0
	strb r0, [r1]
_0821CEE0:
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r5, r2
	ldr r0, [r1]
	cmp r0, #0
	beq _0821CF1C
	movs r4, #0
	str r4, [r1]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_0821c010
	ldr r3, _0821CF14 @ =0x00000BF6
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _0821CF18 @ =0x00000BCC
	adds r0, r5, r1
	movs r2, #0xbf
	lsls r2, r2, #4
	adds r1, r5, r2
	ldr r1, [r1]
	movs r2, #0
	bl FUN_08234f80
	b _0821D03E
	.align 2, 0
_0821CF14: .4byte 0x00000BF6
_0821CF18: .4byte 0x00000BCC
_0821CF1C:
	adds r0, r5, #0
	movs r1, #4
	bl FUN_0821c010
	adds r1, r5, #0
	adds r1, #0x50
	adds r0, r5, #0
	mov r2, sp
	bl FUN_0821c044
	adds r3, r0, #0
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0821CF58
	subs r3, #2
	cmp r3, #0
	bge _0821CF66
	ldr r2, _0821CF54 @ =0x00000BF5
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r3, r3, r0
	b _0821CF66
	.align 2, 0
_0821CF54: .4byte 0x00000BF5
_0821CF58:
	adds r3, #2
	ldr r1, _0821CF80 @ =0x00000BF5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r3, r0
	blt _0821CF66
	subs r3, r3, r0
_0821CF66:
	ldr r0, _0821CF84 @ =0x00000BF6
	adds r2, r5, r0
	strb r3, [r2]
	ldr r1, _0821CF88 @ =0x00000BCC
	adds r0, r5, r1
	movs r3, #0xbf
	lsls r3, r3, #4
	adds r1, r5, r3
	ldr r1, [r1]
	ldrb r2, [r2]
	bl FUN_08234f80
	b _0821D03E
	.align 2, 0
_0821CF80: .4byte 0x00000BF5
_0821CF84: .4byte 0x00000BF6
_0821CF88: .4byte 0x00000BCC
_0821CF8C:
	adds r0, r5, #0
	movs r1, #0xa
	bl FUN_0821c010
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	mov r2, sp
	bl FUN_0821c044
	adds r3, r0, #0
	ldr r2, _0821CFC0 @ =0x00000BF6
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r3, r0
	bne _0821CFC8
	ldr r1, _0821CFC4 @ =0x00000BCC
	adds r2, r5, r1
	adds r0, r5, #0
	mov r1, sp
	bl FUN_0821c044
	strb r0, [r4]
	b _0821D03E
	.align 2, 0
_0821CFC0: .4byte 0x00000BF6
_0821CFC4: .4byte 0x00000BCC
_0821CFC8:
	strb r3, [r4]
	ldr r3, _0821CFD8 @ =0x00000BCC
	adds r2, r5, r3
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r2]
	str r1, [r2, #4]
	b _0821D03E
	.align 2, 0
_0821CFD8: .4byte 0x00000BCC
_0821CFDC:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0821c010
	adds r1, r5, #0
	adds r1, #0x50
	adds r0, r5, #0
	mov r2, sp
	bl FUN_0821c044
	adds r3, r0, #0
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0821D018
	adds r3, #1
	ldr r2, _0821D014 @ =0x00000BF5
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r3, r0
	blt _0821D026
	movs r3, #0
	b _0821D026
	.align 2, 0
_0821D014: .4byte 0x00000BF5
_0821D018:
	subs r3, #1
	cmp r3, #0
	bge _0821D026
	ldr r3, _0821D068 @ =0x00000BF5
	adds r0, r5, r3
	ldrb r0, [r0]
	subs r3, r0, #1
_0821D026:
	ldr r0, _0821D06C @ =0x00000BF6
	adds r2, r5, r0
	strb r3, [r2]
	ldr r1, _0821D070 @ =0x00000BCC
	adds r0, r5, r1
	movs r3, #0xbf
	lsls r3, r3, #4
	adds r1, r5, r3
	ldr r1, [r1]
	ldrb r2, [r2]
	bl FUN_08234f80
_0821D03E:
	adds r0, r5, #0
	movs r1, #2
	movs r2, #1
	bl FUN_08221268
_0821D048:
	movs r1, #0x10
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0821D05E
	adds r0, r5, #0
	bl FUN_0821cb90
_0821D05E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0821D068: .4byte 0x00000BF5
_0821D06C: .4byte 0x00000BF6
_0821D070: .4byte 0x00000BCC
