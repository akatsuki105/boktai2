	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	adds r5, r6, #4
	ldr r0, _082414B8 @ =0x00001004
	adds r0, r0, r6
	mov sb, r0
	movs r7, #0
	b _082414F2
	.align 2, 0
_082414B8: .4byte 0x00001004
_082414BC:
	movs r4, #0
	movs r1, #8
	adds r1, r1, r5
	mov r8, r1
	ldrh r1, [r5, #4]
	cmp r4, r1
	bge _082414F0
	cmp r7, r0
	bhs _082414F0
_082414CE:
	mov r0, sb
	adds r0, #4
	mov sb, r0
	subs r0, #4
	ldm r0!, {r2}
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823206c
	adds r7, #1
	adds r4, #1
	ldrh r1, [r5, #4]
	cmp r4, r1
	bge _082414F0
	ldr r0, [r6]
	cmp r7, r0
	blo _082414CE
_082414F0:
	mov r5, r8
_082414F2:
	ldr r0, [r6]
	cmp r7, r0
	blo _082414BC
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
