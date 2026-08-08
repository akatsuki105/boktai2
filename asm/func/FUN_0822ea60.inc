	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r1, #0
	adds r4, r2, #0
	adds r5, r3, #0
	movs r0, #0
	bl GetTilemapBuffer
	mov sl, r0
	mov sb, r6
	adds r1, r6, r4
	adds r5, r5, r7
	mov r8, r5
	cmp r7, r8
	bhs _0822EAC4
_0822EA88:
	mov r6, sb
	adds r5, r7, #1
	cmp r6, r1
	bhs _0822EABE
	ldr r0, _0822EAD4 @ =0x000003FF
	adds r2, r0, #0
_0822EA94:
	lsls r0, r7, #5
	adds r0, r0, r6
	lsls r0, r0, #1
	mov r3, sl
	adds r4, r0, r3
	ldrh r0, [r4]
	ands r0, r2
	str r1, [sp]
	str r2, [sp, #4]
	bl FUN_0822ea10
	ldr r1, [sp]
	ldr r2, [sp, #4]
	cmp r0, #0
	beq _0822EAB8
	ldr r3, _0822EAD8 @ =0x0000F001
	adds r0, r3, #0
	strh r0, [r4]
_0822EAB8:
	adds r6, #1
	cmp r6, r1
	blo _0822EA94
_0822EABE:
	adds r7, r5, #0
	cmp r7, r8
	blo _0822EA88
_0822EAC4:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822EAD4: .4byte 0x000003FF
_0822EAD8: .4byte 0x0000F001
