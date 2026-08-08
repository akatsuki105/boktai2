	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	adds r5, r6, #4
	ldr r0, _0824143C @ =0x00001004
	adds r0, r0, r6
	mov sb, r0
	ldr r1, _08241440 @ =0x000001FF
	mov r8, r1
	b _08241482
	.align 2, 0
_0824143C: .4byte 0x00001004
_08241440: .4byte 0x000001FF
_08241444:
	adds r0, r5, #0
	bl FUN_0823167c
	movs r4, #0
	adds r7, r5, #0
	adds r7, #8
	ldrh r0, [r5, #4]
	cmp r4, r0
	bge _08241480
	ldr r0, [r6]
	cmp r0, r8
	bhi _08241480
_0824145C:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_082320e4
	mov r1, sb
	adds r1, #4
	mov sb, r1
	subs r1, #4
	stm r1!, {r0}
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
	adds r4, #1
	ldrh r1, [r5, #4]
	cmp r4, r1
	bge _08241480
	cmp r0, r8
	bls _0824145C
_08241480:
	adds r5, r7, #0
_08241482:
	ldr r0, [r6]
	cmp r0, r8
	bhi _08241490
	bl FUN_082316bc
	cmp r0, #0
	bne _08241444
_08241490:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
