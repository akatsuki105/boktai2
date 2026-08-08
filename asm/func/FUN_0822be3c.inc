	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x30
	adds r7, r0, #0
	mov ip, r1
	mov r8, r2
	ldr r5, [sp, #0x48]
	ldr r6, [sp, #0x4c]
	cmp r6, #8
	ble _0822BE54
	movs r6, #8
_0822BE54:
	movs r2, #0
	adds r1, r5, #0
	ldr r0, _0822BF58 @ =0x0098967F
	cmp r3, r0
	bls _0822BE68
	ldr r4, _0822BF5C @ =0xFF676980
_0822BE60:
	adds r1, #1
	adds r3, r3, r4
	cmp r3, r0
	bhi _0822BE60
_0822BE68:
	lsls r0, r2, #2
	add r0, sp
	adds r0, #0x10
	str r1, [r0]
	adds r2, #1
	adds r1, r5, #0
	ldr r0, _0822BF60 @ =0x000F423F
	cmp r3, r0
	bls _0822BE84
	ldr r4, _0822BF64 @ =0xFFF0BDC0
_0822BE7C:
	adds r1, #1
	adds r3, r3, r4
	cmp r3, r0
	bhi _0822BE7C
_0822BE84:
	lsls r0, r2, #2
	add r0, sp
	adds r0, #0x10
	str r1, [r0]
	adds r2, #1
	adds r1, r5, #0
	ldr r0, _0822BF68 @ =0x0001869F
	cmp r3, r0
	bls _0822BEA0
	ldr r4, _0822BF6C @ =0xFFFE7960
_0822BE98:
	adds r1, #1
	adds r3, r3, r4
	cmp r3, r0
	bhi _0822BE98
_0822BEA0:
	lsls r0, r2, #2
	add r0, sp
	adds r0, #0x10
	str r1, [r0]
	adds r2, #1
	adds r1, r5, #0
	ldr r0, _0822BF70 @ =0x0000270F
	cmp r3, r0
	bls _0822BEBC
	ldr r4, _0822BF74 @ =0xFFFFD8F0
_0822BEB4:
	adds r1, #1
	adds r3, r3, r4
	cmp r3, r0
	bhi _0822BEB4
_0822BEBC:
	lsls r0, r2, #2
	add r0, sp
	adds r0, #0x10
	str r1, [r0]
	adds r2, #1
	adds r1, r5, #0
	ldr r0, _0822BF78 @ =0x000003E7
	cmp r3, r0
	bls _0822BED8
	ldr r4, _0822BF7C @ =0xFFFFFC18
_0822BED0:
	adds r1, #1
	adds r3, r3, r4
	cmp r3, r0
	bhi _0822BED0
_0822BED8:
	lsls r0, r2, #2
	add r0, sp
	adds r0, #0x10
	str r1, [r0]
	adds r2, #1
	adds r1, r5, #0
	cmp r3, #0x63
	bls _0822BEF0
_0822BEE8:
	adds r1, #1
	subs r3, #0x64
	cmp r3, #0x63
	bhi _0822BEE8
_0822BEF0:
	lsls r0, r2, #2
	add r0, sp
	adds r0, #0x10
	str r1, [r0]
	adds r2, #1
	adds r1, r5, #0
	cmp r3, #9
	bls _0822BF08
_0822BF00:
	adds r1, #1
	subs r3, #0xa
	cmp r3, #9
	bhi _0822BF00
_0822BF08:
	lsls r0, r2, #2
	add r0, sp
	adds r0, #0x10
	str r1, [r0]
	adds r2, #1
	adds r1, r5, #0
	cmp r3, #0
	beq _0822BF20
_0822BF18:
	adds r1, #1
	subs r3, #1
	cmp r3, #0
	bne _0822BF18
_0822BF20:
	lsls r0, r2, #2
	add r0, sp
	adds r0, #0x10
	str r1, [r0]
	adds r2, #1
	subs r0, r2, r6
	movs r1, #1
	str r1, [sp]
	lsls r0, r0, #2
	add r0, sp
	adds r0, #0x10
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0x50]
	str r0, [sp, #0xc]
	adds r0, r7, #0
	mov r1, ip
	mov r2, r8
	adds r3, r6, #0
	bl FUN_0822bd28
	add sp, #0x30
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822BF58: .4byte 0x0098967F
_0822BF5C: .4byte 0xFF676980
_0822BF60: .4byte 0x000F423F
_0822BF64: .4byte 0xFFF0BDC0
_0822BF68: .4byte 0x0001869F
_0822BF6C: .4byte 0xFFFE7960
_0822BF70: .4byte 0x0000270F
_0822BF74: .4byte 0xFFFFD8F0
_0822BF78: .4byte 0x000003E7
_0822BF7C: .4byte 0xFFFFFC18
