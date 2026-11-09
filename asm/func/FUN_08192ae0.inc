	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x3c
	mov sl, r0
	str r1, [sp, #0x38]
	mov sb, r3
	movs r1, #0
	ldr r0, [sp, #0x38]
	cmp r1, r0
	bge _08192BDC
	movs r0, #0x40
	adds r0, r0, r2
	mov r8, r0
	adds r7, r2, #0
	subs r7, #0x40
	movs r5, #0
	movs r6, #2
_08192B08:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08192B78
	mov r0, sb
	cmp r0, #0
	beq _08192B22
	adds r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	add r0, r8
	b _08192B2C
_08192B22:
	adds r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	subs r0, r7, r0
_08192B2C:
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r4, r1, #0
	movs r0, #0xc
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	str r2, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x32
	str r0, [sp, #0x10]
	str r6, [sp, #0x14]
	str r6, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x1c]
	str r5, [sp, #0x20]
	ldr r0, _08192B70 @ =0x0000F422
	str r0, [sp, #0x24]
	ldr r0, _08192B74 @ =0x0000121B
	str r0, [sp, #0x28]
	str r5, [sp, #0x2c]
	str r5, [sp, #0x30]
	movs r0, #0xda
	str r0, [sp, #0x34]
	mov r0, sl
	movs r1, #0xc
	movs r2, #8
	movs r3, #6
	bl Entity081ee7a8_SpawnEx
	b _08192BD4
	.align 2, 0
_08192B70: .4byte 0x0000F422
_08192B74: .4byte 0x0000121B
_08192B78:
	mov r0, sb
	cmp r0, #0
	beq _08192B8A
	adds r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	add r0, r8
	b _08192B94
_08192B8A:
	adds r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	subs r0, r7, r0
_08192B94:
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r4, r1, #0
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	str r2, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x32
	str r0, [sp, #0x10]
	str r6, [sp, #0x14]
	str r6, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [sp, #0x1c]
	str r5, [sp, #0x20]
	ldr r0, _08192BEC @ =0x0000F422
	str r0, [sp, #0x24]
	ldr r0, _08192BF0 @ =0x0000121B
	str r0, [sp, #0x28]
	str r5, [sp, #0x2c]
	str r5, [sp, #0x30]
	movs r0, #0xda
	str r0, [sp, #0x34]
	mov r0, sl
	movs r1, #0xc
	movs r2, #8
	movs r3, #6
	bl Entity081ee7a8_SpawnEx
_08192BD4:
	adds r1, r4, #0
	ldr r0, [sp, #0x38]
	cmp r1, r0
	blt _08192B08
_08192BDC:
	add sp, #0x3c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08192BEC: .4byte 0x0000F422
_08192BF0: .4byte 0x0000121B
