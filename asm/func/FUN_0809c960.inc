	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0x18
	adds r5, r0, #0
	ldr r2, _0809C9F8 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #8
	orrs r0, r1
	ldr r1, _0809C9FC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x88
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	mov sb, r0
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	ldr r1, _0809CA00 @ =0x00000C0C
	adds r6, r5, r1
	movs r0, #0xa0
	adds r0, r0, r5
	mov sl, r0
	movs r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	movs r1, #0x3c
	mov r8, r1
	str r1, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r6, #0
	mov r1, sl
	movs r2, #0xb6
	movs r3, #0x10
	bl MainSprite_Add
	adds r0, r6, #0
	movs r1, #1
	bl FUN_0808ba0c
	movs r1, #0xd8
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x88
	mov r1, sb
	strh r0, [r1, #2]
	strh r4, [r1, #4]
	ldr r0, _0809CA04 @ =0x00000DA4
	adds r5, r5, r0
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #0x10
	bl MainSprite_Add
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809C9F8: .4byte 0xFFFF0000
_0809C9FC: .4byte 0x0000FFFF
_0809CA00: .4byte 0x00000C0C
_0809CA04: .4byte 0x00000DA4
